//https://www.acmicpc.net/problem/5622 (���� ��ȣ)

//������ ��ȭ���� ���̾��� ������ �� �ɸ��� �ð��� �����ϴ� ���α׷�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char dial[16];
	scanf("%s", dial);
	int times = 0;

	for (int i = 0; dial[i] != 0; i++) {
		switch (dial[i]) {
		case 'A': case 'B': case 'C': times--;
		case 'D': case 'E': case 'F': times--;
		case 'G': case 'H': case 'I': times--;
		case 'J': case 'K': case 'L': times--;
		case 'M': case 'N': case 'O': times--;
		case 'P': case 'Q': case 'R': case 'S': times--;
		case 'T': case 'U': case 'V': times--;
		case 'W': case 'X': case 'Y': case 'Z': times += 10;
		}
	}

	printf("%d", times);
}