/*
 * =====================================================================================
 *
 *       Filename:  orphaned_process.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月23日 15时05分06秒
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
#include <errno.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	//创建一个进程
	pid = fork();

	//创建失败
	if (pid < 0) {

        	perror("fork error:");
        	exit(1);

	}

	//子进程
	if (pid == 0) {

        	printf("I am the child process.\n");
        	//输出进程ID和父进程ID
	        printf("pid: %d\tppid:%d\n",getpid(),getppid());
        	printf("I will sleep five seconds.\n");
        	//睡眠5s，保证父进程先退出
        	sleep(5);
        	printf("pid: %d\tppid:%d\n",getpid(),getppid());
        	printf("child process is exited.\n");
	}

	//父进程
	else {
        
		printf("I am father process.\n");
        	//父进程睡眠1s，保证子进程输出进程id
        	sleep(1);
        	printf("father process is  exited.\n");

	}
	
	return EXIT_SUCCESS;

}
