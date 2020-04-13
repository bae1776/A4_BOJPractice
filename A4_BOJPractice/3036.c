//https://www.acmicpc.net/problem/2981

//톱니바퀴처럼 물려있는 링 N개가 있다. 각 링의 반지름이 주어지고
//첫번째 링을 한 바퀴 돌릴때, 다른 링의 회전수를 N-1줄에 걸쳐 기약분수로 출력하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int up;
	int down;
} Fraction;


int main(void) {
	int ling_count;
	scanf("%d", &ling_count);

	int firstRing;
	scanf("%d", &firstRing);

	int basicFactor[50];
	int arrlen = 0;
	int temp = firstRing;

	for (int i = 2; temp != 1; i++) {
		if (temp % i == 0) {
			while (temp % i == 0)
			{
				temp /= i;
			}
			basicFactor[arrlen++] = i;
		}
	}

	Fraction* rotate = (Fraction*)malloc(sizeof(Fraction) * (ling_count - 1));
	for (int i = 0; i < ling_count - 1; i++) {
		int tempdown;
		scanf("%d", &tempdown);
		rotate[i].up = firstRing;
		rotate[i].down = tempdown;
		for (int j = 0; j < arrlen; j++) {
			if (rotate[i].down % basicFactor[j] == 0 && rotate[i].up % basicFactor[j] == 0) {
				rotate[i].down /= basicFactor[j];
				rotate[i].up /= basicFactor[j];
				j--;
			}
		}
	}

	for (int i = 0; i < ling_count - 1; i++) {
		printf("%d/%d\n", rotate[i].up, rotate[i].down);
	}



}
