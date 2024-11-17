//https://www.acmicpc.net/problem/24511

/* stackqueue (Silver 3)
Solution : 큐와 스택 혼합
설명이 복잡해서 어려워 보이나
그냥 큐인 자료구조의 원소만 스택 S에 push하고,
S의 원소를 하나씩 모두 끄집어내면서 Q에 다 넣은뒤,
이후 수열 C에 입력에 따라, Q에 push, 그리고 Q.pop을 출력하면 된다.
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isStack[100000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<int> q;
	stack<int> s;

	int ds;
	cin >> ds;

	for (int i = 0; i < ds; i++)
		cin >> isStack[i];

	int input;
	for (int i = 0; i < ds; i++)
	{
		cin >> input;
		if (!isStack[i])
			s.push(input);
	}

	while (s.empty() == false)
	{
		q.push(s.top());
		s.pop();
	}

	int size;
	cin >> size;

	while (size--)
	{
		cin >> input;
		q.push(input);
		cout << q.front() << ' ';
		q.pop();
	}

	return 0;
}

