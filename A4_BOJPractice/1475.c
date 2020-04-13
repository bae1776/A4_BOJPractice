//https://www.acmicpc.net/problem/1475

//철수가 6자리 이하의 자연수 방 번호를 붙히려고 한다. 번호 스티커는 0~9 까지의 세트 단위로 판다. 
//주어진 자연수 번호를 붙이려면 세트가 최소 몇개 필요할지 출력하시오. 단, 6과 9는 돌려서 쓸 수 있다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char input[7];
	scanf("%s", input);
	
	char number[10] = { 0 };
	
	for (int i = 0; input[i] != 0; i++) {
		number[input[i]-'0']++;
	}

	number[6] += number[9];
	number[6] = number[6] / 2 + number[6] % 2;


	int set = 0;
	for (int i = 0; i < 9; i++) {
		if (number[i] > set) set = number[i];
	}

	printf("%d", set);



}