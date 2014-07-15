/*
 * =====================================================================================
 *
 *       Filename:  p104.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月14日 15时46分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lafee, wisdomandmircle@gmail.com
 *        Company:  Class 1301 of Software Engineering
 *
 * =====================================================================================
 */

//找出字符串中连续的数字且长度最长的子字符串
//找出字符串中连续的数字且长度最长的子字符串
//找出字符串中连续的数字且长度最长的子字符串
//找出字符串中连续的数字且长度最长的子字符串
//找出字符串中连续的数字且长度最长的子字符串

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findnumstring (char *, char  *);

int main(int argc, char *argv[])
{
	char *p = NULL, string[] = "sfsdf123456wew11sfc0123456789";
	int length = 0;

	p = (char *)malloc(strlen(string) + 1);
	length = findnumstring (p, string);

	printf ("The number string is:%s\nThe number string length = %d\n", p, length);

	return EXIT_SUCCESS;
}

int findnumstring (char *outputstr,char  *inputstr) {

	char *in = inputstr, *out = outputstr, *temp = NULL, *final = NULL;
	int count = 0, maxlen = 0, i = 0;

	while (*in) {
	
		if (*in > 47 && *in < 58) {
		
			for (temp  = in; *in < 58 && *in > 47; in++)
			      count ++;
		
		}

		else 
		      in++;

		if (maxlen < count) {
		
			maxlen = count;
			final = temp;
		
		}

		count = 0;
	
	}

	for (i = 0; i < maxlen; i++) {
	
		*out = *final;
	
		out++;
		final++;
	}

	*out = '\0';

	return maxlen;

}
