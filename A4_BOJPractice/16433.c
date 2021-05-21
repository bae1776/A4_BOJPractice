//https://www.acmicpc.net/problem/16433

//�ֵ�� ��� ����
//��ȸ ��ũ : https://www.acmicpc.net/category/detail/1949

#include <stdio.h>

int main(void) {
	int size, row, col;

	scanf("%d %d %d", &size, &row, &col);
	int sub = row > col ? row - col : col - row;

	switch (sub % 2) {
	case 0:  //(Ȧ��, Ȧ��) (¦��, ¦��)���� �ɱ�� ��
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i + j & 1) { //Ȧ���̸� .
					printf(".");
				}
				else {
					printf("v");
				}
			}
			printf("\n");
		}
		break;
	case 1:  //�� ���迡�� �ɱ�
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i + j & 1) { //Ȧ���̸� .
					printf("v");
				}
				else {
					printf(".");
				}
			}
			printf("\n");
		}
	}

}