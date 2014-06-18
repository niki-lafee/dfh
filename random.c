/*
 * =====================================================================================
 *
 *       Filename:  random.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月15日 23时21分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lafee, wisdomandmircle@gmail.com
 *        Company:  Class 1301 of Software Engineering
 *
 * =====================================================================================
 */
//随机数 && 改进快排



#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 1000

int random ();       //产生随机数 == input
void print (int number[SIZE]);    //输出       == output
void quicksort (int left, int right, int number[SIZE]);    //快速排序


int main(int argc, char *argv[]){

	int  number[SIZE];
	int  i, j;
	
	srand(time(NULL));
	   
	for (i = 0; i < SIZE; ++i) {

		numbers[i] = random();

	/*for (j = 0; j < i; ++j){

			if (numbers[j] == numbers[i]){

				numbers[i] = rand() % 100;
			}
		}
	*/

	}

	printf ("\n The randoms are: \n");
	print (number);

	quicksort (0, SIZE - 1, number);

	printf ("\n After sorting: \n");
	print (number);

	return EXIT_SUCCESS;
}

//产生随机数
int random () {

	return rand() % 100;	

}

//打印
void print (int number[SIZE]) {

	int i;

	for(i = 0; i < SIZE; i++) {
	
		printf ("%3d", number[SIZE]);
	
	}

}

//按照大小排序
void quicksort (int left, int right, int number[SIZE]) {

	int i, j;
	float key;

	i = left;
	j = right;
	key = (number[left] + number[right] + number[(left + right) / 2]) / 3.0

	while (i < j) {
	
		while (i < j && a[i] )
	
	}


}
