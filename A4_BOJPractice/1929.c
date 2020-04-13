//https://www.acmicpc.net/problem/1929

//입력된 두 자연수 사이의 소수 출력

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
	int start, end;
	scanf("%d ", &start);
	scanf("%d", &end);

	
	for (int i = start; i <= end; i++) {
		if (chkprime(i)) printf("%d\n", i);
	}

}