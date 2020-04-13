//https://www.acmicpc.net/problem/1904

//수열의 길이가 주어질 때, 00 타일과 1 타일로 만들 수 있는 서로 다른 수열의 갯수 % 15746을 구하시오.
//타일은 충분히 많은 것으로 간주하자.
//예를 들어 수열 길이가 4면, 0011, 0000, 1001, 1100, 1111 총 5개를 만들 수 있다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

const int REST = 15746;

int main(void)
{
	int input;
	scanf("%d", &input);

	int* ways = (int*)malloc(sizeof(int) * (input + 1));
	ways[1] = 1; ways[2] = 2;

	int unknownidx = 3;
	while (unknownidx <= input)
	{
		ways[unknownidx++] = (ways[unknownidx - 1] + ways[unknownidx - 2]) % REST;
	}

	printf("%d", ways[input]);
	free(ways);
}