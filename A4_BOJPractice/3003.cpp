//https://www.acmicpc.net/problem/3003

/*ŷ, ��, ��, ���, ����Ʈ, �� (Bronze 5)
Solution : ��Ģ����

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
