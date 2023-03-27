#include <stdio.h>
#include <stdlib.h>
/* Structure */


typedef struct Node
{
	int value;
	struct Node* next;
}Node;

void main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	
	head->next = NULL;
	
	Node* node1 = (Node*)malloc(sizeof(Node));
	node1->next = NULL;
	node1->value = 5;
	head->next = node1;

	Node* node2 = (Node*)malloc(sizeof(Node));
	node2->next = NULL;
	node2->value = 10;
	node1->next = node2;

	Node* curr = head->next;
	while (curr != NULL)
	{
		printf("%d\n", curr->value);
		curr = curr->next;
	}
	
	curr = head->next;
	while (curr != NULL)
	{
		printf("%d\n", curr->value);
		curr = curr->next;
	}


	return;
}