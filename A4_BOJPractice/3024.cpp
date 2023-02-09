//https://www.acmicpc.net/problem/3024

/* 마라톤 틱택토 (Silver 3)

최대 30x30 정사각 보드판에 .(빈 칸) 또는 알파벳이 주어진다.
알파벳이 세 글자로 행, 열, 또는 대각선으로 연속할 때, 그 알파벳이 승리한다.
승자를 출력하시오. (없는 경우 ongoing)
반드시 승자가 1개인 입력만 주어진다.
*/

#include <iostream>
using namespace std;

char board[32][32];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int boardSize;
    cin >> boardSize;

    for (int i = 1; i <= boardSize; i++)
        cin >> board[i] + 1;

    int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    char winner = '\0';

    for (int i = 1; i <= boardSize; i++)
        for (int j = 1; j <= boardSize; j++)
        {
            if ('A' <= board[i][j] && board[i][j] <= 'Z')
            {
                for (int rotate = 0; rotate < 4; rotate++)
                {
                    if (board[i + dy[rotate]][j + dx[rotate]] == board[i][j]
                    && board[i + dy[8 - rotate]][j + dx[8 - rotate]] == board[i][j])
                        winner = board[i][j];
                }
            }
        }

    if (!winner)
        cout << "ongoing";
    else
        cout << winner;
    
    return 0;
}