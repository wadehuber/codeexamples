# Scheme vs. Java vs. C++

The same small programs written three ways: in Scheme (functional), in Java, and in C++ (both mainly imperative and object-oriented). Each example matches one idea from the functional programming notes: pure functions, expressions instead of statements, recursion, immutability, higher-order functions, and closures.

The goal is not to show that one language is "better." Many functional ideas carry over to Java and C++, and some imperative habits show up in Scheme. Seeing the same problem solved three ways makes it easier to tell **what the program computes** apart from **how a language makes you say it**.

## Running the examples

| Language | How to run |
|---|---|
| Scheme | Open the `.scm` file in DrRacket and click **Run**. Each top-level expression prints its value. |
| Java (17+) | `javac SumList.java` then `java SumList` (or just `java SumList.java`) |
| C++ (C++17) | `g++ -std=c++17 sumlist.cpp -o sumlist` then `./sumlist` |

The three versions of each example are related programs with **matching core computations**, not line-for-line translations. The Java and C++ versions often add an imperative version for contrast, and each language gets a few demonstrations that only make sense there (for example, the dangling-reference closure in C++). The Scheme examples use Racket's `#lang scheme`, which is the course language.

## The examples

| Topic | Scheme | Java | C++ |
|---|---|---|---|
| Expressions vs. statements | [expressions.scm](expressions.scm) | [Expressions.java](Expressions.java) | [expressions.cpp](expressions.cpp) |
| Summing a list (loops vs. recursion) | [sumlist.scm](sumlist.scm) | [SumList.java](SumList.java) | [sumlist.cpp](sumlist.cpp) |
| Pure functions & side effects | [purefunctions.scm](purefunctions.scm) | [PureFunctions.java](PureFunctions.java) | [purefunctions.cpp](purefunctions.cpp) |
| Immutability | [immutability.scm](immutability.scm) | [Immutability.java](Immutability.java) | [immutability.cpp](immutability.cpp) |
| Recursive list procedures | [listprocedures.scm](listprocedures.scm) | [ListProcedures.java](ListProcedures.java) | [listprocedures.cpp](listprocedures.cpp) |
| Higher-order functions | [higherorder.scm](higherorder.scm) | [HigherOrder.java](HigherOrder.java) | [higherorder.cpp](higherorder.cpp) |
| Closures & currying | [closures.scm](closures.scm) | [Closures.java](Closures.java) | [closures.cpp](closures.cpp) |
| Towers of Hanoi | [hanoi.scm](hanoi.scm) | [Hanoi.java](Hanoi.java) | [hanoi.cpp](hanoi.cpp) |

---

## 1. Expressions vs. statements

[expressions.scm](expressions.scm) · [Expressions.java](Expressions.java) · [expressions.cpp](expressions.cpp)

In Scheme, **almost everything is an expression** that evaluates to a value, including `if` and `cond`. (The exception is `define`, which names a value instead of producing one.) In Java and C++, `if` is a **statement**: it chooses which code to run but doesn't produce a value, so each branch has to assign to a variable.

```scheme
(* 10 (if (> x 0) x (- x)))
```

```java
int abs;
if (x > 0) { abs = x; } else { abs = -x; }
System.out.println(10 * abs);
```

Both Java and C++ have an expression form of `if`, the ternary operator `?:`. A chain of `?:` is the closest match to `cond` (see `gradeExpression` in the C++ file). Java 14+ also has `switch` expressions. They evaluate to a value too, but they work like Scheme's `case` rather than `cond`: a `switch` matches one value against constants, while `cond` tests any conditions you like.

**Things to notice**

- Prefix notation `(- 14 (* 2 6))` needs no precedence rules. Infix `14 - 2 * 6` depends on them.
- `half(square(add1(5)))` is composition, and its *structure* is the same in all three languages. Functional style is about how you think, not only which language you use.
- The structure matches, but the arithmetic doesn't always. `/` on two integers is **integer division** in Java and C++, so `half(3)` is `1`. In Scheme, `(half 3)` is the exact rational `3/2`. The example input `(6 * 6) / 2` happens to divide evenly, which hides this difference. The files include `half(3)` so students can see it.
- Because `switch` matches values instead of testing conditions, the Java `switch` version first has to turn the score into a small integer by dividing by 10. It also caps the score with `Math.min(score, 100)` before dividing. Without that cap, a score of 110 falls to `default` and returns `F`, while the `if` version and the Scheme and C++ versions return `A`. Rewriting a chain of conditions in a new form is an easy place for two "equivalent" versions to drift apart.

## 2. Summing a list

[sumlist.scm](sumlist.scm) · [SumList.java](SumList.java) · [sumlist.cpp](sumlist.cpp)

The classic imperative sum changes two variables, `total` and `i`, on every pass through the loop. To understand it, you trace how they change over time.

