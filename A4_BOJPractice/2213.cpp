//https://www.acmicpc.net/problem/2213

/*트리의 독립집합

트리에서 정점의 부분 집합 S에 속한 모든 정점쌍이 서로 인접하지 않으면 
S를 독립집합(independent set)이라고 한다.

독립 집합의 크기는 정점에 가중치가 주어져 있지 않을 경우에는 독립 집합에 속한 정점의 수를 말하고
가중치가 주어져 있으면 독립 집합에 속한 정점의 가중치의 합으로 정의한다.

이때 크기가 최대인 독립 집합을 최대 독립 집합이라고 한다.

트리의 정점이 최대 10000개 주어지고, 각 정점의 가중치(10000 이하)가 주어질 때,
최대 독립 집합의 크기와, 독립 집합의 원소를 오름차순으로 출력하시오.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nodeCount;
int weightList[10001];
int DP[10001][2];
vector<int> adjList[10001];
vector<int> resultSet;

void dfs(int prev, int now);
void track(int prev, int now, bool parentIncludedSet);



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    
    cin >> nodeCount;

    for (int i = 1; i <= nodeCount; i++)
        cin >> weightList[i];

    int start, end;
    for (int i = 1; i <= nodeCount - 1; i++)
    {
        cin >> start >> end;

        adjList[start].emplace_back(end);
        adjList[end].emplace_back(start);

    }
	
    dfs(0, 1);
    
    cout << max(DP[1][false], DP[1][true]) << '\n';

    track(0, 1, false);

    sort(resultSet.begin(), resultSet.end());

    for (const int& setElement : resultSet)
        cout << setElement << ' ';

	return 0;
}


void dfs(int prev, int now)
{
    DP[now][true] = weightList[now];

    for (const int& adjNode : adjList[now])
    {
        if (adjNode != prev)
        {
            dfs(now, adjNode);
            DP[now][true] += DP[adjNode][false];
            DP[now][false] += max(DP[adjNode][false], DP[adjNode][true]);
        }
    }
    
    return;
}

void track(int prev, int now, bool parentIncludedSet)
{
    if (parentIncludedSet == false && DP[now][false] < DP[now][true])
    {
        resultSet.emplace_back(now);
        parentIncludedSet = true;
    } else
        parentIncludedSet = false;

    for (const int& adjNode : adjList[now])
    {
        if (adjNode != prev)
            track(now, adjNode, parentIncludedSet);
    }
}