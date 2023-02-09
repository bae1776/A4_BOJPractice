//https://www.acmicpc.net/problem/1944

/* 복제 로봇 (Gold 1)

복제 로봇은 미로(최대 50 * 50)에서 모든 열쇠(최대 250)를 찾는 임무를 맡는다.
복제 로봇은 시작 위치 또는 열쇠가 있는 곳에서 원하는 만큼 복제할 수 있다.
모든 열쇠를 얻기 위한 이동 횟수의 최솟값을 구하시오. (복제된 로봇도 이동 횟수에 모두 포함됨)
모든 열쇠를 얻을 수 없는 미로인 경우에는 -1을 출력하시오.

모든 미로는 가장자리가 벽으로 둘러쌓여 있으며, 열쇠를 모두 얻은 후 한 자리로 모일 필요는 없다.
한 칸에 여러 로봇이 동시에 있을 수 있고, 이미 지나간 칸을 다시 지나가는 것도 가능하다.

Solution : MST
시작점/키가 있는 위치 간의 거리를 모두 구해 간선으로 만들고
최소 신장 트리를 찾으면 된다. 밀집 그래프가 되므로 Prim's Algorithm을 이용한다.
복제 로봇의 이동 거리는 최소 신장 트리의 가중치 합과 같다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define EMPTY -1
#define WALL 0

int mazeSize, keyCount;
int board[50][50]; // EMPTY -1, WALL 0, START 1, KEY 2~

vector<int> getAdjList(int startY, int startX);
int primMSTSize(const vector<vector<int>>& adjMatrix);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> mazeSize >> keyCount;

    //input
    char input;
    int keyIndex = 2;
    for (int i = 0; i < mazeSize; i++)
    {
        for (int j = 0; j < mazeSize; j++)
        {
            cin >> input;
            switch (input)
            {
                case '1':
                    break;
                case '0':
                    board[i][j] = EMPTY; break;
                case 'S':
                    board[i][j] = 1; break;
                case 'K':
                    board[i][j] = keyIndex++;
            }
        }
    }

    //make adjacent Matrix
    vector<vector<int>> adjMatrix(keyCount + 1);
    for (int i = 0; i < mazeSize; i++)
        for (int j = 0; j < mazeSize; j++)
        {
            if (board[i][j] >= 1)
                adjMatrix[board[i][j] - 1] = getAdjList(i, j);
        }

    bool hasAnswer = true;
    for (int& distanceToKey : adjMatrix[0])
        if (distanceToKey == -1)
            hasAnswer = false;

    if (hasAnswer)
    {
        cout << primMSTSize(adjMatrix);
    } else {
        cout << -1;
    }


    return 0;
}



vector<int> getAdjList(int startY, int startX)
{
    static const int dy[4] = {-1, 0, 0, 1};
    static const int dx[4] = {0, -1, 1, 0};
    vector<int> result(keyCount + 1, -1);
    vector<vector<char>> visited(mazeSize, vector<char>(mazeSize, false));
    queue<pair<int, int>> bfsQueue;

    visited[startY][startX] = true;
    bfsQueue.emplace(startY, startX);

    int depth = 0;
    while (bfsQueue.empty() == false)
    {
        int lookCount = bfsQueue.size();
        
        while (lookCount--)
        {
            const auto& [nowY, nowX] = bfsQueue.front();
            if (board[nowY][nowX] > EMPTY)
                result[board[nowY][nowX] - 1] = depth;
            
            for (int move = 0; move < 4; move++)
            {
                if (board[nowY + dy[move]][nowX + dx[move]] != WALL &&
                    visited[nowY + dy[move]][nowX + dx[move]] == false)
                {
                    visited[nowY + dy[move]][nowX + dx[move]] = true;
                    bfsQueue.emplace(nowY + dy[move], nowX + dx[move]);
                }
            }

            bfsQueue.pop();
        }

        depth++;
    }


    return result;

}


int primMSTSize(const vector<vector<int>>& adjMatrix)
{
    int totalDistance = 0;
    auto matrixSize = adjMatrix.size(); 
    vector<char> visited(matrixSize, false);
    vector<int> minDist(matrixSize, 0x3FFFFFFF);

    int nowVisit = 0;
    minDist[nowVisit] = 0;

    for (int edge = 0; edge < matrixSize - 1; edge++)
    {
        visited[nowVisit] = true;
        for (int next = 0; next < matrixSize; next++)
            minDist[next] = min(minDist[next], adjMatrix[nowVisit][next]);
        
        int nextDistance = 0x3FFFFFFF;
        for (int next = 0; next < matrixSize; next++)
        {
            if (visited[next] == false)
            {
                if (nextDistance == 0x3FFFFFFF || minDist[next] < nextDistance)
                {
                    nowVisit = next;
                    nextDistance = minDist[next];
                }
            }
        }

        totalDistance += nextDistance;
    }

    return totalDistance;
}