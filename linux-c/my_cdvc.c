/*
 * =====================================================================================
 *
 *       Filename:  my_cdvc.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月17日 10时52分15秒
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
#include <linux/limits.h>
#include <errno.h>

//自定义的错误处理函数
void my_err (const char *err_string, int line) {

	fprintf (stderr, "line: %d", line);
	perror (err_string);

	exit (1);

}

int main(int argc, char *argv[])
{
	char buf[PATH_MAX + 1];

	if (argc < 2) {
	
		printf ("my_cd <target path>\n");

		exit (1);
	
	}

	if (chdir (argv[1]) < 0) {
	
		my_err ("chdir", errno);
	
	}

	if (getcwd (buf, 512) < 0) {
	
		my_err ("getcwd", errno);
	
	}

	printf ("%s\n", buf);

	return EXIT_SUCCESS;
}

