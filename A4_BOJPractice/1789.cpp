//https://www.acmicpc.net/problem/4796

//������ ��
//���� �ٸ� N���� �ڿ����� ���� S��� �Ѵ�. S�� �˶�, N�� �ִ���?


#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned int naturalNum;
	cin >> naturalNum;

	unsigned int max = 1;
	unsigned int sum = 0;
	unsigned int lastSum = 0;

	while (true)
	{
		sum += max;
		if (lastSum > sum || sum > naturalNum)
		{
			max--; break;
		}
		lastSum = sum;
		max++;
	}

	cout << max;


	return 0;
}