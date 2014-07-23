/*
 * =====================================================================================
 *
 *       Filename:  unixp2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 14时42分17秒
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
	int c;
	while ((c = getchar ()) != EOF) {
	
		putchar (c);
	
	}

	return EXIT_SUCCESS;
}

