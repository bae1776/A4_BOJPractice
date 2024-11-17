//https://www.acmicpc.net/problem/7785

/* µèº¸Àâ (Silver 4)
Solution : ¼Â
*/

#include <set>
#include <string>
#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int query;
	cin >> query;

	set<string> office;

	while (query--)
	{
		string who, go;
		cin >> who >> go;

		if (go.compare("enter") == 0)
			office.insert(who);
		else //leave
			office.erase(who);
	}

	for (auto it = office.rbegin(); it != office.rend(); ++it)
		cout << *it << '\n';

	return 0;
}


