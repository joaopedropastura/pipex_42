<h3>I created this file to briefing new external functions allowed this project</h3>
<h4>function list</h3>
<ol>
	<li> perror
	<li> strerror
	<li> acess
	<li> dup
	<li> dup2
	<li> execve
	<li> error
	<li> fork
</ol>

<h4>	1 - perror: </h4>
>	library: "stdio.h" <br>
>	Name: perror - print a system error message. <br>
>	prototype: void	perror(const char *str); <br>
>	This function return a message on standard output, first the string str is printed, followed the error menssage itself. <br>
>	The example(1) shows how perror works.<br>

<h4>	2 - strerror: </h4>
>	library: "string.h", "errno.h" <br>
>	Name: strerror - return string describing error number. <br>
>	prototype: char	*strerror(int errnum); <br>
>	This function is very similar to <i>perror</i>, except its returns a pointer string error. <br>
>	The example(2) shows how strerror works.<br>

<h4>	3 - acess: </h4>
>	library: "unistd.h" <br>
>	Name: acess - check real user's permissions for a file. <br>
>	prototype: int	acess(const char *pathname, int mode); <br>
>	This function check whether the calling program has acess to a specifield file. Its can be used to check whether a file exist or not.<br>
>	The example(3) shows how acess works.<br>
>	List of mode parameter:
<ul>
	<li>	F_OK flag : Used to check for existence of file.
	<li>	R_OK flag : Used to check for read permission bit.
	<li>	W_OK flag : Used to check for write permission bit.
	<li>	X_OK flag : Used to check for execute permission bit.
</ul>

<h4>	4 - dup </h4>
>	library: "unistd.h" <br>
>	Name: dup - duplicate an open file descriptor. <br>
>	prototype: int	dup(int	oldfd); <br>
>	This function returns a new open file descriptor. <br>
>	If the copy is successfully created, then the original and copy file descriptors(returns fuction value) may be used interchangeably.<br>
>	The example(4) shows how dup works.<br>

<h4>	5 - dup2 </h4>
>	library: "unistd.h" <br>
>	Name: dup2 - duplicate file descriptor. <br>
>	prototype: int	dup2(int oldfd, int newfd); <br>
>	This function is very similar to <i>dup</i> the basic diference between them is that instead of using the lowest-numbered unused file descriptor, it uses the descriptor number specified by the user. <br>
>	In other words, the file descriptor newfd is adjusted so that it now refers to the same open file description as <i>oldfd</i>.<br>
>	The example(5) shows how dup2 works.<br>

<h4>	6 - execve </h4>
>	library: "unistd.h" <br>
>	Name: execve - execute program. <br>
>	prototype: int	execve(const char *pathname, char *const argv[], char *const envp[]); <br>
>	The execve() system call loads a new program into a process's memory. <br>
>	The existing process is discarded. <br>
>	The newly create process grt all new stack, data and heap. In other words, its almost like you're replacing what was running with something else <br>
>	This system call not return any value, unless will be have a problem.<br>
>	The example(6) shows how execve works.<br>

<h4>	7 - exit </h4>
>	library: "stdlib.h" <br>
>	Name: exit - cause normal process termination. <br>
>	prototype: void	exit(int status); <br>
>	In C linguage, exit() terminates the calling process whithout executing the rest code whicj is after the exit() function.<br>
>	There are two types of exit status in C/C++
<ul>
	<li>exit success
	<li>exit failure
>	exit success: Its indicated by "exit(0)" statement which means successful.<br>
>	exit faulure: Its indicated by "exit(1)" statement wich means the abnormal termination of the program.<br>
</ul>
>	OBS: we can use diferents integers to indicate diferent types of errors in code.<br>
>	The example(7) shows how exit works.<br>

<h4>	8 - fork </h4>
>	library: "unistd.h" <br>
>	Name: fork - create a child process. <br>
>	prototype: pid_t fork(void) <br>
>	Create a new process by duplicating the calling process. The new process is referred to a sthe <i>child process</i>. The calling process is referred to as the parent process. <br>
>	
>	OBS: the child process run in different memory spaces. <br>
>	The example(8) shows how exit works.<br>
<h4>-----------------EXAMPLES-----------------</h4>

