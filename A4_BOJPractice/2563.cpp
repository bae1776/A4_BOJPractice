//https://www.acmicpc.net/problem/2563

/* 색종이 (Silver 5)
Solution : 2차원 배열 / 반복문
그냥 naive하게 덮으면 됨

*/

#include <map>
#include <iostream>
using namespace std;

bool board[102][102];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cnt;
    cin >> cnt;

    while (cnt--)
    {
        int start, end;
        cin >> start >> end;

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                board[start + i][end + j] = true;
    }

    int area = 0;
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            area += board[i][j];

    cout << area;

    return 0;
}
