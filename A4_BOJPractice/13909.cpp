//https://www.acmicpc.net/problem/13909

/* â�� �ݱ� (Silver 5)
Solution : n^2 ���� ������ â���� ���� ���°� �ȴ�.
K�� â���� K�� ��� ������ŭ ���� �ݴ� �۾��� �ϴµ�, ���� �ݴ� �۾��� Ȧ�����ؾ� â���� ���� ���°� �ȴ�.
�׷��� K�� n^2 �ø� �����Ѵ�. 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	double input;
	cin >> input;
	cout << (int)sqrt(input);

	return 0;
}
