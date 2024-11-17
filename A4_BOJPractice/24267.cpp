//https://www.acmicpc.net/problem/24267

/* �˰��� ���� - �˰����� ���� �ð� 6 (Bronze 2)
Solution :
�Է��� ũ�� n�϶�,
���� Ƚ���� (n-2) + (n-1) + ... + 1 + (n-3) + (n-2) + ... + 1 + ...
= sum of i(i+1)/2 for i in range(1, n-1) �� �ش�ȴ�.
�ð����⵵�� 3����.
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

	long long op = 0;
	for (long long i = 1; i <= inputsize - 2; i++)
		op += i * (i + 1) / 2;
	cout << op << '\n' << 3;

	return 0;
}


