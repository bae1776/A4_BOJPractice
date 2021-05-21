//https://www.acmicpc.net/problem/1010

/*�ٸ� ����
�ٸ��� ���� ���� ��Ҹ� ����Ʈ��� ����.
�� ������ �պ� �� �� �ִ� �ٸ��� ������� �Ѵ�.
������ ����Ʈ�� N��, ������ ����Ʈ�� M���̸�, N <= M�̴�.

�ٸ��� �ִ��� ���� ����� �ͱ� ������ N���� ������ �Ѵ�.
���� �ٸ� �ٸ��� �������� �ʵ��� �� ��, �ٸ��� ���� �� �ִ� ����� ����?
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