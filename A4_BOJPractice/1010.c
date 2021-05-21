//https://www.acmicpc.net/problem/1010

/*다리 놓기
다리를 놓기 좋은 장소를 사이트라고 하자.
강 동서를 왕복 할 수 있는 다리를 만들려고 한다.
서쪽의 사이트는 N개, 동쪽의 사이트는 M개이며, N <= M이다.

다리를 최대한 많이 만들고 싶기 때문에 N개를 지으려 한다.
서로 다른 다리가 교차되지 않도록 할 때, 다리를 지을 수 있는 경우의 수는?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long combination(int a, int b)
{
	if (b > a / 2)
		return combination(a, a - b);

	long long result = 1;

	for (int i = 0; i < b; i++)
	{
		result *= a - i;
		result /= (i + 1);
	}
		

	return result;
}


int main(void)
{
	int testcase;
	scanf("%d", &testcase);

	for (int tc = 0; tc < testcase; tc++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", combination(b, a));
	}
}