**example 1**<br>

```c

#include stdio.h
int main()
{
	FILE *f;

	f = fopen("no_file_exist.txt", "r");
	if(f == NULL)
		perror("fopen() failed");
	else
		fclose(f);
	return(0);
}
OBS: FILE variable - this is an object type suitable for storing information for a file stream.
output expected: fopen() failed: No such file or directory.
```

**example 2**<br>
```c
#include <string.h>
#include <errno.h>
int main()
{
	FILE *f;
	char *str;

	f = fopen("no_file_exist.txt", "r");
	if(f == NULL)
	{
		str = strerror(errno);
		printf("fopen() failed: %s", str);
	}
	else
		fclose(f);
	return(0);
}
```
OBS: The strerror(errno) parameter its a macro and signify the number of last error,
another words this lib has a list with all errors and their descriptions and then match with your error.
output expected: fopen() failed: No such file or directory.


**example 3**<br>
```c
#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd;

	fd = acess("no_file_exist.txt", F_OK);
	if(f == NULL)
	{
		printf("Error Number : %i\n", errno);
		perror("Error: ");
	}
	else
		printf("No error\n");
	return(0);
}
OBS: if acess() can't acess the file, it will return -1
output expected:
Error Number : 13
Error: : Permission denied
```

**example 4**<br>
```c
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
int main()
{
	fd = open("duptest.txt", O_WRONLY | O_CREAT, 0777);
	if(fd == -1)
	{
		printf("Error Number : %i\n", errno);
		perror("Error: ");
	}
	duptest = dup(fd);
	write(duptest, "lapis sem cor descolorindo tela colorida\n", 41);
	write(fd, "lapis de cor colorindo casas sem cor\n", 37);

	return(0);
}
OBS: you can close originally open file descriptor and manipulate the new variable like original.
	This copy can also be used to do some file operation with the same file "duptest.txt"
output expected, in duptest.txt:
lapis de cor colorindo casas sem cor
 collapis de cor colorindo casas sem cor
```

**example 5**<br>
```c
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
int main()
{
	fd = open("duptest.txt", O_WRONLY | O_CREAT, 0777);
	if(fd == -1)
	{
		printf("Error Number : %i\n", errno);
		perror("Error: ");
	}
	duptest = dup2(fd, 1);
	write(duptest, "lapis sem cor descolorindo tela colorida\n", 41);
	printf("this printf should be printed on terminal");
	return(0);
}
OBS: you can use and chose where return output funcition
output expected, in duptest.txt:
lapis de cor colorindo casas sem cor
this printf should be printed on terminal
```

**example 6**<br>
```c
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
int main()
{
	char	cmd[] = "/bin/ls";

	char	*argV[] = {"ls", "-l", NULL};
	char	*envP[] = {NULL};

	printf("Start of execve call %s: \n", cmd);
	printf("====================================================\n");
	if(execve(cmd, argV, envP) == -1)
	{
		perror("Could not execute execve ");
	}
	printf("Ooooops, something went wrong!\n");
	return(0);
}
OBS: you can use and chose where return output funcition.
	envp is an array of strings, conventionally of the form key=value,
	which are passed as environment to the new program.
	Both args and env must be terminated by a null pointer.
output expected: the same output if you put command "ls -l" on your current directory.
```

**example 7**<br>
```c
#include <unistd.h>
#include <stdio.h>
int main()
{
	printf("start\n");
	exit(0);
	printf("end of program\n");
	return(0);
}
OBS: In the above program, when the exit() function is called, it exits the execution
	immediately and it does not print the statement in the second printf.
output expected: start.
```

**example 8**<br>
```c
#include <unistd.h>
#include <stdio.h>
int main()
{
	printf("start\n");
	exit(0);
	printf("end of program\n");
	return(0);
}
OBS: In the above program, when the exit() function is called, it exits the execution
	immediately and it does not print the statement in the second printf.
output expected: start.
```