#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// O(n^2)!!
void BubbleSort()
{
	char numbers[100000];
	int* arrays;
	int i=0,j;
	int max_length = 0;
	int temp;
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
	for(i = 0 ; i < max_length; i++){
		for (j = i + 1; j < max_length; j++)
		{
			if (arrays[i] > arrays[j])
			{
				temp = arrays[j];
				arrays[j] = arrays[i];
				arrays[i] = temp;

			}
		}
	}

	printf("\nAfter Bubble Sorting!!!\n");
	for (i = 0; i < max_length; i++)
	{
		printf("%d ", arrays[i]);
	}

	for (i = 0; i < max_length; i++) {
		for (j = i + 1; j < max_length; j++)
		{
			if (arrays[i] < arrays[j])
			{
				temp = arrays[j];
				arrays[j] = arrays[i];
				arrays[i] = temp;

			}
		}
	}

	printf("\nBubble Reverse-Sorting!!!\n");
	for (i = 0; i < max_length; i++)
	{
		printf("%d ", arrays[i]);
	}

}