//https://www.acmicpc.net/problem/2903

/*중앙 이동 알고리즘 (Bronze 3)
Solution : 수학
*/

#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int input;
    cin >> input;

    int val = 2;

    for (int i = 0; i < input; i++)
        val = val * 2 - 1;

    cout << val * val;

    return 0;
}