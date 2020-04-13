//https://www.acmicpc.net/problem/11401

//nCk % 1000000007 을 구하시오. (0 <= K <= N <= 4000000, N != 0)
//힌트 : 1000000007 은 소수이다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define PRIME 1000000007

long long int facModPrime(int n) {
	long long int result = 1;
	for (int i = n; i >= 2; i--) {
		result = result * i % PRIME;
	}
	return result;
}

long long int expMod(int a, int b) {
	if (b == 1)
		return a % PRIME;
	else {
		long long int half = expMod(a, b / 2);
		if (b % 2 == 0) return half * half % PRIME;
		else return ((half * half) % PRIME) * (long long int)a % PRIME;
	}
}



int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	//A = n!, B = k!(n-k)! 일때 답은 Ax(B^m-2)%m
	long long int A = facModPrime(N);
	long long int B = facModPrime(K) * facModPrime(N - K) % PRIME;
	long long int result = (expMod(B, PRIME - 2) * A) % PRIME;


	printf("%lld", result);
	


	return 0;

}