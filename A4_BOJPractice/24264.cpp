//https://www.acmicpc.net/problem/24264

/* �˰��� ���� - �˰����� ���� �ð� 3 (Bronze 3)
Solution :
�Է��� ũ�� n�϶�,
���� Ƚ���� n^2�̰� �ð����⵵�� 2����.
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

	cout << inputsize * inputsize << '\n' << 2;

	return 0;
}


