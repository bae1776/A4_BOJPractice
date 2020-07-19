//https://www.acmicpc.net/problem/14490

//백대열
//간단한 약분 문제

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	scanf("%d:%d", &a, &b);

	int realA = a, realB = b;
	
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}

	printf("%d:%d", realA / a, realB / a);


	return 0;
}
