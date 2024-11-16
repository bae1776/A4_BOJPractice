//https://www.acmicpc.net/problem/2480

/*주사위 세계 (Bronze 4)
Solution : 조건문


*/

#include <iostream>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c)
    {
        cout << 10000 + 1000 * a;
        return 0;
    }

    if (a == b || b == c || a == c)
    {
        int same = (a == b) ? a : c;
        cout << 1000 + 100 * same;
        return 0;
    }

    int biggest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    cout << biggest * 100;

    return 0;
}

