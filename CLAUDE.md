# CLAUDE.md

This file provides context and conventions for AI assistants (Claude Code and similar tools) working in this repository.

## Repository Overview

**claude-sandbox** is a minimal static web project owned by `mbialkowski`. It currently consists of a single HTML page serving as a "Hello World" starting point, built with Claude.

- **License**: MIT (Copyright 2026 mbialkowski)
- **Primary branch**: `main` (remote), `master` (local default)
- **Language/stack**: Plain HTML — no build tools, no dependencies, no framework

## Repository Structure

```
claude-sandbox/
├── index.html      # Single-page static HTML app ("My First App")
├── README.md       # Minimal project description
├── LICENSE         # MIT License
└── CLAUDE.md       # This file
```

## Development Workflow

### Branching

- Feature branches follow the pattern: `claude/<description>-<session-id>`
- Never push directly to `main`/`master` without explicit permission
- Always push with: `git push -u origin <branch-name>`

### Commits

- Write clear, descriptive commit messages in imperative form (e.g. "Add navigation bar to index.html")
- Keep commits focused on a single logical change

### Making Changes

Since there is no build system, changes are made directly to source files. There are no compilation, linting, or test steps currently configured.

## Key Conventions

- This is a static site — keep it simple and avoid introducing unnecessary complexity
- Prefer editing existing files over creating new ones unless clearly needed
- HTML should remain well-formed and standards-compliant
- No external dependencies or package managers are in use

## Current State (as of 2026-03-18)

- `index.html`: Basic HTML5 page with a title ("My First App") and a "Hello World" heading
- No CSS, JavaScript, or external assets yet
- Two commits in history: initial commit + HTML scaffold
