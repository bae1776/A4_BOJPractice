//https://www.acmicpc.net/problem/11726

//2xn Ÿ�ϸ� 1

//2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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
