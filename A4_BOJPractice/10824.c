//https://www.acmicpc.net/problem/10824

//input : 10 20 30 40
// --> 1020 + 3040
//output : 4060
//네 수가 주어질 때 위와 같이 출력하시오. 각 수는 백만 이하의 자연수이다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char A[20], B[10], C[20], D[10];
	scanf("%s %s %s %s", A, B, C, D);
	strcat(A, B); strcat(C, D);

	int Alen = strlen(A);
	int Clen = strlen(C);

	if (Alen > Clen)
	{
		memmove(A + 1, A, Alen + 1);
		A[0] = '0';
		memmove(C + 1 + Alen - Clen, C, Clen + 1);
		for (int i = 0; i <= Alen - Clen; i++)
			C[i] = '0';
	}
	else if (Alen < Clen)
	{
		memmove(C + 1, C, Clen + 1);
		C[0] = '0';
		memmove(A + 1 + Clen - Alen, A, Alen + 1);
		for (int i = 0; i <= Clen - Alen; i++)
			A[i] = '0';
	}
	else {
		memmove(A + 1, A, Alen + 1);
		A[0] = '0';
		memmove(C + 1, C, Clen + 1);
		C[0] = '0';
	}

	int nowlen = strlen(A);

	for (int i = 0; i < nowlen; i++)
	{
		A[i] += C[i] - '0';
	} 

	for (int i = nowlen - 1; i > 0; i--)
	{
		if (A[i] > '9')
		{
			A[i - 1]++;
			A[i] -= 10;
		}
	}

	for (int i = A[0] == '0' ? 1 : 0; i < nowlen; i++)
	{
		printf("%c", A[i]);
	}
}

