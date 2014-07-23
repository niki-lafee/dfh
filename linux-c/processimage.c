/*
 * =====================================================================================
 *
 *       Filename:  processimage.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 17时01分30秒
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
#include <sys/types.h>

int main(int argc, char *argv[], char **environ)
{
	int i;

	printf ("I am a process image!\n");
	printf ("My pid = %d. parentpid = %d\n", getpid (), getppid ());
	printf ("uid = %d, gid = %d\n", getuid (), getgid ());

	for (i = 0; i < argc; i++) {
	
		printf ("argv[%d]:%s\n", i, argv[i]);
	
	}

	return EXIT_SUCCESS;
}

