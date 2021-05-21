//https://www.acmicpc.net/problem/10997

//별 찍기 - 22
//Silver 2
//규칙을 유추하여 별을 찍어보자. (N <= 100)

#include <iostream>
#include <vector>
#define MAXSIZE 100
using namespace std;
enum {LEFT, DOWN, RIGHT, UP} DIRECTION;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int lineCount;
    cin >> lineCount;
    
    if (lineCount == 1)
        cout << '*';
    else {
        vector<vector<bool>> board(4 * lineCount - 1, vector<bool>(4 * lineCount - 3, false));
    
        pair<int, int> nowLoc = {0, 4 * lineCount - 4};
        DIRECTION = LEFT;

        while (!(nowLoc.first == 2 * lineCount && nowLoc.second == 2 * lineCount - 2))
        {
            board[nowLoc.first][nowLoc.second] = true;

            switch (DIRECTION)
            {
                case LEFT:
                    nowLoc.second--;

                    if (nowLoc.second == 0)
                        DIRECTION = DOWN;
                    if (board[nowLoc.first][nowLoc.second] == true)
                    {
                        board[nowLoc.first][nowLoc.second + 1] = false;
                        nowLoc.second += 2;
                        DIRECTION = DOWN;
                    }
                    break;
                
                case DOWN:
                    nowLoc.first++;

                    if (nowLoc.first == 4 * lineCount - 2)
                        DIRECTION = RIGHT;
                    if (board[nowLoc.first][nowLoc.second] == true)
                    {
                        board[nowLoc.first - 1][nowLoc.second] = false;
                        nowLoc.first -= 2;
                        DIRECTION = RIGHT;
                    }
                    break;
                
                case RIGHT:
                    nowLoc.second++;

                    if (nowLoc.second == 4 * lineCount - 4)
                        DIRECTION = UP;
                    if (board[nowLoc.first][nowLoc.second] == true)
                    {
                        board[nowLoc.first][nowLoc.second - 1] = false;
                        nowLoc.second -= 2;
                        DIRECTION = UP;
                    }
                    break;
                
                case UP:
                    nowLoc.first--;

                    if (nowLoc.first == 0)
                        DIRECTION = LEFT;
                    if (board[nowLoc.first][nowLoc.second] == true)
                    {
                        board[nowLoc.first + 1][nowLoc.second] = false;
                        nowLoc.first += 2;
                        DIRECTION = LEFT;
                    }
                    break;
            }
        }
        board[nowLoc.first][nowLoc.second] = true;

        for (int i = 0; i < 4 * lineCount - 1; i++)
        {
            if (i == 1)
            {
                cout << "*\n";
                continue;
            }
            for (int j = 0; j < 4 * lineCount - 3; j++)
                if (board[i][j] == true)
                    cout << '*';
                else
                    cout << ' ';
            cout << '\n';
        }
    }

    return 0;
}

