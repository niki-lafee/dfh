/*
 * =====================================================================================
 *
 *       Filename:  secret_code.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月16日 20时34分37秒
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
//#define SECRET dfh1995

int main(void)
{
	char *keyptr;
	char *secret = "dfh1995";

	keyptr = getpass ("input the passwd :");

	//printf ("your passwd is : %s\n",keyptr);

	if (strcmp (secret, keyptr) == 0) {
	
		printf ("\nCan open the file~  \n");
		exit (1);
	
	}
	
	else  {
	
		printf ("\nPasswd error! can not open. \n");
		exit (0);
	
	}

}

