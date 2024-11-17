//https://www.acmicpc.net/problem/14425

/* 문자열 집합 (Silver 4)
Solution : 셋
*/

#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int setCount, searchCount;
	string input;
	unordered_set<string> strset;

	cin >> setCount >> searchCount;
	while (setCount--)
	{
		cin >> input;
		strset.insert(input);
	}

	int ans = 0;
	while (searchCount--)
	{
		cin >> input;
		if (strset.find(input) != strset.end())
			ans++;
	}

	cout << ans;

	return 0;
}


