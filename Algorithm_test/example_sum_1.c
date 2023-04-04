// 구간 합 문제
/*
	입력 1번째 줄에 수의 개수 N(1<= N <= 100,000), 합을 구해야 하는 횟수 M(1<= M <= 100,000), 2번째에 N개의 수가 주어진다.
	각 수는 1,000보다 작거나 같은 자연수이다. 3번째 불부터는 M개의 줄에 합을 구해야 하는 구간 i와 j 가 주어진다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void sum_previous(int end,int* input, int* result)
{
	if (result[end - 1] != -1)
	{
		return;
	}
	else if (end - 1 == 0)
	{
		result[end - 1] = input[end-1];
	}
	else if (result[end - 2] == -1)
	{
		sum_previous(end - 1, input, result);
		result[end - 1] = result[end - 2] + input[end - 1];
	}
	else
	{
		result[end - 1] = result[end - 2] + input[end - 1];
	}
	
	
}

int sum_section(int start, int end, int* input, int* result)
{
	if(result[start - 1] == -1)
	{
		sum_previous(start, input, result);
	}
	if(result[end - 1] == -1)
	{
		sum_previous(end, input, result);
	}
	if (start == 1){
		return result[end - 1];
	}
	else{
		return result[end - 1] - result[start - 2];
	}
	
}

void sum_1_example()
{
	int* results;
	int* outputs;
	int* input_numbers;
	int i;
	char numbers[100000];
	char* context = NULL;

	int start, end;
	int number_of_samples, number_of_lines;
	scanf_s("%d %d", &number_of_samples, &number_of_lines, sizeof(int), sizeof(int));
	rewind(stdin);

	results = malloc(sizeof(int) * number_of_samples);
	input_numbers = malloc(sizeof(int) * number_of_samples);
	outputs = malloc(sizeof(int) * number_of_lines);
	gets(numbers);

	char* token_number = strtok_s(numbers," ",&context);
	int max_length = 0;
	while (token_number != NULL)              //ptr이 NULL일때까지 (= strtok 함수가 NULL을 반환할때까지)
	{
		results[max_length] = -1;
		input_numbers[max_length++] = atoi(token_number);       //자른 문자 출력
		token_number = strtok_s(NULL, " ", &context);     //자른 문자 다음부터 구분자 또 찾기
	}
	for (i = 0; i < number_of_lines; i++)
	{
		scanf_s("%d %d", &start, &end, sizeof(int), sizeof(int));
		rewind(stdin);
		outputs[i] = sum_section(start, end, input_numbers, results);
	}
	
	for (i = 0; i < number_of_lines; i++)
	{
		printf("%d\n", outputs[i]);
	}


}