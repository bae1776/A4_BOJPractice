//https://www.acmicpc.net/problem/2750

//입력 받은 수를 오름차순 정렬해보자. (입력 받는 수는 중복 받지 않음)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}


int main() {
	int testcase;
	scanf("%d", &testcase);
	
	int *arbnum = malloc(sizeof(int) * testcase);


	for (int i = 0; i < testcase; i++) {
		scanf("%d", &arbnum[i]);
	}

	qsort(arbnum, testcase, sizeof(int), compare); //퀵 소트 알고리즘

	for (int i = 0; i < testcase; i++) {
		printf("%d\n", arbnum[i]);
	}

	free(arbnum);
}