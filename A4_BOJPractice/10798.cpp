//https://www.acmicpc.net/problem/10798

/*세로 읽기 (Bronze 1)
Solution : 2차원 배열 그런데 열 방향으로 읽기

*/

#include <map>
#include <iostream>
using namespace std;

char str[5][16];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 5; i++)
        cin >> str[i];

    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 5; j++)
        {
            if (str[j][i] != NULL)
                cout << str[j][i];
        }

    return 0;
}
