//https://www.acmicpc.net/problem/1414

/*불우이웃돕기 (Gold 3)

Solution : MST

최소 신장 트리를 이용하여
최소한의 랜선만을 이용해서 모든 컴퓨터를 연결해놓고 나머지는 기부하면 된다.
*/

#include <iostream>
#include <vector>
using namespace std;

int adjList[50][50];
int totalLength;
int prim(int nodeCount);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int comCount;
    cin >> comCount;

    char input;
    for (int i = 0; i < comCount; i++)
        for (int j = 0; j < comCount; j++)
        {
            cin >> input;
            
            if ('a' <= input && input <= 'z')
                adjList[i][j] = input - 'a' + 1;
            else if ('A' <= input && input <= 'Z')
                adjList[i][j] = input - 'A' + 27;
            else if (input == '0')
                adjList[i][j] = 0;

            totalLength += adjList[i][j];

            if (i == j)
                adjList[i][j] = 0;
        }

    for (int i = 0; i < comCount; i++)
        for (int j = i + 1; j < comCount; j++)
        {
            if (adjList[i][j] == 0 && adjList[j][i] == 0)
                continue;
            else if (adjList[i][j] == 0 || adjList[j][i] == 0)
                adjList[i][j] = adjList[j][i] = max(adjList[i][j], adjList[j][i]);
            else
                adjList[i][j] = adjList[j][i] = min(adjList[i][j], adjList[j][i]);
        }

    int minLAN = prim(comCount);
    if (minLAN == -1)
        cout << -1;
    else
        cout << totalLength - minLAN;

	return 0;
}


int prim(int nodeCount)
{
    vector<int> minDist(nodeCount, 0x3FFFFFFF);
    vector<char> visited(nodeCount, false);
    int total = 0;
    int now = 0;

    for (int i = 0; i < nodeCount - 1; i++)
    {
        visited[now] = true;

        int dist = 0x3FFFFFFF, index = -1;
        for (int next = 0; next < nodeCount; next++)
        {
            if (adjList[now][next] != 0)
                minDist[next] = min(minDist[next], adjList[now][next]);

            if (visited[next] == false && minDist[next] < dist)
            {
                index = next;
                dist = minDist[next];
            }
        }

        if (index == -1)
            return -1;
        else {
            total += dist;
            now = index;
        }
    }

    return total;
}
