//https://www.acmicpc.net/problem/10039

//Æò±Õ Á¡¼ö

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int sum = 0;
	int score[5];
	for (int i = 0; i < 5; i++) {
		scanf("%d", &score[i]);
		if (score[i] >= 40) sum += score[i];
		else sum += 40;
	}
	printf("%d", sum / 5);

}