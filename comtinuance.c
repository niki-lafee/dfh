//一个数
#include<stdio.h> 

int sumN(int n)   //求前n项和
{ 
	if(n <= 0) 
	{  
		return 0;
	}	 	

	else 
	{

		return n + sumN(n - 1);

	} 
}


int BigHalf(int n)//向上取整函数
{ 

	if(n % 2 == 0) 
   		return n/2; 
	else 
   		return (n/2)+1; 

} 

int main() 
{ 

	int n, i, p, q, flag; 


	do 
	{

		flag = 0;

		scanf("%d",&n); 

		for(i = n / 2; i >= 2; i--) 
		{	 
			p = (n / i) - BigHalf(i); 

  			q = p + i; 

	   		if((p >= 0) && (sumN(q) - sumN(p)) == n) 
   			{ 
				 printf ("%d = ", n);
				 while((++p) < q) // while ((p++) < q - 1)
     			 		printf("%d + ", p);//如果满足n个连续整数相加，就输出这几个连续整数
				 printf ("%d", q);

				 printf("\n"); 
	
    			         flag = 1; 

			} 


		}

		if (n == 3)
		{
			printf ("3 = 2 + 1\n");
			flag = 1;
		}

		if (!flag)
			printf ("NONE!\n");



	} while (n >= 2);

//	if(!flag) 
//		printf ("NONE!\n"); 

//	printf ("%d\n", sumN(n)); 

	return 0;

}

