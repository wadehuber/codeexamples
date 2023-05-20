# git & GitHub

## Git Videos

- [Fixing chmod on config.lock failed error](https://youtu.be/uTw50U9sMO8) (1:35) walks through setting up Windows Subsystem for Linux to allow git to update file permissions
- [Adding SSH keys to GitHub](https://youtu.be/_sTURUDtTQs) (2:40) walks through generating SSH keys on Ubuntu then adding the to your GitHub account

## Git Tutorials

- [Simple guide to git](http://rogerdudler.github.io/git-guide/)
- GitHub [cheat sheet](https://education.github.com/git-cheat-sheet-education.pdf)
- Additional resources [from GitHub](https://services.github.com/resources/)
- [5 Git ideas explained the hard way](https://zwischenzugs.com/2018/03/14/five-key-git-concepts-explained-the-hard-way/)
- [git - the simple guild](http://rogerdudler.github.io/git-guide/)
- [Getting](https://git-scm.com/book/en/v2/Git-Basics-Getting-a-Git-Repository) a repo
- [Updating](https://git-scm.com/book/en/v2/Git-Basics-Recording-Changes-to-the-Repository) a repo
- Branching in git can be hard to get your head around.  Here is a great [introduction to branching](https://learngitbranching.js.org/)
- This claims to be [the only introduction to git you'll ever need](https://areknawo.com/git-basics-the-only-introduction-you-will-ever-need/)
- A guide to [More Productive Git](https://increment.com/open-source/more-productive-git/)
- [Learn Git with Bitbucket Cloud](https://www.atlassian.com/git/tutorials/learn-git-with-bitbucket-cloud) is from Atlassian so it focuses on Bitbucket instead of GitHub, but it is nicely organized and has nice illustations of how git works.
- Videos
  - [Basic Git Concepts](https://www.youtube.com/watch?v=8KCQe9Pm1kg) is a nice overview of what git does
  - [Git & GitHub Crash Course For Beginners](https://www.youtube.com/watch?v=SWYqp7iY_Tc)
  - [Git command line basics](https://www.youtube.com/watch?v=HVsySz-h9r4)
  - [Learn Git in 20 Minutes](https://www.youtube.com/watch?v=IHaTbJPdB-s)
  - [Introduction to GitHub for Student Developers](https://mybuild.microsoft.com/sessions/d29ddc03-a873-41df-bb4e-5c0af5bf7b5c) is a short introduction to GitHub presented at Microsoft Build 2020
  - [Introduction to Git - Core Concepts](https://www.youtube.com/watch?v=uR6G2v_WsRA) goes a little more in detail into what git does.

## Git Best Practices

- [Commit Often, Perfect Later, Publish Once: Git Best Practices](https://sethrobertson.github.io/GitBestPractices/)
- [10 Common git Mistakes & How  to Fix Them](https://sethrobertson.github.io/GitBestPractices/)
- [What is the best Git branch strategy?](https://www.gitkraken.com/learn/git/best-practices/git-branch-strategy)

## GitHub, GitLab, & BitBucket

- [Git vs GitHub/GitLab](https://youtu.be/wpISo9TNjfU)

## GitHub Error 403 help

If you get Error 403 when working with GitHub, some here are some [suggestions for resolving that error](http://stackoverflow.com/questions/7438313/pushing-to-git-returning-error-code-403-fatal-http-request-failed)

## Getting the class examples from git

The following shows how to download the Class examples from GitHub.  Note that this isn't required, you can just use a web browser if you prefer.  Replace the URL in the ```git clone``` line the URL for your course/semester which is posted on Canvas.  User commands are in bold.

```bash
whuber@kong:/mnt/c$ cd /mnt/c
whuber@kong:/mnt/c$ mkdir classes
whuber@kong:/mnt/c$ cd classes
whuber@kong:/mnt/c/classes$ ls -ltr
total 0
whuber@kong:/mnt/c/classes$ git clone https://github.com/wadehuber/codeexamples.git
Cloning into 'codeexamples'...
remote: Enumerating objects: 2136, done.
remote: Counting objects: 100% (495/495), done.
remote: Compressing objects: 100% (364/364), done.
remote: Total 2136 (delta 248), reused 334 (delta 124), pack-reused 1641
Receiving objects: 100% (2136/2136), 710.24 KiB | 1.71 MiB/s, done.
Resolving deltas: 100% (1174/1174), done.
Updating files: 100% (308/308), done.
whuber@kong:/mnt/c/classes$ ls -ltr
total 0
drwxrwxrwx 1 whuber whuber 4096 Aug 24 18:23 codeexamples
whuber@kong:/mnt/c/classes$ cd codeexamples/
whuber@kong:/mnt/c/classes/codeexamples$ ls -ltr
total 16
-rwxrwxrwx 1 whuber whuber 11357 Aug 24 18:23 LICENSE
-rwxrwxrwx 1 whuber whuber  1734 Aug 24 18:23 README.md
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 algorithms
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 applications
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 bash
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 c
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 concurrency
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 cpp
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 debugging
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 java
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 javascript
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 linux
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 programming
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 prolog
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 python
drwxrwxrwx 1 whuber whuber  4096 Aug 24 18:23 scheme
```

## GitHub Student Developer Pack

GitHub offers a variety of [tools for students](https://education.github.com/pack).  None of these are required for this class, but you may find some of the items helpful.
