//https://www.acmicpc.net/problem/4673

//"셀프 넘버" 수열을 출력하는 문제이다. 사이트 참고.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int selfnum(int input) {
	int output = input;
	while (input) {
		output += input % 10;
		input /= 10;
	}
	return output;
}

int main() {
	 for (int i = 1; i < 10000; i++) {
		if (i >= 1000) {
			int samechk = 0;
			for (samechk = i - 36; samechk < i; samechk++) {
				if (i == selfnum(samechk)) break;
			}
			if (samechk == i) printf("%d\n", i);
		}
		else if (i >= 100) {
			int samechk = 0;
			for (samechk = i - 27; samechk < i; samechk++) {
				if (i == selfnum(samechk)) break;
			}
			if (samechk == i) printf("%d\n", i);
		}
		else if (i >= 20) {
			int samechk = 0;
			for (samechk = i - 18; samechk < i; samechk++) {
				if (i == selfnum(samechk)) break;
			}
			if (samechk == i) printf("%d\n", i);
		}
		else {
			if (i%2 && i/2 <= 4) printf("%d\n", i);
		}

	}
	
	 return 0;
}