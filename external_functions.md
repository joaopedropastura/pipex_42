I created this file to briefing new external functions allowed this project

<ol>
	<li> perror <ul>
	<li> strerror <ul>
</ol>
<a name="link"></a>
<p>	1 - perror: </p>
>	library: stdio.h <br>
>	Name: perror - print a system error message. <br>
>	prototype: void	perror(const char *str); <br>
>	This function return a message on standard output, first the string str is printed, followed the error menssage itself. <br>
>	The example(1) shows how perror works.<br>

<p>	2 - strerror: </p>
>	library: string.h, errno.h <br>
>	Name: strerror - return string describing error number. <br>
>	prototype: char	*strerror(int errnum); <br>
>	This function is very similar to <b>perror</b>, except its returns a pointer string error. <br>
>	The example(2) shows how strerror works.<br>

<h4>-----------------EXAMPLES-----------------</h4>

**example 1**<br>
<pre>
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
</pre>
**example 2**<br>
<pre>
#include string.h
#include errno.h
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
OBS: The strerror(errno) parameter its a macro and signify the number of last error,
another words this lib has a list with all errors and their descriptions and then match with your error.
output expected: fopen() failed: No such file or directory.
</pre>