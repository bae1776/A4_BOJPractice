//https://www.acmicpc.net/problem/17267

/*상남자 (Platinum 5)
최대 1000 * 1000 공간에 땅 혹은 벽(갈 수 없는 곳), 출발 지점이 주어진다.
영조와 보성이는 상하로는 무제한 자유롭게 이동할 수 있지만
좌, 우로는 각각 L, R번만 움직일 수 있을 경우, 출발 지점을 포함하여 갈 수 있는 땅의 개수를 출력하시오.

Solution : 단순 BFS만 이용하면, 특정 경우에 틀릴 수 있다.
위, 아래로 움직이는 것에 대해서는 우선순위를 부여해 먼저 탐색하고 그 다음, 좌, 우를 탐색하는 순으로 변형하여야 틀리지 않는다.
*/

#include <iostream>
#include <queue>
using namespace std;

struct Element {
    short y, x, leftLimit, rightLimit;
};

char board[1004][1004];
bool visited[1004][1004];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    short rowSize, colSize;
    cin >> rowSize >> colSize;

    short leftLimit, rightLimit;
    cin >> leftLimit >> rightLimit;

    short startY, startX;
    for (int i = 0; i < rowSize; i++)
    {
        cin >> board[i];
        for (int j = 0; j < colSize; j++)
            if (board[i][j] == '2')
            {
                startY = i;
                startX = j;
                board[i][j] = '0';
            }
    }
    
    queue<Element> verticalQueue, horizontalQueue;
    verticalQueue.push({startY, startX, leftLimit, rightLimit});

    while (true)
    {
        Element now;
        if (verticalQueue.empty() == false)
        {
            now = verticalQueue.front();
            verticalQueue.pop();
        }
        else if (horizontalQueue.empty() == false)
        {
            now = horizontalQueue.front();
            horizontalQueue.pop();
        }
        else break;

        if (visited[now.y][now.x] == true)
            continue;

        visited[now.y][now.x] = true;

        if (now.y != 0 && board[now.y - 1][now.x] != '1' && visited[now.y - 1][now.x] == false)
            verticalQueue.push({now.y - 1, now.x, now.leftLimit, now.rightLimit});
        
        if (now.y != rowSize - 1 && board[now.y + 1][now.x] != '1' && visited[now.y + 1][now.x] == false)
            verticalQueue.push({now.y + 1, now.x, now.leftLimit, now.rightLimit});

        if (now.x != 0 && board[now.y][now.x - 1] != '1' && visited[now.y][now.x - 1] == false &&
            now.leftLimit != 0)
            horizontalQueue.push({now.y, now.x - 1, now.leftLimit - 1, now.rightLimit});
        
        if (now.x != colSize - 1 && board[now.y][now.x + 1] != '1' && visited[now.y][now.x + 1] == false &&
            now.rightLimit != 0)
            horizontalQueue.push({now.y, now.x + 1, now.leftLimit, now.rightLimit - 1});
    }

    int count = 0;
    for (int i = 0; i < rowSize; i++)
        for (int j = 0; j < colSize; j++)
            if (visited[i][j])
                count++;

    cout << count;

    return 0;
}   
