//https://www.acmicpc.net/problem/2108

//평균, 중앙값, 최빈값, 범위(최대최소 차)를 출력하시오.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}


int main() {
	int testcase;
	scanf("%d", &testcase);

	int *element = (int *)malloc(sizeof(int) * testcase);

	int mid = (testcase-1) / 2;
	int sum = 0;

	for (int i = 0; i < testcase; i++) {
		scanf("%d", &element[i]);
		sum += element[i];
	}

	qsort(element, testcase, sizeof(int), compare);

	int maxtimes = 0;
	int mostfreq_num = 0;
	char occur_count = 0;

	if (testcase == 1) {
		mostfreq_num = element[0];
	}
	else {
		for (int i = 0; i < testcase; ) {
			int j;
			for (j = 1; element[i] == element[i + j]; j++);
			if (j > maxtimes) {
				maxtimes = j;
				mostfreq_num = element[i];
				occur_count = 1;
			}
			else if (j == maxtimes) {
				if (occur_count == 1) mostfreq_num = element[i];
				occur_count++;
			}
			i += j;
		}
	}


	double mean = (double)sum / testcase;
	mean += (mean > 0) ? 0.5 : -0.5;
	
	printf("%d\n", (int) mean); //평균
	printf("%d\n", element[mid]); //중앙값
	printf("%d\n", mostfreq_num);
	printf("%d\n", element[testcase - 1] - element[0]); //범위
}



//1 1 1 4 5 5 6 7 10 13 13 