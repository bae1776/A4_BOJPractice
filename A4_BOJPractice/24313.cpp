//https://www.acmicpc.net/problem/24313

/* �˰��� ���� - ������ ǥ�� 1 (Silver 5)
Solution :
O(n) ������ ���� ���� �� ���� (��� �����ؾ���)
1. n = n0���� f(n) <= c*g(n) �̴�.
2. f(n)�� ������ ����� c���� �۰ų� ����. (n�� �ſ� Ŀ���� �ε�� ���� ����)

*/


#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;

	cout << ((a1 * n0 + a0 <= c * n0) && (a1 <= c));

	return 0;
}


