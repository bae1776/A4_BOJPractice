//https://www.acmicpc.net/problem/17413

//�ܾ� ������ 2
//�±׿� �ܾ�� �̷���� ������ �ִ�.
//<tag>word go<tag> --> <tag>drow og<tag>
//�±׷� ���� ���ڴ� ������ ����, �ܾ ����� ����Ͻÿ�.

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



