/*
 * =====================================================================================
 *
 *       Filename:  test_umask.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月17日 10时11分24秒
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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	umask(0); 	//不屏蔽任何权限

	if (creat ("example_681.test", S_IRWXU|S_IRWXG|S_IRWXO) < 0) {
	
		perror ("creat");
		exit (1);
	
	}

	umask (S_IRWXO); 	//屏蔽其他用户所有权限

	if (creat ("example_682.test", S_IRWXU|S_IRWXG|S_IRWXO) < 0) {
	
		perror ("creat");
	
	}

	return EXIT_SUCCESS;
}
