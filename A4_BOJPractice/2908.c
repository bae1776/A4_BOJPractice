//https://www.acmicpc.net/problem/2908 (���� ��ȣ)

//�� ���� �� �ڸ� �ڿ����� �ڸ��� ������ ���� �� �� ū ���� (������ ���·�) ����ϱ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void output(char num[]) {
	for (int i = 0; i < 3; i++) {
		printf("%d", num[i]);
	}
}

int main() {
	int ntr1, ntr2;
	scanf("%d ", &ntr1);
	scanf("%d", &ntr2);

	char ntr1_digit[3] = { ntr1 % 10 , ntr1 / 10 % 10 , ntr1 / 100 };
	char ntr2_digit[3] = { ntr2 % 10 , ntr2 / 10 % 10 , ntr2 / 100 };

	if (ntr1_digit[0] == ntr2_digit[0]) {
		if (ntr1_digit[1] == ntr2_digit[1]) {
		if (ntr1_digit[2] > ntr2_digit[2]) output(ntr1_digit);
		else output(ntr2_digit);
		}
		else if (ntr1_digit[1] > ntr2_digit[1]) output(ntr1_digit);
		else output(ntr2_digit);
	}
	else if (ntr1_digit[0] > ntr2_digit[0]) output(ntr1_digit);
	else output(ntr2_digit);

}