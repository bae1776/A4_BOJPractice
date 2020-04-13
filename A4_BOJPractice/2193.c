//https://www.acmicpc.net/problem/2193

//��ģ��

//0�� 1�θ� �̷���� ���� �������� �Ѵ�.
//�̷��� ������ �� Ư���� ������ ���� �͵��� �ִµ�, �̵��� ��ģ��(pinary number)�� �Ѵ�. ��ģ���� ������ ������ �����Ѵ�.

//1. ��ģ���� 0���� �������� �ʴ´�.
//2. ��ģ�������� 1�� �� �� �������� ��Ÿ���� �ʴ´�. ��, 11�� �κ� ���ڿ��� ���� �ʴ´�.

//���� ��� 1, 10, 100, 101, 1000, 1001 ���� ��ģ���� �ȴ�.
//������ 0010101�̳� 101101�� ���� 1, 2�� ��Ģ�� ����ǹǷ� ��ģ���� �ƴϴ�.

//N(1 �� N �� 90)�� �־����� ��, N�ڸ� ��ģ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//DP[len][endsNum];


int main(void)
{
	int len;
	scanf("%d", &len);

	long long int(*DP)[2] = 
		(long long int(*)[2])malloc(sizeof(long long int) * 2 * (len + 1));
	DP[1][0] = 0;
	DP[1][1] = 1;

	for (int i = 2; i <= len; i++) {
		DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
		DP[i][1] = DP[i - 1][0];
	}

	printf("%lld", DP[len][0] + DP[len][1]);

	free(DP);


	return 0;
}
