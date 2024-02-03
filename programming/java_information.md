# General Java, Object-Oriented, and General Programming Links

## Commonly used classes

I don't expect you to memorize all the methods from these packages but you will be using them extensively this semester so you should be able to use the documentation to find any methods you will need.

- [String](http://docs.oracle.com/javase/8/docs/api/java/lang/String.html)
- [Math](http://docs.oracle.com/javase/8/docs/api/java/lang/Math.html)
- [Random](http://docs.oracle.com/javase/8/docs/api/java/util/Random.html)

## compareTo

When you have a line in your code like the following:

```(java)
return (name.compareTo(m.getName()));
```

Note that this is not a recursive call to ```compareTo``` - it is calling the ```compareTo()``` of the String class (or whatever the type is for data member m).  This is common way of implementing a compareTo method since it leverages code that has already been implemented for the data member.  If we want to sort our class based on a String data member then using the ```String.compareTo()``` method is much easier than trying to write something ourselves.

## Java Versions

- [A Guide to Java Versions and Features](https://dzone.com/articles/a-guide-to-java-versions-and-features)
- [New Features in Java Versions since Java 8](https://ondro.inginea.eu/index.php/new-features-in-java-versions-since-java-8/)

## General Programming Advice

- Why you should always use braces even around one line of code - [Apple's SSL Bug Explained](https://nakedsecurity.sophos.com/2014/02/24/anatomy-of-a-goto-fail-apples-ssl-bug-explained-plus-an-unofficial-patch/)
- [Rob Pike's 5 Rules of Programming](http://users.ece.utexas.edu/~adnan/pike.html).  Rules 3 - 5 are relevant for CSC205. We will learn a lot of different algorithms and data structures, but keep in mind that it isn't always worth it to use the more advanced ones. You have to decide based on the specific problem you are trying to solve.

## Interesting Code

[Lines of Code That Changed Everything](https://slate.com/technology/2019/10/consequential-computer-code-software-history.html) has some examples of famous (or infamous) programs
