//超市管理系统


#include <stdio.h>

#include <stdlib.h>

#include <io.h>

#define MAX 20

#define N 3

#define PAGE 3

//日期
typedef struct {

	int year;
	int month;
	int day;

}DATE;

//商品类型
typedef struct {

	int num;	//商品号
	char name[20];  //名称
	char kind[10];  //类型
	DATE pro_time;  //生产日期
	int save_day;	//保质期

}GOODS;

int read_file (GOODS goods[]);
void save_file (GOODS goods[], int sum);
int input (GOODS goods[]);			//输入模块
void output (GOODS goods[], int sum);		//输出
void append();					//添加信息模块
void modify (GOODS goods[], int sum);
void delete ();
void inquire ();				//查询
void count ();					//信息统计
void sort (GOODS goods[], int sum);

void main() {

	GOODS goods[MAX];
	int choice, sum;
	
	sum = read_file(goods);

	if (sum == 0) {

		printf ("Key in the goods information~********\n");
		getchar();
		sum = input (goods);

	}

	do {

		clrscr();

		printf ("\n\n		**********the managed system of supermarket***********");

		printf ("	1.Append the goods information	\n\n");
		printf ("	2.Modify the goods information	\n\n");
		printf ("	3.Delete the goods information	\n\n");
		printf ("	4.Print the informationof stock goods	\n\n");
		printf ("	5.Inquire the goods information	\n\n");
		printf ("	6.Count the goods information	\n\n");
		printf ("	7.Sort the goods information	\n\n");
		printf ("	0.Exit the system of goods information	\n\n");
		
		printf ("	Please choose that you want(0~7):");
		
		scanf ("%d", &choice);	

		switch (choice)	{

			case 1:append();
			       break;
			case 2:modify(goods, sum);
		       	       break;
			case 3:delete();
			       break;
			case 4:output(goods, sum);
			       break;
			case 5:inquire();
			       break;
			case 6:count();
			       break;
			case 7:sort(goods, sum);
			       break;
			case 0:break;

		}

	   }while (choice != 0);

	save_file(goods, sum);

}

int read_file (GOODS goods[]) {

	FILE *fp;

	int i = 0;

	if ((fp = fopen("supermarket.txt","rt")) == NULL) {

		printf ("\n\n***can not open!!!*** please create~");
		return 0;

	}	

	while (feof(fp) != 1) {

		fread (&goods[i], sizeof(GOODS), 1, fp);
		if (goods[i].num == 0)
			break;
		else
			i++;

	}

	fclose(fp);
	
	return i;

}

void save_file (GOODS goods[], int sum) {

	FILE *fp;
	
	int i;

	if ((fp = fopen("supermarket.txt", "wb")) == NULL) {

		printf ("error! can not find!\n");
		return ;

	}

	for (i = 0; i < sum; i++) {

		if (fwrite(&goods[i],sizeof(GOODS), 1, fp) != 1)
			printf ("error!\n");

	}

	fclose (fp);

}
//输入模块
int input (GOODS goods[]) {

	int i = 0;
	
	system("clear");

	printf ("\n\n	key in the foods information (the max %d)", MAX);

	printf ("	-----------------------------------\n");

	do {

		printf ("\n	the information of %d ", i + 1);
		printf ("\n	the num ;");
		scanf ("%d", &goods[i].num);
		
		if (goods[i].num == 0)
			break;

		printf ("\n	the name of goods:");
		scanf ("%s", goods[i].name);
		printf ("\n	the kind of goods:");
		scanf ("%s", goods[i].kind);
		printf ("\n	the pro_time(yyyy_mm_dd):");
		scanf ("%d-%d-%d", &goods[i].pro_time.year, &goods[i].pro_time.month, &goods[i].pro_time.day);
		printf ("\n	the best-before day of goods:");
		scanf ("%d", &goods[i].save_day);

		i++;

	}while (i < MAX);

	printf ("\n	The number of goods is %d,which have input over", i);
	printf ("\n	Please press an uncoditional key to return home page!");
	
	getchar();
	
	return i;

}

