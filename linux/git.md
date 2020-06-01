# git & GitHub

## Git Tutorials

- [Simple guide to git](http://rogerdudler.github.io/git-guide/)
- GitHub [cheat sheet](https://services.github.com/on-demand/downloads/github-git-cheat-sheet.pdf)
- Additional resources [from GitHub](https://services.github.com/resources/)
- [5 Git ideas explained the hard way](https://zwischenzugs.com/2018/03/14/five-key-git-concepts-explained-the-hard-way/)
- [Getting](https://git-scm.com/book/en/v2/Git-Basics-Getting-a-Git-Repository) a repo
- [Updating](https://git-scm.com/book/en/v2/Git-Basics-Recording-Changes-to-the-Repository) a repo
- Branching in git can be hard to get your head around.  Here is a great [introduction to branching](https://learngitbranching.js.org/)
- This claims to be [the only introduction to git you'll ever need](https://areknawo.com/git-basics-the-only-introduction-you-will-ever-need/)
- A guide to [More Productive Git](https://increment.com/open-source/more-productive-git/)
- Videos
  - [Git command line basics](https://www.youtube.com/watch?v=HVsySz-h9r4)
  - [Learn Git in 20 Minutes](https://www.youtube.com/watch?v=IHaTbJPdB-s)
  - [Introduction to GitHub for Student Developers](https://mybuild.microsoft.com/sessions/d29ddc03-a873-41df-bb4e-5c0af5bf7b5c) is a short introduction to GitHub presented at Microsoft Build 2020

## Git Best Practices

[10 Common git Mistakes & How  to Fix Them](ttps://sethrobertson.github.io/GitBestPractices/)

## GitHub Error 403 help

If you get Error 403 when working with GitHub, some here are some [suggestions for resolving that error](http://stackoverflow.com/questions/7438313/pushing-to-git-returning-error-code-403-fatal-http-request-failed)

## Getting the class examples from git

The following shows how to download the Class examples from GitHub.  Note that this isn't required, you can just use a web browser if you prefer.  Replace the URL in the ```git clone``` line the URL for your course/semester which is posted on Canvas.  User commands are in bold.

```bash
[student@localhost ~]$ mkdir git
[student@localhost ~]$ cd git/
[student@localhost git]$ ls
[student@localhost git]$ git clone https://github.com/CGCC-CS/csc240fall19.git
Cloning into 'csc240fall18'...
remote: Counting objects: 77, done.
remote: Compressing objects: 100% (68/68), done.
remote: Total 77 (delta 0), reused 73 (delta 0), pack-reused 0
Unpacking objects: 100% (77/77), done.
[student@localhost git]$ ls
csc240fall18
[student@localhost git]$ cd csc240fall18/
[student@localhost csc240fall18]$ ls -ltr
total 4
-rw-rw-r--. 1 student student 51 Aug 27 22:54 README.md
drwxrwxr-x. 2 student student 79 Aug 27 22:54 c1
drwxrwxr-x. 2 student student 57 Aug 27 22:54 c0
drwxrwxr-x. 2 student student 106 Aug 27 22:54 c2
drwxrwxr-x. 4 student student 168 Aug 27 22:54 c3
drwxrwxr-x. 2 student student 70 Aug 27 22:54 cpp3
drwxrwxr-x. 2 student student 94 Aug 27 22:54 cpp2
drwxrwxr-x. 2 student student 59 Aug 27 22:54 cpp1
drwxrwxr-x. 2 student student 23 Aug 27 22:54 cpp0
drwxrwxr-x. 2 student student 45 Aug 27 22:54 c4
drwxrwxr-x. 2 student student 25 Aug 27 22:54 scheme2
drwxrwxr-x. 2 student student 25 Aug 27 22:54 scheme1
drwxrwxr-x. 2 student student 25 Aug 27 22:54 scheme0
drwxrwxr-x. 2 student student 24 Aug 27 22:54 prolog3
drwxrwxr-x. 2 student student 24 Aug 27 22:54 prolog2
drwxrwxr-x. 2 student student 24 Aug 27 22:54 prolog1
drwxrwxr-x. 2 student student 24 Aug 27 22:54 prolog0
drwxrwxr-x. 2 student student 56 Aug 27 22:54 cpp4
drwxrwxr-x. 2 student student 25 Aug 27 22:54 scheme4
drwxrwxr-x. 2 student student 47 Aug 27 22:54 scheme3
```

## GitHub Student Developer Pack

GitHub offers a variety of [tools for students](https://education.github.com/pack).  None of these are required for this class, but you may find some of the items helpful.
