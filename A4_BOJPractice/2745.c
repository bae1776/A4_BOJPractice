//https://www.acmicpc.net/problem/2745

//진법 변환

//N 값과 정수 P(2~36)가 주어질때,
//N은 P진수 정수이다.
//이를 10진수로 변환하시오.
//단, N은 10진수로 변환 했을때 10억보다 작다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char num[100];
	int radix;
	scanf("%s %d", &num, &radix);

	int last_idx = strlen(num) - 1;
	int mulVar = 1;
	int result = 0;

	while (last_idx >= 0) {
		int temp;
		if (num[last_idx] <= '9')
			temp = num[last_idx] - '0';
		else temp = num[last_idx] - 'A' + 10;

		result += mulVar * temp;
		mulVar *= radix;
		last_idx--;
	}

	printf("%d", result);


}