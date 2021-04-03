//https://www.acmicpc.net/problem/17413

//단어 뒤집기 2
//태그와 단어로 이루어진 문장이 있다.
//<tag>word go<tag> --> <tag>drow og<tag>
//태그로 쌓인 문자는 뒤집지 말고, 단어만 뒤집어서 출력하시오.

#include <iostream>
#include <string>
using namespace std;




int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	getline(cin, str);

	auto start_itr = str.begin();
	auto end_itr = str.begin();
	auto tag = false;
	
	for (; end_itr != str.end(); ++end_itr)
	{
		if (*end_itr == '<')
		{
			tag = true;
			string subString(start_itr, end_itr);
			for (auto i = subString.rbegin(); i != subString.rend(); ++i)
				cout << *i;
			start_itr = end_itr;
		}
		else if (*end_itr == '>') {
			tag = false;
			cout << string(start_itr, end_itr + 1);
			start_itr = end_itr + 1;
		}
		else if (*end_itr == ' ' && tag == false)
		{
			string subString(start_itr, end_itr);
			for (auto i = subString.rbegin(); i != subString.rend(); ++i)
				cout << *i;
			cout << ' ';
			start_itr = end_itr + 1;
		}

	}

	string subString(start_itr, end_itr);
	for (auto i = subString.rbegin(); i != subString.rend(); ++i)
		cout << *i;
	start_itr = end_itr;
	
	return 0;
}



