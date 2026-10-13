// Smoke test of the web export in headless Chromium (Playwright): serves remake/build/web, opens the game,
// starts a new game, walks, and saves screenshots - desktop 16:9 and a touch phone in landscape.
//     node remake/tests/web_smoke.mjs remake/build/web OUT_DIR
import http from "node:http";
import fs from "node:fs";
import path from "node:path";
import { createRequire } from "node:module";

const require = createRequire(import.meta.url);
let playwright;
try {
  playwright = require("playwright");
} catch {
  playwright = require(path.join(process.execPath, "../../lib/node_modules/playwright"));
}

const [root, out] = [process.argv[2] || "remake/build/web", process.argv[3] || "web-shots"];
fs.mkdirSync(out, { recursive: true });
const types = { ".html": "text/html", ".js": "text/javascript", ".wasm": "application/wasm",
  ".pck": "application/octet-stream", ".png": "image/png", ".json": "application/json" };
const server = http.createServer((req, res) => {
  const p = path.join(root, decodeURIComponent(req.url.split("?")[0]).replace(/\/$/, "/index.html"));
  fs.readFile(p, (err, data) => {
    if (err) { res.writeHead(404); res.end(); return; }
    res.writeHead(200, { "Content-Type": types[path.extname(p)] || "application/octet-stream" });
    res.end(data);
  });
}).listen(0);
const url = `http://127.0.0.1:${server.address().port}/index.html`;
const sleep = (ms) => new Promise((r) => setTimeout(r, ms));

const browser = await playwright.chromium.launch({
  args: ["--use-angle=swiftshader", "--enable-unsafe-swiftshader", "--ignore-gpu-blocklist", "--autoplay-policy=no-user-gesture-required"],
});
const errors = [];

async function run(name, ctxOpts, steps) {
  const ctx = await browser.newContext(ctxOpts);
  const page = await ctx.newPage();
  page.on("console", (m) => { if (m.type() === "error") errors.push(`${name}: ${m.text()}`); });
  page.on("pageerror", (e) => errors.push(`${name}: ${e.message}`));
  await page.goto(url);
  await page.waitForSelector("canvas");
  await sleep(9000);
  await steps(page);
  await ctx.close();
}

await run("desktop", { viewport: { width: 1280, height: 720 } }, async (page) => {
  await page.screenshot({ path: `${out}/desktop_press.png` });
  await page.mouse.click(5, 5);                   // "press a key": starts the intro (and the audio)
  await sleep(6000);
  await page.screenshot({ path: `${out}/desktop_intro.png` });
  await page.keyboard.press("Escape");            // skip the intro
  await sleep(1500);
  await page.screenshot({ path: `${out}/desktop_title.png` });
  await page.keyboard.press("Enter");
  await sleep(2500);
  await page.screenshot({ path: `${out}/desktop_game.png` });
  await page.keyboard.down("ArrowRight");
  await sleep(2600);
  await page.keyboard.up("ArrowRight");
  await sleep(800);
  await page.screenshot({ path: `${out}/desktop_walk.png` });
});

await run("phone", { viewport: { width: 915, height: 412 }, deviceScaleFactor: 2, isMobile: true, hasTouch: true },
  async (page) => {
    await page.touchscreen.tap(457, 200);          // press a key -> intro
    await sleep(1000);
    await page.touchscreen.tap(457, 200);          // skip the intro
    await sleep(1500);
    await page.screenshot({ path: `${out}/phone_title.png` });
    await page.touchscreen.tap(457, 132);          // NOWA GRA (first title row, y 77 of 240)
    await sleep(2500);
    await page.screenshot({ path: `${out}/phone_game.png` });
  });

await run("portrait", { viewport: { width: 412, height: 915 }, deviceScaleFactor: 2, isMobile: true, hasTouch: true },
  async (page) => {
    await page.touchscreen.tap(206, 300);          // press a key -> intro
    await sleep(1000);
    await page.touchscreen.tap(206, 300);          // skip the intro
    await sleep(1500);
    await page.touchscreen.tap(206, 137);          // NOWA GRA
    await sleep(2500);
    await page.screenshot({ path: `${out}/portrait_game.png` });
  });

await browser.close();
server.close();
console.log(errors.length ? "errors:\n" + errors.join("\n") : "no page errors");
