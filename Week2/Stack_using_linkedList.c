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
	Node* Queue = (Node*)malloc(sizeof(Node));
	int num;
	int value;
	Queue->next = NULL;


	while (1)
	{
		printf("1 : 추가 / 2 : 제거 / 3 : 출력 / 4 : 종료\n");
		scanf_s("%d", &num, sizeof(num));
		if (num == 1)
		{
			printf("값을 입력하세요 : ");
			scanf_s("%d", &value, sizeof(value));

			Node* node = (Node*)malloc(sizeof(Node));
			node->next = NULL;
			node->value = value;

			Node* curr = (Node*)malloc(sizeof(Node));
			curr = Queue;

			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = node;
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
				Node* curr = (Node*)malloc(sizeof(Node));
				Node* prev = (Node*)malloc(sizeof(Node));
				curr = Queue;
				
				while (curr->next != NULL)
				{
					prev = curr;
					curr = curr->next;
					

				}
				prev->next = NULL;
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
					printf("%d\t", curr->value);
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