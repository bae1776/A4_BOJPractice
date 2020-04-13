//https://www.acmicpc.net/problem/10799

//�踷���
//( )(((( )( ))(( ))( )))(( ))
//       |  |    |   |     |
//      -|--|-  -|-  |     |
//     --|--|----|---|-    |
//    ---|--|----|---|--  -|-

//() �� ���ʴ�� ������ �κп��� �������� ������������ �߻��Ͽ� �踷��⸦ �ڸ���.
//�� ��� �踷���� 17 ������ �ȴ�.
//�ִ� 10�� ������ ��ȣ���� �־�����, �����Ǵ� ����� ���� ����?

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char str[100002];
	scanf("%s", str);
	
	int strLength = 0;
	while (str[strLength++] != '\0');
	strLength--;

	int lcount = 0, isLPrev = 0;
	long long result = 0;

	for (int i = 0; i < strLength; i++)
	{
		if (str[i] == '(')
		{
			lcount++;
			isLPrev = 1;
		}
		else {
			if (isLPrev) result += --lcount;
			else {
				lcount--;
				result++;
			}
			isLPrev = 0;
		}
	}

	printf("%lld", result);

	return 0;
}
