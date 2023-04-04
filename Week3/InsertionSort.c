#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
	O(N) = N^2
*/

void Insertion_Sorting()
{
	char numbers[100000];
	int* arrays;
	int i = 0, j;
	int max_length = 0;
	int temp,key;
	char* next = NULL;
	printf("Length of Array : ");
	scanf_s("%d", &max_length, sizeof(max_length));
	rewind(stdin);

	printf("Insert array numbers : ");
	gets(numbers);
	arrays = malloc(sizeof(arrays) * max_length);
	char* ptr = strtok_s(numbers, " ", &next);

	while (ptr != NULL)
	{
		arrays[i++] = atoi(ptr);
		ptr = strtok_s(NULL, " ", &next);
	}
	printf("Before Bubble Sorting!!!\n");
	for (i = 0; i < max_length; i++)
	{
		printf("%d ", arrays[i]);
	}
	for (i = 1; i < max_length; i++) {
		key = arrays[i];
		for (j = i-1; j >= 0; j--)
		{
			
			if (key < arrays[j])
			{
				arrays[j+1] = arrays[j];
			}
			else
			{
				arrays[j + 1] = key;
				break;
			}
			arrays[j] = key;
		}
	}

	printf("\nAfter Bubble Sorting!!!\n");
	for (i = 0; i < max_length; i++)
	{
		printf("%d ", arrays[i]);
	}
	for (i = 1; i < max_length; i++) {
		key = arrays[i];
		for (j = i - 1; j >= 0; j--)
		{

			if (key > arrays[j])
			{
				arrays[j + 1] = arrays[j];
			}
			else
			{
				arrays[j + 1] = key;
				break;
			}
			arrays[j] = key;
		}
	}

	printf("\nInsertion Reverse-Sorting!!!\n");
	for (i = 0; i < max_length; i++)
	{
		printf("%d ", arrays[i]);
	}
	
	return;

}