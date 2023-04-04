#include <stdio.h>

// O(N^2)
// 가장 작은 값을 맨 앞으로(바로바로)
void SelectSort()
{
	char numbers[100000];
	int* arrays;
	int i = 0, j;
	int max_length = 0;
	int head,temp,index;
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
	printf("Before Select Sorting!!!\n");
	for (i = 0; i < max_length; i++)
	{
		printf("%d ", arrays[i]);
	}
	for (i = 0; i < max_length; i++) {
		head = arrays[i];
		index = i;
		for (j = i + 1; j < max_length; j++)
		{
			if (arrays[index] > arrays[j])
			{
				index = j;
				head = arrays[j];
			}
			temp = arrays[i];
			arrays[i] = head;
			arrays[index] = temp;
		}
	}

	printf("\nAfter Select Sorting!!!\n");
	for (i = 0; i < max_length; i++)
	{
		printf("%d ", arrays[i]);
	}

	for (i = 0; i < max_length; i++) {
		head = arrays[i];
		index = i;
		for (j = i + 1; j < max_length; j++)
		{
			if (arrays[index] < arrays[j])
			{
				
				index = j;
				head = arrays[j];
			}
			temp = arrays[i];
			arrays[i] = head;
			arrays[index] = temp;
		}
	}

	printf("\nBubble Reverse-Sorting!!!\n");
	for (i = 0; i < max_length; i++)
	{
		printf("%d ", arrays[i]);
	}
}