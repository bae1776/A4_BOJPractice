//https://www.acmicpc.net/problem/16236

/*아기 상어 (Gold 3)

N*N 공간(최대 20 * 20)에 물고기 M마리와 아기 상어 1마리가 있다.
아기 상어와 물고기는 모두 자연수의 크기를 가진다. (물고기는 1~6) 아기 상어는 다음 규칙을 따라 움직인다.
1. 처음 아기 상어의 크기는 2이고, 1초에 1칸씩 움직일 수 있다.
2. 아기 상어는 자기보다 작은 물고기만 먹을 수 있고, 자기보다 큰 물고기는 지나갈 수 없다.
3. 아기 상어는 다음과 같은 과정으로 이동한다.
 - 더 이상 먹을 수 있는 물고기가 없는 경우 엄마 상어에게 도움을 요청한다.
 - 먹을 수 있는 물고기가 1마리면, 그 물고기를 먹으러 간다.
 - 먹을 수 있는 물고기가 2마리 이상이면, 가장 빨리 먹을 수 물고기 쪽으로 간다.
   (여러 마리가 거리가 같은 경우, 가장 위쪽 -> 가장 왼쪽 순으로 물고기를 선택한다.)
4. 물고기를 먹는 데 걸리는 시간은 없다고 가정한다.
5. 아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때마다 크기가 1 증가한다.

공간이 주어질 때, 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하시오.
Solution : BFS + 시뮬레이션
*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using tuple3 = tuple<int, int, int>;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int sharkSize = 2, sharkExp = 0, moveCount = 0;
    int boardSize;
    cin >> boardSize;

    pair<int, int> sharkLoc;
    vector<vector<int>> board(boardSize, vector<int>(boardSize));
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
                sharkLoc = {i, j};
        }


    while (true)
    {
        //현재 상태에서 BFS 탐색하여 가장 가까운 먹이 찾기
        vector<vector<char>> visited(boardSize, vector<char>(boardSize, false));
        queue<tuple3> bfsQueue;
        int nextLocDistance = -1;
        vector<pair<int, int>> nextLocList;
        bfsQueue.emplace(sharkLoc.first, sharkLoc.second, 0);
        board[sharkLoc.first][sharkLoc.second] = 0;
        visited[sharkLoc.first][sharkLoc.second] = true;
        
        while (bfsQueue.empty() == false)
        {
            const auto& [y, x, depth] = bfsQueue.front();
            if (depth == nextLocDistance)
                break;

            if (y != 0 && visited[y - 1][x] == false && board[y - 1][x] <= sharkSize)
            {
                visited[y - 1][x] = true;
                if (board[y - 1][x] == sharkSize || board[y - 1][x] == 0)
                {
                    bfsQueue.emplace(y - 1, x, depth + 1);
                } else {
                    nextLocDistance = depth + 1;
                    nextLocList.emplace_back(y - 1, x);
                }
            }

            if (y != boardSize - 1 && visited[y + 1][x] == false && board[y + 1][x] <= sharkSize)
            {
                visited[y + 1][x] = true;
                if (board[y + 1][x] == sharkSize || board[y + 1][x] == 0)
                {
                    bfsQueue.emplace(y + 1, x, depth + 1);
                } else {
                    nextLocDistance = depth + 1;
                    nextLocList.emplace_back(y + 1, x);
                }
            }

            if (x != 0 && visited[y][x - 1] == false && board[y][x - 1] <= sharkSize)
            {
                visited[y][x - 1] = true;
                if (board[y][x - 1] == sharkSize || board[y][x - 1] == 0)
                {
                    bfsQueue.emplace(y, x - 1, depth + 1);
                } else {
                    nextLocDistance = depth + 1;
                    nextLocList.emplace_back(y, x - 1);
                }
            }

            if (x != boardSize - 1 && visited[y][x + 1] == false && board[y][x + 1] <= sharkSize)
            {
                visited[y][x + 1] = true;
                if (board[y][x + 1] == sharkSize || board[y][x + 1] == 0)
                {
                    bfsQueue.emplace(y, x + 1, depth + 1);
                } else {
                    nextLocDistance = depth + 1;
                    nextLocList.emplace_back(y, x + 1);
                }
            }

            bfsQueue.pop();
        }

        if (nextLocList.empty()) break;

        //먹이를 찾은 경우, 그 먹이는 사라지고 아기 상어는 경험치/크기를 얻는다.
        //- 다음 먹이 선택
        pair<int, int> nextLoc = nextLocList[0];
        for (int i = 1; i < nextLocList.size(); i++)
        {
            if (nextLocList[i].first < nextLoc.first)
                nextLoc = nextLocList[i];
            else if (nextLocList[i].first == nextLoc.first && nextLocList[i].second < nextLoc.second)
                nextLoc = nextLocList[i];
        }

        moveCount += nextLocDistance;
        sharkExp++;
        if (sharkExp == sharkSize)
        {
            sharkExp = 0;
            sharkSize++;
        }
        sharkLoc = nextLoc;
    }

    cout << moveCount;
    
	return 0;
}