//https://www.acmicpc.net/problem/10820

//���ڿ� �м�
//���ڿ� �ִ� 100���� �־��� ��, �� ���� �ҹ���, �빮��, ����, ������ ������
//�������� �����Ͽ� ����Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char str[103];

	while (1) {
		int small = 0, big = 0, num = 0, space = 0;
		if (fgets(str, 102, stdin) == NULL) break;

		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				small++;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				big++;
			else if (str[i] >= '0' && str[i] <= '9')
				num++;
			else if (str[i] == ' ')
				space++;
		}
		printf("%d %d %d %d\n", small, big, num, space);
	}
}