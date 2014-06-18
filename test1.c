#include <stdio.h>

int main()
{
	int n;
	char s[20];

//	while (scanf ("%s%d", s, &n)==2)	break;
//	while (scanf ("%s%d", s, &n)!=EOF)	break;

	while (scanf ("%s%d", s, &n)==2)	puts("111");
	while (scanf ("%s%d", s, &n)!=EOF)	puts("222");

	return 0;

}
