(() => {
  "use strict";

  const MOVIES = window.MOVIES;
  const USERS = window.USERS;
  const STORAGE_KEY = "kino-rodzinne.v1";
  const MAX_LIMIT = MOVIES.length;
  const app = document.getElementById("app");
  const who = document.getElementById("who");
  const tabs = document.getElementById("tabs");
  const dock = document.getElementById("dock");

  // Podium odsłania się przyciskiem; po resecie znowu jest zakryte.
  let revealed = false;

  // ---------- stan (localStorage, z zapasem w pamięci) ----------

  let memoryState = null;

  function loadState() {
    try {
      const raw = localStorage.getItem(STORAGE_KEY);
      if (raw) return JSON.parse(raw);
    } catch (e) { /* prywatne okno, zablokowany storage itp. */ }
    return memoryState;
  }

  function saveState(state) {
    memoryState = state;
    try { localStorage.setItem(STORAGE_KEY, JSON.stringify(state)); } catch (e) { /* zostaje w pamięci */ }
  }

  function clearState() {
    memoryState = null;
    try { localStorage.removeItem(STORAGE_KEY); } catch (e) { /* nic */ }
  }

  // ---------- pomocnicze ----------

  const esc = (s) => String(s).replace(/[&<>"']/g, (c) => ({ "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;", "'": "&#39;" }[c]));
  const movieById = (id) => MOVIES.find((m) => m.id === id);
  const userById = (id) => USERS.find((u) => u.id === id);
  const doneCount = (state) => USERS.filter((u) => state.votes[u.id]).length;

  // 1 głos, 2–4 głosy, 5+ głosów (12–14 głosów)
  function plural(n, one, few, many) {
    if (n === 1) return one;
    const d = n % 10, h = n % 100;
    return d >= 2 && d <= 4 && (h < 12 || h > 14) ? few : many;
  }
  const votesWord = (n) => `${n} ${plural(n, "głos", "głosy", "głosów")}`;
  const filmsWord = (n) => `${n} ${plural(n, "film", "filmy", "filmów")}`;
  const filmsGen = (n) => `${n} ${n === 1 ? "filmu" : "filmów"}`; // „do 1 filmu”, „do 3 filmów”
  const voted = (u) => (u.female ? "zagłosowała" : "zagłosował");
  const notVoted = (u) => (u.female ? "jeszcze nie głosowała" : "jeszcze nie głosował");

  function badge(u, kind = "") {
    const inner = kind === "dot" ? esc(u.name[0]) : u.emoji;
    return `<span class="badge ${kind}" style="--u:${u.color}" title="${esc(u.name)}">${inner}</span>`;
  }

  function posterHTML(movie, extraClass = "") {
    const [c1, c2] = movie.colors;
    const img = movie.poster
      ? `<img src="${esc(movie.poster)}" alt="" loading="lazy" referrerpolicy="no-referrer" onerror="kinoPosterFailed(this, '${movie.id}')">`
      : "";
    return `
      <div class="poster ${extraClass}" data-movie="${movie.id}" style="--c1:${c1};--c2:${c2}">
        <div class="poster-fallback" aria-hidden="true">
          <span class="poster-emoji">${movie.emoji}</span>
          <span class="poster-title">${esc(movie.title)}</span>
        </div>
        ${img}
      </div>`;
  }

  // Bieżący ekran trzymamy w zmiennej; adres (#/…) to tylko wygoda dla przycisku „Wstecz”.
  // W ramkach, które nie pozwalają zmieniać adresu, aplikacja działa i bez niego.
  let current = location.hash;

  function go(hash) {
    current = hash;
    try { if (location.hash !== hash) history.pushState(null, "", hash); } catch (e) { /* bez historii */ }
    render();
  }

  // Ramka aplikacji: plakietka w nagłówku, dolne zakładki albo pasek akcji.
  function chrome({ chip = "", tab = null, dockHTML = "" } = {}) {
    who.innerHTML = chip;
    tabs.hidden = !tab || !!dockHTML;
    tabs.querySelectorAll("a").forEach((a) => a.classList.toggle("active", a.dataset.tab === tab));
    dock.hidden = !dockHTML;
    dock.innerHTML = dockHTML;
    document.body.classList.toggle("has-bar", !tabs.hidden || !dock.hidden);
  }

  const progressChip = (state) =>
    `<span class="chip"><span class="chip-icon">🎟️</span><span class="chip-name">Głosy</span><span class="tokens ${doneCount(state) === USERS.length ? "full" : ""}">${doneCount(state)}/${USERS.length}</span></span>`;

  function toast(text) {
    document.querySelectorAll(".toast").forEach((t) => t.remove());
    const el = document.createElement("div");
    el.className = "toast";
    el.textContent = text;
    document.body.appendChild(el);
    setTimeout(() => el.remove(), 2600);
  }

  // Okno z wyborem; zwraca wartość klikniętego przycisku albo null (Anuluj / Esc).
  function choiceDialog(text, choices) {
    const tpl = document.getElementById("confirm-dialog");
    const dlg = tpl.content.firstElementChild.cloneNode(true);
    if (typeof dlg.showModal !== "function") {
      return Promise.resolve(window.confirm(text) ? choices[choices.length - 1].value : null);
    }
    dlg.querySelector(".dialog-text").textContent = text;
    dlg.querySelector(".row").innerHTML = [{ value: "", label: "Anuluj", cls: "secondary" }, ...choices]
      .map((c) => `<button value="${c.value}" class="btn ${c.cls || ""}">${esc(c.label)}</button>`)
      .join("");
    document.body.appendChild(dlg);
    return new Promise((resolve) => {
      dlg.addEventListener("close", () => {
        resolve(dlg.returnValue || null);
        dlg.remove();
      });
      dlg.showModal();
    });
  }

  const confirmDialog = (text, okLabel = "Tak", cls = "") =>
    choiceDialog(text, [{ value: "ok", label: okLabel, cls }]).then((v) => v === "ok");

  // ---------- ekran: start ----------

  function renderStart() {
    let limit = Math.min(3, MAX_LIMIT);
    chrome();
    app.innerHTML = `
      <section class="screen">
        <h1>🎬 Nowe głosowanie</h1>
        <div class="card start-card">
          <p>Tata, Mama, Ula i Antek wybierają film na rodzinny wieczór.<br>Ile filmów może wybrać jedna osoba?</p>
          <div class="stepper" role="group" aria-label="Limit głosów">
            <button class="step" data-step="-1" aria-label="Mniej">−</button>
            <output id="limit">${limit}</output>
            <button class="step plus" data-step="1" aria-label="Więcej">+</button>
          </div>
          <p class="muted center" id="limit-hint"></p>
          <button class="btn block big" id="start">🍿 Rozpocznij głosowanie</button>
        </div>
        <h2>W programie</h2>
        <div class="grid">
          ${MOVIES.map((m) => `
            <div class="tile">
              <div class="art">${posterHTML(m)}</div>
              <div class="name">${esc(m.title)}</div>
            </div>`).join("")}
        </div>
      </section>`;

    const out = app.querySelector("#limit");
    const hint = app.querySelector("#limit-hint");
    const update = () => {
      out.textContent = limit;
      hint.textContent = `każdy może wybrać do ${filmsGen(limit)}`;
      app.querySelector('[data-step="-1"]').disabled = limit <= 1;
      app.querySelector('[data-step="1"]').disabled = limit >= MAX_LIMIT;
    };
    app.querySelectorAll("[data-step]").forEach((b) =>
      b.addEventListener("click", () => {
        limit = Math.max(1, Math.min(MAX_LIMIT, limit + Number(b.dataset.step)));
        update();
      })
    );
    app.querySelector("#start").addEventListener("click", () => {
      saveState({ maxVotes: limit, startedAt: new Date().toISOString(), votes: {} });
      revealed = false;
      go("#/osoby");
    });
    update();
  }

  // ---------- ekran: wybór osoby ----------

  function renderUsers(state) {
    const done = doneCount(state);
    chrome({ chip: progressChip(state), tab: "osoby" });
    app.innerHTML = `
      <section class="screen">
        <h1>🎞️ Kto teraz głosuje?</h1>
        <p class="muted lead">Każdy wybiera do <b>${filmsGen(state.maxVotes)}</b>. Zagłosowało <b>${done} z ${USERS.length}</b> osób.</p>
        <div class="people">
          ${USERS.map((u) => {
            const picks = state.votes[u.id];
            return `
              <button class="card person ${picks ? "is-done" : ""}" data-user="${u.id}">
                ${badge(u, "big")}
                <span class="pinfo">
                  <span class="pname">${esc(u.name)}</span>
                  ${picks
                    ? `<span class="pstatus ok">✓ ${voted(u)} · ${filmsWord(picks.length)}</span>`
                    : `<span class="pstatus">${notVoted(u)}</span>`}
                </span>
                <span class="pill ${picks ? "" : "accent"}">${picks ? "Zmień" : "Głosuj"} ›</span>
              </button>`;
          }).join("")}
        </div>
        <button class="btn block big" id="results">🏆 Pokaż wyniki</button>
      </section>`;

    app.querySelectorAll("[data-user]").forEach((b) =>
      b.addEventListener("click", () => go(`#/glosuj/${b.dataset.user}`))
    );
    app.querySelector("#results").addEventListener("click", () => go("#/wyniki"));
  }

  // ---------- ekran: głosowanie ----------

  function renderVote(state, user) {
    const max = state.maxVotes;
    const hadVote = !!state.votes[user.id];
    const selected = new Set((state.votes[user.id] || []).filter(movieById));

    chrome({
      chip: `<button class="chip" id="chip" aria-label="Zmień osobę">${badge(user)}<span class="chip-name">${esc(user.name)}</span><span class="tokens" id="tokens"></span></button>`,
      dockHTML: `
        <button class="btn secondary" id="cancel">Anuluj</button>
        <button class="btn grow" id="confirm">Zatwierdź głos · <span id="cnt"></span></button>`,
    });

    app.innerHTML = `
      <section class="screen">
        <h1>Cześć, ${esc(user.name)}! 👋</h1>
        <p class="muted lead">Wybierz do <b>${filmsGen(max)}</b> – każdy wybór to jeden 🍿. Dotknij plakatu albo przycisku pod nim.</p>
        <div class="grid">
          ${MOVIES.map((m) => `
            <article class="tile" data-movie="${m.id}">
              <button class="art" aria-pressed="false" aria-label="${esc(m.title)}">
                ${posterHTML(m)}
                <span class="meta"><span class="count">✓ 🍿</span></span>
              </button>
              <div class="name">${esc(m.title)} <span class="year">${m.year}</span></div>
              <div class="actions">
                <button class="pick"></button>
              </div>
            </article>`).join("")}
        </div>
        ${hadVote ? `<div class="center"><button class="btn danger-ghost" id="clear-mine">🗑️ Usuń mój głos</button></div>` : ""}
      </section>`;

    const tiles = [...app.querySelectorAll(".tile")];
    const tokens = document.getElementById("tokens");
    const cnt = document.getElementById("cnt");
    const confirmBtn = document.getElementById("confirm");

    function refresh() {
      const full = selected.size >= max;
      tiles.forEach((t) => {
        const on = selected.has(t.dataset.movie);
        t.classList.toggle("is-selected", on);
        t.classList.toggle("is-locked", full && !on);
        t.querySelector(".art").setAttribute("aria-pressed", String(on));
        t.querySelector(".pick").textContent = on ? "✓ Wybrany" : "🍿 Wybieram";
      });
      tokens.textContent = `${max - selected.size} 🍿`;
      tokens.classList.toggle("full", full);
      cnt.textContent = `${selected.size}/${max}`;
      confirmBtn.disabled = selected.size === 0;
    }

    function toggle(tile) {
      const id = tile.dataset.movie;
      if (selected.has(id)) selected.delete(id);
      else if (selected.size < max) selected.add(id);
      else {
        toast(`Masz już ${filmsWord(max)} – najpierw odznacz któryś.`);
        tile.classList.remove("shake");
        void tile.offsetWidth;
        tile.classList.add("shake");
        return;
      }
      refresh();
    }

    tiles.forEach((t) => {
      t.querySelector(".art").addEventListener("click", () => toggle(t));
      t.querySelector(".pick").addEventListener("click", () => toggle(t));
    });

    const back = () => go("#/osoby");
    document.getElementById("chip").addEventListener("click", back);
    document.getElementById("cancel").addEventListener("click", back);
    confirmBtn.addEventListener("click", () => {
      const current = loadState() || state;
      current.votes[user.id] = MOVIES.map((m) => m.id).filter((id) => selected.has(id));
      saveState(current);
      toast(`Dzięki, ${user.name}! Głos zapisany 🍿`);
      go("#/osoby");
    });

    const clearMine = app.querySelector("#clear-mine");
    if (clearMine) clearMine.addEventListener("click", async () => {
      if (!(await confirmDialog(`${user.name}, usunąć Twój głos? Będzie można zagłosować ponownie.`, "Usuń", "danger"))) return;
      const current = loadState() || state;
      delete current.votes[user.id];
      saveState(current);
      toast(`Głos usunięty – ${user.name} może zagłosować ponownie`);
      go("#/osoby");
    });

    refresh();
    window.scrollTo(0, 0);
  }

  // ---------- ekran: wyniki ----------

  function tally(state) {
    const rows = MOVIES.map((m) => ({
      movie: m,
      voters: USERS.filter((u) => (state.votes[u.id] || []).includes(m.id)),
    }));
    rows.forEach((r) => (r.points = r.voters.length));
    rows.sort((a, b) => b.points - a.points || MOVIES.indexOf(a.movie) - MOVIES.indexOf(b.movie));

    // Miejsca: filmy z tą samą liczbą głosów dzielą miejsce.
    const levels = [...new Set(rows.filter((r) => r.points > 0).map((r) => r.points))];
    rows.forEach((r) => (r.place = r.points > 0 ? levels.indexOf(r.points) + 1 : 0));
    const places = levels.slice(0, 3).map((pts, i) => ({ place: i + 1, points: pts, rows: rows.filter((r) => r.points === pts) }));
    return { rows, places };
  }

  function podiumHTML(places) {
    const medal = { 1: "🥇", 2: "🥈", 3: "🥉" };
    const col = (n) => {
      const p = places.find((x) => x.place === n);
      if (!p) return `<div class="podium-col"></div>`;
      const films = p.rows.length <= 2
        ? `<div class="podium-films">${p.rows.map((r) => `
            <figure class="podium-film">${posterHTML(r.movie, "small")}<figcaption>${esc(r.movie.title)}</figcaption></figure>`).join("")}</div>`
        : `<figure class="podium-film tie">
             <div class="fan">${p.rows.slice(0, 3).map((r) => posterHTML(r.movie, "thumb")).join("")}</div>
             <figcaption>${filmsWord(p.rows.length)} ex aequo</figcaption>
           </figure>`;
      return `
        <div class="podium-col place-${n}">
          ${films}
          <div class="pstep">
            <span class="medal">${medal[n]}</span>
            <span class="place-num">${n}</span>
            <span class="pts">${votesWord(p.points)}</span>
          </div>
        </div>`;
    };
    return `<div class="podium" id="podium">${col(2)}${col(1)}${col(3)}</div>`;
  }

  function renderResults(state) {
    const { rows, places } = tally(state);
    const done = doneCount(state);
    chrome({ chip: progressChip(state), tab: "wyniki" });

    let top;
    if (!places.length) {
      top = `<div class="card empty"><span class="big">🍿</span>Nikt jeszcze nie zagłosował.<br>Sala czeka na widzów!</div>`;
    } else if (revealed) {
      const first = places[0].rows.map((r) => r.movie.title);
      top = `
        <div class="card winner">
          <p class="winner-head">🎉 ${first.length === 1 ? "Dzisiaj oglądamy…" : "Remis na szczycie!"}</p>
          ${podiumHTML(places)}
          <p class="winner-title">${first.map(esc).join(" · ")}</p>
        </div>`;
    } else {
      top = `<button class="btn block big" id="reveal">🏆 Odsłoń podium</button>`;
    }

    const standings = rows.map((r) => `
      <li class="srow ${r.place === 1 ? "lead" : ""} ${r.points === 0 ? "zero" : ""}">
        <span class="rank">${r.place ? r.place + "." : "–"}</span>
        ${posterHTML(r.movie, "thumb")}
        <span class="sname">${esc(r.movie.title)}</span>
        <span class="sdots">${r.voters.map((u) => badge(u, "dot")).join("")}</span>
        <span class="spts">${r.points} 🍿</span>
      </li>`).join("");

    app.innerHTML = `
      <section class="screen">
        <h1>🍿 Wieczór filmowy</h1>
        <p class="muted lead">Zagłosowało <b>${done} z ${USERS.length}</b> osób${done < USERS.length ? " – wyniki mogą się jeszcze zmienić" : ""}.</p>
        ${top}
        <h2>Aktualne wyniki</h2>
        <ol class="card standings">${standings}</ol>
        <h2>Wszystkie filmy</h2>
        <div class="grid">
          ${rows.map((r) => `
            <div class="tile">
              <div class="art ${r.place === 1 ? "leading" : ""}">
                ${posterHTML(r.movie)}
                ${r.points ? `<span class="meta"><span class="count">${r.points} 🍿</span><span class="dots">${r.voters.map((u) => badge(u, "dot")).join("")}</span></span>` : ""}
              </div>
              <div class="name">${esc(r.movie.title)}</div>
            </div>`).join("")}
        </div>
      </section>`;

    const reveal = app.querySelector("#reveal");
    if (reveal) reveal.addEventListener("click", () => {
      revealed = true;
      renderResults(state);
      setTimeout(() => {
        const first = app.querySelector(".place-1 .podium-film");
        const r = first ? first.getBoundingClientRect() : null;
        popcornBurst(r ? r.left + r.width / 2 : innerWidth / 2, r ? r.top + r.height / 2 : innerHeight / 3);
      }, 1500);
    });
  }

  // Wybuch popcornu: ziarenka i 🍿 rozlatują się z jednego punktu.
  function popcornBurst(x, y) {
    if (window.matchMedia("(prefers-reduced-motion: reduce)").matches) return;
    const box = document.createElement("div");
    box.className = "nova";
    for (let i = 0; i < 36; i++) {
      const el = document.createElement("span");
      const angle = Math.random() * Math.PI * 2;
      const dist = 110 + Math.random() * 230;
      if (i % 5 === 0) {
        el.className = "emo";
        el.textContent = "🍿";
        el.style.fontSize = 20 + Math.random() * 16 + "px";
      } else {
        el.className = "pop";
        const s = 12 + Math.random() * 12;
        el.style.width = el.style.height = s + "px";
      }
      el.style.left = x + "px";
      el.style.top = y + "px";
      el.style.setProperty("--tx", Math.cos(angle) * dist + "px");
      el.style.setProperty("--ty", Math.sin(angle) * dist - 60 + "px");
      el.style.setProperty("--rot", Math.random() * 720 - 360 + "deg");
      el.style.animationDelay = Math.random() * 0.12 + "s";
      box.appendChild(el);
    }
    document.body.appendChild(box);
    setTimeout(() => box.remove(), 2000);
  }

  // ---------- ekran: więcej ----------

  function renderMore(state) {
    chrome({ chip: progressChip(state), tab: "wiecej" });
    app.innerHTML = `
      <section class="screen">
        <h1>Więcej</h1>
        <div class="card row-card">
          <span class="rc-title">🎟️ Limit głosów</span>
          <span class="muted">Każdy wybiera do ${filmsGen(state.maxVotes)}</span>
        </div>
        <button class="card row-card link" id="clear">
          <span class="rc-title">🧹 Wyczyść głosy</span>
          <span class="muted">Usuwa wszystkie głosy – głosujemy od nowa z tym samym limitem</span>
        </button>
        <button class="card row-card link" id="new">
          <span class="rc-title">🔄 Nowe głosowanie</span>
          <span class="muted">Zaczyna od początku – można ustawić nowy limit filmów</span>
        </button>
        <div class="card row-card">
          <span class="rc-title">🗑️ Głos jednej osoby</span>
          <span class="muted">Wybierz osobę w zakładce „Głosowanie” i kliknij „Usuń mój głos” pod listą filmów</span>
        </div>
        <div class="card row-card">
          <span class="rc-title">💾 Gdzie są głosy?</span>
          <span class="muted">Zapisane w tej przeglądarce, na tym urządzeniu</span>
        </div>
      </section>`;

    app.querySelector("#clear").addEventListener("click", async () => {
      if (!(await confirmDialog("Wyczyścić wszystkie głosy? Limit filmów zostanie bez zmian.", "Wyczyść", "danger"))) return;
      const current = loadState() || state;
      saveState({ ...current, startedAt: new Date().toISOString(), votes: {} });
      revealed = false;
      toast("Głosy wyczyszczone – można głosować od nowa 🍿");
      go("#/osoby");
    });
    app.querySelector("#new").addEventListener("click", async () => {
      if (!(await confirmDialog("Zacząć nowe głosowanie? Wszystkie głosy zostaną usunięte.", "Zacznij od nowa", "danger"))) return;
      clearState();
      revealed = false;
      go("#/start");
    });
  }

  // ---------- plakaty z Wikipedii ----------

  // Przeglądarka pyta angielską Wikipedię o grafikę z ramki artykułu (tam jest oryginalny plakat).
  // Adresy trzymamy w localStorage, żeby nie pytać przy każdym otwarciu. Bez sieci zostają plakaty zastępcze.
  const POSTERS_KEY = "kino-rodzinne.posters.v1";
  const WIKI_API = "https://en.wikipedia.org/w/api.php";

  function showPoster(movie) {
    document.querySelectorAll(`.poster[data-movie="${movie.id}"]`).forEach((el) => {
      if (el.querySelector("img")) return;
      const img = document.createElement("img");
      img.alt = "";
      img.referrerPolicy = "no-referrer";
      img.onerror = () => window.kinoPosterFailed(img, movie.id);
      img.src = movie.poster;
      el.appendChild(img);
    });
  }

  // Plakat się nie wczytał: zostaje plakat zastępczy, a w tle próbujemy Wikipedii (raz na film).
  window.kinoPosterFailed = (img, id) => {
    img.remove();
    const m = movieById(id);
    if (!m || img.getAttribute("src") !== m.poster) return;
    m.poster = "";
    if (m.wiki && !m.wikiTried) loadPosters([m]);
  };

  async function loadPosters(movies = MOVIES) {
    let cache = {};
    try { cache = JSON.parse(localStorage.getItem(POSTERS_KEY)) || {}; } catch (e) { /* bez pamięci */ }
    const missing = [];
    movies.forEach((m) => {
      if (m.poster) return;
      if (cache[m.id] && !m.wikiTried) { m.wikiTried = true; m.poster = cache[m.id]; showPoster(m); }
      else if (m.wiki && m.wiki.length && !m.wikiTried) { m.wikiTried = true; missing.push(m); }
    });
    if (!missing.length || window.KINO_NO_REMOTE_POSTERS || !window.fetch) return;

    const titles = [...new Set(missing.flatMap((m) => m.wiki))];
    const params = new URLSearchParams({
      action: "query", format: "json", formatversion: "2", origin: "*", redirects: "1",
      prop: "pageimages", piprop: "thumbnail", pithumbsize: "500", pilicense: "any",
      titles: titles.join("|"),
    });
    let data;
    try {
      const res = await fetch(`${WIKI_API}?${params}`);
      if (!res.ok) return;
      data = await res.json();
    } catch (e) { return; }

    const q = (data && data.query) || {};
    const follow = (list, t) => ((list || []).find((x) => x.from === t) || {}).to || t;
    const thumbOf = (title) => {
      const t = follow(q.redirects, follow(q.normalized, title));
      const page = (q.pages || []).find((p) => p.title === t);
      return page && page.thumbnail && page.thumbnail.source;
    };
    missing.forEach((m) => {
      const src = m.wiki.map(thumbOf).find(Boolean);
      if (!src) return;
      m.poster = src;
      cache[m.id] = src;
      showPoster(m);
    });
    try { localStorage.setItem(POSTERS_KEY, JSON.stringify(cache)); } catch (e) { /* bez pamięci */ }
  }

  // ---------- routing ----------

  function render() {
    const state = loadState();
    const [, route, arg] = current.split("/");

    if (!state || route === "start") return renderStart();
    if (route === "glosuj" && userById(arg)) return renderVote(state, userById(arg));
    if (route === "wyniki") return renderResults(state);
    if (route === "wiecej") return renderMore(state);
    return renderUsers(state);
  }

  const syncFromUrl = () => { current = location.hash; render(); };
  window.addEventListener("popstate", syncFromUrl);
  window.addEventListener("hashchange", syncFromUrl);
  render();
  loadPosters();
})();
