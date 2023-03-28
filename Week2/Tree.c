#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
}Tree;


void print_tree(Tree* tree)
{
	if (tree != NULL)
	{
		printf("%d ", tree->data);
		print_tree(tree->left);
		print_tree(tree->right);
	}
	
}
void print_left_root_right(Tree* tree)
{
	if (tree != NULL)
	{
		print_left_root_right(tree->left);
		printf("%d ", tree->data);
		print_left_root_right(tree->right);
	}
}

void main()
{
	Tree* tree;
	tree = (Tree*)malloc(sizeof(Tree));
	int counts = 0;
	int select;
	int data;
	tree = NULL;
	while (1)
	{

		printf("1. 삽입 / 2. 제거 / 3. 출력 / 4. 종료 ==>");
		scanf_s("%d", &select, sizeof(select));

		if (select == 1)
		{
			printf("추가할 노드 값을 입력하세요 : ");
			scanf_s("%d", &data, sizeof(data));
			if (counts == 0)
			{
				Tree* node = (Tree*)malloc(sizeof(Tree));
				node->data = data;
				node->left = NULL;
				node->right = NULL;
				tree = node;
				counts += 1;
			}
			else
			{
				Tree* curr = (Tree*)malloc(sizeof(Tree));
				curr = tree;
				while(curr != NULL)
				{
					if (curr->left == NULL && curr->data > data)
					{
						Tree* node = (Tree*)malloc(sizeof(Tree));
						node->data = data;
						node->left = NULL;
						node->right = NULL;
						curr->left = node;
						counts += 1;
						break;
					}
					else if (curr->right == NULL && curr->data < data)
					{
						Tree* node = (Tree*)malloc(sizeof(Tree));
						node->data = data;
						node->left = NULL;
						node->right = NULL;
						curr->right = node;
						counts += 1;
						break;
					}
					else 
					{// 1 3 7 15
						if (curr->data > data)
						{
							curr = curr->left;
						}
						else
						{
							curr = curr->right;
						}
					}
				}
			}
			
		}
		else if (select == 2)
		{
			if (counts = 0)
			{
				printf("제거할 노드가 없습니다\n");
			}
			else if (counts == 1)
			{
				tree = NULL;
				counts -= 1;
			}
			else
			{
				Tree* previous_node = (Tree*)malloc(sizeof(Tree));
				Tree* curr = (Tree*)malloc(sizeof(Tree));
				curr = tree;
				if (curr->right != NULL)
				{
					curr = curr->right;
					while (curr->left != NULL)
					{
						previous_node = curr;
						curr = curr->left;
					}
					tree->data = curr->data;
					if (curr->right != NULL)
					{
						Tree* saved_node = (Tree*)malloc(sizeof(Tree));
						saved_node = curr->right;
						previous_node->left = saved_node;
					}
					else
					{
						previous_node->left = NULL;
					}
					counts -= 1;
				}
				else
				{
					curr = curr->left;
					while (curr->right != NULL)
					{
						previous_node = curr;
						curr = curr->right;
					}
					tree->data = curr->data;
					if (curr->left != NULL)
					{
						Tree* saved_node = (Tree*)malloc(sizeof(Tree));
						saved_node = curr->left;
						previous_node->right = saved_node;
					}
					else
					{
						previous_node->right = NULL;
					}
					counts -= 1;
				}

			}
		}
		else if (select == 3)
		{
			//print_tree(tree);
			print_left_root_right(tree);
			printf("\n");
		}
		else if (select == 4)
		{
			printf("프로그램을 종료합니다.\n");
			return;
		}
		else
		{
			printf("잘못된 숫자를 입력하셨습니다.\n");
		}
	}
}