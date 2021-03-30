# Scheme & Functional Programming Information

## Scheme Compiler

For Scheme, we will be using [DrRacket](https://download.racket-lang.org/).  Make sure you include the language directive `#lang scheme` at the top of each Scheme source file you create.  Save your files with the extension `.scm`.

## Scheme (and other LISPs) Tutorials

- An excellent video explaining how recursively adding elements of a list works - [The Parable of the Clones](https://youtu.be/Al15GtRxmRE)

## History of Lisp & Scheme

- A great video on the [history of LISP](https://www.youtube.com/watch?v=hGY3uBHVVr4)
- John McCarthy on the [history of Lisp](http://jmc.stanford.edu/articles/lisp/lisp.pdf). And the original [LISP paper](http://www-formal.stanford.edu/jmc/recursive.pdf)
- Guy L. Steele Jr & Richard P. Gabriel on [The Evolution of Lisp](https://www.dreamsongs.com/Files/HOPL2-Uncut.pdf)
- [The History of Common Lisp](http://www.cs.cmu.edu/afs/cs/project/ai-repository/ai/lang/lisp/doc/history/cl.txt)
- A StackOverflow question about [why the LISP community is so fragmented](https://stackoverflow.com/questions/2114819/why-is-the-lisp-community-so-fragmented/2116517#2116517)
- [The Evolution of Lisp](https://www.dreamsongs.com/Files/HOPL2-Uncut.pdf) is from the mid-90's, but contains some good information on the history of Lisp.

## Where did the names CAR/CDR come from

- A nice has a summary of an old online discussion about [the history of where the names CAR/CDR come from](http://www.iwriteiam.nl/HaCAR_CDR.html).   Near the bottom are some comments from [Steve Russell](https://en.wikipedia.org/wiki/Steve_Russell_(computer_scientist)) who worked on the initial LISP implementations.

## Scheme (Racket) vs. Clojure vs. Lisp

- A detailed chart of the [differences between various flavors of Lisp](http://hyperpolyglot.org/lisp).

## Scheme Lists and Box & Arrow notation

- A good discussion about Scheme lists with examples of [box & arrow notation](http://icem-www.folkwang-hochschule.de/~finnendahl/cm_kurse/doc/schintro/schintro_93.html).

## Clojure

- [A Clojure Newbie Guide](http://www.clojurenewbieguide.com/)
- [The Newbie's Guide to Learning Clojure](https://elangocheran.com/2012/03/26/the-newbies-guide-learning-clojure/)
- [Clockwise](http://doc.ccw-ide.org/documentation.html) is an IDE for Clojure based on Eclipse
- VIDEO: [Clojure for Java Programmers](https://www.youtube.com/watch?v=P76Vbsk_3J0)
- A [good introduction to Clojure](http://clojure-doc.org/articles/tutorials/introduction.html) that parallels what we will cover in 240.
- If you are interested in learning even more about functional programming, a student a few semesters ago took this [free online course](http://mooc.fi/courses/2014/clojure/) and said it was very good.
- A [comparison of OO & Functional Programming](https://bobonmedicaldevicesoftware.com/blog/2019/01/27/exploring-clojure-and-fp-vs-oop/) by someone learning Clojure
- [Clojure for the Brave and True](http://www.braveclojure.com/) is an introductory Clojure book available online for free.
- [Clojure vs LISP, Scheme, & Java](https://clojure.org/reference/lisps)
- [Effective Programs - 10 Years of Clojure](https://github.com/matthiasn/talk-transcripts/blob/master/Hickey_Rich/EffectivePrograms.md) - a talk by the creator of Clojure
- [Lightmod](https://sekao.net/lightmod/) is "An all-in-one tool for full stack Clojure" if you want to try Clojure.
- Clojure - [the perfect language to expand your brain?](https://eli.thegreenplace.net/2017/clojure-the-perfect-language-to-expand-your-brain/)
- You can use `#lang rackjure` to get some [Clojure features in Racket](http://docs.racket-lang.org/rackjure/index.html).
- Structure and Interpretation of Computer Programs (SICP) is a classic Scheme text.  SICP Distilled covers some of the topics from that book using Clojure.
- A comparison of [Clojure functions to Java Streams](https://blog.frankel.ch/learning-clojure/5/)
- VIDEO: [An Introduction to Clojure](https://vimeo.com/68375202) by Stuart Halloway

## Lisp

- [Lisp Quickstart](https://cs.gmu.edu/~sean/lisp/LispTutorial.html) - a tutorial for students of an AI class
- [Alan Kay on LISP](https://www.quora.com/What-did-Alan-Kay-mean-by-Lisp-is-the-greatest-single-programming-language-ever-designed/answer/Alan-Kay-11?share=1). He also has an interesting [comparison of OOP & Functional Programming](https://www.quora.com/Why-is-functional-programming-seen-as-the-opposite-of-OOP-rather-than-an-addition-to-it/answer/Alan-Kay-11?share=a52bda70).
- [The Common Lisp Standard document](http://cvberry.com/tech_writings/notes/common_lisp_standard_draft.html)
- [The Common Lisp home page](http://lisp-lang.org/)
- The book [Practical Common Lisp](http://www.gigamonkeys.com/book/) is available free online.
- [Nine things that made Lisp different](http://www.gigamonkeys.com/book/)
- [Is LISP really functional?](https://letoverlambda.com/index.cl/guest/chap5.html)
- Peter Norvig's [Python for LISP Programmers](http://norvig.com/python-lisp.html)
- Peter Norvig's [Paradigms of Artificial Intelligence is available on GitHub](https://github.com/norvig/paip-lisp)
- An interesting (but very advanced) article on [Modern C++ & LISP programming style](https://chriskohlhepp.wordpress.com/advanced-c-lisp/convergence-of-modern-cplusplus-and-lisp/).

## Racket

- An introduction to Racket [using its picture-drawing libraries](https://docs.racket-lang.org/quick/)

## S-Expressions

- A detailed [overview of S-Expressions](http://people.csail.mit.edu/rivest/Sexp.txt)
- A proposal to use [S-Expressions for inter-business communication](http://www-formal.stanford.edu/jmc/cbcl.html).
- [It Came From S-Expressions](http://natecull.org/wordpress/2017/07/06/dataspace-3/) discusses using S-Expressions with Prolog.

## Functional Programming Talks

- [Functional Thinking talk from OSCON 2013](https://www.youtube.com/watch?v=7aYS9PcAITQ) doesn't cover anything about Scheme, but does a good job of explaining where functional programming fits in to modern programming.
- [The Power of Composition](https://www.youtube.com/watch?v=WhEkBCWpDas) is a great introduction to Functional Programming.  It uses F#, but most of it should be at a level where you can follow it.
- [Plain Functional Programming](https://www.youtube.com/watch?v=YXDm3WHZT5g) by Martin Odersky is another good talk about some more advanced topics (with  Scala) in functional programming.

## Other Scheme & LISP implementations

- [GNU Guile](https://www.gnu.org/software/guile/) is one of the more commonly used Scheme implementations.
- [Chez Scheme](https://github.com/cisco/ChezScheme) is an open-source Scheme compiler (available on GitHub).  You can read about its history here.
- [Racket](https://racket-lang.org/) is its own language
  - [Beautiful Racket](https://beautifulracket.com/) is an online book that talks about writing languages with Racket.  See [Why Language-oriented programming?  Why Racket?](https://beautifulracket.com/appendix/why-lop-why-racket.html)

## Prototyping with Functional Languages

[Haskell vs Ada vs. C++ vs AWK](http://haskell.cs.yale.edu/wp-content/uploads/2011/03/HaskellVsAda-NSWC.pdf) is an interesting write up about a US Navy experiment in the early 90's which compared different languages and their suitability for creating a prototype of a larger system (written from the perspective of the Haskell developers).  It covers some interesting benefits of functional programming.
More information:

- [A Case Study in Architectural Modelling: The AEGIS System](http://www.cs.cmu.edu/afs/cs/project/able/ftp/aegis-iwssd8/aegis-iwssd8.pdf)
- [An Experiment Using Haskell to Prototype "Geometric Region Servers" for Navy Command and Control](http://www.cs.yale.edu/publications/techreports/tr1031.pdf)

## Introductions to Functional Programming

- A list of [Functional Programming Jargon](https://github.com/hemanth/functional-programming-jargon/blob/master/readme.md)
- A practical [introduction to FP using Python](https://maryrosecook.com/blog/post/a-practical-introduction-to-functional-programming)
- An old [Introduction to Functional Programming Book](http://usi-pl.github.io/lc/sp-2015/doc/Bird_Wadler.%20Introduction%20to%20Functional%20Programming.1ed.pdf)
- [F# for Fun and Profit](https://fsharpforfunandprofit.com/) has a lot of resources for learning F#, a functional language that was developed by Microsoft.
- [The Functional Style](https://codurance.com/2018/08/09/the-functional-style-part-1/) - an introduction to Functional Programming
- [Professor Frisby's Mostly Adequate Guide to Functional Programming](https://github.com/MostlyAdequate/mostly-adequate-guide) is an introduction to Functional Programming using JavaScript.
- [JavaScript Allongé](https://leanpub.com/javascriptallongesix/read) is another guild to Functional Programming in JavaScript.

## Functional Features in Other Languages

- Examples of [Higher Order Functions in JavaScript](https://medium.com/better-programming/the-power-of-higher-order-functions-in-javascript-91fc8edc3a7a)
- [What is a Pure Function](https://medium.com/better-programming/what-is-a-pure-function-3b4af9352f6f) with examples in Python

## F# (F Sharp)

- [F# 5.0 Announcement](https://devblogs.microsoft.com/dotnet/announcing-f-5/)

## Lambda Calculus

- VIDEO: Steven Syrek - Lambda Calculus For People Who Can't Be Bothered to Learn It [Part 1](https://www.youtube.com/watch?v=c_ReqkiyCXo) and [Part 2](https://www.youtube.com/watch?v=9lM825quliY)
- [Algebra and the Lambda Calculus](https://people.csail.mit.edu/jaffer/lambda.txt) discusses some of the mathematical underpinnings of functional programming.
- VIDEO: [Lambda Calculus Tutorial from PYCON 2019](https://www.youtube.com/watch?v=5C6sv7-eTKg)
- VIDEO: [Lambda Calculus Then and Now](https://www.youtube.com/watch?v=SphBW9ILVPU)

## Interesting Links

- [Functional Pearls](http://www.cs.ox.ac.uk/people/jeremy.gibbons/pearls/)
- A great article on [What's Functional Programming All About?](http://www.lihaoyi.com/post/WhatsFunctionalProgrammingAllAbout.html)
- A paper on [Why Functional Programming Matters](https://www.cs.kent.ac.uk/people/staff/dat/miranda/whyfp90.pdf)
- A guide to [Functional Programming Jargon](https://github.com/hemanth/functional-programming-jargon/blob/master/readme.md)
- A blog post asks if Functional Programming [can be liberated fro the Von Neumann paradigm](http://conal.net/blog/posts/can-functional-programming-be-liberated-from-the-von-neumann-paradigm).
- [((All those parens!))](http://blog.avenuecode.com/all-those-parens) discusses S-expressions and there use.  The examples are in Clojure, but you should be able to understand most of the examples.
- Myth of the Day: [Functional Programmers Don't Use Loops](https://two-wrongs.com/myth-of-the-day-functional-programmers-dont-use-loops) lists several loops and shows their functional equivalent.  Note that the functional examples all use higher-order functions to encapsulate the looping behavior.
- [The LISP issue](https://ia902603.us.archive.org/30/items/byte-magazine-1979-08/1979_08_BYTE_04-08_LISP.pdf) of BYTE magazine from 1979.
- [LISP & the Foundations of Computing](https://lwn.net/Articles/778550/)
- There are lots of options for languages based on Lisp, including Scheme.  Here is a discussion of [Which Lisp dialect do you use and why](https://news.ycombinator.com/item?id=15031855).  Another view in favor of Common Lisp in [Why I haven't jumped ship from Common Lisp to Racket (just yet)](http://fare.livejournal.com/188429.html).
- [John Carmack on Functional Programming](https://www.gamasutra.com/view/news/169296/Indepth_Functional_programming_in_C.php)
- Carmack also talked about FP in his [keynote at QuakeCon 2013](https://www.youtube.com/watch?v=1PhArSujR_A)
- Some resources for [functional programming in Python](https://github.com/sfermigier/awesome-functional-python).
- [McCLIM](https://common-lisp.net/project/mcclim/) is a Common Lisp GUI toolkit.
- [Pragmatic Functional Programming](http://blog.cleancoder.com/uncle-bob/2017/07/11/PragmaticFunctionalProgramming.html) from The Clean Code Blog
- A discussion of [why unnecessary variables are bad for your code](https://techbeacon.com/why-unnecessary-variables-are-bad-your-code?imm_mid=0f5938&cmp=em-prog-na-na-newsltr_20170819).
- An interview from Microsoft about [Functional Programming](https://www.microsoft.com/en-us/research/blog/functional-programming-languages-pursuit-laziness-dr-simon-peyton-jones/) (audio w/ transcript).
- Some thoughts on the Near Future of Programming Languages from Stephen Diehl.

## LISP in the real world

- [Why Isn't Functional Programming the Norm](https://youtu.be/QyJZzq0v7Z4)
- [LambdaNative](http://www.lambdanative.org/) is a framework for developing mobile apps in Scheme.
- A LISP application in [the pharmaceutical industy](https://franz.com/success/customer_apps/bioinformatics/mdl_story.lhtml)
- LISP & [the development of the GNU Emacs](https://www.gnu.org/gnu/rms-lisp.en.html)
- LISP was used in several games.  Here are some post-mortem comments about [LISP's use in Jax & Dexter](http://wiki.c2.com/?LispInJakAndDaxter).
- The Halo mission scripting language [was based on LISP](https://opencarnage.net/index.php?/topic/4156-scripting-guide/)
- The Symbolics, Inc. [LISP machine](https://www.ifis.uni-luebeck.de/~moeller/symbolics-info/index.html).
- [A Road to Common LISP](http://stevelosh.com/blog/2018/08/a-road-to-common-lisp/) is a guide to learning more about Common LISP.
- A paper describing how LISP is useful for [work in bioinformatics & computational biology](https://arxiv.org/pdf/1608.02621.pdf).
- Sound processing using LISP: [Basic sound processing in Common Lisp](https://www.youtube.com/watch?v=sYcDtniJdoE) by Dmitry Petrov
- A very incomplete list of [companies using functional programming](https://github.com/elamje/FunctionalProgrammingCompanies)
- A list of [companies using Common LISP](https://common-lisp.net/lisp-companies)
- Another list of [companies using Common LISP](http://pchristensen.com/blog/lisp-companies/)
- And yet one more list of [companies using Common LISP](https://lisp-journey.gitlab.io/who/)
- A list of [companies using Clojure](https://clojure.org/community/companies)
