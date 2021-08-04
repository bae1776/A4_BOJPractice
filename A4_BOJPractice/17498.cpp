//https://www.acmicpc.net/problem/17498

/*폴짝 게임

태균이는 분필과 바닥만 있으면 언제든지 할 수 있는 재미있는 게임을 하나 만들었습니다.
바닥에 N×M 사각 격자를 그린 뒤 각 칸에 정수들을 쓰고 다음의 규칙을 따라 게임을 진행합니다.

1. 1번 행에 있는 원하는 칸을 하나 정하여 해당 칸에서 시작합니다.
2. N번 행에 있는 임의의 칸에 도착하면 게임이 끝납니다.
3. 칸에서 칸으로 이동하려면 행의 번호가 증가하는 칸으로만 이동이 가능하며 이동한 칸 사이의 거리가 D이하여야 합니다.
4. 게임 시작 시 점수의 초기값은 0이며, 칸에서 칸으로 이동할 때 각 칸의 수를 곱하여 현재 점수에 더합니다.

D, N, M, 칸에 적힌 수들이 주어지면 게임에서 낼 수 있는 최대 점수를 구해주세요.

(1 <= D <= 10, N >= 2, N*M <= 200000, 각 칸은 -100 ~ 100 임)
*/

#include <iostream>
using namespace std;
#define INF 1999999999


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int row, col, jump;
    cin >> row >> col >> jump;

    short** board = new short*[row];
    int** DP = new int*[row];
    for (int i = 0; i < row; ++i)
    {
        board[i] = new short[col];
        DP[i] = new int[col];

        for (int j = 0; j < col; ++j)
        {
            cin >> board[i][j];
            DP[i][j] = -INF;
        }
    }

    for (int j = 0; j < col; ++j)
        DP[0][j] = 0;
    
    
    for (int nowRow = 1; nowRow < row; ++nowRow) 
        for (int nowCol = 0; nowCol < col; ++ nowCol)
            for (int beforeRow = max(0, nowRow - jump); beforeRow < nowRow; ++beforeRow)
            {
                int xJump = jump - (nowRow - beforeRow);
                int rightestCol = min(col - 1, nowCol + xJump);
                for (int beforeCol = max(0, nowCol - xJump); beforeCol <= rightestCol; ++beforeCol)
                    DP[nowRow][nowCol] 
                    = max(DP[nowRow][nowCol], 
                         DP[beforeRow][beforeCol] + board[nowRow][nowCol] * board[beforeRow][beforeCol]);
            }
    

    int result = -INF;
    for (int i = 0; i < col; i++)
        result = max(DP[row - 1][i], result);

    cout << result;
    
    
    for (int i = 0; i < row; ++i)
    {
        delete[] board[i];
        delete[] DP[i];
    }
    delete[] board;
    delete[] DP;

    return 0;
}