//https://www.acmicpc.net/problem/24265

/* �˰��� ���� - �˰����� ���� �ð� 4 (Bronze 3)
Solution :
�Է��� ũ�� n�϶�,
���� Ƚ���� (n-1) + (n-2) + ... + 1 = n(n-1)/2 �̰�
�ð����⵵�� O(n^2).
int ���� �ʰ��ʿ� ����
*/


#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long inputsize;
	cin >> inputsize;

	cout << inputsize * (inputsize-1) / 2 << '\n' << 2;

	return 0;
}


