//https://www.acmicpc.net/problem/2884

//�˶� �ð�

//����̴� ���ÿ� �˶��� ���ߴ� �ǳ� �ʾ ���ú��� 45�� ���� �˶��� ���߷��� �Ѵ�. 
//��� ����� �ϴ°�?  �Ϸ��� ������ 0 0�̰� ���� 23 59 �̴�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int hour, min;
	scanf("%d %d", &hour, &min);

	min -= 45;
	if (min < 0) {
		hour--;
		min += 60;
	}
	if (hour < 0) {
		hour += 24;
	}


	printf("%d %d", hour, min);
}