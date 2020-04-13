//https://www.acmicpc.net/problem/1904

//testcase�� n�� �Է� ���� �� �ĵ��� ����[n]�� testcase Ƚ����ŭ ���Ͻÿ�. (1 <= n <= 100)
//�ĵ��� ����[n]���� ���� �������� �̹� �׷��� ������ �� ���� �����ϴ� ���� ū n��° �ﰢ���� �׷��� ���� �� �ﰢ���� �Ѻ� �����̴�.
//1��° ���� ���� 1�̴�.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int testcase;
	scanf("%d", &testcase);

	long long int spinSeq[101] = { 0,1,1,1,2,2 };
	int lookidx = 6;

	for (int i = 0; i < testcase; i++)
	{
		int input;
		scanf("%d", &input);
		while (lookidx <= input)
		{
			spinSeq[lookidx] = spinSeq[lookidx-1] + spinSeq[lookidx-5];
			lookidx++;
		}

		printf("%lld\n", spinSeq[input]);
	}

	return 0;
}