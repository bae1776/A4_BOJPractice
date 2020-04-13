//https://www.acmicpc.net/problem/1475

//ö���� 6�ڸ� ������ �ڿ��� �� ��ȣ�� �������� �Ѵ�. ��ȣ ��ƼĿ�� 0~9 ������ ��Ʈ ������ �Ǵ�. 
//�־��� �ڿ��� ��ȣ�� ���̷��� ��Ʈ�� �ּ� � �ʿ����� ����Ͻÿ�. ��, 6�� 9�� ������ �� �� �ִ�.

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