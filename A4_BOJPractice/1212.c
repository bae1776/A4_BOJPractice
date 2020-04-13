//https://www.acmicpc.net/problem/1212

//8���� 2����
//8������ �־����� 2������ ��ȯ�ϼ���.
//�־����� ���� ���̴� �ִ� 333444����.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char converter[8][4] = { "000", "001", "010", "011", "100", "101", "110", "111" };

int main(void)
{

	char str[333335];
	scanf("%s", str);

	switch (str[0]) {
	case '0':
		printf("0");
		break;
	case '1':
		printf("1");
		break;
	case '2':
		printf("10");
		break;
	case '3':
		printf("11");
		break;
	default:
		printf("%s", converter[str[0] - '0']);
	}

	

	int idx = 1;
	while (str[idx] != 0) {
		printf("%s", converter[str[idx++] - '0']);
	}
	

	return 0;
}