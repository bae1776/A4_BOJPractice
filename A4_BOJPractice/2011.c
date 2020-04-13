//https://www.acmicpc.net/problem/2133

/* ��ȣ �ڵ�
����̿� �����̰� �ٸ� ������� ���Ű��� ��ȭ�� ��� ���� �����ϱ� ���ؼ� ��ȭ�� ���� ��ȣȭ �ϱ�� �ߴ�.�׷��� ������ ���� ��ȭ�� �ߴ�.

��� : �׳� ������ ��ȣȭ ����. A�� 1�̶�� �ϰ�, B�� 2��, �׸��� Z�� 26���� �ϴ°ž�.
���� : �׷� �ȵ�. ����, "BEAN"�� ��ȣȭ�ϸ� 25114�� �����µ�, �̰� �ٽ� ���ڷ� �ٲٴ� ����� ���� ������ �־�.

� ��ȣ�� �־����� ��, �� ��ȣ�� �ؼ��� �� ������ ���� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
(�ִ� ���� 5õ �ڸ�)
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
