//https://www.acmicpc.net/problem/4344 (문제 번호)

//사이트 참고 (너무 김)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int cases, studentnum, score[1001];
	scanf("%d ", &cases);
	for (int i = 0; i < cases; i++) {
		int sum = 0, overmean = 0;
		scanf("%d", &studentnum);
		for (int j = 0; j < studentnum; j++) {
			scanf("%d", &score[j]);
			sum += score[j];
		}
		double mean = (double) sum / studentnum;
		for (int j = 0; j < studentnum; j++) {
			if (score[j] > mean) overmean++;
		}
		double percent = (double) overmean / studentnum * 100;
		printf("%.3f%%\n", percent);
	}
}