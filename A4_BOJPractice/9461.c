//https://www.acmicpc.net/problem/1904

//testcase와 n을 입력 받을 때 파도반 수열[n]을 testcase 횟수만큼 구하시오. (1 <= n <= 100)
//파도반 수열[n]값은 나선 방향으로 이미 그려진 도형과 한 변을 공유하는 가장 큰 n번째 삼각형을 그렸을 때의 그 삼각형의 한변 길이이다.
//1번째 수열 값은 1이다.


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