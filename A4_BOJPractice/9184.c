//https://www.acmicpc.net/problem/9184

/* 신나는 함수 실행
모든 것을 재귀함수로 구현하면 너무나 많은 시간이 걸린다.

if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
    1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
    w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

인 재귀 함수 w의 결과값을 좀 더 빨리 구하는 방법을 생각해보세요.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define UNKNOWN -9999

int DP[21][21][21];

int w(int a, int b, int c);

int main(void)
{
    int a, b, c;
	for (int i = 0; i <= 20; i++)
		for (int j = 0; j <= 20; j++)
			for (int k = 0; k <= 20; k++)
				DP[i][j][k] = UNKNOWN;

	
	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1)
			break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
	
	return 0;
}


int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	else if (DP[a][b][c] != UNKNOWN)
		return DP[a][b][c];
	else if (a < b && b < c)
		return DP[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		return DP[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

}