```java
int total = 0;
for (int i = 0; i < values.length; i++) {
    total = total + values[i];
}
```

The Scheme version reads like a mathematical definition: *the sum of an empty list is 0; otherwise it is the first item plus the sum of the rest.*

```scheme
(define sum
  (lambda (lst)
    (if (null? lst)
        0
        (+ (car lst) (sum (cdr lst))))))
```

The Java and C++ files include recursive versions too. Arrays and vectors have no `car`/`cdr`, so an **index** stands for "the rest of the list."

**Things to notice**

- **Tail recursion:** in `sum-acc`, the recursive call is the last thing the function does. The Scheme standard guarantees **proper tail recursion**: tail calls don't grow the stack, so `sum-acc` runs in constant stack space, as a loop would. Java makes no such guarantee and does not eliminate tail calls. The C++ standard makes no guarantee either. Optimizing compilers (`-O2`) often eliminate tail calls, but you can't rely on it. So in Java and C++, deep recursion can overflow the stack even when it's written in tail form.
- **Higher-order version:** `(foldl + 0 lst)`, `stream().reduce(0, Integer::sum)`, and `std::accumulate` all express the same idea: combine the elements with `+`, starting from 0. They agree because the order doesn't matter for `+`. For an operation like `-` the three folds give different answers, and `(apply + lst)` matches only because of how `+` works (see section 6 for both).

## 3. Pure functions & side effects

[purefunctions.scm](purefunctions.scm) · [PureFunctions.java](PureFunctions.java) · [purefunctions.cpp](purefunctions.cpp)

A **pure function** always returns the same output for the same input and has no side effects. `square` is pure in all three languages. The function `f` below is not, because it changes hidden state each time it's called:

```cpp
int f(int x) {
    static int count = 0;
    count++;
    return x + count;
}
```

Starting from a fresh count, `f(10) + f(10)` is **23** (11 + 12) but `2 * f(10)` is **22**, so `a + a = 2a` no longer holds. The answer also depends on what was called earlier. The example files evaluate `2 * f(10)` *after* the sum, when the count is already 2, so they print **26**. **Referential transparency**, the ability to replace an expression with its value, breaks down, and ordinary algebra no longer applies.

**Things to notice**

