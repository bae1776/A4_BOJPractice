//https://www.acmicpc.net/problem/1100

/*하얀 칸

체스판은 8*8 크기에 검정 칸과 하얀 칸이 번갈아가면서 색칠되어있다.
체스판의 상태가 주어졌을 때, 하얀 칸 위에 말 개수를 구하시오.
*/

#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char board[8][9];

    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        cin >> board[i];
        for (int j = 0; j < 8; j++)
            if ((i + j) % 2 == 0 && board[i][j] == 'F')
                count++;
    }

    cout << count;


    return 0;
}
