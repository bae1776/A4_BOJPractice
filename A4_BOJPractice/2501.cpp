//https://www.acmicpc.net/problem/2501

/*��� ���ϱ� (Bronze 2)
Solution : ����
*/

#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            k--;

        if (k == 0)
        {
            cout << i;
            return 0;
        }

    }

    cout << 0;

    return 0;
}