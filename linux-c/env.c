/*
 * =====================================================================================
 *
 *       Filename:  env.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 16时34分32秒
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
#include <malloc.h>

extern char **environ;

int main(int argc, char *argv[])
{
	int i;

	printf ("Argument: \n");
	for (i = 0; i < argc; i++) {
	
		printf ("argv[%d] is %s\n", i, argv[i]);
	
	}

	printf ("Environment: \n");

	for (i = 0; environ[i] != NULL; i++) {
	
		printf ("%s\n", environ[i]);
	
	}

	return EXIT_SUCCESS;
}

