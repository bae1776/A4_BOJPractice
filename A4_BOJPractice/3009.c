//https://www.acmicpc.net/problem/3009

//�� ��° ��
//�� �������� ��ǥ�� �־��� ��, ���簢���� �ǰ� �ϴ� ������ �� ���� ��ǥ�� ����Ͻÿ�.
//(�Ұ����� ��츦 ���� ����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x[3];
	int y[3];

	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &x[i], &y[i]);

	}

	int ansx, ansy;

	if (x[0] == x[1]) ansx = x[2];
	else if (x[0] == x[2]) ansx = x[1];
	else ansx = x[0];

	if (y[0] == y[1]) ansy = y[2];
	else if (y[0] == y[2]) ansy = y[1];
	else ansy = y[0];

	printf("%d %d", ansx, ansy);
}

