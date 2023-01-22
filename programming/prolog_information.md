# Prolog & Logic Programming Information

## SWI-Prolog Install Link

If you have not already done so, please install [SWI-Prolog](http://www.swi-prolog.org/download/stable).
Once you install SWI Prolog it will associate files with a .pl extension.  If you double click on the file it will open SWI & consult the file.  At that point you should be able to do queries.

SWI-Prolog has an [online Prolog environment](http://swish.swi-prolog.org/).  It is still in the experimental phase, but all the CSC240 assignment solutions work.  For the project you should still test with the stand alone project since that is how assignments will be graded.

If you want something a bit more high-end, [Sicstus](https://sicstus.sics.se/) is a commercial-quality Prolog implementation with a ton of additional features.  You can get a free 30-day license which will get you through the end of class if you wait until we finish Scheme.

## Prolog Tutorials & References

- An [Introduction to Logic Programming](https://www.matchilling.com/introduction-to-logic-programming-with-prolog/)
- [12 Days to Prolog](https://dev.to/donaldkellett/less-than-12-days-of-prolog---a-guide--brief-review-of-the-prolog-programming-language-1dgl) with some nice advanced examples
- *The Art of Prolog* is an excellent book on Prolog and logic programming.  It is available [for free online](https://mitpress.mit.edu/books/art-prolog-second-edition) - look under the "Open Access" tab.
- [The Power of Prolog](https://www.metalevel.at/prolog) is a more thorough, advanced tutorial.

## Representation of Lists of 2 elements in Scheme vs Prolog

- Scheme: `(X1, Y1)` is equivalent to `(X1 . (Y1 . ())`
- Prolog: `[X1, Y1]` is equivalent to `[X1 | [Y1 | []]]`

## Calling C from Prolog

We will not be doing this in class, but for those of you interested here is an example of [calling Prolog code from C](https://sicstus.sics.se/sicstus/docs/4.0.7/html/sicstus/Train-Example.html#Train-Example).  The functions starting with SP_ are part of the Sicstus Prolog library.  SWI has a similar feature, but I have never used it.

## Prolog Links

- [Prolog as a Database Query Langauge](https://www3.cs.stonybrook.edu/~warren/xsbbook/node11.html) shows you you can use Porlog as a database query langauge.  

## Prolog Links

- A [comparison of SQL and Prolog](https://stackoverflow.com/questions/2117651/comparing-sql-and-prolog)
- SWI-Prolog offers an [online Prolog course](https://edu.swi-prolog.org/), including constraint programming
- The author of [Logic Programming Is Overrated](http://programming-puzzler.blogspot.com/2013/03/logic-programming-is-overrated.html) talks about how a certain problem was easier to solve in Clojure without using logic programming extensions.  While not directly related to what we cover in this class, there are some interesting examples of Clojure & logic programming in the article.

## Other Logic Languages

I have not looked in depth at most of these, but here are a few newer logic languages that I've heard about.

- [Mercury](https://mercurylang.org/), a functional-logic language
- [Datomic](http://docs.datomic.com/query.html), a query language based on Datalog (if you are interested, there is a [tutorial](http://www.learndatalogtoday.org/))

## Prolog in the Real World

- VIDEO: [Production Prolog](https://www.youtube.com/watch?v=G_eYTctGZw8) by Michael Hendricks
- An interesting experiment in using Prolog for [bots in Counter-Strike](http://ceur-ws.org/Vol-928/0170.pdf).  Two interesting conclusions: C++ bot code can be rewritten to Prolog, & Prolog bots can be used e?ciently.
- [cozo](https://github.com/cozodb/cozo) is a relational database that ueses Datalog as its query language
- [GRAKN.AI](http://grakn.ai/) is a distributed graph database that is [compatible with logic programs](https://blog.grakn.ai/isa-graql-logic-program-8af1258054a4).
- Windows NT had an [embedded Prolog interpreter](http://www.redditmirror.cc/cache/websites/web.archive.org_84624/web.archive.org/web/20040603192757/research.microsoft.com/research/dtg/davidhov/pap.htm) to help with network configuration
- [Web Prolog and the Programmable Prolog Web](https://github.com/Web-Prolog/swi-web-prolog/blob/master/web-client/apps/swish/web-prolog.pdf) (book).
- [SICStus Prolog](https://www.sics.se/projects/sicstus-prolog-leading-prolog-technology) is used in the airline & rail industries.
- Prolog was used in [the Java specification](https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-0-preface7.html).
- [IBM Watson](https://www.cs.nmsu.edu/ALP/2011/03/natural-language-processing-with-prolog-in-the-ibm-watson-system/) uses Prolog.
- In 2016, the AppLP workshop was held where different applications of logic programming were discussed.  The talks are summarized in [this document](https://arxiv.org/pdf/1704.02375.pdf).

## Where logic programming failed

### 5th Generation Project

- New York Times article about [Japan's Fifth Generation project](https://www.nytimes.com/1992/06/05/business/fifth-generation-became-japan-s-lost-generation.html)

### Semantic Web

Logic programming was used with the [Semantic Web](http://www.w3.org/2001/sw)

- [SWI-Prolog’s Semantic Web extensions](https://www.swi-prolog.org/web/index.html)
- A [survey of the first 20 years of the Semantic Web](https://hal.inria.fr/hal-01935898/document)

Why the semantic web failed:

- [The Semantic Web and why it failed](http://data-mining.philippe-fournier-viger.com/lessons-from-the-past-the-semantic-web-ontologies-and-why-it-failed/)
- [Whatever Happened to the Semantic Web?](https://twobithistory.org/2018/05/27/semantic-web.html)
- [Three reasons why the Semantic Web has failed](https://gigaom.com/2013/11/03/three-reasons-why-the-semantic-web-has-failed/)

## Advanced Prolog Topics

- The [Warren Abstract Machine](https://github.com/a-yiorgos/wambook)
- The [Micro-Prolog manual](http://www.worldofspectrum.org/pub/sinclair/games-info/m/Micro-PROLOGPrimer.pdf) from Spectrum

### Other links of interest

- VIDEO: A solution to the four-color problem which we will be solving using Prolog in the project - [Four color theorem: coloring algorithm](https://www.youtube.com/watch?v=YmYGFxtj2es)
