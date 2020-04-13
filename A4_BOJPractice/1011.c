//https://www.acmicpc.net/problem/1011 (문제 번호)

//비행선 이동하기 (규칙찾기)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int testcase;
	scanf("%d", &testcase);


	for (int i = 0; i < testcase; i++) {
		int begin, last;
		scanf("%d %d", &begin, &last);
		int distance = last - begin;

		int i = 1;
		while (distance > (long long) i * i) i++;
		if (distance > i * i - i)  printf("%d\n", 2 * i - 1);
		else printf("%d\n", 2 * i - 2);
	}

	
}

