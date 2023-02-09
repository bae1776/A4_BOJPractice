//https://www.acmicpc.net/problem/11559

/* Puyo Puyo (Gold 4)

뿌요뿌요의 룰은 다음과 같다.
필드에 여러 색깔의 뿌요를 하나씩 놓는다. 뿌요는 중력의 영향을 받아 바닥이나 다른 뿌요 위에 떨어진다.
뿌요를 놓고 난 후, 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면, 그 뿌요들이 한꺼번에 없어지며 1연쇄가 시작된다.
뿌요들이 없어지고 나서 위에 뿌요들이 떠 있으면 중력에 따라 차례대로 아래에 떨어진다.
아래에 떨어지고 나서 또 다시 위 삭제 조건을 만족하면 1연쇄 씩 늘어나며 뿌요가 삭제된다. (반복)

12 * 6의 뿌요판이 주어질 때, 몇 연쇄가 일어날 지 출력하시오.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char board[12][7];
int lookBlock(vector<vector<char>>& visited, const int& startY, const int& startX);
void dropBlock();

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for (int i = 0; i < 12; i++)
        cin >> board[i];


    int result = 0;
    
    while (true)
    {
        bool poped = false;
        vector<vector<char>> visited(12, vector<char>(6, false));

        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 6; j++)
                if (board[i][j] != '.' && visited[i][j] == false)
                { 
                    if (lookBlock(visited, i, j) >= 4)
                        poped = true;
                }

        if (poped) result++;
        else break;

        dropBlock();
    }

    cout << result;
    
	return 0;
}


pair<int, int> temp[80];

int lookBlock(vector<vector<char>>& visited, const int& startY, const int& startX)
{
    int count = 0;
    char nowColor = board[startY][startX];
    queue<pair<int, int>> bfsQueue;
    bfsQueue.emplace(startY, startX);
    visited[startY][startX] = true;

    while (bfsQueue.empty() == false)
    {
        auto& now = temp[count++] = bfsQueue.front();
        bfsQueue.pop();
        
        if (now.first != 0 && visited[now.first - 1][now.second] == false && board[now.first - 1][now.second] == nowColor)
        {
            visited[now.first - 1][now.second] = true;
            bfsQueue.emplace(now.first - 1, now.second);
        }

        if (now.first != 11 && visited[now.first + 1][now.second] == false && board[now.first + 1][now.second] == nowColor)
        {
            visited[now.first + 1][now.second] = true;
            bfsQueue.emplace(now.first + 1, now.second);
        }

        if (now.second != 0 && visited[now.first][now.second - 1] == false && board[now.first][now.second - 1] == nowColor)
        {
            visited[now.first][now.second - 1] = true;
            bfsQueue.emplace(now.first, now.second - 1);
        }

        if (now.second != 5 && visited[now.first][now.second + 1] == false && board[now.first][now.second + 1] == nowColor)
        {
            visited[now.first][now.second + 1] = true;
            bfsQueue.emplace(now.first, now.second + 1);
        }
    }

    if (count >= 4)
        for (int i = 0; i < count; i++)
            board[temp[i].first][temp[i].second] = '.';

    return count;
}



void dropBlock()
{
    int blockList[12];

    for (int col = 0; col < 6; col++)
    {
        int colBlockCount = 0;

        for (int i = 11; i >= 0; i--)
        {
            if (board[i][col] != '.')
                blockList[colBlockCount++] = i;    
        }

        for (int i = 0; i < colBlockCount; i++)
            board[11 - i][col] = board[blockList[i]][col];

        for (int i = 11 - colBlockCount; i >= 0; i--)
            board[i][col] = '.';
    }

}