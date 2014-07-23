/*
 * =====================================================================================
 *
 *       Filename:  fork.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月21日 10时20分25秒
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

	printf ("Process Creation Study.\n");
	pid = vfork ();
	printf ("pid:%d\n", pid);
	switch (pid) {
	
		case 0:
			printf ("Child process is running,CurPid is %d,ParentPid is %d.\n", pid, getppid());
			break;
		case -1:
			perror ("Process creation is failed!\n");
			break;
		default:
			printf ("Parent process is running,ChildPid is %d, ParentPid is %d.\n",pid, getpid());
			break;
	
	}

	return EXIT_SUCCESS;
}

