//https://www.acmicpc.net/problem/14888

//삼성 기출 : 연산자 끼워넣기
//식의 수와 수 사이에 끼워넣을 사칙 연산자의 갯수가 주어질 때 그 식의 결과 최대 최소를 출력하시오.
//단, 식을 계산할 때 연산자 우선순위는 따지지 않고 무조건 순서대로 계산한다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SWAP(a, b, type) do{type temp = a; a = b; b = temp;}while(0)

int operlen;
int* numbers;
char opstr[12];
int operate[4]; //+ - * /


int cmp(const void* a, const void* b) {
	return *(char*)a - *(char*)b;
}


int nextOpStr()
{
	int lastidx = operlen - 2;

	for (int i = lastidx; i > 0; i--)
	{
		if (opstr[i - 1] >= opstr[i]) continue;
		else {
			int minidx = i;
			for (int j = i + 1; j < operlen - 1; j++)
				if (opstr[minidx] > opstr[j] && opstr[j] > opstr[i-1]) minidx = j;
			SWAP(opstr[i - 1], opstr[minidx], char);
			qsort(opstr + i, lastidx-i+1, sizeof(char), cmp);
			return 1;
		}
	}

	return 0;
}


int operating()
{
	int result = numbers[0];

	for (int i = 0; i < operlen - 1; i++)
		{
			if (opstr[i] == '+')
			{
				result += numbers[i + 1];
			}
			else if (opstr[i] == '-') {
				result -= numbers[i + 1];
			}
			else if (opstr[i] == '*') {
				result *= numbers[i + 1];
			}
			else {
				result /= numbers[i + 1];
			}
		}
	return result;
}


int main(void)
{
	scanf("%d", &operlen);

	numbers = (int*)malloc(sizeof(int) * operlen);

	for (int i = 0; i < operlen; i++)
	{
		scanf("%d", &numbers[i]);
	}
	
	int twistidx[4] = { 2, 0, 1, 3 };
	int opstridx = 0;
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &operate[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < operate[twistidx[i]]; j++)
		{
			switch (twistidx[i])
			{
			case 0:
				opstr[opstridx++] = '+';
				break;
			case 1:
				opstr[opstridx++] = '-';
				break;
			case 2:
				opstr[opstridx++] = '*';
				break;
			case 3:
				opstr[opstridx++] = '/';
			}
		}
	}
	opstr[opstridx] = '\0';
	

	int max = 0x80000000;
	int min = 0x7FFFFFFF;

	do {
		int result = operating();
		if (result > max) max = result;
		if (result < min) min = result;
	} while (nextOpStr());

	printf("%d\n%d", max, min);
	return 0;
}

