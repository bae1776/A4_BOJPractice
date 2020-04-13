//https://www.acmicpc.net/problem/1654

//랜선 K개를 잘라 랜선 N개를 만들려고 할때
//가능한 최대 길이는?
//K <= N이고 K는 10000 이하, N은 1000000 이하의 자연수이다.
//랜선의 처음 길이는 int 범위이다. (음수는 당연히 아님)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a == *(int*)b) return 0;
	else return -1;
}

long long int maxCase(int* lens, int arrlen, long long int left, long long int right, int wants)
{
	while (left <= right)
	{
		long long int middle = (left + right) / 2;
		if (middle == 0) return 1;

		long long int result = 0;
		for (int i = 0; i < arrlen; i++) {
			result += lens[i] / middle;
		}

		if (result < wants) {
			right = middle - 1;
		}
		else if (result >= wants) {
			left = middle + 1;
		}
	}

	return right;
}


int main(void)
{
	int org, wants;
	scanf("%d %d", &org, &wants);

	int* orglens = (int*)malloc(sizeof(int) * org);
	for (int i = 0; i < org; i++) {
		scanf("%d", &orglens[i]);
	}

	qsort(orglens, org, sizeof(int), cmp);

	printf("%lld", maxCase(orglens, org, 0, orglens[org - 1], wants));



	return 0;
}


