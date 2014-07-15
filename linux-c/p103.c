/*
 * =====================================================================================
 *
 *       Filename:  p103.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月14日 15时11分28秒
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

char *retmemory ();

int main(int argc, char *argv[])
{
	char *str = NULL;

	str = retmemory ();

//	printf ("%s\n", str);
//	printf (str);
	puts (str);

	return EXIT_SUCCESS;
}

char *retmemory () {

	char *p = "hello world";

	return p;
}
