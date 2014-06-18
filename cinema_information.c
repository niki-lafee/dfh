/*
 * =====================================================================================
 *
 *       Filename:  cinema_information.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月18日 16时08分32秒
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
#include <time.h>

#define N sizeof(struct theater)

typedef struct theater {

	int screening_year;                  //影片上映时间-年               
	int screening_month;                 //影片上映时间-月
	int screening_day;                   //影片上映时间-日
	char name[20];                       //影片名称
	char director[20];                   //导演
	char type[20];                       //影片类型（喜剧，惊悚等）
	int time_hour;                       //影片时长-时
	int time_min;                        //影片时长-分
	int time_sec;                        //影片时长-秒
	int price;                           //影片价格

	struct theater *next;                //后继
	struct theater *pro;                 //前驱

}movie;

movie *creat ();                             //创建链表-录入信息
int open (FILE *fp);
int fpf (movie *head, FILE *fp);
int fsf (movie *head, FILE *fp);
void print (movie *head);
int quicksort ();
int secret_code ();
void seek_screening();
void seek_name ();
void seek_director();
void seek_time();
void seek_price();
int insert (movie *head);
int delete (movie *head);
int alter (movie *head);


 
int main(int argc, char *argv[])
{
	movie *head;
	FILE *fp;

	head = creat ();
	fpf (head, fp);
	fsf (haed, fp);
	print (head);

	return EXIT_SUCCESS;
}

movie *creat () {

	movie *head, *node1, *node2;
	char choice;

	head = node1 = malloc(N);

	printf ("/nPLease input the movie information(screening day,movie name, director, time,price):   /n");
	do {
	
		node2 = malloc(N);
		scanf ("%d%d%d%s%s%s%d%d%d%d", &node2->screening_year, &node2->screening_month, &node2->screening_day,
					       node2->name, noed2->director,_noed2->type,
					       &noed2->time_hour, &node2->time_min, &node2->time_sec,
					       &node2->price);
		node1->next = node2;
		node2->pro = node1;
		node2->next->pro = node2;
		node1->pro->next = node1;
		node1 = node2;
		
		printf ("\nDo you want to continue?(y/n) \n");
		getchar();
		scanf ("%c", &choice);
	
	}while (choice == 'y' || choice == 'Y');

	node1->next = NULL;

	return head;

}

int open (FILE *fp) {

	if (fp == NULL) {
	
		printf ("\nCan not open! \n");
		exit (0);
	
	}

	else 
	      return 1;

}

int fpf (movie *head, FILE *fp) {

	movie *node;

	node  = head->neat;

	fp = fopen ("cinema_information", "wt");

	open (fp);

	while (node != NULL) {
	
		fprintf (fp, "%-d-%-d-%-d\t%10s%10s%10s\t%d.%d.%d\t%d\n", node->screening_year, node->screening_month, node->screening_day,
					                                  node->name, noed->director,_noed->type,
					       				  noed->time_hour, node->time_min, node->time_sec,
					       				  node->price);
	
		node = node->next;
	}

	fclose (fp);
}

int fsf (movie *head, FILE *fp) {

	movie *node;

	node = head->next;

	fp = fopen ("cinema_information", "rt");

	open (fp);

	while (node != NULL) {
	
		fsacnf (fp, "%-d-%-d-%-d\t%10s%10s%10s\t%d.%d.%d\t%d\n", &node->screening_year, &node->screening_month, &node->screening_day,
					                                 node->name, noed->director,_noed->type,
					       				 &noed->time_hour, &node->time_min, &node->time_sec,
					       				 &node->price);
	
		node  = node->next;
	}

	fclose (fp);

}

void print (movie *head) {

	movie *node;

	node = head->next;

	while (node != NULL) {

		printf ("%-d-%-d-%-d\t%10s%10s%10s\t%d.%d.%d\t%d\n", node->screening_year, node->screening_month, node->screening_day,
					                             node->name, noed->director,_noed->type,
					       	 	             noed->time_hour, node->time_min, node->time_sec,
					       		             node->price);
	
		node = node->next;
	}

}

int secret_code () {

	

}
