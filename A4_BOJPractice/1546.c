//https://www.acmicpc.net/problem/1546 (���� ��ȣ)

//������ �ʹ� ���.
//����ϸ� ���� ���� �� �ִ��� �̾Ƴ��� ��Ģ�������� �̷���� ���ο� ����� ���ض�.. ����.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int subjectnum, max = 0, scan;
	double sum = 0;
	scanf("%d", &subjectnum);
	for (int i = 1; i <= subjectnum; i++) {
		scanf("%d", &scan);
		if (scan > max) max = scan;
		sum += scan * 100;
	}
	sum /= (max * subjectnum);
	printf("%f", sum);
}