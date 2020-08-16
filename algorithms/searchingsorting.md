# Searching & Sorting

## Shuffling using sorting

For the sorting project, **your shuffling method must use the technique below**.  The point of the project is not to shuffle a deck of cards - it is to use sorting to shuffle a deck of cards. Suppose you have 4 card array:

Suppose you have  4 card array:

```(text)
4H 3S KD 9C
```

Create a random array of 4:

```(text)
3 8 6 1
```

Sort the random array:

```(text)
1 3 6 8
```

Rearrange the card array the same way you did to sort the random array:

```(text)
9C 4H KD 3S
```

Notice how the 1st card in the original list of cards was 4H and the first element of the random array was 3.  In the sorted array the 3 is in the 2nd position so 4H is in the 2nd position in the shuffled array.  There are many ways to do this in Java.

### More information about shuffling

If you are interested in other techniques of shuffling, the following links may be interesting to you.  Keep in mind that for the sorting project you must use the algorithm described above, not the ones described the links below!

- [Shuffling](http://datagenetics.com/blog/november42014/)
- [How yould you write code to shuffle a deck of cards?](http://blog.codinghorror.com/shuffling/)
- [The Danger of Naivete](http://blog.codinghorror.com/the-danger-of-naivete/), with shuffling as the example
- [The math behind shuffling](https://fredhohman.com/card-shuffling/)
- VIDEO: [The Best (and Worst) Ways to Shuffle Cards](https://www.youtube.com/watch?v=AxJubaijQbI) from Numberphile

## Sorting Algorithm Animations

- [Sorting Algorithm Animations](https://www.toptal.com/developers/sorting-algorithms/) - notice the difference in Insertion sort's performance between sorted & reverse sorted data
- [Comparison of Sorting Algorithms](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html) - notice how the recursive merge sort sorts the array from left to right
- A nice [demonstration of quicksort](https://illustrated-algorithms.now.sh/quicksort) at a high level, though it glosses over the details of how you actually partition the elements.

## Sorting Videos

- [Quicksort Animation - Visualization of Quick sort](https://www.youtube.com/watch?v=aXXWXz5rF64)
- [Merge Sort vs Quick Sort](https://www.youtube.com/watch?v=es2T6KY45cA)
- For those of you who find algorithms easier when they are demonstrated by Hungarian folk dancers, here is a demonstration of [quick-sort with Hungarian (Küküllomenti legényes) folk dance](https://www.youtube.com/watch?v=ywWBy6J5gz8)

## Sorting algorithm comparison

[This Google Sheets document](https://docs.google.com/spreadsheets/d/1DGkiYP2vd0ftv_TmEQRqLLO-a8ghtbuzZd6yLjm6FUM/view) contains a comparison of the 5 sorting algorithms we covered using the code from the jsjf package from Java Foundations.  It includes runs of different sizes and different types of arrays and the differences in the number of comparisons performed and the elapsed time. (Note that elapsed time is not 100% accurate, so don't get too hung up on any one particular result.)

A few questions to think about:

- It should make sense why insertion sort performs so well on sorted data (and why that isn't particularly impressive!). But why is its performance also consistently better on random arrays?
- Why is merge sort so much slower than quick sort (elapsed time) despite usually doing fewer comparisons.
- 1,0002 = 1,000,000 and 1000 * log2 1,000 ~= 10,000. But the O(n2) algorithms do <500,000 comparisons and the O(n log n) algorithms do between 5,000 and 14,000 comparisons. Why the discrepancy?
- Why is quicksort the worst algorithm to sort the Random3 array where size=10?
- Looking at the data, can you say which algorithm is "best"?
- Trick question: What is the first "sorting algorithm" we implemented in this course?

## Interesting links

- A discussion of [how Java does sorting](https://stackoverflow.com/questions/4018332/is-java-7-using-tim-sort-for-the-method-arrays-sort/)
- A good [description of TimSort](https://hackernoon.com/timsort-the-fastest-sorting-algorithm-youve-never-heard-of-36b28417f399), mentioned in the Java article above. If you are interested in how algorithms are analyzed in the real (or at least the academic) world, [this paper](http://drops.dagstuhl.de/opus/volltexte/2018/9467/) goes into it in detail.  
- A claim that the Python & Java implementation of [TimSort is broken](http://www.envisage-project.eu/proving-android-java-and-python-sorting-algorithm-is-broken-and-how-to-fix-it/)
