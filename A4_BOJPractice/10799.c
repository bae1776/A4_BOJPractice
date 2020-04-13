//https://www.acmicpc.net/problem/10799

//쇠막대기
//( )(((( )( ))(( ))( )))(( ))
//       |  |    |   |     |
//      -|--|-  -|-  |     |
//     --|--|----|---|-    |
//    ---|--|----|---|--  -|-

//() 가 차례대로 나오는 부분에서 레이저를 연직방향으로 발사하여 쇠막대기를 자른다.
//이 경우 쇠막대기는 17 조각이 된다.
//최대 10만 길이의 괄호식이 주어질때, 생성되는 막대기 조각 수는?

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
