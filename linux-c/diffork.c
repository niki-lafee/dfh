/*
 * =====================================================================================
 *
 *       Filename:  diffork.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月21日 16时13分51秒
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

int globVar = 5;

int main(int argc, char *argv[])
{
	pid_t pid;
	int var = 1, i;

	printf ("fork is different with vfork.\n");

	//pid = fork ();
	pid = vfork();
	switch (pid) {
	
		case 0:
			i = 3;
			while (i-- > 0) {
			
				printf ("Child process");
				globVar++;
				var++;
				sleep(1);
			
			}
			printf ("child's globVar = %d, var = %d.\n, globVar, var");
			break;
		case -1:
			perror ("Process creation is failed!\n");
			exit (0);
		default:
			i = 5;
			while (i-- > 0) {
			
				printf ("Parent process is running.\n");
				globVar++;
				var++;
				sleep (1);
			
			}

			printf ("Parent's globVar = %d, var = %d.\n", globVar, var);
			exit (0);
	
	}
	

	return EXIT_SUCCESS;
}

