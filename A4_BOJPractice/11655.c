//https://www.acmicpc.net/problem/11655

//ROT13
//���� ���ڿ��� ���ĺ� ��ҹ��ڸ� 13���ھ� �о� ��ȣȭ�ϴ� ���� ROT13�̶�� �Ѵ�.
//������ �־��� ��, ��ȣȭ�Ͽ� ����غ���. ���ĺ��� �����ϰ� ��ȣȭ�ϸ� �ȵȴ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char str[103];
	fgets(str, 102, stdin);

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 13;
			if (str[i] < 'a') str[i] += 26;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] -= 13;
			if (str[i] < 'A') str[i] += 26;
		}
	}

	printf("%s", str);

	return 0;
}