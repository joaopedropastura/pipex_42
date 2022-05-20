/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:43:08 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/20 00:50:45 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // printf, fopen, fclose, rename
#include <unistd.h> // perror
#include <stdlib.h> //malloc
#include <string.h> // strerror
#include <errno.h>

int main()
{
	FILE *fp;
	char *str;
	char *s = {"lapis de cor colorindo casas sem cor"};
	int len = 0;
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
	// rename("test.txt", "ntest.txt");
	fp = fopen("non_existfile.txt", "r");
	if(fp == NULL)
	{
		strerr = strerror(errno);
		printf("fopen() failed: %s", strerr);
		perror("fopen() failed");
	}
	else
		printf("deu certo bobao");
		printf("\nstr: %s\n", str);

	return(0);
}