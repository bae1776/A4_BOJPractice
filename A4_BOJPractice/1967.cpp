//https://www.acmicpc.net/problem/1967

/*트리의 지름

트리의 지름이란 트리의 임의의 두 점 사이의 거리 중 가장 긴 것을 말합니다.
트리의 지름을 구하는 프로그램을 작성하십시오.

트리는 정점이 최대 1만개 이고 가중치가 있다.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> distanceDP[10002]; 
vector<pair<int, int>> adjList[10002];
bool visited[10002];

int dfs(const int& nodeNumber, const int& distFrom1, const int& beforeNodeLen);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int vertex;
    cin >> vertex;

    for (int i = 1; i <= vertex - 1; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        adjList[start].emplace_back(weight, end);
        
    }

    dfs(1, 0, 0);

    int maxDist = 0, firstMax, secondMax;
    for (int nodeNumber = 1; nodeNumber <= vertex; nodeNumber++)
    {
        if (distanceDP[nodeNumber].size() == 1)
            maxDist = max(maxDist, distanceDP[nodeNumber][0]);
        else
        {
            firstMax = max(distanceDP[nodeNumber][0], distanceDP[nodeNumber][1]);
            secondMax = min(distanceDP[nodeNumber][0], distanceDP[nodeNumber][1]);

            for (int i = 2; i < distanceDP[nodeNumber].size(); i++)
            {
                if (firstMax < distanceDP[nodeNumber][i])
                {
                    secondMax = firstMax;
                    firstMax = distanceDP[nodeNumber][i];
                } else if (secondMax < distanceDP[nodeNumber][i])
                    secondMax = distanceDP[nodeNumber][i];
            }

            maxDist = max(maxDist, firstMax + secondMax);
        }
    }


    cout << maxDist;

    return 0;
}


int dfs(const int& nodeNumber, const int& distFrom1, const int& beforeNodeLen)
{
    visited[nodeNumber] = true;
    distanceDP[nodeNumber].emplace_back(distFrom1);

    for (const auto& nodeEdge : adjList[nodeNumber])
    {
        if (visited[nodeEdge.second] == false)
            distanceDP[nodeNumber].emplace_back(dfs(nodeEdge.second, distFrom1 + nodeEdge.first, nodeEdge.first));
    }

    int maxDist = 0;
    for (auto iter = distanceDP[nodeNumber].begin() + 1; iter != distanceDP[nodeNumber].end(); ++iter)
        if (maxDist < *iter)
            maxDist = *iter;

    return maxDist + beforeNodeLen;
}


