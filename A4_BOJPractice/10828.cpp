//https://www.acmicpc.net/problem/10828

//명령어 입력에 의한 스택을 구현하시오.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int commandCount;
	cin >> commandCount;

	stack<int> myStack;
	string command;

	for (int i = 0; i < commandCount; i++)
	{
		cin >> command;

		if (command.compare("push") == 0)
		{
			int value;
			cin >> value;
			myStack.push(value);
		}
		else if (command.compare("pop") == 0)
		{
			if (!myStack.empty())
			{
				cout << myStack.top() << '\n';
				myStack.pop();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (command.compare("size") == 0)
		{
			cout << myStack.size() << '\n';
		}
		else if (command.compare("empty") == 0)
		{
			cout << myStack.empty() << '\n';
		}
		else if (command.compare("top") == 0)
		{
			if (!myStack.empty())
			{
				cout << myStack.top() << '\n';
			}
			else {
				cout << "-1\n";
			}
		}
	}
	



	return 0;
}


