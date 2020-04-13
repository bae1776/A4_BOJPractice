//https://www.acmicpc.net/problem/2753

//윤년
//연도를 입력받고 윤년이면 1 아니면 0을 출력하시오.

#include <stdio.h>

int main() {
	short year;
	char output;
	scanf("%hd", &year);
	output = (year % 400 == 0) ? 1 : ((year % 100 == 0) ? 0 : ((year % 4) ? 0 : 1));
	printf("%d", output);

	return 0;
}