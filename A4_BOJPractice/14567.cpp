//https://www.acmicpc.net/problem/14567

/*선수과목 (Prerequisite) (Gold 5)

Solution : 위상 정렬
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

list<int> nextCourse[1001];
int answer[1001], in[1001];


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int course, edgeCount;
	cin >> course >> edgeCount;

	int start, end;
	for (int i = 0; i < edgeCount; i++)
	{
		cin >> start >> end;
		nextCourse[start].emplace_back(end);
		in[end]++;
	}

	queue<int> enrollQueue;
	for (int i = 1; i <= course; i++)
	{
		if (in[i] == 0)
			enrollQueue.push(i);
	}

	int semester = 1;
	while (enrollQueue.empty() == false)
	{
		int qSize = enrollQueue.size();
		while (qSize--)
		{
			int enroll = enrollQueue.front();
			enrollQueue.pop();
			answer[enroll] = semester;
			for (const int& after : nextCourse[enroll])
			{
				in[after]--;
				if (in[after] == 0)
					enrollQueue.push(after);
			}
		}

		semester++;
	}

	for (int i = 1; i <= course; i++)
		cout << answer[i] << ' ';
	
	return 0;
}
