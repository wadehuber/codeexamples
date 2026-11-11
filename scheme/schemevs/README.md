# Scheme vs. Java vs. C++

The same small programs written three ways: in Scheme (functional), in Java, and in C++ (both mainly imperative and object-oriented). Each example matches one idea from the functional programming notes: pure functions, expressions instead of statements, recursion, immutability, higher-order functions, and closures.

The goal is not to show that one language is "better." Many functional ideas carry over to Java and C++, and some imperative habits show up in Scheme. Seeing the same problem solved three ways makes it easier to tell **what the program computes** apart from **how a language makes you say it**.

## Running the examples

| Language | How to run |
|---|---|
| Scheme | Open the `.scm` file in DrRacket and click **Run**. Each top-level expression prints its value. |
| Java (17+) | `javac SumList.java` then `java SumList` (or just `java SumList.java`) |
| C++ (C++17) | `g++ -std=c++17 sumlist.cpp -o sumlist` then `./sumlist` |

Each Java and C++ program prints the same results as the Scheme version, in the same order, so you can run all three side by side.

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

In Scheme, **everything is an expression** that evaluates to a value, including `if` and `cond`. In Java and C++, `if` is a **statement**: it chooses which code to run but doesn't produce a value, so each branch has to assign to a variable.

```scheme
(* 10 (if (> x 0) x (- x)))
```

```java
int abs;
if (x > 0) { abs = x; } else { abs = -x; }
System.out.println(10 * abs);
```

Both Java and C++ have an expression form of `if`, the ternary operator `?:`. Java 14+ also has `switch` expressions, which work much like Scheme's `cond`.

**Things to notice**

- Prefix notation `(- 14 (* 2 6))` needs no precedence rules. Infix `14 - 2 * 6` depends on them.
- `half(square(add1(5)))` is composition, and it works the same in all three languages. Functional style is about how you think, not only which language you use.

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

- **Tail recursion:** in `sum-acc`, the recursive call is the last thing the function does. Scheme is *required* to optimize this into a loop. Java never does, and C++ compilers usually do only with optimization turned on. So in Java, deep recursion can overflow the stack even when it's written in tail form.
- **Higher-order version:** `(foldl + 0 lst)`, `stream().reduce(0, Integer::sum)`, and `std::accumulate` all express the same idea: combine the elements with `+`, starting from 0.

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

So `f(10) + f(10)` is **23** but `2 * f(10)` is **26**. **Referential transparency**, the ability to replace an expression with its value, breaks down, and ordinary algebra no longer applies.

**Things to notice**

- Scheme *can* write impure code with `set!`. It's shown here only as a counterexample and should never appear in your assignments.
- The fix is the same in every language: make the hidden state an explicit parameter (`f-pure`, `fPure`).
- Java and C++ have a second source of side effects: **references**. `addBonus(scores)` changes the caller's array. In C++, a `const&` parameter that returns a new vector (`withBonus`) keeps the function pure, and the compiler enforces it.
- The C++ version calls `f(10)` on separate lines, because C++ doesn't define which operand of `+` is evaluated first. Side effects make even evaluation order matter.

## 4. Immutability

[immutability.scm](immutability.scm) · [Immutability.java](Immutability.java) · [immutability.cpp](immutability.cpp)

Scheme list procedures don't modify a list. They **build a new one** with `cons`. Java and C++ code usually changes data in place, and that causes trouble once two names refer to the same data:

```java
int[] arr = {1, 2, 3, 4, 5};
int[] alias = arr;          // same array, two names
// ...double every element of arr...
System.out.println(Arrays.toString(alias));   // alias changed too!
```

**Things to notice**

- **Structural sharing:** `(cons 0 lst)` doesn't copy `lst`. The new list's `cdr` *is* `lst` (`eq?` returns `#t`). Sharing is only safe because nobody can change `lst`.
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

- Scheme lists are built for this pattern, and `car`/`cdr`/`cons` are cheap. Array-based lists are built for indexing, so recursive Java and C++ code feels awkward and makes extra copies.
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
| fold / reduce | `foldl`, `apply` | `stream().reduce` | `std::accumulate` |
| anonymous function | `(lambda (x) ...)` | `x -> ...` | `[](int x) { ... }` |
| function type | *(none needed)* | `Function<T,R>`, `Predicate<T>` | `std::function<R(T)>` |

**Things to notice**

- Scheme reads inside-out, while Java streams read top-to-bottom. The logic is the same: filter, then map, then fold.
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

The examples also include `valid-number-curr`, which curries a range check so it can be passed to `filter`, `quad`, which generates polynomial functions, and `compose`.

**Things to notice**

- Java lambdas can only capture **effectively final** local variables. You can read a captured variable but not change it, which keeps closures functional.
- C++ makes you choose how to capture: `[n]` by copy, `[&n]` by reference, or `[=]` everything by copy. Capturing a local variable **by reference** and returning the lambda is undefined behavior (see `makeBadAdder`). Scheme's garbage collector keeps captured values alive, so this bug can't happen in Scheme.
- Java's `add5.compose(square)` is built into `Function`. In Scheme and C++, `compose` takes just a few lines to write.

See also: [Scheme 3](../scheme3/README.md) - `currying.scm`.

## 8. Towers of Hanoi

[hanoi.scm](hanoi.scm) · [Hanoi.java](Hanoi.java) · [hanoi.cpp](hanoi.cpp)

The recursion is identical in all three languages: move `n-1` disks out of the way, move the largest disk, then move the `n-1` disks back on top. The difference is **what the function does with the answer**.

The usual Java and C++ textbook version **prints** each move inside the recursion. It returns nothing, so the only thing you can do with it is watch the output.

The Scheme version **returns the moves as a list**. Since the answer is a value, you can count it, take its first element, or pass it to another function. The Java and C++ files include this pure version too.

**Things to notice**

- This is the design principle *keep most of the program pure and isolate side effects at the edges*. The pure `hanoiMoves` does the work, and `main` does the printing.
- `hanoi` (nested result) and `hanoi-moves` (flat result using `append`) show that the shape of the returned data is a design choice.

---

## Summary

| | Scheme | Java | C++ |
|---|---|---|---|
| Main paradigm | Functional | Object-oriented / imperative | Imperative / object-oriented |
| Repetition | Recursion (tail calls optimized) | Loops (no tail-call optimization) | Loops (TCO only with optimizer) |
| Conditionals | Expressions (`if`, `cond`) | Statements (plus `?:`, `switch` expressions) | Statements (plus `?:`) |
| Default data | Immutable lists | Mutable arrays/lists (`List.of` is immutable) | Mutable vectors (`const` on request) |
| Functions as values | Built in | Lambdas + functional interfaces (Java 8+) | Lambdas + `std::function` (C++11+) |
| Closures | Capture anything, kept alive by GC | Capture effectively final locals only | You choose copy or reference (and the risk) |

Functional programming is a way of thinking, not just a feature of one language. Java and C++ have both adopted many functional ideas, and recognizing them in Scheme, where nothing else gets in the way, makes them easier to spot and use elsewhere.
