(() => {
  "use strict";

  const MOVIES = window.MOVIES;
  const USERS = window.USERS;
  const STORAGE_KEY = "kino-rodzinne.v1";
  const MAX_LIMIT = MOVIES.length;
  const app = document.getElementById("app");

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

  // 1 głos, 2–4 głosy, 5+ głosów (12–14 głosów)
  function plural(n, one, few, many) {
    if (n === 1) return one;
    const d = n % 10, h = n % 100;
    return d >= 2 && d <= 4 && (h < 12 || h > 14) ? few : many;
  }
  const votesWord = (n) => `${n} ${plural(n, "głos", "głosy", "głosów")}`;
  const filmsWord = (n) => `${n} ${plural(n, "film", "filmy", "filmów")}`;
  const voted = (u) => (u.female ? "zagłosowała" : "zagłosował");

  function posterHTML(movie, extraClass = "") {
    const [c1, c2] = movie.colors;
    const img = movie.poster
      ? `<img src="${esc(movie.poster)}" alt="" loading="lazy" referrerpolicy="no-referrer" onerror="this.remove()">`
      : "";
    return `
      <div class="poster ${extraClass}" style="--c1:${c1};--c2:${c2}">
        <div class="poster-fallback" aria-hidden="true">
          <span class="poster-emoji">${movie.emoji}</span>
          <span class="poster-title">${esc(movie.title)}</span>
          <span class="poster-year">${movie.year}</span>
        </div>
        ${img}
      </div>`;
  }

  function go(hash) {
    if (location.hash === hash) render();
    else location.hash = hash;
  }

  function toast(text) {
    const el = document.createElement("div");
    el.className = "toast";
    el.textContent = text;
    document.body.appendChild(el);
    setTimeout(() => el.remove(), 2600);
  }

  // Okno z wyborem; zwraca wartość klikniętego przycisku albo null (Anuluj / Esc).
  // choices: [{ value, label, gold? }]
  function choiceDialog(text, choices) {
    const tpl = document.getElementById("confirm-dialog");
    const dlg = tpl.content.firstElementChild.cloneNode(true);
    if (typeof dlg.showModal !== "function") {
      return Promise.resolve(window.confirm(text) ? choices[choices.length - 1].value : null);
    }
    dlg.querySelector(".dialog-text").textContent = text;
    dlg.querySelector(".row").innerHTML = [{ value: "", label: "Anuluj" }, ...choices]
      .map((c) => `<button value="${c.value}" class="btn ${c.gold ? "btn-gold" : "btn-ghost"}">${esc(c.label)}</button>`)
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

  const confirmDialog = (text, okLabel = "Tak") =>
    choiceDialog(text, [{ value: "ok", label: okLabel, gold: true }]).then((v) => v === "ok");

  async function resetVoting() {
    const state = loadState();
    const choice = await choiceDialog("Resetować głosowanie? Wszystkie oddane głosy zostaną usunięte.", [
      { value: "new", label: "Zmień limit filmów" },
      { value: "clear", label: "Wyczyść głosy", gold: true },
    ]);
    if (choice === "clear" && state) {
      saveState({ ...state, startedAt: new Date().toISOString(), votes: {} });
      toast("Głosy wyczyszczone – można głosować od nowa 🎟️");
      go("#/osoby");
    } else if (choice === "new") {
      clearState();
      go("#/start");
    }
  }

  // ---------- ekran: start ----------

  function renderStart() {
    let limit = Math.min(3, MAX_LIMIT);
    app.innerHTML = `
      <section class="screen start">
        <div class="ticket big">
          <div class="ticket-body">
            <p class="eyebrow">Seans specjalny</p>
            <h2>Nowe głosowanie</h2>
            <p>Każdy z nas wybiera swoje ulubione filmy z listy ${filmsWord(MOVIES.length)}. Ile filmów może wybrać jedna osoba?</p>
            <div class="stepper" role="group" aria-label="Limit głosów">
              <button class="btn-round" data-step="-1" aria-label="Mniej">−</button>
              <output id="limit" class="limit">${limit}</output>
              <button class="btn-round" data-step="1" aria-label="Więcej">+</button>
            </div>
            <p class="hint" id="limit-hint">maksymalnie ${filmsWord(limit)} na osobę</p>
            <button class="btn btn-gold btn-xl" id="start">🎬 Rozpocznij głosowanie</button>
          </div>
          <div class="ticket-stub" aria-hidden="true"><span>BILET WSTĘPU</span><span>№ 001</span></div>
        </div>
      </section>`;

    const out = app.querySelector("#limit");
    const hint = app.querySelector("#limit-hint");
    app.querySelectorAll("[data-step]").forEach((b) =>
      b.addEventListener("click", () => {
        limit = Math.max(1, Math.min(MAX_LIMIT, limit + Number(b.dataset.step)));
        out.textContent = limit;
        hint.textContent = `maksymalnie ${filmsWord(limit)} na osobę`;
      })
    );
    app.querySelector("#start").addEventListener("click", () => {
      saveState({ maxVotes: limit, startedAt: new Date().toISOString(), votes: {} });
      go("#/osoby");
    });
  }

  // ---------- ekran: wybór osoby ----------

  function renderUsers(state) {
    const doneCount = USERS.filter((u) => state.votes[u.id]).length;
    const cards = USERS.map((u) => {
      const picks = state.votes[u.id];
      const status = picks
        ? `<span class="stamp">Głos oddany</span><span class="status">✓ ${voted(u)} · ${filmsWord(picks.length)}</span>`
        : `<span class="status waiting">czeka na głos…</span>`;
      return `
        <button class="ticket user ${picks ? "is-done" : ""}" data-user="${u.id}">
          <div class="ticket-body">
            <span class="avatar">${u.emoji}</span>
            <span class="name">${esc(u.name)}</span>
            ${status}
          </div>
          <div class="ticket-stub" aria-hidden="true"><span>${picks ? "ZMIEŃ" : "GŁOSUJ"}</span></div>
        </button>`;
    }).join("");

    app.innerHTML = `
      <section class="screen users">
        <h2 class="screen-title">Kto teraz głosuje?</h2>
        <p class="subtitle">Każdy może wybrać do <strong>${filmsWord(state.maxVotes)}</strong>.
          Zagłosowało <strong>${doneCount} z ${USERS.length}</strong> osób.</p>
        <div class="progress" aria-hidden="true"><span style="width:${(doneCount / USERS.length) * 100}%"></span></div>
        <div class="user-grid">${cards}</div>
        <div class="actions">
          <button class="btn btn-gold btn-xl" id="results">🏆 Pokaż wyniki</button>
          <button class="btn btn-ghost" id="reset">↺ Resetuj głosowanie</button>
        </div>
      </section>`;

    app.querySelectorAll("[data-user]").forEach((b) =>
      b.addEventListener("click", () => go(`#/glosuj/${b.dataset.user}`))
    );
    app.querySelector("#results").addEventListener("click", () => go("#/wyniki"));
    app.querySelector("#reset").addEventListener("click", resetVoting);
  }

  // ---------- ekran: głosowanie ----------

  function renderVote(state, user) {
    const max = state.maxVotes;
    const selected = new Set((state.votes[user.id] || []).filter(movieById));

    app.innerHTML = `
      <section class="screen vote">
        <div class="top-row">
          <button class="btn btn-ghost btn-back" id="back">← Zmień osobę</button>
          ${state.votes[user.id] ? `<button class="btn btn-ghost btn-back" id="clear-mine">🗑 Usuń mój głos</button>` : ""}
        </div>
        <h2 class="screen-title"><span class="avatar-sm">${user.emoji}</span> Cześć, ${esc(user.name)}!</h2>
        <p class="subtitle">Wybierz maksymalnie <strong>${filmsWord(max)}</strong>, które chcesz obejrzeć. Dotknij plakatu, aby zaznaczyć.</p>
        <div class="movie-grid">
          ${MOVIES.map((m) => `
            <article class="movie" data-movie="${m.id}">
              <button class="movie-pick" aria-pressed="false" aria-label="${esc(m.title)}">
                ${posterHTML(m)}
                <span class="ribbon">✓ Mój wybór</span>
              </button>
              <div class="movie-info">
                <h3>${esc(m.title)} <span class="year">(${m.year})</span></h3>
                <p>${esc(m.blurb)}</p>
                ${m.trailer ? `<a class="trailer" href="${esc(m.trailer)}" target="_blank" rel="noopener">▶ Zwiastun</a>` : ""}
              </div>
            </article>`).join("")}
        </div>
      </section>
      <div class="vote-bar">
        <div class="seats" id="seats" aria-hidden="true"></div>
        <span class="count" id="count"></span>
        <button class="btn btn-gold" id="confirm">Zatwierdzam ✓</button>
      </div>`;

    const cards = [...app.querySelectorAll(".movie")];
    const seats = app.querySelector("#seats");
    const count = app.querySelector("#count");
    const confirmBtn = app.querySelector("#confirm");

    function refresh() {
      const full = selected.size >= max;
      cards.forEach((card) => {
        const on = selected.has(card.dataset.movie);
        card.classList.toggle("is-selected", on);
        card.classList.toggle("is-locked", full && !on);
        card.querySelector(".movie-pick").setAttribute("aria-pressed", String(on));
      });
      seats.innerHTML = Array.from({ length: Math.min(max, 10) }, (_, i) =>
        `<span class="seat ${i < selected.size ? "on" : ""}">🎟️</span>`).join("");
      count.textContent = `Wybrano ${selected.size} z ${max}`;
      confirmBtn.disabled = selected.size === 0;
    }

    cards.forEach((card) =>
      card.querySelector(".movie-pick").addEventListener("click", () => {
        const id = card.dataset.movie;
        if (selected.has(id)) selected.delete(id);
        else if (selected.size < max) selected.add(id);
        else {
          toast(`Można wybrać najwyżej ${filmsWord(max)} – najpierw odznacz któryś.`);
          card.classList.remove("shake");
          void card.offsetWidth;
          card.classList.add("shake");
          return;
        }
        refresh();
      })
    );

    app.querySelector("#back").addEventListener("click", () => go("#/osoby"));
    const clearMine = app.querySelector("#clear-mine");
    if (clearMine) clearMine.addEventListener("click", async () => {
      if (!(await confirmDialog(`${user.name}, usunąć Twój głos? Będzie można zagłosować ponownie.`, "Usuń"))) return;
      const current = loadState() || state;
      delete current.votes[user.id];
      saveState(current);
      toast(`Głos usunięty – ${user.name} może zagłosować ponownie`);
      go("#/osoby");
    });
    confirmBtn.addEventListener("click", () => {
      const current = loadState() || state;
      current.votes[user.id] = MOVIES.map((m) => m.id).filter((id) => selected.has(id));
      saveState(current);
      toast(`Dzięki, ${user.name}! Głos zapisany 🎟️`);
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
    const levels = [...new Set(rows.filter((r) => r.points > 0).map((r) => r.points))].slice(0, 3);
    const places = levels.map((pts, i) => ({ place: i + 1, points: pts, rows: rows.filter((r) => r.points === pts) }));
    return { rows, places };
  }

  function renderResults(state) {
    const { rows, places } = tally(state);
    const doneCount = USERS.filter((u) => state.votes[u.id]).length;
    const top = rows[0] ? rows[0].points : 0;

    let podium;
    if (!places.length) {
      podium = `<div class="empty"><span>🍿</span><p>Nikt jeszcze nie zagłosował.<br>Sala czeka na widzów!</p></div>`;
    } else {
      const medal = { 1: "🥇", 2: "🥈", 3: "🥉" };
      const step = (p) => {
        if (!p) return `<div class="podium-col empty-col"></div>`;
        return `
          <div class="podium-col place-${p.place}">
            ${p.rows.length <= 2 ? `
            <div class="podium-films">
              ${p.rows.map((r) => `
                <figure class="podium-film">
                  ${posterHTML(r.movie, "small")}
                  <figcaption>${esc(r.movie.title)}</figcaption>
                </figure>`).join("")}
            </div>` : `
            <figure class="podium-film podium-tie">
              <div class="fan">${p.rows.slice(0, 4).map((r) => posterHTML(r.movie, "tiny")).join("")}</div>
              <figcaption>${filmsWord(p.rows.length)} ex aequo</figcaption>
            </figure>`}
            <div class="podium-step">
              <span class="medal">${medal[p.place]}</span>
              <span class="place-num">${p.place}</span>
              <span class="points">${votesWord(p.points)}</span>
            </div>
          </div>`;
      };
      const byPlace = (n) => places.find((p) => p.place === n);
      podium = `<div class="podium">${step(byPlace(2))}${step(byPlace(1))}${step(byPlace(3))}</div>`;
    }

    const list = rows.map((r) => `
      <li class="result-row">
        ${posterHTML(r.movie, "tiny")}
        <div class="result-main">
          <div class="result-head">
            <span class="result-title">${esc(r.movie.title)}</span>
            <span class="result-pts">${votesWord(r.points)}</span>
          </div>
          <div class="bar"><span style="width:${top ? (r.points / top) * 100 : 0}%"></span></div>
          <div class="voters">${r.voters.map((u) => `<span title="${esc(u.name)}">${u.emoji} ${esc(u.name)}</span>`).join("") || "<em>brak głosów</em>"}</div>
        </div>
      </li>`).join("");

    app.innerHTML = `
      <section class="screen results">
        <button class="btn btn-ghost btn-back" id="back">← Wróć do głosowania</button>
        <h2 class="screen-title">🏆 A zwycięzcą zostaje…</h2>
        <p class="subtitle">Zagłosowało <strong>${doneCount} z ${USERS.length}</strong> osób${doneCount < USERS.length ? " – wyniki mogą się jeszcze zmienić" : ""}.</p>
        <div class="stage">
          <div class="spotlight" aria-hidden="true"></div>
          ${podium}
        </div>
        <h3 class="list-title">Pełne wyniki</h3>
        <ol class="result-list">${list}</ol>
        <div class="actions">
          <button class="btn btn-ghost" id="reset">↺ Resetuj głosowanie</button>
        </div>
      </section>`;

    app.querySelector("#back").addEventListener("click", () => go("#/osoby"));
    app.querySelector("#reset").addEventListener("click", resetVoting);
    window.scrollTo(0, 0);
    if (places.length) setTimeout(confetti, 1900);
  }

  function confetti() {
    if (window.matchMedia("(prefers-reduced-motion: reduce)").matches) return;
    const box = document.createElement("div");
    box.className = "confetti";
    const colors = ["#f5c542", "#ff4d6d", "#ffffff", "#ffd60a", "#e63946", "#ffb703"];
    for (let i = 0; i < 90; i++) {
      const p = document.createElement("i");
      p.style.left = Math.random() * 100 + "%";
      p.style.background = colors[i % colors.length];
      p.style.animationDelay = Math.random() * 0.8 + "s";
      p.style.animationDuration = 2.4 + Math.random() * 1.8 + "s";
      p.style.setProperty("--drift", (Math.random() * 200 - 100).toFixed(0) + "px");
      p.style.setProperty("--spin", (Math.random() * 1080 - 540).toFixed(0) + "deg");
      box.appendChild(p);
    }
    document.body.appendChild(box);
    setTimeout(() => box.remove(), 5000);
  }

  // ---------- routing ----------

  function render() {
    const state = loadState();
    const [, route, arg] = location.hash.split("/");

    if (!state || route === "start") return renderStart();
    if (route === "glosuj" && userById(arg)) return renderVote(state, userById(arg));
    if (route === "wyniki") return renderResults(state);
    return renderUsers(state);
  }

  window.addEventListener("hashchange", render);
  render();
})();
