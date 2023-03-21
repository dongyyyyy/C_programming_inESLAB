#include <stdio.h>

void main()
{
	int size_of_array = 5;
	int arr[5];
	printf("sizeof(int) = %d\n", sizeof(arr)/sizeof(int));
	printf("%p // %p\n",&arr[0],arr);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		arr[i] = i;
		for (int j = 0; j < sizeof(arr) / sizeof(int); j++)
		{
			printf("%d ", arr[j]);
		}
		printf("\n");
	}

	return;
}