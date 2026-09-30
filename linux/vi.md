# Vim Information

**Vi** and **Vim** are text editors that are commonly available on Linux, Unix, and other command-line systems. Vim is an enhanced version of the classic Vi editor and is designed for fast, keyboard-driven editing. Even if you normally use an IDE such as VS Code, learning the basics of Vi/Vim is valuable because you may encounter it when working on remote servers, using SSH, editing configuration files, or working in a terminal-only environment. You do not need to become a Vim expert, but knowing how to open a file, make changes, save, and quit is a useful skill for any computer science student. 

## Installing Vim

You can download Vim from [vim.org](http://www.vim.org/download.php)

### Linux

Most 
On the Debian/Ubuntu Linux installations (including the classroom VMs), you can install Vim with the command

```bash
sudo apt install vim
```

On the Fedora/CentOS Linux installations, you can install Vim with the command

```bash
sudo dnf install vim
```

## Learning Vim

The best way to start learning Vim is the built-in interactive tutorial:

```bash
vimtutor
```


## Add the current Vim help site

I strongly recommend:

[Vim Help](https://vimhelp.org/?utm_source=chatgpt.com)

It provides the current Vim 9.2 help pages, quick reference, user manual, reference manual, and FAQ. :chatgpt-content-reference{index="16"}

You can also get help from inside Vim: 

```vim
:help
:help quit
:help dd
:help visual
```

## Tutorials

- Cheet sheets
  - [vimsheet.com](http://vimsheet.com/)
  - [fprintf.net](http://www.fprintf.net/vimCheatSheet.html)
- [Tutorial](http://heather.cs.ucdavis.edu/~matloff/UnixAndC/Editors/ViIntro.html)
- [VIM Adventures](https://vim-adventures.com/) — learn Vim by playing a game.
- [OpenVim](http://www.openvim.com/) is an interactive Vim tutorial.
- [A Vim Guide for Advanced Users](https://thevaluable.dev/vim-advanced)

## Plugins & settings

- The vimrc file stores your settings.  Here is a [good introduction](https://dougblack.io/words/a-good-vimrc.html)
- Another introduction to [settings and plugins for Vim](https://boddy.im/vim-dev-env.html)

## Vim & VS Code

If you primarily use Visual Studio Code, you can use Vim-style editing without leaving VS Code.

- [VSCodeVim](https://marketplace.visualstudio.com/items?itemName=vscodevim.vim)
- [Boost your Coding Fu with VSCode and Vim](https://www.barbarianmeetscoding.com/boost-your-coding-fu-with-vscode-and-vim/dedication)

## Links

- If you have difficulty exiting Vim, you aren’t the only one - see [How to exit Vim on Stack Overflow](https://stackoverflow.blog/2017/05/23/stack-overflow-helping-one-million-developers-exit-vim/)

## ed

Most Unix or Linux installations include vi.  But if not, you might be able to use ed.  

- Here is [a tutorial](https://www.nyx.net/~ewilli/edtut.pdf).
- A [discussion of how people used ed](https://retrocomputing.stackexchange.com/questions/5341/how-did-people-use-ed)
