//https://www.acmicpc.net/problem/23038

/*박스 그림 문자 (Silver 4)

.과 #으로 이루어진 평면 판이 있다.
평면 판의 각 3x3 부분은 +, ㅣ, -, ㅗ, ㅜ, ㅏ, ㅓ 등의 모양으로 #이 칠해져 있다.
그런데, 평면 판에서 일부 자료가 날라가버렸다. 당신은 이를 복구해야 한다.
다행히, 날라간 부분은 체스판 처럼 배열되어 있다. 다시 말해 i + j가 홀수일 때, i행 j열의 문자가 .으로 대체되어 있다.
그리고 #이 끊어진 곳은 존재하지 않는다.

위 제약 조건을 참고하여 잘 복구해보자. 판의 크기는 최대 900x900이다.
*/

#include <iostream>
using namespace std;

char board[909][909];

void recover(const int& row, const int& col)
{
    if (board[row + 1][col + 1] == '#') return;
    bool haveSharp = false;
    

    if (row != 0 && board[row - 1][col + 1] == '#')
    {
        board[row][col + 1] = '#';
        haveSharp = true;
    }

    if (col != 0 && board[row + 1][col - 1] == '#')
    {
        board[row + 1][col] = '#';
        haveSharp = true;
    }

    if (board[row + 3][col + 1] == '#')
    {
        board[row + 2][col + 1] = '#';
        haveSharp = true;
    }

    if (board[row + 1][col + 3] == '#')
    {
        board[row + 1][col + 2] = '#'; 
        haveSharp = true;
    }

    if (haveSharp)
        board[row + 1][col + 1] = '#';
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int row, col;
    cin >> row >> col;

    for (int i = 0; i < row * 3; i++)
        cin >> board[i];

    for (int r = 0; r < row * 3; r += 3)
        for (int c = 0; c < col * 3; c += 3)
        {
            recover(r, c);
        }


    for (int r = 0; r < row * 3; r++)
    {
        for (int c = 0; c < col * 3; c++)
        {
            cout << board[r][c];
        }
        cout << '\n';
    }

    return 0;
}