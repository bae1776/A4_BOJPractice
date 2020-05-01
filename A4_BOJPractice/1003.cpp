//https://www.acmicpc.net/problem/1003

//n�� �Է¹޾� n��° �Ǻ���ġ ���� ��������� ���� ��, fib(0), fib(1)�� ȣ��Ǵ� Ƚ����
//���� �Է¹��� �׽�Ʈ ���̽� ������ŭ ���� ����Ͻÿ�.


#include <iostream>
#include <utility>
#include <array>

using namespace std;

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b)
{
	return pair<int, int>(a.first + b.first, a.second + b.second);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	array<pair<int, int>, 41> fiboCall;
	fiboCall[0] = make_pair(1, 0);
	fiboCall[1] = make_pair(0, 1);


	int testcase;
	cin >> testcase;

	int max = 1;

	for (int i = 0; i < testcase; i++)
	{
		int input;
		cin >> input;

		if (input > max)
		{
			for (int j = max + 1; j <= input; j++)
			{
				fiboCall[j] = fiboCall[j - 2] + fiboCall[j - 1];
			}
			max = input;
		}

		std::cout << fiboCall[input].first << ' ' << fiboCall[input].second << '\n';
	}


	return 0;

}