//https://www.acmicpc.net/problem/28279

/* µ¦ 2 (Silver 4)
Solution : µ¦ »ç¿ëÇÏ±â
*/

#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int query;
	cin >> query;
	deque<int> s;

	while (query--)
	{
		int n;
		cin >> n;
		if (n == 1)
		{
			int in;
			cin >> in;
			s.push_front(in);
		}
		else if (n == 2) {
			int in;
			cin >> in;
			s.push_back(in);
		}
		else if (n == 3) {
			if (s.empty())
				cout << -1 << '\n';
			else {
				cout << s.front() << '\n';
				s.pop_front();
			}
		}
		else if (n == 4) {
			if (s.empty())
				cout << -1 << '\n';
			else {
				cout << s.back() << '\n';
				s.pop_back();
			}
		}
		else if (n == 5) {
			cout << s.size() << '\n';
		}
		else if (n == 6) {
			cout << s.empty() << '\n';
		}
		else if (n == 7) {
			if (s.empty())
				cout << -1 << '\n';
			else
				cout << s.front() << '\n';
		}
		else if (n == 8) {
			if (s.empty())
				cout << -1 << '\n';
			else
				cout << s.back() << '\n';
		}
	}

	return 0;
}

