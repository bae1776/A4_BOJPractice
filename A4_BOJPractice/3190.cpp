//https://www.acmicpc.net/problem/3190

/* 뱀 (Gold 4)

스네이크 게임이 몇 초에 끝나는지 구하여라. (뱀은 1초에 1칸을 간다)
뱀의 시작 위치는 좌상단 끝이고, 진행 방향은 처음에 오른쪽이다.

보드의 크기는 최대 100이고, 사과의 개수도 최대 100개이다.
그리고 사과의 위치와, 방향 전환 방향 및 시간이 오름차순으로 주어진다.

Solution : 시뮬레이션
*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

enum {EMPTY, SNAKE, APPLE};
enum {RIGHT, DOWN, LEFT, UP};
int board[102][102];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int boardSize;
    cin >> boardSize;

    int appleCount;
    cin >> appleCount;

    while (appleCount--)
    {
        int y, x;
        cin >> y >> x;
        board[y][x] = APPLE;
    }

    list<pair<int, int>> snakeLocation;
    
    int rotateCount;
    cin >> rotateCount;

    vector<pair<int, char>> rotateList(rotateCount);

    for (int i = 0; i < rotateCount; i++)
        cin >> rotateList[i].first >> rotateList[i].second;

    
    snakeLocation.emplace_front(1, 1);
    board[1][1] = SNAKE;
    int snakeDir = RIGHT, time = 0;
    auto nextRotate = rotateList.begin();

    while (true)
    {
        ++time;
        auto [nextY, nextX] = snakeLocation.front();

        //try Move
        switch (snakeDir)
        {
            case RIGHT:
                nextX++;
                break;
            case DOWN:
                nextY++;
                break;
            case LEFT:
                nextX--;
                break;
            case UP:
                nextY--;
        }

        if (nextY < 1 || nextY > boardSize 
         || nextX < 1 || nextX > boardSize || board[nextY][nextX] == SNAKE)
            break;

        //apply Move
        if (board[nextY][nextX] != APPLE)
        {
            auto& [passedY, passedX] = snakeLocation.back();
            board[passedY][passedX] = EMPTY;
            snakeLocation.pop_back();
        }

        snakeLocation.emplace_front(nextY, nextX);
        board[nextY][nextX] = SNAKE;


        //rotate
        if (nextRotate != rotateList.end() && nextRotate->first == time)
        {
            if (nextRotate->second == 'L')
            {
                snakeDir--;
                if (snakeDir == -1)
                    snakeDir = 3;
            } else if (nextRotate->second == 'D') {
                snakeDir++;
                if (snakeDir == 4)
                    snakeDir = 0;
            }
            ++nextRotate;
        }
        
    }

    cout << time;




    return 0;
}

