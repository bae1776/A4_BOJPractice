//https://www.acmicpc.net/problem/1938

/* 통나무 옮기기 (Gold 2)

최대 50x50 평지에 대하여 0, 1, B, E 중 하나의 문자로 된 문자열이 주어진다.
0은 빈 땅, 1은 장애물, B는 통나무의 시작 위치, E는 통나무가 가야할 위치이다.
통나무는 1x3 또는 3x1 구성으로 BBB 같은 형태로 되어있으며, E도 이와 같다.
통나무는 상하좌우로 움직일 수 있고, 통나무를 둘러싸는 3x3 공간에 아무것도 없으면 90도 회전할 수 있다.

B->E까지의 최소 동작(회전도 포함)횟수를 구하시오. 이동 불가능한 경우 0을 출력하시오.

Solution : BFS
방문처리를 잘하면 최대 가능한 방문 경우의 수는 50 * 50 * 2 = 5000 밖에 안되므로 시간 초과가 나지 않는다.
*/


#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using Element = tuple<int, int, bool>; //row, col, isVertical

char board[52][52];
bool visited[52][52][2]; //horizontal / vertical

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int boardSize;
    cin >> boardSize;

    Element start, end;
    for (int row = 1; row <= boardSize; row++)
    {
        cin >> board[row] + 1;

        for (int col = 1; col <= boardSize; col++)
            if (board[row][col] == 'B')
            {
                get<0>(start) = row;
                get<1>(start) = col;
            } else if (board[row][col] == 'E') {
                get<0>(end) = row;
                get<1>(end) = col;
            }
    }

    //시작 위치와 끝 위치 결정
    auto& [sy, sx, sIsVertical] = start;
    if (board[sy - 1][sx] == 'B')
    {
        sy--;
        board[sy - 1][sx] = board[sy][sx] = board[sy + 1][sx] = '0'; 
        sIsVertical = true;
    }
    else if (board[sy][sx - 1] == 'B')
    {
        sx--;
        board[sy][sx - 1] = board[sy][sx] = board[sy][sx + 1] = '0';
        sIsVertical = false;
    }

    auto& [ey, ex, eIsVertical] = end;
    if (board[ey - 1][ex] == 'E')
    {
        ey--;
        board[ey - 1][ex] = board[ey][ex] = board[ey + 1][ex] = '0'; 
        eIsVertical = true;
    }
    else if (board[ey][ex - 1] == 'E')
    {
        ex--;
        board[ey][ex - 1] = board[ey][ex] = board[ey][ex + 1] = '0';
        eIsVertical = false;
    }
    
    //BFS 수행
    int depth = 0;
    queue<Element> bfsQueue;
    bfsQueue.emplace(sy, sx, sIsVertical);
    visited[sy][sx][sIsVertical] = true;

    while (true)
    {
        int nowDepthCount = bfsQueue.size() + 1;
        while (--nowDepthCount)
        {
            auto& [y, x, isVertical] = bfsQueue.front();
            if (ey == y && ex == x && eIsVertical == isVertical)
                break;

            //move
            if (isVertical)
            {
                //Vertical : Left Move
                if (board[y-1][x-1] == '0' && board[y][x-1] == '0' && board[y+1][x-1] == '0'
                    && visited[y][x-1][isVertical] == false)
                {
                    visited[y][x-1][isVertical] = true;
                    bfsQueue.emplace(y, x-1, isVertical);
                }

                //Vertical : Right Move
                if (board[y-1][x+1] == '0' && board[y][x+1] == '0' && board[y+1][x+1] == '0'
                    && visited[y][x+1][isVertical] == false)
                {
                    visited[y][x+1][isVertical] = true;
                    bfsQueue.emplace(y, x+1, isVertical);
                }

                //Vertical : Up Move
                if (board[y-2][x] == '0' 
                    && visited[y-1][x][isVertical] == false)
                {
                    visited[y-1][x][isVertical] = true;
                    bfsQueue.emplace(y-1, x, isVertical);
                }

                //Vertical : Down Move
                if (board[y+2][x] == '0' 
                    && visited[y+1][x][isVertical] == false)
                {
                    visited[y+1][x][isVertical] = true;
                    bfsQueue.emplace(y+1, x, isVertical);
                }

            } else {
                //Horizontal : Left Move
                if (board[y][x-2] == '0' 
                    && visited[y][x-1][isVertical] == false)
                {
                    visited[y][x-1][isVertical] = true;
                    bfsQueue.emplace(y, x-1, isVertical);
                }

                //Horizontal : Right Move
                if (board[y][x+2] == '0' 
                    && visited[y][x+1][isVertical] == false)
                {
                    visited[y][x+1][isVertical] = true;
                    bfsQueue.emplace(y, x+1, isVertical);
                }

                //Horizontal : Up Move
                if (board[y-1][x-1] == '0' && board[y-1][x] == '0' && board[y-1][x+1] == '0'
                    && visited[y-1][x][isVertical] == false)
                {
                    visited[y-1][x][isVertical] = true;
                    bfsQueue.emplace(y-1, x, isVertical);
                }

                //Horizontal : Down Move
                if (board[y+1][x-1] == '0' && board[y+1][x] == '0' && board[y+1][x+1] == '0'
                    && visited[y+1][x][isVertical] == false)
                {
                    visited[y+1][x][isVertical] = true;
                    bfsQueue.emplace(y+1, x, isVertical);
                }
            }
            

            //rotate
            if (visited[y][x][!isVertical] == false)
            {
                bool rotatable = true;
                for (int dy = y - 1; dy <= y + 1; dy++)
                    for (int dx = x - 1; dx <= x + 1; dx++)
                        if (board[dy][dx] != '0')
                            rotatable = false;
                
                if (rotatable)
                {
                    visited[y][x][!isVertical] = true;
                    bfsQueue.emplace(y, x, !isVertical);
                }
            }
            


            bfsQueue.pop();
        }

        if (nowDepthCount || bfsQueue.empty())
            break;

        depth++;
    }

    if (bfsQueue.empty())
        cout << 0;
    else
        cout << depth;

    return 0;
}