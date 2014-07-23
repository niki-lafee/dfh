/*
 * =====================================================================================
 *
 *       Filename:  child_forkmore.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月23日 16时15分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lafee, wisdomandmircle@gmail.com
 *        Company:  Class 1301 of Software Engineering
 *
 * =====================================================================================
 */

//fork 两次
//fork 两次
//fork 两次

//原理:将子进程成为孤儿进程，从而其的父进程变为init进程，通过init进程可以处理僵尸进程。测试程序如下所示


#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	pid_t  pid;
	//创建第一个子进程
	pid = fork();
	if (pid < 0) {

		perror("fork error:");
		exit(1);
    
	}

	//第一个子进程
	else if (pid == 0) {

		//子进程再创建子进程
		printf("I am the first child process.pid:%d\tppid:%d\n",getpid(),getppid());
		pid = fork();

		if (pid < 0) {

			perror("fork error:");
			exit(1);

		}

		//第一个子进程退出
		else if (pid >0) {

			printf("first process is exited.\n");
			exit(0);
        
		}

		//第二个子进程
		//睡眠3s保证第一个子进程退出，这样第二个子进程的父亲就是init进程里
		sleep(3);
		printf("I am the second child process.pid: %d\tppid:%d\n",getpid(),getppid());
		exit(0);
    
		}

	//父进程处理第一个子进程退出
	if (waitpid(pid, NULL, 0) != pid) {
  
		perror("waitepid error:");
		exit(1);
	
	}

	exit(0);

	return EXIT_SUCCESS;

}
