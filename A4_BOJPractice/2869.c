//https://www.acmicpc.net/problem/2869

//�����̴� �ö󰡰� �ʹ�
//�Ϸ翡 a��ŭ �ö󰬴� b��ŭ �̲������� �����̰� �ִ�. c��ŭ �ö���� �� �ɸ��� ��(����)�� ����Ͻÿ�.
//�Է� : a b c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int up, down, goal;
	scanf("%d %d %d", &up, &down, &goal);


	if (goal <= down + 1) {
		printf("1");
	}
	else {
		printf("%d", (goal - down - 1) / (up - down) + 1);
	}


	return 0;
}