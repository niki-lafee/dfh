/*
 * =====================================================================================
 *
 *       Filename:  my_mv.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月17日 10时23分09秒
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
	//检查参数个数
	if (argc < 3) {
	
		printf ("my_mv <old file> <new file>\n");
		exit (0);
	
	}

	if (rename (argv[1], argv[2]) < 0) {
	
		perror ("rename");
		exit (1);
	
	}

	return EXIT_SUCCESS;
}

