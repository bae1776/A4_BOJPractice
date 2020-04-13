//https://www.acmicpc.net/problem/4153

//직각삼각형
//a b c 세 정수값이 주어질 때, 이를 변의 길이로 하는 삼각형이 직각삼각형이면 right, 아니면 wrong을
//0 0 0 이 입력될 때 까지 매 라인 출력하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num[3];
	int maxidx = 3;

	do {
		switch (maxidx) {
		case 0:
			if (num[0] * num[0] == num[1] * num[1] + num[2] * num[2]) printf("right\n");
			else printf("wrong\n");
			break;
		case 1:
			if (num[1] * num[1] == num[0] * num[0] + num[2] * num[2]) printf("right\n");
			else printf("wrong\n");
			break;
		case 2:
			if (num[2] * num[2] == num[1] * num[1] + num[0] * num[0]) printf("right\n");
			else printf("wrong\n");
			break;
		case 3:
			break;
		}

		scanf("%d %d %d", &num[0], &num[1], &num[2]);
		maxidx = (num[0] > num[1]) ? (num[0] > num[2] ? 0 : 2) : (num[1] > num[2] ? 1 : 2);
	} while (num[0] != 0);


	return 0;
}