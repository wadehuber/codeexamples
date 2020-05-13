# Setup

For CSC220 and for compiling C & C++ in CSC240 you will need a UNIX-style terminal.  The best solution is to install Linux, either dual-boot or on a virtual machine, but you can also use Windows or Mac.  No matter what environment you use, make sure you install gcc, g++, gdb, and make.  You may have to choose those separately during Cygwin or Linux installation.  If you forget, you can always install them later - consult the documentation for your system.
I will predominately be using Cygwin, a Centos 8 VM, and MacOS for class examples.

## Installing Linux on a virtual machine

- Directions for [installing Linux on a VMWare virtual machine](https://www.linux.com/news/installing-virtual-machines-vmware), which will allow you to install & run Linux on your computer without needing to reboot.
- You can download a [free (non-commercial) version of VM Player](https://my.vmware.com/en/web/vmware/free#desktop_end_user_computing/vmware_workstation_player/15_0)

## Installing Cygwin on Windows

- [Cygwin](https://www.cygwin.com/) is a good choice if you want to be able to run UNIX commands on Windows without doing a full Linux install.  This also allows you to use your favorite Windows editory.  Be sure to install at least gcc & g++.  You will also want to install make & cppcheck.  
- VIDEO: [Installing C & C++ Compiler for Windows 7, 8.1, & 10](https://youtu.be/DAlS4hF_PbY) - Cygwin has a pretty thorough walkthrough of installing Cygwin all the way through compiling a C program.
- VIDEO: [Installing Cygwin on Windows by James Jardine](https://www.youtube.com/watch?v=zRbbDkDb5UM) is another nice walkthrough of the installation process

## Windows 10

You can install several different Linux distributions in the Microsoft Store.  If you go this route I sugguest [Ubuntu](https://www.microsoft.com/en-us/p/ubuntu/9nblggh4msv6)

## MacOS

The Mac Terminal should be sufficient for what we do in this class.  You will need to install Xcode to get access to gcc/g++.  On Mac I use [iTerm2](https://www.iterm2.com/) which is a replacment for the built in terminal.  

## Installing Linux on a USB drive

[Pendrive Linux](http://www.pendrivelinux.com/) has directions for installing Linux on a bootable USB drive.  Note that you want to choose an option with persistent storage so that you can save your work.

## Using C on a Virtual Machine

![VMWare Icon](images/vmicon.png)

- Start the virtual machine (on the classroom computers there should be a virtual machine like abovek with the VMWare Icon with "CentOS CSC24" or something similar in the name)
- Log on (use the default user if you are on the classroom VM)
- Start a terminal (Applications -> Accessories -> Terminal)
- Edit the file using one of the following commands:
  - ```gedit file.c &```
  - ```vi file.c```
- Run your programm using the command

```bash
./a.out
```

![Running a C Program](images/desktop.png)

## Sample Session

The text below is from a session on the classroom VM.  I've added comments (Starting with '#') describing what each command does.  The commands below should be the same on Linux, MacOS, Cygwin, or Bash for Windows.

```bash
[student@localhost ~]$ ls                  # List the files in the current directory
Desktop Documents Downloads Music Pictures Public Templates Videos
[student@localhost ~]$ mkdir 240           # Create a directory
[student@localhost ~]$ cd 240/             # Change to directory 240
[student@localhost 240]$ ls                # List the files in the current directory
[student@localhost 240]$ pwd               # Show the current directory
/home/student/240
[student@localhost 240]$ gedit first.c &   # Edit first.c with gedit (note that the & is important - it tells Linux to run gedit in the background which lets you keep using the current terminal session)
[1] 3600
[student@localhost 240]$ cat first.c       # Display the contents of first.c
#include<stdio.h>

int main() {
   printf("Hello, world!");
   return 0;
}
[student@localhost 240]$ gcc -ansi -pedantic -Wall first.c # Compile
[student@localhost 240]$ ls                # Notice the new file - a.out.  That is the executable that is generated when we compile.  
a.out first.c
[student@localhost 240]$ a.out
bash: a.out: command not found...          # Linux does not look in the current directory by default
[student@localhost 240]$ ./a.out           # Specify to look in the current directory (./) for the file to run.
Hello, world!                              # Output from the program
```

## Using C with Cygwin

After installing Cygwin you should se an icon on your desktop like below:

![Cygwin Icon](images/cygicon.png)

Double-clicking the icon should bring up a Cygwin terminal like below:

![Cygwin Terminal](images/cygterm.png)

### Editing Cygwin Files

You can either edit files under the Cygwin home directory or change to a Windows directory.  

#### Editing files under the Cygwin home directory

The Cygwin home directory is selected during installation.  TYpically it is under ```C:\cygwin``` or ```C:\cygwin64```.  Under that installation directory, navigate to ```home\username```.

![Cygwin Directory in Explorer](images/cygdir.png)

Once you navigate to that directory (or whatever subdirectory you want to storeyour files) you can edit and save files there with your favorite text editor.

#### Editing files in a regular Windows directory

If you already have a directory where you store your code you can navigate to that directory under Cygwin.  Suppose you have a directory called ```csc240``` on your ```C:``` drive.

![Windows Directory in Explorer](images/windir.png)

You can access your Windows drives by changing to the directory ```/cygdrive/driveletter```.  Note the leading slash.  Replace driveletter with the appripriate drive letter, for example ```/cygdrive/c``` will be your computer's ```C:``` drive.

![Compiling & running C in Cygwin](images/cygcomp.png)

## Compiling C files with the Linux Subsystem for Windows

If you have installed a Linux distribution from the Windows Store, the simplest way to compile & run your C files is to change to the apprpriate directory from inside the Linux window then follow the directions for the VM's above.  

If you save you rfiles in a directory called ```csc240``` on your ```C:``` drive:

![Windows Directory in Explorer](images/windir.png)

Then you can change to that directory in the Linux window using the command

```bash
cd /mnt/c/csc240
```

You should modify the drive letter & directory as necessary.
