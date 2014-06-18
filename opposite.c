//链表的逆置


#include <stdio.h>

#include <malloc.h>

#include <stdlib.h>

#define N sizeof(struct student)

typedef struct student {

        int num;
        struct student *next;

}stu;

stu *creat ();
void print (stu *);
int opposite (stu *);

int main() {

	stu *head;

	head = creat();
	print (head);
	opposite (head);
	print (head);

	return 0;

}

stu *creat () {

	stu *head, *node1, *node2;
//	char choice;

	head = node1 = (stu *)malloc(N);

//	printf ("You will key the num on you computer,while keying the 'y'on,over.\n");
	do {

		node2 = (stu *)malloc(N);
		puts("lll");
		scanf ("%d", &node2->num);
		node1->next = node2;
		node1 = node2;
		node1 = node1->next;
//		printf ("continue?(y/n)");
//		scanf ("%c", &choice);
//		choice = getchar();
	} while (node2->num != 0/*choice == 'y' || choice == 'Y'*/);

	node1->next = NULL;
	free (node2);

	return head;

}

void print (stu *node) {

	node = node->next;
	while (node != NULL) {

		printf ("%d\n", node->num);
		node = node->next;
	
	}

}

int opposite (stu *head) {

	stu *node1, *node2, *node3;

	node1 = head->next;

	while (node1 != NULL) {

		node2 = node1->next;
		node3->next = node1;
		node1->next = node2->next;
		node2 = node3;	

	}

	return 1;

}
