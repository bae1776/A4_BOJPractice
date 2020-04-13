//https://www.acmicpc.net/problem/5086

//�� ���� �־�����, ù ���ڰ� �ι�° ������ ����� factor, ����� multiple, �� �� �ƴϸ� neither�� ����Ͻÿ�.
//�� �Է��� 0 0 �� �Է��� ������ ������ �ݺ��Ѵ�.
//+�� ���� ���� ���� ����.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	while (1) {
		int left, right;
		scanf("%d %d", &left, &right);

		if (left == 0 && right == 0) break;

		if (left < right)
		{
			int orgleft = left;
			while (left < right) {
				left += orgleft;
			}

			if (left == right) printf("factor\n");
			else printf("neither\n");
		}
		else if (left > right)
		{
			int orgright = right;
			while (left > right) {
				right += orgright;
			}

			if (left == right) printf("multiple\n");
			else printf("neither\n");
		}
	}


	return 0;
}