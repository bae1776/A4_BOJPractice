//https://www.acmicpc.net/problem/4948

//�ڿ��� n�� �Է����� �� n �ʰ� 2n ���� ������ �Ҽ� ������ ����Ͻÿ�.
//0�� �Է��ϸ� �Է��� �����Ͻÿ�.
//(����Ʈ�� ���ؿ� ���� n~2n���̿� �Ҽ��� �ݵ�� �������� ����Ǿ���.)

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
	int input;
	while (1) {
		int number = 0;
		scanf("%d", &input);
		if (input == 0) break;
		for (int i = input + 1; i <= input * 2; i++) {
			if (chkprime(i)) number++;
		}
		printf("%d\n", number);
	}
}