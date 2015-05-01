# SCRIPT #

This README documents the why, the what, and the how of this repository

/!\ This software is experimental, you SHOULD NOT use it if you're looking for the original script utility /!\


### What is this repository for? ###

* An illustration of my C skills, attached to my [personal portfolio](http://nicolas.chauv.in/portfolio.phtml) *(online soon)*
* Was a school project

### What is "script"? ###

From [Wikipedia](http://en.wikipedia.org/wiki/Script_%28Unix%29):

*"The script command is a Unix utility that records a terminal session. The session is captured in file. The scriptreplay command offers a replay function to script. The advantage of sessions recorded in this format from the usual screencasts is that shell instructions can be easily copy/pasted from the player screen."*


### How do I get set up? ###

```
$ cd
$ git clone https://github.com/NicolasChauvin/script.git
$ cd script
$ make
$ ./script --help

Usage:
 script [option] [file]

Options:
 -a, --append			append the output
 -c, --command <command>	run command rather than interactive shell
 -f, --force   			use output file even when it is a link
 -V, --version			output version information and exit
 -h, --help			display this help and exit
```

### A quick example ###

```
$ pwd
/home/nicolas/script
$ ls
LICENSE  Makefile  README.md  script  source
$ ./script
Script started, file is typescript
$ ls
LICENSE  Makefile  README.md  script  source  typescript
$ echo "Foobar"
Foobar
$ exit
exit
Script done, file is typescript
$ cat typescript
Script started on Fri 01 May 2015 09:21:14 PM CEST
$ ls
LICENSE  Makefile  README.md  script  source  typescript
$ echo "Foobar"
Foobar
$ exit
exit

Script done on Fri 01 May 2015 09:21:19 PM CEST
```

### Specificity of this software ###

* Experimental, you SHOULD NOT use it if you're looking for the original script utility
* Originaly designed for Opensuse 12 and Debian 7 x86_64, but should work on others distributions and architectures
* Known bugs with terminal capacities (window size...)

### Who do I talk to? ###

* Nicolas Chauvin <chauvin.nico@gmail.com>
