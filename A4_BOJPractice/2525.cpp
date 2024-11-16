//https://www.acmicpc.net/problem/2525

/*오븐 시계 (Bronze 3)
Solution : 사칙연산


*/

#include <iostream>
#include <string>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int hour, minute, t;
    cin >> hour >> minute >> t;
    t = (hour * 60 + minute + t) % (24 * 60);
    cout << t / 60 << ' ' << t % 60;
    return 0;
}

