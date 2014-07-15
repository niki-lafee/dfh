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

#define SF "%d%d%d%s%s%s%d%d%d%d", &node->screening_year, &node->screening_month, &node->screening_day,node->name, node->director, node->type,&node->time_hour,&node->time_min, &node->time_sec,&node->price

#define PF "% -d  -%-d-%-d\t%10s%10s%10s\t%d.%d.%d\t%d\n", node->screening_year, node->screening_month, node->screening_day,node->name, node->director, node->type,node->time_hour, node->time_min, node->time_sec, node->price

#define DF "%d%d%d%s%s%s%d%d%d%d", &node_insert->screening_year, &node_insert->screening_month, &node_insert->screening_day,node_insert->name, node_insert->director, node_insert->type,&node_insert->time_hour, &node_insert->time_min, &node_insert->time_sec, &node_insert->price

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
int open (FILE *fp);                         //判断文件是否为空
int fpf (movie *head, FILE *fp);             //文件写入
int fsf (movie *head, FILE *fp);             //文件读取
void print (movie *head);                    //打印影片信息
//movie *point (movie *left, movie *right);    //找到分割点
//int swap (movie *l, movie *r);               //交换结点
//void quicksort (movie *left, movie *right);  //排序影片信息
int secret_code ();                          //密码保障
int seek (movie *head);                      //查找
int seek_screening(movie *head);             //查找-上映日期
int seek_name (movie *head);                 //查找-电影名称
int seek_director(movie *head);              //查找-影片导演
int seek_time(movie *head);                  //查找-影片时长
int seek_price(movie *head);                 //查找-影片价格
int insert (movie *head);                    //插入影片
int del_name (movie *head); 		     //删除相同的
//int delete (movie *head);                    //删除影片
//int alter (movie *head);                     //修改影片信息
 
int main(int argc, char *argv[])
{
	movie *head, *left, *right;
	FILE *fp;

	head = creat ();

	left = head->next;
	right = head->pro;

	quicksort (left, right);
	print (head);
	insert (head);
	del_same (head);
	fpf (head, fp);
	fsf (head, fp);
	print (head);
	seek (head);

	return EXIT_SUCCESS;
}

//创建链表-录入信息
movie *creat () {

	movie *head, *node1, *node2;
	char choice;

	head = node1 = malloc(N);
	head->next = head;
	head->pro = head;

	printf ("\n PLease input the movie information(screening day,movie name, director, type, time,price):   \n");
	do {
	
		node2 = malloc(N);

		scanf ("%d%d%d%s%s%s%d%d%d%d", &node2->screening_year, &node2->screening_month, &node2->screening_day,node2->name,
					       node2->director, node2->type,&node2->time_hour, &node2->time_min, &node2->time_sec,
					       &node2->price);

		
		node2->next = head;
		head->pro = node2;
		node2->pro = node1;
		node1->next = node2;
		node1 = node2;
		
		printf ("\nDo you want to continue?(y/n) \n");
		getchar();
		scanf ("%c", &choice);
	
	}while (choice == 'y' || choice == 'Y');

//	node1->next = NULL;

	return head;

}

//检验文件是否为空
int open (FILE *fp) {

	if (fp == NULL) {
	
		printf ("\nCan not open! \n");
		exit (0);
	
	}

	else 
	      return 1;

}

//文件信息写入
int fpf (movie *head, FILE *fp) {

	movie *node;

	node  = head->next;

	fp = fopen ("cinema_information", "wt");

	open (fp);

	while (node != head) {
	
		fprintf (fp, PF);
	
		node = node->next;
	}

	fclose (fp);
}

//文件信息录入
int fsf (movie *head, FILE *fp) {

	movie *node;

	node = head->next;

	fp = fopen ("cinema_information", "rt");

	open (fp);

	while (node != head) {
	
		fscanf (fp, PF);
	
		node  = node->next;

	}

	fclose (fp);

}

//打印模块信息
void print (movie *head) {

	movie *node;

	node = head->next;

	while (node != head) {

		printf (PF);
	
		node = node->next;

	}

}

