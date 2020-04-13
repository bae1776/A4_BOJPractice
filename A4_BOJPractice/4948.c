//https://www.acmicpc.net/problem/4948

//자연수 n을 입력했을 때 n 초과 2n 이하 사이의 소수 갯수를 출력하시오.
//0을 입력하면 입력을 종료하시오.
//(베르트랑 공준에 의해 n~2n사이에 소수가 반드시 존재함은 증명되었다.)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int chkprime(int input) {
	if (input >= 4) {
		for (int i = 2; i <= (int)sqrt(input); i++) {
			if (!(input % i)) return 0;
		}
	}
	else return (input >> 1);
	return 1;
}

int main() {
	int input;
	while (1) {
		int number = 0;
		scanf("%d", &input);
		if (input == 0) break;
		for (int i = input + 1; i <= input * 2; i++) {
			if (chkprime(i)) number++;
		}
		printf("%d\n", number);
	}
}