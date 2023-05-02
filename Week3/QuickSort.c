#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int partitioning(int* arr, int left, int right)
{
	int pivot_index = floor((left + right) / 2);
	int pivot_value = arr[pivot_index];
	int temp;
	while (left < right)
	{
		while (left <= right && arr[left] < pivot_value)
			left++;
		while (right > left && arr[right] > pivot_value)
			right--;
		if (arr[left] > arr[right])
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}


	}
	return right;
}

void quick_sort(int* arr, int left, int right)
{	
	if (left < right)
	{
		int pivot = partitioning(arr, left, right);
		quick_sort(arr, left, pivot - 1);
		quick_sort(arr, pivot+1, right);
	}
}

int partitioning_reverse(int* arr, int left, int right)
{
	int pivot_index = floor((left + right) / 2);
	int pivot_value = arr[pivot_index];
	int temp;
	while (left <= right)
	{
		while (arr[left] > pivot_value)
			left++;
		while (arr[right] < pivot_value)
			right--;
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
	return left;
}

void quick_sort_reverse(int* arr, int left, int right)
{

	int pivot = partitioning_reverse(arr, left, right);
	if (left > pivot - 1)
	{
		quick_sort_reverse(arr, left, pivot - 1);
	}
	if (pivot > right)
	{
		quick_sort_reverse(arr, pivot, right);
	}
}


void Quick_Sorting()
{
	char numbers[100000];
	int arrays[10];
	int i = 0, j;
	int left_index, right_index;
	int max_length = 0;
	int temp, key;
	char* next = NULL;
	printf("Length of Array : ");
	scanf_s("%d", &max_length, sizeof(max_length));
	rewind(stdin);

	printf("Insert array numbers : ");
	gets(numbers);
	//arrays = malloc(sizeof(arrays) * max_length);
	char* ptr = strtok_s(numbers, " ", &next);

	while (ptr != NULL)
	{
		arrays[i++] = atoi(ptr);
		ptr = strtok_s(NULL, " ", &next);
	}

	printf("Before Quick Sorting!!!\n");
	for (i = 0; i < max_length; i++)
	{
		printf("%d ", arrays[i]);
	}

	left_index = 0;
	right_index = max_length - 1;
	quick_sort(arrays, left_index, right_index);

	printf("\nAfter Quick Sorting!!!\n");
	for (i = 0; i < max_length; i++)
	{
		printf("%d ", arrays[i]);
	}


	quick_sort_reverse(arrays, left_index, right_index);

	printf("\nAfter Quick Sorting(Reverse)!!!\n");
	for (i = 0; i < max_length; i++)
	{
		printf("%d ", arrays[i]);
	}
	return;

}