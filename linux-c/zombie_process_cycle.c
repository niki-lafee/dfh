/*
 * =====================================================================================
 *
 *       Filename:  zombie_process_1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月23日 15时27分56秒
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
	pid_t  pid;
     	//循环创建子进程
     	while(1)
     	{
		pid = fork();

		if (pid < 0) {
             	
			perror("fork error:");
         	  
			exit(1);
         	
		}
 
		else if (pid == 0) {

			printf("I am a child process.\nI am exiting.\n");
			//子进程退出，成为僵尸进程
			exit(0);

         	}

		else {

			//父进程休眠20s继续创建子进程
			sleep(20);
			//输出进程信息
			system("ps -o pid,ppid,state,tty,command");
			continue;
         
		}

		//输出进程信息
		//system("ps -o pid,ppid,state,tty,command");
     
	}

	return EXIT_SUCCESS;

}

