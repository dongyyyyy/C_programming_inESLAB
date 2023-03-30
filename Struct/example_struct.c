#include <stdio.h>

struct Student {
	char *name;
	int grade;
	char* number;
	char* major;
};

struct Classromm
{
	struct Student *students;
};