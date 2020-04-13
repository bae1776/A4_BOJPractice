//https://www.acmicpc.net/problem/2581

//�Էµ� �� �ڿ��� ������ �Ҽ��� �հ� �� �Ҽ��� �� �ּڰ��� ��� (���� ���� �Ҽ��� ������ -1 ���)

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
	int start, end;
	scanf("%d ", &start);
	scanf("%d", &end);

	int primenum = 0, primesum = 0;

	for (int i = start; i <= end; i++) {
		if (chkprime(i)) {
			if (!primenum) primenum = i;
			primesum += i;
		}
	}

	if (primenum) printf("%d\n%d", primesum, primenum);
	else printf("-1");
}