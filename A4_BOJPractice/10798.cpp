//https://www.acmicpc.net/problem/10798

/*���� �б� (Bronze 1)
Solution : 2���� �迭 �׷��� �� �������� �б�

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
