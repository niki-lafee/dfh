/*
 * =====================================================================================
 *
 *       Filename:  strcpy.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月14日 19时49分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lafee, wisdomandmircle@gmail.com
 *        Company:  Class 1301 of Software Engineering
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcpy (char *, char *);

int main(int argc, char *argv[])
{
	char *str = "dfsgsdac4545xs";
	char *p = NULL;

	p = (str, p);

	puts (p);

	return EXIT_SUCCESS;
}

char *strcpy (char *dest, char *scr) {

	char *ret_string;

	if (dest == NULL ) {
	
		printf ("error!\n");
		return NULL;
	
	}

	ret_string = scr;

	while ((*scr++ = *dest++) != '\0');

	return ret_string;
}
