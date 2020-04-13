//https://www.acmicpc.net/problem/1546 (문제 번호)

//문제가 너무 길다.
//요약하면 시험 점수 중 최댓값을 뽑아내고 사칙연산으로 이루어진 새로운 평균을 구해라.. 란것.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int subjectnum, max = 0, scan;
	double sum = 0;
	scanf("%d", &subjectnum);
	for (int i = 1; i <= subjectnum; i++) {
		scanf("%d", &scan);
		if (scan > max) max = scan;
		sum += scan * 100;
	}
	sum /= (max * subjectnum);
	printf("%f", sum);
}