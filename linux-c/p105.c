/*
 * =====================================================================================
 *
 *       Filename:  p105.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月14日 19时28分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lafee, wisdomandmircle@gmail.com
 *        Company:  Class 1301 of Software Engineering
 *
 * =====================================================================================
 */

//将字符串对调并显示
//将字符串对调并显示
//将字符串对调并显示
//将字符串对调并显示
//将字符串对调并显示



#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char str[] = "dasfa3423xvxd";
	char *p, *q, *temp;
	int length = strlen (str);

	p = str;
	q = p + length - 1;

	while (p < q) {
	
		*temp = *p;
		*p = *q;
		*q = *temp;

		q--;
		p++;
	
	}

	printf ("The string is:%s\n", str);

	return EXIT_SUCCESS;
}

