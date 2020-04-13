//https://www.acmicpc.net/problem/10818 (문제 번호)

//최댓값과 최솟값 출력
//첫째 줄에 입력할 정수의 갯수가 주어지고
//입력한 정수 중에서 가장 작은 수와 가장 큰 수를 차례대로 출력하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int input;
	scanf("%d", &input);

	int max = -1000001;
	int min = 1000001;

	int num;

	for (int i = 0; i < input; i++) {
		scanf("%d", &num);
		if (num > max) max = num;
		if (num < min) min = num;
	}

	printf("%d %d", min, max);

}