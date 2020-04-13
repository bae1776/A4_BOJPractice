//https://www.acmicpc.net/problem/4153

//�����ﰢ��
//a b c �� �������� �־��� ��, �̸� ���� ���̷� �ϴ� �ﰢ���� �����ﰢ���̸� right, �ƴϸ� wrong��
//0 0 0 �� �Էµ� �� ���� �� ���� ����Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num[3];
	int maxidx = 3;

	do {
		switch (maxidx) {
		case 0:
			if (num[0] * num[0] == num[1] * num[1] + num[2] * num[2]) printf("right\n");
			else printf("wrong\n");
			break;
		case 1:
			if (num[1] * num[1] == num[0] * num[0] + num[2] * num[2]) printf("right\n");
			else printf("wrong\n");
			break;
		case 2:
			if (num[2] * num[2] == num[1] * num[1] + num[0] * num[0]) printf("right\n");
			else printf("wrong\n");
			break;
		case 3:
			break;
		}

		scanf("%d %d %d", &num[0], &num[1], &num[2]);
		maxidx = (num[0] > num[1]) ? (num[0] > num[2] ? 0 : 2) : (num[1] > num[2] ? 1 : 2);
	} while (num[0] != 0);


	return 0;
}