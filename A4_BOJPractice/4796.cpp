//https://www.acmicpc.net/problem/4796

//ķ��
//�谭��� �������� �Բ� ķ���� ������. ������, ķ���忡�� ������ ���� ����� ���� �־���.
//ķ������ �����ϴ� P�� �� L�� ���ȸ� ����� �� �ֽ��ϴ�.
//�谭�� ���� ���� �� V�� �ް��� �����ߴ�. �̹� �ް� �Ⱓ ���� �����̴� ķ������ ��ĥ ���� ����� �� ������?

//�Է��� L P V�� �־�����.

#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int permitted, interval, vacation;
	int caseOrder = 1;

	while (true)
	{
		cin >> permitted >> interval >> vacation;
		if (permitted == 0) 
			break;

		int fullCycle = vacation / interval;
		int leftCycle = vacation % interval;

		cout << "Case " << caseOrder++ << ": " <<
			fullCycle * permitted + [](int a, int b) {return a > b ? b : a; } (permitted, leftCycle) << '\n';
	}


	return 0;
}