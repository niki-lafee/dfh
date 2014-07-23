/*
 * =====================================================================================
 *
 *       Filename:  fork3.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月21日 11时58分09秒
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

	pid = fork();
	switch(pid) {
	
		case 0:
			while (1) {
			
				printf ("A background process, PID: %d, ParentID:%d.\n", getpid(), getppid());
				sleep (3);

			
			}
		case -1:
			perror ("Process creation failed!\n");
			exit (-1);
		default:
			printf ("I am parent process, my pid is %d\n", getpid());
			exit (0);
	
	}

	return EXIT_SUCCESS;
}

