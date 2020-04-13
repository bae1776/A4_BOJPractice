//https://www.acmicpc.net/problem/11726

//2xn 타일링 1

//2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int DP[1001] = { 0 };


int tile(int length)
{
	if (DP[length] != 0) return DP[length];

	int total = 0;
	switch (length)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	default:
		total += (tile(length - 2) + tile(length - 1)) % 10007;
		DP[length] = total;
		return total;
	}
}



int main(void)
{
	int length;
	scanf("%d", &length);

	printf("%d", tile(length));

	return 0;
}
