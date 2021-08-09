//https://www.acmicpc.net/problem/1520

/*내리막길

여행객 세준이는 격자형 지도를 구했다. 각 칸에는 그 지점에 높이가 있고,
세준이는 왼쪽 윗끝 칸에서 오른쪽 아랫칸까지 지점 높이가 낮아지는 방향으로만 이동하고 싶다.
세준이는 상하좌우로 1칸씩만 이동이 가능하다.
높이가 쓰여 있는 지도가 주어졌을 때, 이동할 수 있는 경우의 수를 구하시오.

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using DIR = enum {RIGHT, DOWN, LEFT, UP};
const static int dirX[4] = {1, 0, -1, 0};
const static int dirY[4] = {0, 1, 0, -1};

struct Block {
    short row;
    short col;
    short height;
    int routeCount;
    bool visited;
    vector<char> comeFrom;
};

vector<vector<Block>> board;

int getRouteCount(int row, int col);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int row, col;
    cin >> row >> col;

    board = vector<vector<Block>>(row, vector<Block>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j].row = i;
            board[i][j].col = i;
            cin >> board[i][j].height;
            board[i][j].routeCount = 0;
            board[i][j].visited = false;
        }
    }

    board[0][0].routeCount = 1;
    board[0][0].visited = true;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            for (int nowdir = 0; nowdir < 4; nowdir++)
            {
                if (i + dirY[nowdir] < 0 || i + dirY[nowdir] == row) continue;
                if (j + dirX[nowdir] < 0 || j + dirX[nowdir] == col) continue;
                if (board[i][j].height < board[i + dirY[nowdir]][j + dirX[nowdir]].height)
                    board[i][j].comeFrom.push_back(nowdir);
            }
        }
    
    cout << getRouteCount(row - 1, col - 1);
    return 0;
}


int getRouteCount(int row, int col)
{
    Block& nowBlock = board[row][col];
    if (nowBlock.visited == true)
        return board[row][col].routeCount;

    nowBlock.visited = true;

    for (auto fromDir : nowBlock.comeFrom)
        nowBlock.routeCount += getRouteCount(row + dirY[fromDir], col + dirX[fromDir]);
        //싸이클이 생성될 수 없는 그래프기 때문에 해당 재귀가 가능한것임.

    return nowBlock.routeCount;
}