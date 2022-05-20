I created this file to briefing new external functions allowed this project

<ol>
	<li> perror <ul>
</ol>
<a name="link"></a>
<p>	1 - perror: </p>
>	library: <code><stdio.h></code> <br>
>	Name: perror - print a system error message. <br>
>	prototype: void	perror(const char *str); <br>
>	This function return a message on standard output, first the string str is printed, followed the error menssage itself. <br>
>	The [example(1)](#link1) shows how perror works **output expected** <br>

<h4>-----------------EXAMPLES-----------------</h4>

<a id="#link1">**example 1**</a><br>
<code>
#include <stdio.h>
{
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
}
</code>