//https://www.acmicpc.net/problem/2566

/*�ִ� (Bronze 3)
Solution : 2���� �迭���� �ִ� �� �� ��ġ ã��.

*/

#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int input, max = -1, r = 0, c = 0;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> input;
            if (input > max)
            {
                r = i + 1;
                c = j + 1;
                max = input;
            }
        }

    cout << max << '\n' << r << ' ' << c;




    return 0;
}
