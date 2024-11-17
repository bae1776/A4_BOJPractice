//https://www.acmicpc.net/problem/11478

/* 서로 다른 부분 문자열의 개수 (Silver 3)
Solution : 셋
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


	set<string> unique_substr;
	string input;
	
	cin >> input;
	int len = input.size();
	for (int offset = 0; offset < len; offset++)
		for (int size = 1; size <= len - offset; size++)
			unique_substr.insert(input.substr(offset, size));

	cout << unique_substr.size();

	return 0;
}