- Scheme *can* write impure code with `set!`. It's shown here only as a counterexample and should never appear in your assignments.
- The fix is the same in every language: make the hidden state an explicit parameter (`f-pure`, `fPure`).
- Java and C++ have a second source of side effects: **references**. `addBonus(scores)` changes the caller's array. In C++, `withBonus` takes a `const&` parameter and returns a new vector, and that implementation is pure. The compiler guarantee is narrower than purity, though: `const&` only stops the function from modifying the argument *through that parameter*. The compiler would still allow the same function to change a global variable or print output. Neither Java nor C++ can mark a function as pure.
- Side effects make even evaluation order matter. `f(10) - f(10)` is `-1` if the left operand is evaluated first and `1` if the right one is. (`f(10) + f(10)` is 23 either way, so it can't show this.) Java always evaluates left to right, and so does Racket. C++ and standard Scheme leave the order unspecified, so the C++ file stores the two calls in separate variables to force an order.
- Pure doesn't mean "no assignment anywhere inside." `withBonus` in C++, and `doubleList` and `hanoiMoves` in later sections, build their result by changing a *local* variable that nothing else can see. The caller can't tell, so they are still pure: same input, same output, nothing outside changed. Purity is judged from the outside.

## 4. Immutability

[immutability.scm](immutability.scm) · [Immutability.java](Immutability.java) · [immutability.cpp](immutability.cpp)

Scheme list procedures don't modify a list. They **build a new one** with `cons`. In Racket's `#lang scheme`, which these examples use, ordinary pairs are actually **immutable**: there is no `set-car!` or `set-cdr!`, and mutable pairs are a separate type (`mcons`). That's a feature of this dialect. Standard Scheme (R5RS/R7RS) lets you modify ordinary pairs with `set-car!` and `set-cdr!`, so immutability there is a matter of programming style rather than a language rule.

Java and C++ code usually changes data in place, and that causes trouble once two names refer to the same data:

```java
int[] arr = {1, 2, 3, 4, 5};
int[] alias = arr;          // same array, two names
// ...double every element of arr...
System.out.println(Arrays.toString(alias));   // alias changed too!
```

The two languages differ in how you get there. In Java, assigning an array or object *always* shares it. In C++, `vector<int> copy = arr;` makes an independent copy, and you get a second name for the same vector only by asking for a reference with `&`. The C++ file shows both. In practice, C++ sharing usually comes from passing a parameter by reference, as `addBonus` does in section 3.

**Things to notice**

- **Structural sharing:** `(cons 0 lst)` doesn't copy `lst`. The new list's `cdr` *is* `lst` (`eq?` returns `#t`). Sharing is only safe because nobody can change `lst`, which `#lang scheme` guarantees.
- Java's `List.of(...)` creates an immutable list. Trying to `set` an element throws `UnsupportedOperationException` **at run time**.
- C++ `const` catches the same mistake **at compile time**. Uncomment `lst[0] = 100;` and the program will not build.
- `insertSorted` in C++ takes its vector **by value**, so it gets its own copy to modify, and the caller's vector stays safe.

## 5. Recursive list procedures

[listprocedures.scm](listprocedures.scm) · [ListProcedures.java](ListProcedures.java) · [listprocedures.cpp](listprocedures.cpp)

`member?`, `rember` (from *The Little Schemer*), and `count-of` all follow the same recursive pattern:

1. Is the list empty? → base case
2. Otherwise, do something with `(car lst)` and recur on `(cdr lst)`

The Java and C++ files show each procedure twice: once with a loop, and once translated directly from the Scheme structure.

| Scheme | Java | C++ |
|---|---|---|
| `(null? lst)` | `lst.isEmpty()` | `i == lst.size()` |
| `(car lst)` | `lst.get(0)` | `lst[i]` |
| `(cdr lst)` | `lst.subList(1, lst.size())` | recur with `i + 1` |
| `(cons x lst)` | write a `cons` helper | `rest.insert(rest.begin(), x)` |

**Things to notice**

- Scheme lists are built for this pattern, and `car`/`cdr`/`cons` are cheap. Array-based lists are built for indexing, so recursive Java and C++ code feels awkward. The real cost is in recursive **`rember`**: each level "conses" onto the front of a new list, which means copying the elements behind it, so the work grows **quadratically**. The recursive `member` and `count` procedures don't have this problem. Java's `subList` is a view of the original list, not a copy, and the C++ versions just advance an index.
- A Scheme list can mix types: `(3 hello "World" 7.5 (1 2))`. A Java list needs `List<Object>`, and a C++ vector needs `std::variant` or `std::any`.
- Both libraries already provide these operations (`contains`, `std::find`, `std::count`). Scheme has them too (`member`, `remove`). Writing them yourself is how you learn the pattern.

See also: [Scheme 2](../scheme2/README.md) - `listprocedures1.scm` through `listprocedures4.scm`.

## 6. Higher-order functions

[higherorder.scm](higherorder.scm) · [HigherOrder.java](HigherOrder.java) · [higherorder.cpp](higherorder.cpp)

`map`, `filter`, and `fold` handle the most common loop patterns. You supply the function, and they handle the looping. Here is the sum of the squares of the positive numbers in each language:

```scheme
(foldl + 0 (map square (filter positive? lst)))
```

```java
lst.stream().filter(x -> x > 0).map(x -> x * x).reduce(0, Integer::sum);
```

```cpp
auto squares = mapList(square, filterList(positive, lst));
accumulate(squares.begin(), squares.end(), 0);
```

| Idea | Scheme | Java | C++ |
|---|---|---|---|
| map | `map` | `stream().map` | `std::transform` |
| filter | `filter` | `stream().filter` | `std::copy_if` |
| fold / reduce | `foldl`, `foldr` | `stream().reduce` | `std::accumulate` |
| call with a list of args | `apply` | *(no direct equivalent)* | `std::apply` (C++17, tuples only) |
| anonymous function | `(lambda (x) ...)` | `x -> ...` | `[](int x) { ... }` |
| function type | *(none needed)* | `Function<T,R>`, `Predicate<T>` | `std::function<R(T)>` |

**Things to notice**

- Scheme reads inside-out, while Java streams read top-to-bottom. The logic is the same: filter, then map, then fold.
- `apply` and `foldl` are **not** interchangeable. `apply` calls a function once, with every list element as an argument. `foldl` calls it once per element, building up an accumulator. They agree for `+`, but `(apply - '(1 2 3))` is `-4` while `(foldl - 0 '(1 2 3))` is `2`. C++17's `std::apply` does the same job for a `std::tuple`, whose size is fixed at compile time. Neither Java nor C++ can do it for a list built at run time.
- The folds are **not** interchangeable across languages either. Racket's `foldl` calls `(f element accumulator)`. C++'s `std::accumulate` and Java's `reduce` call `f(accumulator, element)`. So folding `-` over `1 2 3` from 0 gives `2` in Racket but `-6` in C++ (see `higherorder.cpp`). Java's `reduce` goes further and *requires* an associative function such as `+` or `max`, so `-` doesn't belong there at all.
- In Scheme, a function is just a value. Java needs a **functional interface** type, and you call it with `op.apply(x)` rather than `op(x)`.
- C++ `<algorithm>` functions work on iterators and write into an output container. The small `mapList`/`filterList` helpers make them return new vectors, as Scheme's functions do.

See also: [Scheme 3](../scheme3/README.md) - `higherorder.scm`, `higherorderuser.scm`, `reduce.scm`.

## 7. Closures & currying

[closures.scm](closures.scm) · [Closures.java](Closures.java) · [closures.cpp](closures.cpp)

A function can **return a new function**. The returned function remembers the values that were in scope when it was created. This combination is called a **closure**.

```scheme
(define make-adder
  (lambda (n)
    (lambda (x) (+ x n))))
```

```java
static Function<Integer, Integer> makeAdder(int n) {
    return x -> x + n;
}
```

```cpp
auto makeAdder(int n) {
    return [n](int x) { return x + n; };
}
```

The examples also include a two-function `compose` (named `compose2` in Scheme and C++).

**Currying vs. partial application.** Strict **currying** turns a function of several arguments into a chain of one-argument functions: `add` in Scheme, `a -> b -> a + b` in Java, and a lambda that returns a lambda in C++. `valid-number-curr` takes *both* range bounds at once and returns a one-argument predicate for `filter`. That's **partial application**: some arguments are fixed now and the rest are supplied later. The course notes call this currying, and the two ideas are closely related, but the precise terms are worth knowing.

**Things to notice**

- Java lambdas can only capture **effectively final** local variables. You can't *reassign* a captured variable, but that's all the rule prevents. A lambda can still change an object or array it captured, update fields, or do I/O. The `sneaky` example captures an array and returns `11` and then `12` for the same argument. The restriction stops reassignment. It doesn't make a lambda pure.
- C++ makes you choose how to capture: `[n]` by copy, `[&n]` by reference, or `[=]` everything by copy. If a lambda captures a local variable **by reference** and is called after that variable is gone, the result is undefined behavior (see `makeBadAdder`). The compiler doesn't warn, and the program may even print the right answer on one build and garbage on another. Scheme's garbage collector keeps captured values alive, so this bug can't happen in Scheme.
- Java's `add5.compose(square)` is built into `Function`, and Racket has a built-in `compose` as well. The Scheme and C++ files write their own `compose2` to show that it takes just a few lines.

See also: [Scheme 3](../scheme3/README.md) - `currying.scm`.

## 8. Towers of Hanoi

[hanoi.scm](hanoi.scm) · [Hanoi.java](Hanoi.java) · [hanoi.cpp](hanoi.cpp)

The recursion is identical in all three languages: move `n-1` disks out of the way, move the largest disk, then move the `n-1` disks back on top. The difference is **what the function does with the answer**.

The usual Java and C++ textbook version **prints** each move inside the recursion. It returns nothing, so the only thing you can do with it is watch the output.

The Scheme version **returns the moves as a list**. Since the answer is a value, you can count it, take its first element, or pass it to another function. The Java and C++ files include this pure version too.

**Things to notice**

- This is the design principle *keep most of the program pure and isolate side effects at the edges*. The pure `hanoiMoves` does the work, and `main` does the printing.
- `hanoi` (nested result) and `hanoi-moves` (flat result using `append`) show that the shape of the returned data is a design choice.
- The two Scheme versions accept different inputs. `hanoi` uses `n = 1` as its base case, so it requires `n >= 1`. Called with 0, it recurs on -1, -2, ... forever. `hanoi-moves` and the Java and C++ versions stop at `n <= 0`, so they also accept 0 and return no moves, and a negative number can't send them into endless recursion.

---

## Summary

| | Scheme | Java | C++ |
|---|---|---|---|
| Main paradigm | Functional | Object-oriented / imperative | Imperative / object-oriented |
| Repetition | Recursion (proper tail calls guaranteed) | Loops (no tail-call elimination) | Loops (no guarantee; optimizers often eliminate tail calls) |
| Conditionals | Expressions (`if`, `cond`) | Statements (plus `?:`, `switch` expressions) | Statements (plus `?:`) |
| Default data | Immutable pairs/lists in Racket's `#lang scheme` (standard Scheme pairs are mutable) | Mutable arrays/lists (`List.of` is immutable) | Mutable vectors (`const` on request) |
| Functions as values | Built in | Lambdas + functional interfaces (Java 8+) | Lambdas + `std::function` (C++11+) |
| Closures | Capture anything, kept alive by GC | Can't reassign captured locals (captured objects can still change) | You choose copy or reference (and the risk) |
| Purity enforced? | No (but `set!` stands out) | No | No (`const` restricts one access path) |

Functional programming is a way of thinking, not just a feature of one language. Java and C++ have both adopted many functional ideas, and recognizing them in Scheme, where nothing else gets in the way, makes them easier to spot and use elsewhere.
