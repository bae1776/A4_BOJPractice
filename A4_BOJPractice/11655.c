//https://www.acmicpc.net/problem/11655

//ROT13
//원본 문자열을 알파벳 대소문자를 13글자씩 밀어 암호화하는 것을 ROT13이라고 한다.
//원문이 주어질 때, 암호화하여 출력해보자. 알파벳을 제외하곤 암호화하면 안된다.

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