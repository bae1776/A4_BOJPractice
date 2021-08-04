//https://www.acmicpc.net/problem/17500 

/*국경
무지 어려운 브루트포스 문제.
설명 너무 길어서 링크 참고
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using DIRECTION = enum { NONE, LEFT, UP, RIGHT, DOWN };


int boardSize;
vector<vector<char>> board;
vector<vector<bool>> hWall, vWall, visited;

struct Data {
    short x, y, depth;
    DIRECTION beforeMove;
    Data(short x, short y, short depth, DIRECTION beforeMove) : 
        x(x), y(y), depth(depth), beforeMove(beforeMove) {};
};


void Draw();
bool territoryValid();


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> boardSize;

    board = vector<vector<char>>(boardSize, vector<char>(boardSize));
    hWall = vector<vector<bool>>(boardSize + 1, vector<bool>(boardSize, false));
    vWall = vector<vector<bool>>(boardSize, vector<bool>(boardSize + 1, false));
    visited = vector<vector<bool>>(boardSize + 1, vector<bool>(boardSize + 1, false));

    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++)
            cin >> board[i][j];
    
    bool solved = false;
    stack<Data> dfsStack;
    stack<Data> moveStack;
    dfsStack.emplace(0, 0, 0, NONE);
    moveStack.emplace(0, 0, 0, NONE);

    while (dfsStack.empty() == false)
    {
        Data nowData = dfsStack.top();
        dfsStack.pop();

        while (nowData.depth < moveStack.size())
        { //BackTracking
            Data backMoving = moveStack.top();
            moveStack.pop();

            visited[backMoving.y][backMoving.x] = false;
            
            switch (backMoving.beforeMove)
            {
                case LEFT:
                    hWall[backMoving.y][backMoving.x] = false;
                    break;
                case UP:
                    vWall[backMoving.y][backMoving.x] = false;
                    break;
                case RIGHT:
                    hWall[backMoving.y][backMoving.x - 1] = false;
                    break;
                case DOWN:
                    vWall[backMoving.y - 1][backMoving.x] = false;
                    break;
            }
        }

        moveStack.emplace(nowData);
        visited[nowData.y][nowData.x] = true;

        switch (nowData.beforeMove)
        {
            case LEFT:
                hWall[nowData.y][nowData.x] = true;
                break;
            case UP:
                vWall[nowData.y][nowData.x] = true;
                break;
            case RIGHT:
                hWall[nowData.y][nowData.x - 1] = true;
                break;
            case DOWN:
                vWall[nowData.y - 1][nowData.x] = true;
                break;
        }

        if (nowData.x == boardSize && nowData.y == boardSize)
        {
            //Reached destination Procedure
            if (territoryValid()) {
                cout << "yes\n";
                Draw();
                solved = true;
                break;
            }
            else {
                continue;
            }
        } else {
            //More deeper search

            if (nowData.x != 0 && visited[nowData.y][nowData.x - 1] == false)
                dfsStack.emplace(nowData.x - 1, nowData.y, nowData.depth + 1, LEFT);
            if (nowData.y != 0 && visited[nowData.y - 1][nowData.x] == false)
                dfsStack.emplace(nowData.x, nowData.y - 1, nowData.depth + 1, UP);
            if (nowData.x != boardSize && visited[nowData.y][nowData.x + 1] == false)
                dfsStack.emplace(nowData.x + 1, nowData.y, nowData.depth + 1, RIGHT);
            if (nowData.y != boardSize && visited[nowData.y + 1][nowData.x] == false)
                dfsStack.emplace(nowData.x, nowData.y + 1, nowData.depth + 1, DOWN);
        }
    }

    if (solved == false)
        cout << "no";

	return 0;
}



void Draw()
{
    int pictureXSize = 4 * boardSize + 1;
    int pictureYSize = 2 * boardSize + 1;

    for (int i = 0; i < pictureXSize + 2; i++)
        cout << '#';
    cout << '\n';

    for (int pictureRow = 0; pictureRow < pictureYSize; pictureRow++)
    {
        cout << '#';

        if (pictureRow % 2) // board + vWall row
        {
            for (int pictureCol = 0; pictureCol < pictureXSize; pictureCol++)
            {
                if ((pictureCol % 4) == 0)
                    if (vWall[pictureRow / 2][pictureCol / 4])
                        cout << '|';
                    else
                        cout << ' ';
                else
                {
                    cout << ' ' << board[pictureRow / 2][pictureCol / 4] << ' ';
                    pictureCol += 2;
                }
            }

        } else {  //+ , hWall row
            for (int pictureCol = 0; pictureCol < pictureXSize; pictureCol++)
                if ((pictureCol % 4) == 0)
                    cout << '+';
                else
                {
                    if (hWall[pictureRow / 2][pictureCol / 4])
                        cout << "---";
                    else
                        cout << "   ";
                    pictureCol += 2;
                }
        }


        cout << '#' << '\n';
    }


    for (int i = 0; i < pictureXSize + 2; i++)
        cout << '#';
    cout << '\n';
    
}

bool territoryValid()
{
    char nowOwner;
    vector<vector<bool>> terrinVisited(boardSize, vector<bool>(boardSize, false));
    stack<pair<int, int>> dfsStack;

    for (int y = 0; y < boardSize; y++)
        for (int x = 0; x < boardSize; x++)
        {
            if (board[y][x] != '.' && terrinVisited[y][x] == false)
            {
                nowOwner = board[y][x];
                dfsStack.emplace(y, x);

                while (dfsStack.empty() == false)
                {
                    pair<int, int> nowPos = dfsStack.top();
                    dfsStack.pop();
                    terrinVisited[nowPos.first][nowPos.second] = true;

                    
                    if (nowPos.first != 0 && hWall[nowPos.first][nowPos.second] == false &&
                        terrinVisited[nowPos.first - 1][nowPos.second] == false)
                        if (board[nowPos.first - 1][nowPos.second] == '.' ||
                            board[nowPos.first - 1][nowPos.second] == nowOwner )
                            dfsStack.emplace(nowPos.first - 1, nowPos.second);
                        else
                            return false;
                    
                    if (nowPos.first != boardSize - 1 && hWall[nowPos.first + 1][nowPos.second] == false &&
                        terrinVisited[nowPos.first + 1][nowPos.second] == false)
                        if (board[nowPos.first + 1][nowPos.second] == '.' ||
                            board[nowPos.first + 1][nowPos.second] == nowOwner )
                            dfsStack.emplace(nowPos.first + 1, nowPos.second);
                        else
                            return false;
                    
                    if (nowPos.second != 0 && vWall[nowPos.first][nowPos.second] == false &&
                        terrinVisited[nowPos.first][nowPos.second - 1] == false)
                        if (board[nowPos.first][nowPos.second - 1] == '.' ||
                            board[nowPos.first][nowPos.second - 1] == nowOwner )
                            dfsStack.emplace(nowPos.first, nowPos.second - 1);
                        else
                            return false;
                    
                    if (nowPos.second != boardSize - 1 && vWall[nowPos.first][nowPos.second + 1] == false &&
                        terrinVisited[nowPos.first][nowPos.second + 1] == false)
                        if (board[nowPos.first][nowPos.second + 1] == '.' ||
                            board[nowPos.first][nowPos.second + 1] == nowOwner )
                            dfsStack.emplace(nowPos.first, nowPos.second + 1);
                        else
                            return false;
                }
            }

        }

    return true;
}