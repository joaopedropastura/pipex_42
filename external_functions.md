I created this file to briefing new external functions allowed this project

<ol>
	<li> perror <ul>
</ol>

<p>	1 - perror: </p>
•	library: <stdio.h>
•	Name: perror - print a system error message.
•	prototype: void	perror(const char *str);
•	This function return a message on standard output, first the string str is printed, followed the error menssage itself.
*	The example(1) shows how perror works **output expected**


<<-----------------**EXAMPLES***----------------->>

**example 1**

#include <stdio.h>

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