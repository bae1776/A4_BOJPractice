//https://www.acmicpc.net/problem/3003

/*킹, 퀸, 룩, 비숍, 나이트, 폰 (Bronze 5)
Solution : 사칙연산

*/

#include <iostream>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << 1 - a << ' ' << 1 - b << ' ' << 2 - c << ' ' << 2 - d << ' ' << 2 - e << ' ' << 8 - f;


    return 0;
}
