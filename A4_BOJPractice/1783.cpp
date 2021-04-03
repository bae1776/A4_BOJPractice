//https://www.acmicpc.net/problem/1783

//병든 나이트
//나이트는 원래 2x1 칸씩 이동할 수 있지만 이 나이트는 병이 들어 오른쪽 방향으로 밖에 못 간다.
//체스판의 크기가 주어지고, 병든 나이트는 체스판의 왼쪽 아래일때,
//칸을 최대한 많이 밟았을 때의 값을 구하시오.

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