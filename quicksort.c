/*
 * =====================================================================================
 *
 *       Filename:  quicksort.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月12日 10时55分01秒
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
#define N 100

int input ();
void output (int s[N], int n);
void quicksort (int left, int right, int s[N]);


int main(int argc, char *argv[])
{

	int i, j, n, s[N];

	printf ("How many numbers do you want to sort?\n");
	scanf ("%d", &n);

	printf ("Please input the numbers:\n");
	for (i = 0; i < n; i++) {
	
		s[i] = input ();
	
	}
	
	printf ("\nBefore sorting\n");
	output (s, n);

	quicksort (0,n - 1,s);

	printf ("\nAfter sorting\n");
	output (s, n);

	return EXIT_SUCCESS;
}

int input () {

	int number;

	scanf ("%d", &number);

	return number;

}

void output (int s[N],int  n) {

	int i;

	for (i = 0; i < n; i++) {
	
		printf ("%-5d", s[i]);
	
	}

	printf ("\n");

}

void quicksort (int left, int right, int s[N]) {

	int i, j, length, key;

	i = left;
	j = right;
	key = s[left];
	length = right - left;

	if (length < 1)   return;

	while (i < j ) {
	
		while (s[j] >= key && i < j) {
	puts("lll");	
			j--;
		}
		s[i] = s[j];

		while (s[i] <= key && i < j) {
	puts("lll");
			i++;

		}
		s[j] = s[i];

	}

	s[i] = key;

	quicksort (left, i - 1, s);
	quicksort (i + 1, right, s);

}
