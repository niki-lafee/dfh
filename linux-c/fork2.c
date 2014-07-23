/*
 * =====================================================================================
 *
 *       Filename:  fork2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月21日 11时17分35秒
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

int main(int argc, char *argv[])
{
	pid_t pid;
	char *msg;
	int k;

	printf ("Process Creation is running!\n");
	pid = fork ();
	printf ("pid:%d.\n", pid);
	switch (pid) {
	
		case 0:
			msg = "Child process is running";
			k = 3;
			break;
		case -1:
			perror ("Process creation failed.\n");
			break;
		defauit:
			msg = "Parent process is running";
			k = 5;
			break;
	
	}

	while (k > 0) {
	
		puts (msg);
		sleep (1);
		k--;
	
	}

	return EXIT_SUCCESS;
}

