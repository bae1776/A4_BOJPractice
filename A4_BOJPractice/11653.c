//https://www.acmicpc.net/problem/11653

//정수 N이 주어졌을 때 소인수분해하는 프로그램을 작성하시오.
//소인수 분해 인자는 오름차순으로 출력한다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int num;
	scanf("%d", &num);
	for (int i = 2; i <= num; i++) {
		while (num % i == 0) {
			printf("%d\n", i);
			num /= i;
		}
	}
	return 0;
}