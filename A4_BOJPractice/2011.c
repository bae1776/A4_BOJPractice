//https://www.acmicpc.net/problem/2133

/* 암호 코드
상근이와 선영이가 다른 사람들이 남매간의 대화를 듣는 것을 방지하기 위해서 대화를 서로 암호화 하기로 했다.그래서 다음과 같은 대화를 했다.

상근 : 그냥 간단히 암호화 하자. A를 1이라고 하고, B는 2로, 그리고 Z는 26으로 하는거야.
선영 : 그럼 안돼. 만약, "BEAN"을 암호화하면 25114가 나오는데, 이걸 다시 글자로 바꾸는 방법은 여러 가지가 있어.

어떤 암호가 주어졌을 때, 그 암호의 해석이 몇 가지가 나올 수 있는지 구하는 프로그램을 작성하시오.
(최대 길이 5천 자리)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char secretCode[5002];
	scanf("%s", secretCode);

	int codeLength = strlen(secretCode);
	int* DP = (int*)malloc(sizeof(int) * codeLength);

	DP[0] = secretCode[0] == '0' ? 0 : 1;

	for (int i = 1; i < codeLength; i++) 
	{
		if (DP[i - 1] == 0)
		{
			DP[codeLength - 1] = 0;
			break;
		}

		switch (secretCode[i])
		{
		case '0':
			if (secretCode[i - 1] == '1' || secretCode[i - 1] == '2')
			{
				if (i == 1) DP[i] = 1;
				else DP[i] = DP[i - 2];
			}
			else {
				DP[i] = 0;
			}
			break;
		case '1': case '2': case '3': case '4': case '5': case '6':
			if (secretCode[i - 1] == '1' || secretCode[i - 1] == '2')
			{
				if (i == 1) DP[i] = 2;
				else DP[i] = (DP[i - 1] + DP[i - 2]) % 1000000;
			}
			else {
				DP[i] = DP[i - 1];
			}
			break;
		case '7': case '8': case '9':
			if (secretCode[i - 1] == '1')
			{
				if (i == 1) DP[i] = 2;
				else DP[i] = (DP[i - 1] + DP[i - 2]) % 1000000;
			}
			else {
				DP[i] = DP[i - 1];
			}
			break;
		}

	}
	
	printf("%d", DP[codeLength - 1]);


	return 0;
}
