#include <stdio.h>
/*
	https://www.acmicpc.net/problem/1003
*/



int fibonacci(int num, int* num0, int* num1)
{
	if (num == 0)
	{
		*num0 += 1;
		return 0;
	}
	else if (num == 1)
	{
		*num1 += 1;
		return 1;
	}
	else
	{
		return fibonacci(num - 2,num0,num1) + fibonacci(num - 1, num0, num1);
	}
}

void main()
{
	int num;
	while (1)
	{
		printf("숫자를 입력하세요 : (-1 : 종료)");
		int num0, num1;
		num0 = 0;
		num1 = 0;
		scanf_s("%d", &num, sizeof(num));

		if (num == -1)
		{
			return;
		}
		fibonacci(num, &num0, &num1);
		printf("결과 : %d %d \n", num0, num1);
	}
}