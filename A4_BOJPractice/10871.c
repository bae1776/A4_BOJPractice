//https://www.acmicpc.net/problem/10871

//첫째 줄에 N X 가 주어지고 둘째 줄에 N개 원소의 수열이 주어진다.
//이 중 X보다 작은 수만 공백으로 구분해 출력하는 프로그램이다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, X, A;
	scanf("%d %d", &N, &X);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A);

		// Tips : 10 3 4 8 와 같이 입력했을 때 반복되면서 다시 입력을 요구하는 것이 아니라
		// 그냥 공백 다음에 있는 글자를 자동으로 읽어준다.
		// 위 같은 경우, 처음 10 3 4 8 입력하면 첫 루프에선 A = 10, 두 번째 루프에서는 입력 받지
		// 않고 그냥 A = 3이 되고, 세 번째는 A = 4...

		if (A < X) printf("%d ", A);
	}
	
}