//https://www.acmicpc.net/problem/16433

//주디와 당근 농장
//대회 링크 : https://www.acmicpc.net/category/detail/1949

#include <stdio.h>

int main(void) {
	int size, row, col;

	scanf("%d %d %d", &size, &row, &col);
	int sub = row > col ? row - col : col - row;

	switch (sub % 2) {
	case 0:  //(홀수, 홀수) (짝수, 짝수)에만 심기게 됨
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i + j & 1) { //홀수이면 .
					printf(".");
				}
				else {
					printf("v");
				}
			}
			printf("\n");
		}
		break;
	case 1:  //역 관계에만 심김
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i + j & 1) { //홀수이면 .
					printf("v");
				}
				else {
					printf(".");
				}
			}
			printf("\n");
		}
	}

}