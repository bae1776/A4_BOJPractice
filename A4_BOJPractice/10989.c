//https://www.acmicpc.net/problem/10989

//카운팅 정렬 방법을 통해 수를 오름차순으로 정렬해보자.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int intnum[10001] = { 0 };
	int testcase;
	scanf("%d", &testcase);

	short input;
	for (int i = 0; i < testcase; i++) {
		scanf("%hd", &input);
		intnum[input]++;
	}

	int maxnum = 1;
	for ( ;; maxnum++) {
		intnum[maxnum] += intnum[maxnum - 1];
		if (intnum[maxnum] == testcase)	break;	
	}

	for (int i = 1; i <= maxnum; i++) {
		for (int j = intnum[i - 1]; j < intnum[i]; j++) {
		printf("%d\n", i);
		}
	}


}
// 1 7 6 5 8 5 4 8 2 2
// 1 3 3 4 6 7 8 10