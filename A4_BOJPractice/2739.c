//https://www.acmicpc.net/problem/2739

//������
//N�� �Է¹��� ��, ������ N���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��� ���Ŀ� ���缭 ����ϸ� �ȴ�.

#include <stdio.h>

int main() {
	int input;
	scanf("%d", &input);
	for (int i = 1; i <= 9; i++) {
		printf("%d * %d = %d\n", input, i, input*i);
	}
}