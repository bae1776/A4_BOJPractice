//https://www.acmicpc.net/problem/1316 (���� ��ȣ)

//�׷� �ܾ��� ������ ����ϴ� �����̴�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int datacase;
	scanf("%d", &datacase);

	char **wordlist;
	wordlist = malloc(sizeof(char*) * datacase);
	
	char bools = 0;

	for (int i = 0; i < datacase; i++) {
		wordlist[i] = malloc(sizeof(char) * 101);
		scanf("%s", wordlist[i]);

		
		//�׷�ܾ� üũ
		char alphabet[26] = { 0 };
		for (int j = 0; wordlist[i][j] != 0; j++) {
			if (alphabet[wordlist[i][j] - 'a'] != 0 && j > 0) {
				if (wordlist[i][j] == wordlist[i][j - 1]) continue;
				else {
					bools++;
					break;
				}
			}
			else alphabet[wordlist[i][j] - 'a']++;
		}
	}

	printf("%d", datacase - bools);
}