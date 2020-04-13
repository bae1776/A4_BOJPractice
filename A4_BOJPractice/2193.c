//https://www.acmicpc.net/problem/2193

//이친수

//0과 1로만 이루어진 수를 이진수라 한다.
//이러한 이진수 중 특별한 성질을 갖는 것들이 있는데, 이들을 이친수(pinary number)라 한다. 이친수는 다음의 성질을 만족한다.

//1. 이친수는 0으로 시작하지 않는다.
//2. 이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.

//예를 들면 1, 10, 100, 101, 1000, 1001 등이 이친수가 된다.
//하지만 0010101이나 101101은 각각 1, 2번 규칙에 위배되므로 이친수가 아니다.

//N(1 ≤ N ≤ 90)이 주어졌을 때, N자리 이친수의 개수를 구하는 프로그램을 작성하시오.


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
