#include <stdio.h>

#include <stdlib.h>

#include <string.h>

char map[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};

char phone[100000][9];

int n;

char number[80];

int main() {

	int loop;	
	int phone_i = 0, phone_j = 0;	
	int tag = 0;
	int count = 1;
	
	scanf ("%d", &n);
	
	for (phone_i = 0; phone_i <= n ; phone_i++) {
	
		gets (number);

		for (loop = 0; number [loop] != '\0'; loop++) {

			if (phone_j == 3) {
	
				phone [phone_i][phone_j] = '-';
				phone_j++;

			}
		
			if (number[loop] >= '0' && number[loop] <= '9') {

				phone[phone_i][phone_j] = number[loop];
	
			}

			else if (number [loop] >= 'A' && number [loop] <= 'Z') {

				phone[phone_i][phone_j] = map[number[loop] - 'A'];

			}

			else if (number[loop] = '-') {

				continue;

			}
		
			phone_j++;
		}

		phone_j = 0;

	}

	qsort (phone,n,9,strcmp);

	for (loop = 1; loop <= n; loop++) {

		if (strcmp(phone[loop],phone[loop - 1]) == 0) {

			tag = 1;
			count++;

		}
		
		else {

			if (count > 1) {

				printf ("%s %d\n",phone[loop - 1], count);

			}

		count = 1;

		}
	}

	if (count >1) {
	
		printf ("%s %d\n", phone[loop - 1], count);
		
	}
	
	if (!tag) {

		printf ("No duplicats!\n");

	}

	return 0;

}
