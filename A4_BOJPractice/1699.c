//https://www.acmicpc.net/problem/1699

//제곱 수의 합

//어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다. 
//예를 들어 11=9+1+1(3개 항)이다. 이런 표현방법은 여러 가지가 될 수 있는데, 
//11의 경우 11=4+4+1+1+1(5개 항)도 가능하다. 
//이 경우, 수학자 숌크라테스는 “11은 3개 항의 제곱수 합으로 표현할 수 있다.”라고 말한다. 
//또한 11은 그보다 적은 항의 제곱수 합으로 표현할 수 없으므로, 
//11을 그 합으로써 표현할 수 있는 제곱수 항의 최소 개수는 3이다.

//주어진 자연수 N을 이렇게 제곱수들의 합으로 표현할 때에 
//그 항의 최소개수를 구하는 프로그램을 작성하시오.
//N <= 100000

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int quadNum[400];

int main(void)
{
	int number;
	scanf("%d", &number);

	int i = 1;
	while (1) {
		int quad = i * i;
		quadNum[i] = i * i;
		if (quad <= number) {
			i++;
		}
		else break;
	}

	int* DP = (int*)malloc(sizeof(int) * (number + 1));

	
	int quadNumCursor = 1;
	for (int i = 1; i <= number; i++) {
		if (i == quadNum[quadNumCursor]) {
			DP[i] = 1;
			quadNumCursor++;
			continue;
		}
		else {
			int tempCursor = 1;
			int min = 123456789;
			while (i > quadNum[tempCursor]) {
				if (DP[i - quadNum[tempCursor]] < min) 
					min = DP[i - quadNum[tempCursor]];
				tempCursor++;
			}
			DP[i] = min + 1;
		}
	}


	printf("%d", DP[number]);
	free(DP);


	return 0;
}