// 输出
void output (GOODS goods[], int sum) {

	int i = 0, j = 0, page = 1;

	system(clear);

	printf ("\n\n	--------the information of goods--------	the page of %d",page);	
	printf ("the goods num---goods name---goods kind---goods pro_time(yyyy_mm_dd)---the goods best-before day\n");
	printf ("-------------------------------------------------------------------------------\n");
	
	do {

		if (goods[i].num != 0) {

			j++;
			if (j % PAGE != 0) {

				printf ("%4d%8s%15d-%2d-%2d%10d\n", goods[i].num, goods[i].name, goods[i].kind,
								    goods[i].pro_time.year,
								    goods[i].pro_time.month,
								    goods[i].pro_time.day,
								    goods[i].save_day);

				printf ("--------------------\n");				

			}
		
			else {

				printf ("please press an unconditional key to continue~");

				getch();
				clrscr();

				printf ("\n\n	---the information of goods---		the page is %d", ++page);
				printf ("-----------------------------------\n");
				printf ("%4d%8s%15d-%2d-%2d%10d\n", goods[i].num, goods[i].name, goods[i].kind,
								    goods[i].pro_time.year,
								    goods[i].pro_time.month,
								    goods[i].pro_time.day,
								    goods[i].save_day);

				printf ("----------------------------------\n");
				
			}

		}

		i++;

	}while (goods[i].num != 0);

	printf ("please press an unconditional key to return to the home page~");

	getchar();

}

//添加信息模块
void attend() {
	;
}

//修改模块信息
void modify (GOODS goods[], int sum) {

	int i = 0, choice, modify_num, flag;

	do {

		system("clear");

		printf ("\n	please input the goods information yoi want to modify:");
		scanf ("%d", &modify_num);
		
		for (i = 0; i < sum; i++) 
			if (goods[i].num == modify_num) {

				printf ("\n	---the information of goods---\n");
				printf ("the goods num---the goods name---the goods kind---the goods pro_time(yyyy_mm__dd)---the goods est-before day\n");
				printf ("----------------------------\n");
				printf ("%4d%8s%15d-%2d-%2d%10d\n", goods[i].num, goods[i].name, goods[i].kind,
								    goods[i].pro_time.year,
								    goods[i].pro_time.month,
								    goods[i].pro_time.day,
								    goods[i].save_day);

				printf ("\n	what kinds of goods do you want to modity?\n");
				printf ("\n	1.name\n");
				printf ("\n	2.kind\n");
				printf ("\n	3.pro_time\n");
				printf ("\n	4.the best-before day\n");
				printf ("\n	please choose (1~4):");
				scanf ("%d", &choice);

				switch (choice) {

					case 1: printf ("\n	the name that after moditying:");
						scanf ("%s", goods[i].name);
						break;
					case 2: printf ("\n	the kind that after moditying:");
						scanf ("%s", goods[i].kind);
						break;
					case 3: printf ("\n	the pro_time that after modifying:");
						scanf ("%d-%d-%d", &goods[i].pro_time.year,
								   &goods[i].pro_time.month,
								   &goods[i].pro_time.day);
						break;
					case 4: printf ("\n	the best-before day after modifying:");
						scanf ("%d", &goods[i].save_day);
						break;

			}

			printf ("\n	-----------the information of goods-------");
			printf ("the goods num---the goods name---the goods kind---the goods pro_time(yyyy_mm_dd)---the goods best-before day\n");
			printf ("--------------------------------------------\n");
			printf ("%4d%8s%15d-%2d-%2d%10d\n", goods[i].num, goods[i].name, goods[i].kind,
							    goods[i].pro_time.year,
							    goods[i].pro_time.month,
							    goods[i].pro_time.day,
							    goods[i].save_day);
			break;
		}
		if (i == sum) {

			printf ("it is not existent~");
			bioskey(0);

		}
		
		printf ("\n Continue to modify? (y/n)");
		choice = getchar();
		if (choice == 'y' || choice == 'Y') {

			flag = 1;
			printf ("\n	continue!	\n");

		}

		else
			flag = 0;

	}while (flag == 1);

	printf ("\n	Please press an unconditional key to return to home page~");
	
	bioskey(0);

}

//删除模块信息
void delete () {
	;
}

//查询模块信息
void inquire () {
	;
}

//统计模块信息
void count () {
	;
}

void sort (GOODS goods[], int sum) {

	GOODS t;
	int i, j, k;

	system(clear);

	printf ("\n	--------the sort of the stock goods---------\n");
	printf ("\n	--------------------------------------	\n");
	printf ("\n	rank	num	name	stock	\n");
	for (i = 0; i < sum; i++) {

		 k = i;

		for (j = i + 1; j < sum; j++) {

			if (goods[k].save_day > goods[j].save_day) {

				k = j;
	
			}

		}

		if (k != i) {

			t = goods[i];
			goods[i] = goods[k];
			goods[k] = t;

		}

	}

	output (goods, sum);

	bioskey(0);

}
