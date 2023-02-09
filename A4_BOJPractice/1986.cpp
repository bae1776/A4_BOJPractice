//https://www.acmicpc.net/problem/1986

/* 체스 (Silver 2)

최대 1000 x 1000 체스판에 상대편의 Queen, Knight, Pawn 위치가 주어져 있을 때 (각각 100개 이하)
자신의 말이 있어도 잡히지 않는 칸의 개수를 구하시오.

Queen : 가로, 세로, 대각선으로 장애물이 없는 한 무제한 이동 가능
Knight : 한칸 + 대각선 (장애물 통과 가능)
Pawn : 장애물 역할만 함

Solution : 구현
*/

#include <iostream>
#include <vector>
using namespace std;

enum {SAFE, DANGER, QUEEN, KNIGHT, PAWN};
int board[1002][1002];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int boardY, boardX;
    cin >> boardY >> boardX;

    vector<pair<int, int>> locationList[5];
    pair<int, int> coord;
    int count;
    
    for (int isWhat = QUEEN; isWhat <= PAWN; isWhat++)
    {
        cin >> count;
        locationList[isWhat].reserve(count);

        while (count--)
        {
            cin >> coord.first >> coord.second;
            board[coord.first][coord.second] = isWhat;
            locationList[isWhat].push_back(coord);
        }
    }

    //Queen Spread
    const int queendy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int queendx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (const pair<int, int>& queenLoc : locationList[QUEEN])
    {
        for (int move = 0; move < 8; move++)
        {
            pair<int, int> pos = {queenLoc.first + queendy[move], queenLoc.second + queendx[move]};

            while (1 <= pos.first && pos.first <= boardY &&
                   1 <= pos.second && pos.second <= boardX && board[pos.first][pos.second] <= DANGER)
            {
                board[pos.first][pos.second] = DANGER;
                pos.first += queendy[move];
                pos.second += queendx[move];
            }
        } 
    }

    //Knight Spread
    const int knightdy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    const int knightdx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
    for (const pair<int, int>& knightLoc : locationList[KNIGHT])
    {
        for (int move = 0; move < 8; move++)
        {
            int nowY = knightLoc.first + knightdy[move];
            int nowX = knightLoc.second + knightdx[move];
            if (1 <= nowY && nowY <= boardY
             && 1 <= nowX && nowX <= boardX)
            {
                board[nowY][nowX] = max(1/*DANGER*/, board[nowY][nowX]);
            }
        }
    }

    int safeCount = 0;
    for (int i = 1; i <= boardY; i++)
        for (int j = 1; j <= boardX; j++)
            if (board[i][j] == SAFE)
                safeCount++;

    cout << safeCount;

    return 0;
}

