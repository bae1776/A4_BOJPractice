//https://www.acmicpc.net/problem/10869

//��Ģ ����
//�� �ڿ��� A,B�� �Է¹޾�
//ù° �ٿ� A+B, ��° �ٿ� A-B, ��° �ٿ� A*B, 
//��° �ٿ� A/B, �ټ�° �ٿ� A%B�� ����Ͻÿ�.

#include <stdio.h>

int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	printf("%d\n%d\n%d\n%d\n%d\n", A + B, A - B, A*B, A / B, A%B);
	return 0;
}