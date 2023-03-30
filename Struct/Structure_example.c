#include <stdio.h>
#include <stdlib.h>
#include "example_struct.c"



int examples1()
{
	struct Classromm class_room;
	int number_of_student;
	int i = 0;
	printf("교실의 학생의 수를 입력하세요 : ");

	scanf_s("%d", &number_of_student, sizeof(number_of_student));
	rewind(stdin);
	//fflush(stdin);
	class_room.students = (struct Student*)malloc(sizeof(struct Student) * number_of_student);

	printf("size = %d\n", sizeof(class_room.students));

	while (i < number_of_student)
	{
		struct Student a;
		a.name = (char*)malloc(sizeof(char) * 50);
		a.major = (char*)malloc(sizeof(char) * 50);
		a.number = (char*)malloc(sizeof(char) * 50);

		printf("학생(%d)의 이름을 입력하세요 : ", i + 1);
		gets(a.name);

		printf("학생(%d)의 학년을 입력하세요 : ", i + 1);
		scanf_s("%d", &a.grade);
		rewind(stdin);

		printf("학생(%d)의 번호을 입력하세요 : ", i + 1);
		gets(a.number);

		printf("학생(%d)의 전공을 입력하세요 : ", i + 1);
		gets(a.major);

		(char*)realloc(a.name, strlen(a.name) + 1);
		(char*)realloc(a.major, strlen(a.major) + 1);
		(char*)realloc(a.number, strlen(a.number) + 1);

		class_room.students[i] = a;

		i++;
	}

	for (i = 0; i < number_of_student; i++)
	{
		printf("%s // %d // %s // %s \n", class_room.students[i].name, class_room.students[i].grade, class_room.students[i].number, class_room.students[i].major);
	}

	return 0;
}

