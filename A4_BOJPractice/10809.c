//https://www.acmicpc.net/problem/10809

//���ĺ� �ҹ��ڰ� ó�� �����ϴ� ��ġ�� ����Ͻÿ�. (�� ù �ڸ��� 0���� �ϰ� ���� ����) ������ -1 ���.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char alphabet_digit[26] = { 0, };

	char input[101];
	scanf("%s", input);

	for (int i = 0; input[i] != 0; i++) {
		int index = input[i] - 'a';
		if (alphabet_digit[index] == 0) alphabet_digit[index] = i + 1;
	}

	for (int i = 0; i < 26; i++) {
		alphabet_digit[i]--;
		printf("%d ", alphabet_digit[i]);
	}
	return 0;
}