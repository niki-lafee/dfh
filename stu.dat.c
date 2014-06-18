/*
 * =====================================================================================
 *
 *       Filename:  stu.dat1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月11日 03时53分55秒
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
#define N 3

typedef struct{

//	int num;
//	char name[20];
	int tech;
	int math;
	int eng;

}STU;

STU input ();
void output (STU stu[N]);
int test (FILE *fp);
int fpf (STU stu[N], FILE *fp);
int fsf (STU stu[N], FILE *fp);

int main(int argc, char *argv[])
{
	int i, j, k;
	FILE *fp;
	STU stu[N];
 
	for (i = 0; i < N; i++) {
	
		stu[i] = input();
	
	}
puts("111");
	fpf (stu, fp);
puts("222");	
	fsf (stu, fp);
puts("333");
	output (stu);
	
	return EXIT_SUCCESS;
}

STU input () {

	STU stu;

	printf ("Please input the information:\n");
	scanf ("%d%d%d", &stu.tech, &stu.math, &stu.eng);

	return stu;

}

int test (FILE *fp) {

if (fp == NULL) {
		
		printf ("Can not open~:\n ");
		exit (0);
	}

	else 
	      return (1);

}

int fpf (STU stu[N], FILE *fp) {

	int i;

	fp = fopen ("stu.dat", "wt");

	test (fp);

	for (i = 0; i < N; i++) {
	
		fprintf (fp, "%d,%d,%d\n", stu[i].tech, stu[i].math, stu[i].eng);
	
	}

	return (1);


}

int fsf (STU stu[N], FILE *fp) {

	int i;

	fp = fopen ("stu.dat", "rt");

	test (fp); 
	
	for (i = 0; i < N; i++) {
	
		fscanf (fp, "%d,%d,%d\n", &stu[i].tech,&stu[i].math, &stu[i].eng);
	
	}

	return 1;

}

void output(STU stu[N]) {

	int i;

	for (i = 0; i < N; i++) {
	
		printf ("%d,%d,%d\n", stu[i].tech, stu[i].math, stu[i].eng);
	
	}
									
}
