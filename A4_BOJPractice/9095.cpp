//https://www.acmicpc.net/problem/9095

//���� 1 ~ 10�� 1, 2, 3�� �� �÷� ��Ÿ�� �� �ִ� ������ ���Ͻÿ�.

#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int DP[11] = { 0, 1, 2, 4 };

	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int input;
		cin >> input;

		if (DP[input] == 0)
		{
			for (int i = 4; i <= input; i++)
			{
				DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
			}
		}

		cout << DP[input] << '\n';
	}

	return 0;
}