//密码设置-安全保障
int secret_code () {

	char *passwd;
	char *secret = "dfh1995";

	passwd = getpass ("\nPlease input the passwd:");

	if (strcmp (passwd, secret) == 0) {
	
		printf ("\nopen! \n");
		return 1;
	
	}

	else 
	      printf ("\nPasswd error!Please try again! \n");

	return 0;

}

//查询影片信息 
int seek (movie *head) {

	int choose;
	char choice;

	do {
		printf ("***************************************************************************************\n");
		printf ("********************************************************");
		printf ("\n     **    1.Seek screening time 		**\n");
 		printf ("     **    2.Seek the movie name 		**\n ");
		printf ("    **    3.Seek the director of the movie     **\n");
                printf ("     **    4.Seek the movie time 		**\n");
		printf ("     **    0.exit 				**\n");
		printf ("********************************************************\n");
		printf ("***************************************************************************************\n");
		printf ("Please choose you want to seek:");
		scanf ("%d", &choose);
		printf ("\n");

		switch (choose) {
		
			case 1: seek_screening (head);break;
			case 2: seek_name (head);     break;
			case 3: seek_director (head); break;
			case 4: seek_time (head);     break;
			case 0:                       break;
		
		}

		printf ("\nDo you want to continue?(y/n)\n:");
		getchar();
		scanf ("%c", &choice);

	} while (choice == 'y' || choice == 'Y');

	return 1;

}

//查询影片信息-上映日期
int seek_screening (movie *head) {

	movie *node;
	int day_year, day_month, day_date, flag = 0;

	node = head->next;

	printf ("\nPlease input the screening day of the movie:");
	scanf ("%d%d%d", &day_year, &day_month, &day_date);

	while (node != head) {
	
		if (node->screening_year == day_year && node->screening_month == day_month && node->screening_day == day_date) {
		
			printf ("\nThe move is:");
			printf (PF);
		
			flag = 1;
		}

		node = node->next;
	
	}

	if (flag == 1) {
		
		return 1;
	
	}

	else {

		printf ("\nCan not found! Please try again!\n");

		return 0;
	}

}

//查询影片信息-名称
int seek_name (movie *head) {


	movie *node;
	char names[20];
	int flag = 0;

	node = head->next;

	printf ("\nPlease input the movie name:");
	scanf ("%s", names);

	while (node != head) {
	
		if (strcmp(node->name,names) == 0) {
		
			printf ("\nThe movie is:");
			printf (PF);
		
			flag = 1;
		}

		node = node->next;
	
	}

	if (flag == 1) {
	
		return 1;
	
	}
	
	else {

		printf ("\nCan not found! Please try again! \n");
		
		return 0;

	}

}

//查询影片信息-导演
int seek_director (movie *head) {

	movie *node;
	char direc[20];
	int flag = 0;

	node = head->next;

	printf ("\nPlease input the screenint day of the movie:");
	scanf ("%s", direc);

	while (node != head) {
	
		if (strcmp(node->director,direc) == 0) {
		
			printf ("\nThe movie is:");
			printf (PF);
		
			flag = 1;
		}

		node = node->next;
	
	}

	if (flag == 1) {
	
		return 1;
	
	}

	else {
	
		printf ("\nCan not found! Please try again! \n");

		return 0;
	
	}
	
}

//查询影片信息-时长
int seek_time (movie *head) {

	movie *node;
	int hour, min, sec, flag = 0;

	node = head->next;

	printf ("\nPlease input the time of the movie:");
	scanf ("%d%d%d", &hour, &min, &sec);

	while (node != head) {
	
		if (node->time_hour == hour && node->time_min == min && node->time_sec == sec) {
		
			printf ("\nThe movie is:");
			printf (PF);
		
			flag = 1;
		}

		node = node->next;
	
	}

	if (flag == 1) {
	
		return 1;
	
	}

	else {
	
		printf ("\nCan not found! Please try again! \n");

		return 0;
	}

}

