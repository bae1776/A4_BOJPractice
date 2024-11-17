//https://www.acmicpc.net/problem/10845

//명령어 입력에 의한 큐를 구현하시오.
//18258 보다 입력 갯수가 적고 O(n)으로 구현하더라도 통과될 수도 있는 문제인 걸 빼면
//문제 내용은 동일함
//소스 코드는 18258번과 똑같이 넣어도 통과됨


#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int commandCount;
	cin >> commandCount;

	queue<int> myQueue;
	string command;

	for (int i = 0; i < commandCount; i++)
	{
		cin >> command;

		if (command.compare("push") == 0)
		{
			int value;
			cin >> value;
			myQueue.push(value);
		}
		else if (command.compare("pop") == 0)
		{
			if (!myQueue.empty())
			{
				cout << myQueue.front() << '\n';
				myQueue.pop();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (command.compare("size") == 0)
		{
			cout << myQueue.size() << '\n';
		}
		else if (command.compare("empty") == 0)
		{
			cout << myQueue.empty() << '\n';
		}
		else if (command.compare("front") == 0)
		{
			if (!myQueue.empty())
			{
				cout << myQueue.front() << '\n';
			}
			else {
				cout << "-1\n";
			}
		}
		else if (command.compare("back") == 0)
		{
			if (!myQueue.empty())
			{
				cout << myQueue.back() << '\n';
			}
			else {
				cout << "-1\n";
			}
		}
	}

	return 0;
}


