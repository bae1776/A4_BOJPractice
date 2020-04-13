//https://www.acmicpc.net/problem/2941

//특정 크로아티아 알파벳을 대체한 두 글자 이상의 합성 알파벳을 실제 크로아티아 알파벳으로 치환하여 글자 수를 세시오.
//입력된 문자는 소문자와 합성 알파벳의 재료인 -, = 으로만 이루어져 있다.

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