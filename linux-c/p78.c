/*
 * =====================================================================================
 *
 *       Filename:  p78.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月14日 18时59分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lafee, wisdomandmircle@gmail.com
 *        Company:  Class 1301 of Software Engineering
 *
 * =====================================================================================
 */


//找出3个数中最大的一个
//找出3个数中最大的一个
//找出3个数中最大的一个
//找出3个数中最大的一个
//找出3个数中最大的一个



#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_max (int, int);
int get_leadermax (int, int, int, int (*p)(int, int));

int main(int argc, char *argv[])
{
	int a, b, c, max;

	printf ("Please input a,b,c:\n");
	scanf ("%d%d%d", &a, &b, &c);

	max = get_leadermax (a, b, c, get_max);

	printf ("The max is:%d\n", max);

	return EXIT_SUCCESS;
}

int get_max (int a, int b) {

	return (a > b ? a : b);

}

int get_leadermax (int a, int b, int c, int (*p)(int, int)) {

	int max;

	max = p (a, b);
	max = p (max, c);

	return max;

}
