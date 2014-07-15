/*
 * =====================================================================================
 *
 *       Filename:  p139.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月14日 21时24分52秒
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

int func (int );

int main(int argc, char *argv[])
{
	int x;

	printf ("Please input x:\n");
	scanf ("%d", &x);
	printf ("Ruturn count:%d\n", func(x));
	
	return EXIT_SUCCESS;
}

int func (int x) {

	int count = 0;

	while (x) {
	
		count++;
		x = x & (x - 1);
	
	}

	return count;

}
