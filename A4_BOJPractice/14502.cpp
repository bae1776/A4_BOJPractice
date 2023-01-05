//https://www.acmicpc.net/problem/14502

/* 연구소 (Gold 4)

연구소에서 바이러스가 유출되었다. 아직 퍼지지는 않아서, 벽을 세워 이를 막으려고 한다.
주어진 벽은 3개이며, 벽은 모두 세워야 한다.

최대 8x8 격자에 각 칸은 연구소, 빈 칸, 벽이다.
벽을 세웠을 때 바이러스(상하좌우 1칸씩만 퍼짐)가 퍼지지 않는 빈 칸의 수의 최댓값을 구하시오.
단, 빈 칸의 개수는 3개 이상이다.
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <array>
using namespace std;
using WallIndices = array<int, 3>;

int y, x;

bool next_permutation(WallIndices& t3, int max);
void spreadVirus(vector<vector<int>>& board, vector<vector<char>>& checked, const int& nowY, const int& nowX);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> y >> x;
    vector<vector<int>> board(y, vector<int>(x));
    vector<pair<int, int>> emptyList;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                emptyList.emplace_back(i, j);
        }
    }

    int maxSafeZone = 0;

    WallIndices walls = {0, 1, 2};
    do {
        auto copyBoard = board;
        copyBoard[emptyList[walls[0]].first][emptyList[walls[0]].second] = 
        copyBoard[emptyList[walls[1]].first][emptyList[walls[1]].second] =
        copyBoard[emptyList[walls[2]].first][emptyList[walls[2]].second] = 1;
        vector<vector<char>> checked(y, vector<char>(x, false));
        
        for (int i = 0; i < y; i++)
            for (int j = 0; j < x; j++)
            {
                if (copyBoard[i][j] == 2 && checked[i][j] == false)
                    spreadVirus(copyBoard, checked, i, j);
            }

        int safeZone = 0;
        for (const auto& line : copyBoard)
            for (const auto& element : line)
                if (element == 0) safeZone++;

        maxSafeZone = max(maxSafeZone, safeZone);

    } while (next_permutation(walls, emptyList.size()));
    
    cout << maxSafeZone;
	
	return 0;
}



bool next_permutation(WallIndices& t3, int max)
{
    int changeIndex = 2;
    while (t3[changeIndex] == --max)
        if (--changeIndex == -1) 
            return false;

    t3[changeIndex]++;
    for (int i = changeIndex + 1; i <= 2; i++)
        t3[i] = t3[i - 1] + 1;

    return true;
}

void spreadVirus(vector<vector<int>>& board, vector<vector<char>>& checked, const int& nowY, const int& nowX)
{
    if (nowX != 0 && board[nowY][nowX - 1] != 1 && checked[nowY][nowX - 1] == false)
    {
        board[nowY][nowX - 1] = 2;
        checked[nowY][nowX - 1] = true;
        spreadVirus(board, checked, nowY, nowX - 1);
    }

    if (nowX != x - 1 && board[nowY][nowX + 1] != 1 && checked[nowY][nowX + 1] == false)
    {
        board[nowY][nowX + 1] = 2;
        checked[nowY][nowX + 1] = true;
        spreadVirus(board, checked, nowY, nowX + 1);
    }
    
    if (nowY != 0 && board[nowY - 1][nowX] != 1 && checked[nowY - 1][nowX] == false)
    {
        board[nowY - 1][nowX] = 2;
        checked[nowY - 1][nowX] = true;
        spreadVirus(board, checked, nowY - 1, nowX);
    }

    if (nowY != y - 1 && board[nowY + 1][nowX] != 1 && checked[nowY + 1][nowX] == false)
    {
        board[nowY + 1][nowX] = 2;
        checked[nowY + 1][nowX] = true;
        spreadVirus(board, checked, nowY + 1, nowX);
    }
}