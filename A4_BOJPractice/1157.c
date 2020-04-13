//https://www.acmicpc.net/problem/1157 (���� ��ȣ)

//�־��� �ܾ�� ���� ���� ���� ���ĺ�(��ҹ��ڱ��� X)�� ����ϴ� ���α׷��� ����ÿ�.
//�� ���� ���� ���ĺ��� �ߺ����� ������ ? ǥ���Ͻÿ�.

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