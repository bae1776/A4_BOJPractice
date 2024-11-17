//https://www.acmicpc.net/problem/2346

/* ǳ�� ��Ʈ���� (Silver 4)
Solution : ���̱� �ѵ� ����Ʈ�� ������
*/

#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	list<pair<int, int>> q;

	int n, input;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		q.push_back({ i, input });
	}

	while (true)
	{
		cout << q.front().first << ' ';
		int move = q.front().second;
		q.pop_front();

		if (q.empty()) break;

		if (move < 0)
		{
			while (move++) {
				q.push_front(q.back());
				q.pop_back();
			}
		}
		else if (move > 0) {
			while (--move) {
				q.push_back(q.front());
				q.pop_front();
			}
		}

	}


	return 0;
}

