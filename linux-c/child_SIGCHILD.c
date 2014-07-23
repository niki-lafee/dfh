/*
 * =====================================================================================
 *
 *       Filename:  SIGCHILD.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月23日 16时00分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lafee, wisdomandmircle@gmail.com
 *        Company:  Class 1301 of Software Engineering
 *
 * =====================================================================================
 */

//通过信号机制
//通过信号机制
//通过信号机制

//子进程退出时向父进程发送SIGCHILD信号，父进程处理SIGCHILD信号。在信号处理函数中调用wait进行处理僵尸进程


#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

static void sig_child(int signo);
 
int main(int argc, char *argv[])
{
	pid_t pid;

	//创建捕捉子进程退出信号
	signal(SIGCHLD,sig_child);
	pid = fork();

	if (pid < 0) {

		perror("fork error:");
		exit(1);

	}

	else if (pid == 0) {
        
		printf("I am child process,pid id %d.I am exiting.\n",getpid());
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
 
static void sig_child(int signo)
{ 
	pid_t pid;
	int stat;

	//处理僵尸进程
	while ((pid = waitpid(-1, &stat, WNOHANG)) >0) {

		printf("child %d terminated.\n", pid);

	}

}

