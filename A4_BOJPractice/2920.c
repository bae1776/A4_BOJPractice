//https://www.acmicpc.net/problem/2920

//음계
//배열 오름차순, 내림차순 판단

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int input[8];
	for (int t = 0; t < 8; t++) {
		scanf("%d", &input[t]);
	}

	int i = 0;
	for (; i < 7; i++) {
		if (input[i + 1] > input[i]) continue;
		else break;
	}

	int j = 0;
	for (; j < 7; j++) {
		if (input[j + 1] < input[j]) continue;
		else break;
	}

	if (i == 7) printf("ascending");
	else if (j == 7) printf("descending");
	else printf("mixed");

	return 0;
}