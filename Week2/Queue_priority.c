#include <stdio.h>
#include <stdlib.h>
/* Structure */


typedef struct Node
{
	int value;
	int priority;
	struct Node* next;
}Node;

void main()
{
	Node* Queue = (Node*)malloc(sizeof(Node));
	int num;
	int value;
	int priority;
	Queue->next = NULL;


	while (1)
	{
		printf("1 : 추가 / 2 : 제거 / 3 : 출력 / 4 : 종료\n");
		scanf_s("%d", &num, sizeof(num));
		if (num == 1)
		{
			printf("우선순위, 값 순서대로 값을 입력하세요 : ");
			scanf_s("%d %d", &priority, &value, sizeof(value),sizeof(priority));

			Node* node = (Node*)malloc(sizeof(Node));
			node->next = NULL;
			node->value = value;
			node->priority = priority;

			Node* curr = (Node*)malloc(sizeof(Node));
			Node* previous = (Node*)malloc(sizeof(Node));

			previous = Queue;
			curr = Queue->next;
			if (curr == NULL)
			{
				previous->next = node;
			}
			else
			{
				while (curr !=  NULL)
				{
					if (curr->priority < priority)
					{
						node->next = curr;
						previous->next = node;
						break;
					}
					else
					{
						previous = curr;
						curr = curr->next;
					}
				}

			}
			if (curr == NULL)
			{
				previous->next = node;
			}

			//free(curr);
		}
		else if (num == 2)
		{
			
			if (Queue->next == NULL)
			{
				printf("제거할 노드가 없습니다.\n");
			}
			else
			{
				Node* removing_node = Queue->next;
				Node* next_node = Queue->next->next;

				Queue->next = next_node;

				free(removing_node);
			}
		}
		else if (num == 3)
		{
			if (Queue->next == NULL)
			{
				printf("출력할 노드가 없습니다.\n");
			}
			else
			{
				Node* curr = (Node*)malloc(sizeof(Node));
				curr = Queue->next;
				while (curr != NULL)
				{
					printf("%d(%d)\t", curr->value,curr->priority);
					curr = curr->next;
				}
				printf("\n");
				//free(curr);
			}
		}
		else if (num == 4)
		{
			printf("종료합니다\n");
			break;
		}
		else
		{
			printf("잘못된 숫자를 입력하셨습니다.\n");
		}
	}


	free(Queue);
	return;
}