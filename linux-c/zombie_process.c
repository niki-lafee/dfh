/*
 * =====================================================================================
 *
 *       Filename:  zombie_process.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月23日 15时13分36秒
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

int main(int argc, char *argv[])
{
	pid_t pid;
 	pid = fork();
 
	if (pid < 0) {

        	perror("fork error:");
	        exit(1);

    	}

	else if (pid == 0) {

		printf("I am child process.I am exiting.\n");
	        exit(0);

	}

	printf("I am father process.I will sleep two seconds\n");
	//等待子进程先退出
	sleep(2);
	//输出进程信息
	system("ps -o pid,ppid,state,tty,command");
	printf("father process is exiting.\n");
	
	return EXIT_SUCCESS;

}
