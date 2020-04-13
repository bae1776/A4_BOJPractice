//https://www.acmicpc.net/problem/2941

//Ư�� ũ�ξ�Ƽ�� ���ĺ��� ��ü�� �� ���� �̻��� �ռ� ���ĺ��� ���� ũ�ξ�Ƽ�� ���ĺ����� ġȯ�Ͽ� ���� ���� ���ÿ�.
//�Էµ� ���ڴ� �ҹ��ڿ� �ռ� ���ĺ��� ����� -, = ���θ� �̷���� �ִ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char str[101];
	scanf("%s", str);
	
	int str_length = 0;
	int replcount = 0;

	for (; str[str_length] != 0; str_length++) {
		switch (str[str_length]) {
		case '-':
			replcount++; break;
		case 'j':
			if (str_length >= 1) {
				if (str[str_length - 1] == 'l' || str[str_length - 1] == 'n') replcount++;
			} 
			break;
		case '=':
			if (str_length >= 1) {
				if (str[str_length - 1] == 'c' || str[str_length - 1] == 's') replcount++;
				else if (str[str_length - 1] == 'z') {
					replcount++;
					if (str_length >= 2) {
						if (str[str_length - 2] == 'd') replcount++;
					}
				}
			}
		}
	}

	printf("%d", str_length - replcount);
}