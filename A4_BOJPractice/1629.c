//https://www.acmicpc.net/problem/1629

//A B C �� �־��� ��, (A^B)%C�� ���Ͻÿ�. A, B, C�� 21�� �����̴�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int halfCal(long long int num, long long int mult, long long int mod) {
	if (mult == 0)
		return 1;
	else {
		long long int half = halfCal(num, mult / 2, mod); 
		if ((mult & 1) == 0)
			return half * half % mod;
		else
			return ((half * half) % mod * num) % mod;
	}

}

int main(void) {
	long long int A, B, C;
	scanf("%lld %lld %lld", &A, &B, &C);

	printf("%lld", halfCal(A, B, C));

	return 0;
}