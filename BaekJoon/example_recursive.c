#include <stdio.h>
/*
	https://www.acmicpc.net/problem/2747
*/


int fibonacci(int num)
{
	if (num == 0)
	{
		return 0;
	}
	else if (num == 1)
	{
		return 1;
	}
	else
	{
		return fibonacci(num - 2) + fibonacci(num - 1);
	}
}

void main()
{
	int num;
	while (1)
	{
		printf("숫자를 입력하세요 : (-1 : 종료)");
		scanf_s("%d", &num, sizeof(num));

		if ( num == -1)
		{
			return;
		}
		printf("결과 : %d\n", fibonacci(num));
	}
}