//https://www.acmicpc.net/problem/9020

//�������� ����

//� ¦�� n�� (2 <= n <= 10000) �־����� �� a+b=n (a, b�� �Ҽ� (a<b)) �� ������Ű�� a,b�� ����Ͻÿ�.

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

int main(void) {
	int primelist[1234] = { 0, };
	int input, testcase;
	scanf("%d", &testcase);

	for (int times = 0; times < testcase; times++) {
		scanf("%d", &input);

		int left = input / 2;
		int right = input / 2;

		while (1) {
		if (chkprime(left)) {
			if (chkprime(right)) {
				printf("%d %d\n", left, right);
				break;
			}
		}
		left--; right++;
		}
		
	}



}


