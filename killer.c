/*
 * =====================================================================================
 *
 *       Filename:  killer.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月11日 23时58分20秒
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
#include <math.h>

int main(int argc, char *argv[])
{

	int i, flag, sum;
	char killer;

	for (i = 0; i < 4; i++) {
	
		flag = 0;

		killer = 64 + i;
		sum = (killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D');

		if (sum == 3) {
		
			printf ("killer is %c\n", killer);
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
	
		printf ("no killer!\n");
	
	}
	return EXIT_SUCCESS;
}

