//https://www.acmicpc.net/problem/1783

//���� ����Ʈ
//����Ʈ�� ���� 2x1 ĭ�� �̵��� �� ������ �� ����Ʈ�� ���� ��� ������ �������� �ۿ� �� ����.
//ü������ ũ�Ⱑ �־�����, ���� ����Ʈ�� ü������ ���� �Ʒ��϶�,
//ĭ�� �ִ��� ���� ����� ���� ���� ���Ͻÿ�.

#include <iostream>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int row, col;

	cin >> row >> col;

	switch (row) {
	case 1:
		cout << 1;
		break;
	case 2:
		if (col >= 9)
			cout << 4;
		else
			cout << (col + 1) / 2;
		break;
	default:
		switch (col) {
		case 1: case 2: case 3: case 4:
			cout << col;
			break;
		case 5: case 6:
			cout << 4;
			break;
		default:
			cout << col - 2;
			break;
		}
		break;
	}


	return 0;
}