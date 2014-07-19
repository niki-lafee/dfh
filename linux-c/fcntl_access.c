/*
 * =====================================================================================
 *
 *       Filename:  fcntl_access.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月16日 11时04分36秒
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
#include <errno.h>

//自定义的错误处理函数
void my_err (const char *err_string, int line) {

	fprintf (stderr, "line:%d ", line);
	perror (err_string);

	exit (1);

}

int main(int argc, char *argv[])
{
	int ret;
	int access_mode;
	int fd;

	if ((fd = open ("example_64", O_CREAT|O_TRUNC|O_RDWR, S_IRWXU)) == -1) {
	
		my_err ("open", errno);
	
	}

	//设置文件打开方式
	if ((ret = fcntl (fd, F_SETFL, O_APPEND)) < 0) {
		
		my_err ("fcntl", errno);
	
	}

	//获取打开方式
	if ((ret = fcntl (fd, F_GETFL, 0)) < 0) {
	
		my_err ("fcntl", errno);
	
	}

	access_mode = ret & O_ACCMODE;

	if (access_mode == O_RDONLY) {
	
		printf ("example_64 access mode: read only");
	
	}

	else if (access_mode == O_WRONLY) {
	
		printf ("example_64 access mode: write only");
	
	}

	else if (access_mode == O_RDWR) {
	
		printf ("example_64 access mode: read + write");
	
	}

	if (ret & O_APPEND) {
	
		printf (" ,append\n");
	
	}
	printf ("ret1:%d\n", ret);
	printf ("append:%d\n", O_APPEND);
	printf ("O_APPEND:%d\n", (ret & O_APPEND));

	if (ret & O_NONBLOCK) {
	
		printf (" ,nonblock\n");
	
	}
	printf ("ret2:%d\n", ret);
	printf ("nonblock:%d\n", O_NONBLOCK);
	printf ("O_NONBLOCK:%d\n", (ret & O_NONBLOCK));

	if (ret & O_SYNC) {
	
		printf (" ,sync\n");
	
	}
	printf ("sync:%d\n", O_SYNC);
	printf ("O_SYNC:%d\n", (ret & O_SYNC));

	printf ("\n");

	return EXIT_SUCCESS;
}

