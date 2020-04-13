//https://www.acmicpc.net/problem/2133

//타일 채우기
//3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.
//N은 1 ~ 30

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int DP[31] = { 0, 0, 3 };


int main(void)
{
	int width;
	scanf("%d", &width);

	for (int i = 4; i <= width; i += 2) 
	{
		int temp = DP[i - 2] * 3;

		int j = 4;
		while (i > j)
		{ 
			temp += DP[i - j] * 2;
			j += 2;
		}

		DP[i] = temp + 2; 
		//모두 맞물리게 배치하는 경우의 수가 2개.
		
	}

	printf("%d", DP[width]);

	return 0;
}
