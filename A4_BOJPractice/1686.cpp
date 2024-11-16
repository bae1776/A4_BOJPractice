//https://www.acmicpc.net/problem/1686

/* 복날 (Gold 4)
Solution : 너비 우선 탐색
벙커가 최대 1000개이므로 a->b 벙커 거리를 모두 계산해도 O(n^2)으로
시간이 초과되지 않는다.
벙커를 최소한으로 들러야하므로 BFS 탐색을 하는 것이 적절하다.
*/

#include <iostream>
#include <queue>
#include <cmath>
#define MAXNODE 1004
using namespace std;
double dist[MAXNODE][MAXNODE];
pair<double, double> loc[MAXNODE];
bool visited[MAXNODE];


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    double speed, time;
    cin >> speed >> time;
    double limit = pow(speed * time * 60.0, 2);

    cin >> loc[0].first >> loc[0].second;
    cin >> loc[1].first >> loc[1].second;

    int bunkerCount = 2;
    while (cin >> loc[bunkerCount].first)
    {
        cin >> loc[bunkerCount].second;
        bunkerCount++;
    }

    for (int start = 0; start < bunkerCount; start++)
    {
        for (int end = start + 1; end < bunkerCount; end++)
        {
            dist[start][end] = dist[end][start]
                = pow(loc[start].first - loc[end].first, 2) + pow(loc[start].second - loc[end].second, 2);                
        }
    }

    queue<pair<int, int>> bfsQueue; //now, depth;
    bfsQueue.emplace(0, 0);
    visited[0] = true;

    while (bfsQueue.empty() == false)
    {
        auto [idx, depth] = bfsQueue.front();
        bfsQueue.pop();

        if (idx == 1)
        {
            cout << "Yes, visiting " << depth - 1 << " other holes.";
            return 0;
        }

        for (int next = 0; next < bunkerCount; next++)
        {
            if (visited[next] == false && dist[idx][next] < limit)
            {
                visited[next] = true;
                bfsQueue.emplace(next, depth + 1);
            }
        }
    }
    
    cout << "No.";

	return 0;
}
