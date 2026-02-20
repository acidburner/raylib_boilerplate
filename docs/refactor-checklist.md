# Refactor & Architecture Checklist

This checklist is organized by impact and dependency so you can execute it in order.

## Phase 1 — Stabilize Core Architecture (High Impact)

### 1) State lifecycle completeness
- [ ] Verify every state in `src/game/states.c` has all handlers wired: `enter`, `update`, `render`, `exit`
- [ ] Add startup validation for missing vtable handlers
- [ ] Add log output on state transitions (`from -> to`)

**Done when:** no missing handlers and state transitions are traceable in logs.

### 2) Input API unification
- [ ] Replace direct raylib checks in state/input handler code with `input_action_pressed()` / `input_action_down()`
- [ ] Restrict raw raylib input calls to `src/input/platform/*`
- [ ] Remove duplicated action helper checks once action map covers all use-cases

**Done when:** gameplay/UI code only consumes your logical `InputKey` actions.

### 3) Symbol ownership & linker safety
- [ ] Ensure headers declare globals with `extern` only
- [ ] Keep single storage definitions in `.c` files
- [ ] Audit menu constants/arrays for header-defined storage

**Done when:** clean link with no multiple-definition errors.

### 4) Naming consistency pass
- [ ] Standardize menu naming (`MainMenuOption` + `MAIN_MENU_*`)
- [ ] Remove mixed naming variants (`MenuOption`, `MENU_*`) unless intentionally shared
- [ ] Keep style consistent: `snake_case` funcs, `UPPER_SNAKE_CASE` constants/macros

**Done when:** no conflicting naming patterns for the same concept.

---

## Phase 2 — Folder Hierarchy & Module Boundaries

### 5) Clarify settings domains
- [ ] Separate persistent config from UI state logic
- [ ] Rename/move one of these to avoid overlap:
  - `src/game/settings/*` (persistent runtime/user settings)
  - `src/game/states/settings/*` (settings screen state)
- [ ] Update include paths after moves

**Done when:** folder names reflect ownership and purpose unambiguously.

### 6) Create cross-state systems boundary
- [ ] Move reusable dispatch/input routing into `src/game/systems/` (or similar)
- [ ] Keep state folders focused on state-specific behavior
- [ ] Reduce cross-state include coupling

**Done when:** shared logic is centralized and state modules are thinner.

### 7) Platform boundary cleanup
- [ ] Keep platform adapters in `src/input/platform/` and `src/render/*/platform` style locations
- [ ] Ensure non-platform code does not depend on backend-specific headers directly

**Done when:** backend swap points are obvious and isolated.

---

## Phase 3 — Robustness & Maintainability

### 8) Defensive checks and type safety
- [ ] Use `size_t` for counts/indices in loops over arrays/tables
- [ ] Add bounds checks/asserts for input/state enum indexing
- [ ] Tighten `const` correctness on immutable tables

**Done when:** fewer implicit conversions and safer indexing.

### 9) Build warnings and static checks
- [ ] Enable stronger warnings in CMake: `-Wall -Wextra -Wshadow -Wconversion`
- [ ] Add `clang-format` config
- [ ] Add `clang-tidy` baseline checks (incremental adoption)

**Done when:** project builds warning-clean under agreed flags.

### 10) Minimal test harness for critical paths
- [ ] Add tests for input binding load/dispatch behavior
- [ ] Add tests for state transition constraints
- [ ] Add at least one regression test for a previously fixed bug

**Done when:** core systems have repeatable confidence checks.

---

## Optional Quick Wins (Can do anytime)
- [ ] Add one-line module purpose comments at top of key headers (`states.h`, `input.h`, dispatch headers)
- [ ] Add a short architecture section to `README.md` with dependency direction
- [ ] Track TODOs by priority tags: `[P0]`, `[P1]`, `[P2]`

---

## Suggested execution order
1. Phase 1.1 → 1.4
2. Phase 2.5 → 2.7
3. Phase 3.8 → 3.10

## Tracking
- Start date: __________
- Target date: __________
- Current phase: __________
- Blockers: __________________________________
