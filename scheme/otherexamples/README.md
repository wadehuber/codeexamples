# Scheme Other Examples

Supplementary Scheme examples that are not tied to a specific course module.
These accompany the **Helper Methods** notes shared across the CS1 courses and
CSC240, showing the same ideas in Scheme.

## [helpermethods.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/otherexamples/helpermethods.scm)

A single file demonstrating the *helper method* pattern: take a larger task,
isolate the smaller well-defined question inside it in its own small procedure,
and let the main procedure focus on walking through a list. It contains three
worked examples plus a lightweight test harness. Every procedure is written with
plain recursion (`null?` / `car` / `cdr` / `cons`) so it works in DrRacket's
teaching languages as well as full Racket.

### Counting positive numbers

`positive-number?` answers one question — *is this number greater than zero?* —
and `count-positive` recurses through the list, adding 1 whenever the helper is
true. Note the predicate is deliberately named `positive-number?` rather than
`positive?`: `positive?` is already built into Racket, and redefining it would
raise an error. This mirrors the "don't shadow a built-in name" point from the
notes.

### Filtering students who passed

A student is represented as a list of `(name score assignments academic-hold?)`,
for example `("Alice" 85 10 #f)`. Three small **getter** helpers —
`student-score`, `student-assignments`, and `student-academic-hold?` — pull each
field out of that list with `cadr` / `caddr` / `cadddr`, so the rest of the code
never has to remember which position holds which value. The `passed?` helper
combines the multi-part rule (score at least 70, at least 8 assignments, and no
academic hold) into a single named question, and `passing-students` recurses
through the list with `cons`, keeping only the students for whom `passed?`
returns true.

### Checking whether a string is a valid username

`valid-username?` is true when a name is 3–16 characters, is entirely
alphanumeric, and does not start with a digit. The length test is written first
so the later `(string-ref name 0)` lookup is always safe. This example is also a
small study in building the alphanumeric check two different ways:

- `char-alphanumeric?` decides a single character, and `list-alphanumeric?`
  recurses through a list of characters — the from-scratch, no-higher-order-
  functions approach. The active `string-alphanumeric?` uses this version via
  `string->list`.
- `string-alphanumeric1?` shows the same idea written with the higher-order
  procedure `andmap`, for contrast.

`filter-valid-usernames` then recurses through a list of names, keeping only the
valid ones.

### Test harness

The file defines its own `check-expect` helper, which prints `PASS` when the
actual value equals the expected value and a `FAIL: got ..., expected ...`
message otherwise. Each of the three examples is followed by a block of
`check-expect` cases (empty lists, boundary lengths, leading digits, punctuation,
spaces, academic holds, borderline-passing students, and so on), so running the
file exercises every helper and prints its results.
