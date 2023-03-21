//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int i, j;
	int size;

	printf("삼각형의 높이를 입력하세요 : ");
	//scanf("%d", &size);
	scanf_s("%d", &size, sizeof(int));
	printf("정 직각 삼각형 출력\n");

	/* 정 직각 삼각형 */
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if(i >= j )
				printf("*");
		}
		printf("\n");
	}

	printf("정 직각 삼각형 출력 version 2\n");

	/* 정 직각 삼각형 */
	for (i = 0; i < size; i++)
	{
		for (j = size-1; j >= 0; j--)
		{
			if (i >= j)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}


	printf("역 직각 삼각형 출력\n");

	/* 역 직각 삼각형 */
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i <= j)
				printf("*");
		}
		printf("\n");
	}
	printf("정삼각형 출력\n");

	/* 정삼각형 */
	for (i = 0; i < size; i++)
	{
		for (j = -size+1; j < size; j++)
		{
			if (i >= abs(j))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("역 정삼각형 출력\n");

	/* 역삼각형 */
	for (i = size-1; i >= 0; i--)
	{
		for (j = -size + 1; j < size; j++)
		{
			if (i >= abs(j))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}


}