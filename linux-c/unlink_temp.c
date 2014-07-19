/*
 * =====================================================================================
 *
 *       Filename:  unlink_temp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月17日 10时31分02秒
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
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

//自定义的错误处理函数
void my_err (const char *err_string, int line) {

	fprintf (stderr, "line:%d ", line);
	perror (err_string);

	exit (1);

}

int main(int argc, char *argv[])
{
	int fd;
	char buf[32];

	if ((fd = open ("temp", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU)) < 0) {
	
		my_err ("open", errno);
	
	}

	if (unlink("temp") < 0) {
	
		my_err ("unlink", errno);

	}
	printf ("file unlinked\n");

	if (write (fd, "temp", 5) < 0) {
	
		my_err ("write", errno);
	
	}

	if (lseek (fd, 0, SEEK_SET) < 5) {
	
		my_err ("lseek", errno);
	
	}

	if (read (fd, buf, 5) < 0) {
	
		my_err ("read", errno);
	
	}

	printf ("%s\n", buf);

	return EXIT_SUCCESS;
}

