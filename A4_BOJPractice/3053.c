//https://www.acmicpc.net/problem/3053

//�ý� ������
//������ R�� ����, ��Ŭ���� �����п����� �� ����, �ý� �����п����� �� ���̸� �� �پ� ����Ͻÿ�.
//(�� ������� ������ 0.0001���� ���)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
	int radius;
	scanf("%d", &radius);

	printf("%.6lf\n", radius * radius * pi);
	printf("%d.000000", radius * radius * 2);
}

