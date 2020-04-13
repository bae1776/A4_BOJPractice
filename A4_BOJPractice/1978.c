//https://www.acmicpc.net/problem/1978

//소수 출력 기본

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int chkprime(int input) {
	if (input >= 4) {
		for (int i = 2; i <= (int)sqrt(input); i++) {
			if (!(input % i)) return 0;
		}
	}
	else return (input >> 1);
	return 1;
}

int main() {
	int testcase;
	scanf("%d", &testcase);

	int count = 0;
	int num;
	for (int i = 0; i < testcase; i++) {
		scanf("%d", &num);
		count += chkprime(num);
	}

	printf("%d", count);

}