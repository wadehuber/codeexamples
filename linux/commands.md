# Linux Commands

## Linux Tutorials and Introductions

- [UNIX Tutorial for Beginners](http://www.ee.surrey.ac.uk/Teaching/Unix/) covers much of what gets covered in CSC220.  
- [LinuxCommand.org](http://linuxcommand.org) is the website for the CSC220 Linux book *The Linux Command Line*.  The "Learning the Shell" link covers many of the commands we will talk about.  There is also a link to download a free PDF of the book.
- Julia Evans [Twitter](https://twitter.com/b0rk) creates excellent comics covering Linux commands and several other topics available at [wizardszines.com](https://wizardzines.com/).  She does an greap job of distilling the important facts into 6 panels.  
- Alex Petralia has a very nice nice overview of some of the most helpful Linux commands - [Learn just enough Linux to get things done](https://alexpetralia.com/posts/2017/6/26/learning-linux-bash-to-get-things-done)
- A good list of [essential Linux commands](https://semanti.ca/blog/?the-most-useful-linux-commands-you-probably-need-to-know)
- [How Unix Works](https://neilkakkar.com/unix.html)
- A [Really Friendly Command Line Intro](https://hellowebbooks.com/learn-command-line/) is available free online (email registration required).  This covers the most important commands you will use navigating around the command line.  

## Linux / UNIX References

- This [Unix/Linux Command Cheatsheet](https://files.fosswire.com/2007/08/fwunixref.pdf) is a great reference for the most commonly used Unix commands.
- A list of [bash environment variables](http://tldp.org/LDP/abs/html/internalvariables.html).
- [Unix for Poets](https://web.stanford.edu/class/cs124/kwc-unix-for-poets.pdf) is a nice write up of text processing in Unix
- If you want to go deeper into what happens when you run different Linux commands, [Safia Abdalla](https://blog.safia.rocks/) has posts that do a deep dive in to "cd", ls", "sudo" and more.  Check the archive link.
- A book about the [Linux kernel and its insides](https://github.com/0xAX/linux-insides)

## The semi-colon (;) on the Linux Command Line

You can use a semicolon to separate UNIX commands on a single command line.  This allows you do to things like put a time stamp on the output of a command.

```bash
$ ls -l ; date
total 64
-rwxrwxr-x 1 Wade None 54373 Jun 14 17:51 a.exe
-rwxrwxr-x 1 Wade None  1061 Jun 14 17:51 test.c
Sun, Jun 14, 2015  5:56:51 PM
```

## grep

- A good [grep example](http://www.panix.com/~elflord/unix/grep.html)
- You can also use [awk to accomplish a lot of the same things you can do with grep](https://blog.jpalardy.com/posts/skip-grep-use-awk/)

## cron

- You can schedule processes using cron.  [A good introduction](https://code.tutsplus.com/tutorials/scheduling-tasks-with-cron-jobs--net-8800).
- [The Beginners Guide to Cron Jobs](https://www.ostechnix.com/a-beginners-guide-to-cron-jobs/)
- The official Ubuntu documentaion includes a nice [CronHowto](https://help.ubuntu.com/community/CronHowto)

## Creating a file using the "cat" command

You can create a file with cat by redirecting output to a file.  cat will read from stdin if no input file is given.  ctrl-d ends input with a EOF.

```bash
$ cat > catfile
Here is a line.
Another line.
ctrl-d will put in an EOF.
$ cat catfile
Here is a line.
Another line.
ctrl-d will put in an EOF.
```

Keep in mind that this will erase anything in the file you are redirecting to.  Most commands that accept a file as a parameter will attempt to read from stdin if no filename is given.

### find

- A nice tutorial on [finding files in Linux](https://www.linode.com/docs/tools-reference/tools/find-files-in-linux-using-the-command-line/)
- Alvin Alexaner has has [several examples of using the find command](http://alvinalexander.com/unix/edu/examples/find.shtml).
- A list of [35 practical examples of the linux find command](https://www.tecmint.com/35-practical-examples-of-linux-find-command/)

### cut

- [Linux & Unix cut command tutorial](https://shapeshed.com/unix-cut/) with a lot of examples
- Alvin Alexaner has has [several examples of using the cut command](https://alvinalexander.com/linux-unix/linux-cut-command-cut-fields-columns-examples/).

## Using Wildcards & Redirection

In UNIX, the wildcard * matches anything while ? will match a single letter.  We can combine that with ls to get a list of files that, for example, start with h.  The command "ls b?g" will list big, bag, bog, bkg, etc.

```bash
administrator@ubuntu:~$ ls h*
hello.c
administrator@ubuntu:~$ ls h?llo.c
hello.c
administrator@ubuntu:~$ ls h?ello.c
ls: cannot access h?ello.c: No such file or directory
```

We can also redirect output to a file using the ">" character.  The following example creates a file called mydir that holds the results of the "ls" command

```bash
administrator@ubuntu:~$ ls > mydir
administrator@ubuntu:~$ cat mydir
220
240
a.out
Desktop
Documents
Downloads
examples.desktop
hello.c
Music
mydir
news.txt
Pictures
Public
Templates
Videos
```

## bash shell notes

- [An introduction to bash scripting](https://code.tutsplus.com/tutorials/the-fundamentals-of-bash-scripting--net-32093)
- If you aren't happy with bash or the other shells, [you can always just write your own](https://indradhanush.github.io/blog/writing-a-unix-shell-part-1/).

## pipes

- Implementating [digital circuits using Unix pipes](http://www.linusakesson.net/programming/pipelogic/index.php)
