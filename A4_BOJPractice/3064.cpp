//https://www.acmicpc.net/problem/3064

/*Minesweeper (Gold 5)
Solution : 아이디어

바깥쪽 지뢰 갯수 숫자의 합을 K라 하자.
꼭짓점에 지뢰가 있는 경우 꼭짓점 숫자는 반드시 1이고, K는 5가 추가된다.
나머지 위치에 지뢰가 있는 경우, K는 3이 추가된다.
지뢰의 갯수는 (K - (꼭짓점 숫자 1 개수) * 2) / 3

*/

#include <iostream>
using namespace std;
char board[100][102];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        int boardSize;
        cin >> boardSize;

        for (int i = 0; i < boardSize; i++)
            cin >> board[i];
        
        if (boardSize <= 2)
        {
            cout << 0 << '\n';
            continue;
        }

        if (boardSize == 3)
        {
            cout << (board[0][0] == '1') << '\n';
            continue;
        }

        int numberSum = 0;
        for (int r = 0; r < boardSize; r++)
        {
            numberSum += board[r][0] - '0';
            numberSum += board[r][boardSize - 1] - '0'; 
        }

        for (int c = 1; c < boardSize - 1; c++)
        {
            numberSum += board[0][c] - '0';
            numberSum += board[boardSize - 1][c] - '0';
        }

        if (board[0][0] == '1')
            numberSum -= 2;
        if (board[0][boardSize - 1] == '1')
            numberSum -= 2;
        if (board[boardSize - 1][0] == '1')
            numberSum -= 2;
        if (board[boardSize - 1][boardSize - 1] == '1')
            numberSum -= 2;

        cout << numberSum / 3 + (boardSize - 4) * (boardSize - 4) << '\n';


    }



	return 0;
}
