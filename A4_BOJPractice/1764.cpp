//https://www.acmicpc.net/problem/1764

/* 듣보잡 (Silver 4)
Solution : 셋 -> 교집합
*/

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nohear, noseen;
	cin >> nohear >> noseen;
	vector<string> hList, sList;

	string input;
	while (nohear--)
	{
		cin >> input;
		hList.push_back(input);
	}
	sort(hList.begin(), hList.end());
		
	while (noseen--)
	{
		cin >> input;
		sList.push_back(input);
	}
	sort(sList.begin(), sList.end());

	vector<string> hsList(min(hList.size(), sList.size()));
	auto iter = set_intersection(hList.begin(), hList.end(), sList.begin(), sList.end(), hsList.begin());
	hsList.erase(iter, hsList.end());

	cout << hsList.size() << '\n';
	for (string& str : hsList)
		cout << str << '\n';


	return 0;
}


