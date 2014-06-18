#include<stdio.h>

#include<string.h>

#define n 3

struct stuff
{
	int num;
	char name [20];
	int age;
	union 
	{
		float score;
		char  level;
	}result;
}stuff[n];

int main()
{
	int i,j = 0,h = 0,k;
	printf ("please input the num of the first stuff:\n");
	scanf ("%d",&k);
	printf ("please input the information about stuffs(name,age,score/level):\n");
	for (i =0 ;i < n; i++)
	{
		printf ("%-10d",stuff[i].num=k+i);
		scanf ("%s%d",stuff[i].name,&stuff[i].age);
		puts("Enter Complete!");
		if (stuff[i].age < 30)
		{
			printf ("please input the score:\n");
			scanf ("%f",&stuff[i].result.score);
			j++;
		}
		else 
		{
			printf ("please input the level:\n");
			scanf ("%c",&stuff[i].result.level);
			stuff[i].result.level=getchar();
			h++;
		}
	}
	printf ("the information about the stuff is :\n");
	for (i = 0; i < n; i++)
	{
		printf ("%d",stuff[i].num=i + k);
		if (stuff[i].age < 30)
			printf ("%8s%5d\t%5.2f\n",stuff[i].name,stuff[i].age,stuff[i].result.score);
		else 
			printf ("%8s%5d\t%5c\n",stuff[i].name,stuff[i].age,stuff[i].result.level);
	}
	printf (" the number of the passed stuff:%d\n",j+h);
	return 0;

}
