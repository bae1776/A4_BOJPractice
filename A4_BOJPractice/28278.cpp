//https://www.acmicpc.net/problem/28278

/* 스택 2 (Silver 4)
Solution : 스택 기능 구현
*/

#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int query;
	cin >> query;
	stack<int> s;

	while (query--)
	{
		int n;
		cin >> n;
		if (n == 1)
		{
			int in;
			cin >> in;
			s.push(in);
		}
		else if (n == 2) {
			if (s.empty())
				cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (n == 3) {
			cout << s.size() << '\n';
		}
		else if (n == 4) {
			cout << s.empty() << '\n';
		}
		else if (n == 5) {
			if (s.empty())
				cout << -1 << '\n';
			else
				cout << s.top() << '\n';
		}
	}

	return 0;
}
