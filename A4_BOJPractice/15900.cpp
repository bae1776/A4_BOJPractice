//https://www.acmicpc.net/problem/15900

/* 나무 탈출 (Silver 1)

Solution : BFS
이 문제의 정답은 각 리프노드에서 루트노드로 가는 거리의 합이
홀수이면 Yes, 짝수이면 No를 출력하면 된다.

여기서, 이 탐색은 너비 우선 탐색으로 가능하다.
*/


#include <iostream>
#include <list>
#include <queue>
using namespace std;

list<int> adjList[500001];
bool visited[500001] = {false};
queue<int> bfsQueue;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int nodeCount;
    cin >> nodeCount;

    int start, end;
    bfsQueue.push(1);
    visited[1] = true;
    for (int i = 0; i < nodeCount - 1; i++)
    {
        cin >> start >> end;
        adjList[start].push_back(end);
        adjList[end].push_back(start);
    }

    long long total = 0;
    int depth = 0;
    while (bfsQueue.empty() == false)
    {
        int queueSize = bfsQueue.size();
        while (queueSize--)
        {
            const int& now = bfsQueue.front();
            
            if (adjList[now].size() == 1 && depth != 0)
                total += depth;
            else {
                for (const int& next : adjList[now])
                {
                    if (!visited[next])
                    {
                        visited[next] = true;
                        bfsQueue.push(next);
                    }
                }
            }
            bfsQueue.pop();
        }
        depth++;
    }


    if (total % 2)
        cout << "Yes";
    else
        cout << "No";

	return 0;
}


