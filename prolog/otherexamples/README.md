# Prolog Other Examples

Supplementary Prolog examples that are not tied to a specific course module.
These accompany the **Helper Methods** notes shared across the CS1 courses and
CSC240, showing the same ideas in Prolog. In Prolog a "helper" is simply another
predicate: a small, well-named rule that answers one focused yes/no question,
while the recursive rules handle walking through a list.

The examples are written for SICStus Prolog, where double-quoted text such as
`"alice"` is a list of character codes (the default `double_quotes` flag is
`codes`). The username predicates rely on this, so they work on character codes
using only standard built-ins (`length/2` and arithmetic comparisons) rather than
any string library.

## [helperrules.pl](https://github.com/wadehuber/codeexamples/blob/master/prolog/otherexamples/helperrules.pl)

Three worked examples plus sample data and a self-contained test battery. Load
it in SICStus Prolog and run the tests with:

```(prolog)
?- run_tests.
```

### Counting positive numbers

`positive/1` answers a single question — is a number strictly greater than zero?
`count_positive/2` then recurses through the list with two mutually exclusive
rules: one for when the head is positive (add 1 to the count of the rest) and one
for when it is not (`\+ positive(H)`, keep the same count). The empty list is the
base case with a count of 0.

### Filtering students who passed

`passed/1` bundles the multi-part passing rule — score at least 70, at least 8
assignments, and no academic hold (`\+ academic_hold(Student)`) — into one named
predicate. It expects each student to be described by `score/2`, `assignments/2`,
and (only when applicable) `academic_hold/1` facts; a small sample factbase for
`alice`, `bob`, `carol`, and `dave` is included. `passing_students/2` recurses
through a list of students, keeping only those for whom `passed/1` succeeds and
preserving the original order.

### Checking whether a string is a valid username

`valid_username/1` succeeds when a name is 3–16 characters, is made up entirely
of alphanumeric characters, and does not start with a digit. Because the name is
a list of character codes, it checks the length with `length/2`, verifies every
character with the recursive helper `alphanumeric_list/1`, and then confirms the
first code is not a digit. Two small character helpers do the low-level work:
`alphanumeric_code/1` succeeds for the code ranges of `A`–`Z`, `a`–`z`, and
`0`–`9`, and `is_digit_code/1` succeeds for the `0`–`9` range. `filter_valid_usernames/2`
recurses through a list of names, keeping only the valid ones.

### Test harness

`run_tests/0` runs a battery of goals covering each predicate (empty lists,
boundary username lengths, leading digits, underscores, academic holds, and
borderline students), printing `PASS`/`FAIL` for each via the `test/2` helper.
It uses only `write/1` and `nl` (no `format/2`) for portability, and succeeds
only if every test passes, ending with a final summary line.
