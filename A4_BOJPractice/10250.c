//https://www.acmicpc.net/problem/10250

//호텔 배정해주기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int testcase;
	scanf("%d", &testcase);


	for (int i = 0; i < testcase; i++) {
		int H, W, N;
		scanf("%d %d %d", &H, &W, &N);

		if (N % H) printf("%d", N % H);
		else printf("%d", H);
		if (N == 1) printf("01\n");
		else printf("%02d\n", (N - 1) / H + 1);
	}
}