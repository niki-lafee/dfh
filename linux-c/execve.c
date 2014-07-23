/*
 * =====================================================================================
 *
 *       Filename:  execve.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 17时08分10秒
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
	pid_t pid;
	int stat_val;

	printf ("Exec example!\n");
	pid = fork ();
	switch (pid) {
	
		case -1:
			perror ("Process Creation failed!\n");
			exit (1);
		case 0:
			printf ("Child process is running!\n");
			printf ("My pid = %d, parentpid = %d\n", getpid (), getppid ());
			printf ("uid = %d, gid = %d\n", getuid (), getgid ());
			execve ("processimage", argv, environ);
			printf ("process never go to here!\n");
			exit (0);
		default:
			printf ("Parent process is running!\n");
			break;
	
	}

	wait (&stat_val);
	exit (0);

	return EXIT_SUCCESS;
}

