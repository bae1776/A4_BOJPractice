//https://www.acmicpc.net/problem/10950

//A + B - 3
//ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.
//�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, �� �ٿ� A�� B�� �־�����. (0 < A, B < 10)
//�� �׽�Ʈ ���̽����� A + B�� ����Ѵ�.

int main() {
	int testcase;
	int a, b;

	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
}