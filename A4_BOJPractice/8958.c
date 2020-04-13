//https://www.acmicpc.net/problem/8958

//OX ДыБо

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int testnum;
	scanf("%d", &testnum);

	char OX[81];
	for (int i = 0; i < testnum; i++) {
		scanf("%s", OX);
		int score = 0;
		int addscore = 1;
		for (unsigned int j = 0; j < strlen(OX); j++) {
			if (OX[j] == 'O') {
				score += addscore;
				addscore++;
			}
			else addscore = 1;
		}
		printf("%d\n", score);
	}
	return 0;
}