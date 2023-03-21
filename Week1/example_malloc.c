#include <stdio.h>
#include <stdlib.h>

void main()
{
	int size_of_array = 10;
	int addition_size = 1;
	//int *a = (int*)malloc(sizeof(int)*size_of_array);
	int* a = (int*)calloc(size_of_array,sizeof(int));
	printf("address of a = %p\n", a);

	//a = (int*)calloc(size_of_array, sizeof(int));
	printf("address of a = %p\n", a);

	(int*)realloc(a, sizeof(int) * (size_of_array+addition_size));
	printf("address of a = %p\n", a);
	printf("%d\n", sizeof(a));

	for (int i = 0; i < size_of_array+ addition_size; i++)
	{
		a[i] = i;
		//printf("%d ", *a);
		
		
		for (int j = 0; j < size_of_array + addition_size; j++)
		{
			printf("%d ", a[j]);
		}
		
		printf("\n");
	}
	printf("\n");
	free(a);
	return;
}