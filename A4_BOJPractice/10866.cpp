//https://www.acmicpc.net/problem/10866

//명령어 입력에 의한 덱(deque)을 구현하시오.


#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int commandCount;
	cin >> commandCount;

	deque<int> myDeque;
	string command;

	for (int i = 0; i < commandCount; i++)
	{
		cin >> command;

		if (command.compare("push_back") == 0)
		{
			int value;
			cin >> value;
			myDeque.push_back(value);
		} 
		else if (command.compare("push_front") == 0)
		{
			int value;
			cin >> value;
			myDeque.push_front(value);
		}
		else if (command.compare("pop_front") == 0)
		{
			if (!myDeque.empty())
			{
				cout << myDeque.front() << '\n';
				myDeque.pop_front();
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (command.compare("pop_back") == 0)
		{
			if (!myDeque.empty())
			{
				cout << myDeque.back() << '\n';
				myDeque.pop_back();
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (command.compare("size") == 0)
		{
			cout << myDeque.size() << '\n';
		}
		else if (command.compare("empty") == 0)
		{
			cout << myDeque.empty() << '\n';
		}
		else if (command.compare("front") == 0)
		{
			if (!myDeque.empty())
			{
				cout << myDeque.front() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (command.compare("back") == 0)
		{
			if (!myDeque.empty())
			{
				cout << myDeque.back() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
	}

	return 0;
}
