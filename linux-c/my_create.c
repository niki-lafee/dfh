/*
 * =====================================================================================
 *
 *       Filename:  my_create.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月15日 11时43分41秒
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

int main(int argc, char *argv[])
{
	int fd;

	if ((fd = open ("example_62.c", O_CREAT|O_EXCL, S_IRUSR| S_IWUSR)) == -1) {
	
		//perror ("open");
		printf ("open: %s with errno:%d\n", strerror(errno), errno);
		exit (1);
	
	}

	else {
	
		printf ("creat file success!\n");
	
	}

	close (fd);

	return EXIT_SUCCESS;
}

