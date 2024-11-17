//https://www.acmicpc.net/problem/24511

/* stackqueue (Silver 3)
Solution : ť�� ���� ȥ��
������ �����ؼ� ����� ���̳�
�׳� ť�� �ڷᱸ���� ���Ҹ� ���� S�� push�ϰ�,
S�� ���Ҹ� �ϳ��� ��� ������鼭 Q�� �� ������,
���� ���� C�� �Է¿� ����, Q�� push, �׸��� Q.pop�� ����ϸ� �ȴ�.
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

