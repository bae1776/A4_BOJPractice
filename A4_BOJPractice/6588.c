//https://www.acmicpc.net/problem/6588

//골드바흐의 추측

//4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다는 것이 이 추측의 전부이다.
//백만 이하의 짝수에 대해 이를 검증하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool isOddPrime[500000] = { false, true, true };  // 1, 3, 5 ...
int isOddPrimeCursor = 3;
int primeSet[1000] = { 2, 3, 5 };
int primeSetCursor = 3;


int main(void)
{
	for (int i = 7; i < 1000000; i += 2) {
		int j = 0;
		for (; primeSet[j] * primeSet[j] <= i; j++)
			if (i % primeSet[j] == 0) {
				j = -1;
				break;
			}
		if (j >= 0) {
			if (i < 1111) {
				primeSet[primeSetCursor++] = i;
			}
			isOddPrime[isOddPrimeCursor++] = true;
		}
		else {
			isOddPrimeCursor++;
		}
	}

	int input;
	scanf("%d", &input);

	while (input) {
		int left = 1;
		int right = input / 2 - 2; // 6 -> 1 , 8 -> 2, 10 -> 3

		while (!(isOddPrime[left] && isOddPrime[right])) {
			left++;
			right--;
			if (left > right) {
				printf("Goldbach's conjecture is wrong.\n");
				left = 0x7FFFFFFF;
				break;
			}
		}

		if (left != 0x7FFFFFFF) {
			printf("%d = %d + %d\n", input, left * 2 + 1, right * 2 + 1);
		}
		scanf("%d", &input);
	}

	return 0;
}


