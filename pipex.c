/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:43:08 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/25 10:22:10 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // printf, fopen, fclose, rename
#include <unistd.h> // perror, acess
#include <stdlib.h> //malloc
#include <string.h> // strerror
#include <errno.h>
#include <fcntl.h> //open


int main(int argc, char *envp[])
{
	FILE	*fp;
	int		fd;
	char	*str;
	char	*s = {"lapis de cor colorindo casas sem cor"};
	int		len = 0;
	int		duptest;
	char	*strerr;

	while(s[len])
		len++;
	printf("\nlen:%i", len);
	printf("\ns  :%s", s);
	printf("\nstr:%s\n", str);
	str = (char *)malloc(len * sizeof(char));
	if (str == NULL)
		return (0);
		len = 0;
	while(s[len])
	{
		str[len] = s[len];
		len++;
	}
	// close(1);
	// fd = dup(1);
	// rename("test.txt", "ntest.txt");
	// duptest = open("ntest.txt", O_WRONLY);
	fd = open("duptest.txt", O_WRONLY | O_CREAT, 0777);
	if(fd == -1)
	{
		printf("Error Number : %i\n", errno);
		perror("Error: ");
	}
	duptest = dup(fd);
	close(duptest);
	write(duptest, "lapis sem cor descolorindo tela colorida\n", 41);
	write(fd, "lapis de cor colorindo casas sem cor\n", 37);
	int i = 0;

	return(0);
}