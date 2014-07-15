/*
 * =====================================================================================
 *
 *       Filename:  p102.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月14日 11时46分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lafee, wisdomandmircle@gmail.com
 *        Company:  Class 1301 of Software Engineering
 *
 * =====================================================================================
 */


// 检验是否为递增数列
// 检验是否为递增数列
// 检验是否为递增数列
// 检验是否为递增数列
// 检验是否为递增数列

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judgement(int a[6], int n); 

int main(int argc, char *argv[])
{
	int a[6] = {1, 2, 3, 4, 5, 6};
	int b[6] = {1, 2, 7, 5, 3, 5};
	
	if (judgement(a, sizeof(a)/sizeof(a[0])) == 1) {
	
		printf ("a:YES!\n");
	
	}

	else {
	
		printf ("a:NO!\n");
	
	}

	if (judgement(b, sizeof(b)/sizeof(b[0])) == 1) {
	
		printf ("b:YES!\n");
	
	}

	else {
	
		printf ("b:NO!\n");
	
	}

	return EXIT_SUCCESS;
}

int judgement (int a[6], int n) {

	if (n == 1)
	      return 1;
	if (n == 2) 
	      return (a[n - 1] > a[n - 2]);
	return (a[n-1] > a[n - 2] && judgement (a, n - 1));

}
