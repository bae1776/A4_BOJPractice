//https://www.acmicpc.net/problem/12789

/* 도키도키 간식드리미 (Silver 3)
Solution : 스택 수열 여부 판단
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
	int line[1001];

	for (int i = 0; i < query; i++)
		cin >> line[i];

	int lineidx = 0;
	int happy = 1;

	while (true)
	{
		if (lineidx < query)
		{
			if (line[lineidx] == happy)
			{
				lineidx++;
				happy++;
			}
			else if (s.empty() == false && s.top() == happy)
			{
				s.pop();
				happy++;
			}
			else {
				s.push(line[lineidx++]);
			}
		}
		else {
			while (s.empty() == false)
			{
				if (s.top() == happy)
				{
					s.pop();
					happy++;
				}
				else break;
			}
			break;
		}

	}

	if (happy == query + 1)
		cout << "Nice";
	else
		cout << "Sad";



	return 0;
}
