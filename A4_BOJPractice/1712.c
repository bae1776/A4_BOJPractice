//https://www.acmicpc.net/problem/1712 (문제 번호)

//손익분기점

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int fixspent, unitspent, unitearn;
	scanf("%d %d %d", &fixspent, &unitspent, &unitearn);

	int unitprofit = unitearn - unitspent;
	if (unitprofit <= 0) {
		printf("-1");
	}
	else {
		printf("%d", fixspent / unitprofit + 1);
	}

	return 0;
}