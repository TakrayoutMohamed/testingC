# Minishill
## part 1 functions

### readline()

to compile this function you need to add the next flag during the compiling phase "-lreadline"
this function returnes a poiter to an allocated string .

### dup2

Syntax: int dup2(int oldfd, int newfd);

duplacate a file descriptor , befor it start copieng it, it does the next two steps first : 
* closes newfd (if opens)
* copies file descriptor table of oldfd to table of file descriptor newfd

dup2(ofd, 1) <=====> close(1); dup(ofd);
