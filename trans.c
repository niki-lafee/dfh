#include "stdio.h"

#include "stdlib.h"

#include "string.h"

char s[28] = {'0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main()
{

	long a[100];
	char c[100];
	int i, j ,k;	

	a[0] = 1;
	a[1] = 1;
	
	for (i = 2; i < 100; i++) {
	
		a[i] = a[i - 1] + a[i - 2];
	}

	gets(c);

	for (i = 0, k = 0; i < strlen(c); ) {

		for (j = 1; j <= 26; j++) {

			if (c[i] == s[j]) {

				c[i] = s[(j - a[k]%26 + 26)%26];
				i++;
				k++;
				break;
			}
			
			else if (c[i] == ' '||c[i] == ',') {
			
				i++;																				}
		}
	}

	printf ("%s", c);

	printf ("\n");

	return 0;
}
