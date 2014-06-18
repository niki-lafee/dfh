/*
 * =====================================================================================
 *
 *       Filename:  test_file1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月16日 23时09分08秒
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
#include "test_file2.c"

int main(int argc, char *argv[])
{
	int m,a,b;
	int max(int a,int b);
	a=10;
	b=20;
	m=max(a,b);
	printf("%d",m);

	return EXIT_SUCCESS;
}

