//https://www.acmicpc.net/problem/19532

/* ������ ���鰭���Դϴ� (Bronze 2)
Solution : ���Ʈ����
��� x, y ��쿡 ���� �����غ��� ��
*/


#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	for (int x = -999; x <= 999; x++)
		for (int y = -999; y <= 999; y++)
			if ((a * x + b * y == c) && (d * x + e * y == f))
			{
				cout << x << ' ' << y;
				return 0;
			}

	return 0;
}


