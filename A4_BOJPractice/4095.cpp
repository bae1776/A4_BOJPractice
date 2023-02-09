//https://www.acmicpc.net/problem/4095

/*최대 정사각형 (Gold 4)

Solution : DP
그냥 브루트 포스로 정사각형을 구하면 1000^3이기 때문에 구하기 어렵다.
DP를 이용하면 1000^2에 풀 수 있다.

i 증가, j 증가 순으로 Bottom-up DP를 한다.
DP[i][j] = min(DP[i-1][j], DP[i-1][j-1], DP[i][j-1]) + 1 이다.
DP[i][j] = 3 이라는 것은 Board[i-2][j-2]~Board[i][j] 까지 모두 꽉 채워져 있음을 의미한다.
*/

#include <iostream>
using namespace std;

int board[1000][1000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    while (true)
    {
        int row, col;
        cin >> row >> col;

        if (row == 0)
            break;
        
        int answer = 0;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                cin >> board[i][j];
                if (board[i][j]) answer = 1;
            }  

        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++)
            {
                if (board[i][j] == 0) continue;

                board[i][j] = max(board[i][j], 
                    min(board[i-1][j], min(board[i-1][j-1], board[i][j-1])) + 1);

                answer = max(answer, board[i][j]);
            }

        cout << answer << '\n';
    }
	
	return 0;
}