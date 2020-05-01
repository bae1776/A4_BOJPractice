//https://www.acmicpc.net/problem/11726

//2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int DP[1001] = { 0, 1, 2 };

	int input;
	cin >> input;

	for (int i = 3; i <= input; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
	}


	cout << DP[input];
	


	return 0;
}