//https://www.acmicpc.net/problem/24266

/* �˰��� ���� - �˰����� ���� �ð� 5 (Bronze 3)
Solution :
�Է��� ũ�� n�϶�,
���� Ƚ���� n^3�̰� �ð����⵵�� 3����.
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

	cout << inputsize * inputsize * inputsize << '\n' << 3;

	return 0;
}