int insert (movie *head) {

	int flag;
	char choice;
	movie *node, *node_insert;

	node = head->next;

	printf ("\nIf you want to insert,please key in your password!\n");

	flag = secret_code();

	if (flag == 1) {

		do {
			node_insert = malloc(N);

			printf ("\nPlease input the movie you want to insert:\n");
			scanf (DF);
			printf ("%d", node_insert->price);
	
			while (node != head && node_insert->screening_year < node->screening_year &&
					       node_insert->screening_month < node->screening_month && 
					       node_insert->screening_day < node->screening_day) {
		
				node = node->next;
		
			}
	
			node_insert->pro = node->pro;
			node->pro->next = node_insert;
			node_insert->next = node;
			node->pro = node_insert;

			printf ("\nDo you  want to continue?(y/n)");
			getchar();
			scanf ("%c", &choice);
	
		}while (choice == 'y' || choice == 'Y');

	}

	return 0;

}

int del_same (movie *head) {

	movie *node1, *node2, *temp;

	node1 = head->next;

	while (node1 != head) {
	
		node1 = node1->next;
		node2 = node1->next;

		while (node2 != head) {
		
			temp = node2;

			if (node1->screening_year == node2->screening_year && node1->screening_month == node2->screening_month &&
			    node1->screening_day == node2->screening_day && node1->time_hour == node2->time_hour &&
			    node1->time_min == node2->time_min && node1->time_sec == node2->time_sec &&
			    (strcmp(node1->name, node2->name) == 0) && (strcmp(node1->director, node2->director) == 0) &&
			    (strcmp(node1->type, node2->type) == 0) && node1->price == node2->price) {
			
				node2 = node2->next;

				temp->pro->next = temp->next;
				temp->next->pro = temp->pro;
				free (temp);
			}
		
			else {

				node2 = node2->next;

			}
		}
	
	}

	return 1;

}


movie *point (movie *left, movie *right) {
puts("aaa");
	movie *key, *orgin, *r, *l, *node1, *node2;

	key = left;
	orgin = left;

	while (left != right || left->next != right) {
	
		l = left;
		r = right;

		while (right->screening_year > key->screening_year && (left != right || left->next != right)) {
		
			right = right->pro;
		
		}

		if (right->screening_month <= key->screening_month && right->screening_year <= key->screening_year && (left != right || left->next != right)) {
		
			if (right->screening_day <= key->screening_day && (left != right || left->next != right)) {
			
				swap(l, r);
			
			}

			else {
				while (right->screening_year > key->screening_year && 
				       right->screening_month > key->screening_month &&
				       (left != right || left->next != right)) {
			 
					right = right->pro;

				}

				if (right->screening_day <= key->screening_day ) {
				
					swap(l, r);
				
				} 

				else {
				
					while (right->screening_year > key->screening_year && 
				       	       right->screening_month > right->screening_month &&
					       right->screening_day > key->screening_day &&
				               (left != right || left->next != right)) {
					
						right = right->pro;
					
					}
		
					swap (l, r);
				}

			}

		}

		else {
		
			swap(l, r);
			
		}

		r = right;
		l = left;

		while (left->screening_year < key->screening_year && (left != right || left->next != right)) {
		
			left = left->next;
		
		}

		if (left->screening_month >= key->screening_month && (left != right || left->next != right)) {
		
			if (left->screening_day >= key->screening_day && (left != right || left->next != right)) {
			
				swap(l, r);
			
			}

			else {

				while (left->screening_year < key->screening_year && 
				       left->screening_month < key->screening_month &&
				       (left != right || left->next != right)) {
			 
					left = left->next;

				}

				if (left->screening_day >= key->screening_day ) {
				
					swap(l, r);
				
				} 

				else {
				
					while (left->screening_year < key->screening_year && 
				       	       left->screening_month < key->screening_month &&
					       left->screening_day < key->screening_day &&
				               (left != right || left->next != right)) {
					
						right = right->pro;
					
					}
				
					swap(l, r);
				
				}
		
			}

		}

		else {
		
			swap (l, r);
		}
		

	}

	left = orgin;

	return left;

}

int swap (movie *l, movie *r) {

	movie *node1, *node2;

	node2 = r->next;
	node1 = l->pro;
	r->pro = l->pro;
	l->pro->next = r;
	r->next = l->next;
	l->next->pro = r;
	l->next = node2;
	node2->pro = l;
	l->pro = node1;

	return 1;

}

void quicksort (movie *left, movie *right) {

	movie *pointkey;

	if (left == right || left->next == right) {

	      return;

	}

	pointkey = point;
	quicksort (left, point);
	quicksort (point, right);

}
