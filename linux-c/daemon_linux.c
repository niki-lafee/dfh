/*
 * =====================================================================================
 *
 *       Filename:  daemon_linux.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 11时41分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lafee, wisdomandmircle@gmail.com
 *        Company:  Class 1301 of Software Engineering
 *
 * =====================================================================================
 */
#pragma inline

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/param.h>
#include <time.h>
#include <sys/stat.h>
#include <syslog.h>
#include <signal.h>

int init_daemon (void);

int main(int argc, char *argv[])
{
	time_t now;
	init_daemon ();
	syslog (LOG_USER|LOG_INFO, "测试守护进程!\n");
	while (1) {
	
		sleep (8);
		time (&now);
		syslog (LOG_USER|LOG_INFO, "系统时间：\t%s\t\t\n", ctime(&now));
	
	}
	
	return EXIT_SUCCESS;
}

int init_daemon (void) {

	int pid;
	int i;

	/*忽略终端I/O信号，STOP信号*/
	signal (SIGTTOU, SIG_IGN);
	signal (SIGTTIN, SIG_IGN);
	signal (SIGTSTP, SIG_IGN);
	signal (SIGHUP, SIG_IGN);

	pid = fork ();
	if (pid > 0) {
	
		exit (0); 	/*结束父进程，使得子进程成为后台进程*/
	
	}

	else if (pid < 0) {
	
		return -1;
	
	}

/*建立一个新的进程组，在这个新的进程组中，子进程成为这个进程的首进程，使该进程脱离所有终端*/
	setsid ();

/*再次新建一个子进程，退出父进程，保证该进程不是进程组长，同时让该进程无法再打开新的终端*/
	pid = fork ();
	if (pid > 0) {

		exit (0);
	
	}

	else if (pid < 0) {
	
		exit (0);
	
	}

	/*关闭所有从父进程继承的不再需要的文件描述符*/
	for (i = 0; i < NOFILE; close (i++));

	/*改变工作目录，使得文件系统不与任何文件系统联系*/
	chdir ("/");

	/*将文件屏蔽字设置为'0'*/
	umask (0);

	/*忽略SIGCHLO信号*/
	signal (SIGCHLD, SIG_IGN);

	return 0;

}
