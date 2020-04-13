//https://www.acmicpc.net/problem/1157 (문제 번호)

//주어진 단어에서 가장 많이 사용된 알파벳(대소문자구분 X)을 출력하는 프로그램을 만드시오.
//단 제일 많은 알파벳이 중복으로 있으면 ? 표시하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	

		char input[1000001];
		scanf("%s", input);

		int capital[26] = { 0, };
		int maxnum = 0;

		for (int i = 0; input[i] != 0; i++) {
			if (input[i] >= 'a' && input[i] <= 'z') input[i] += 'A' - 'a';
			capital[input[i] - 'A']++;
			if (capital[input[i] - 'A'] > maxnum) {
				maxnum = capital[input[i] - 'A'];
			}
		}

		char switcher = 0;
		for (int i = 0; i < 26; i++) {
			if (capital[i] == maxnum) switcher++;
		}

		if (switcher >= 2) printf("?");
		else {
			for (int i = 0; i < 26; i++) {
				if (capital[i] == maxnum) printf("%c", i + 'A');
			}
		}

		return 0;
}