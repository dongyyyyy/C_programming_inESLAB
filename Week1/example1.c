#include <stdio.h>

void main()
{
	int a;
	printf("%p\n", &a);
	a = 1000;
	printf("%p\n", &a);
	printf("Hello World!\n");
	return;
}