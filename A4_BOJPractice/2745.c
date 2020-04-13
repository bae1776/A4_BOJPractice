//https://www.acmicpc.net/problem/2745

//���� ��ȯ

//N ���� ���� P(2~36)�� �־�����,
//N�� P���� �����̴�.
//�̸� 10������ ��ȯ�Ͻÿ�.
//��, N�� 10������ ��ȯ ������ 10�ﺸ�� �۴�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char num[100];
	int radix;
	scanf("%s %d", &num, &radix);

	int last_idx = strlen(num) - 1;
	int mulVar = 1;
	int result = 0;

	while (last_idx >= 0) {
		int temp;
		if (num[last_idx] <= '9')
			temp = num[last_idx] - '0';
		else temp = num[last_idx] - 'A' + 10;

		result += mulVar * temp;
		mulVar *= radix;
		last_idx--;
	}

	printf("%d", result);


}