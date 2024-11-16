//https://www.acmicpc.net/problem/25304

/*영수증 (Bronze 4)
Solution : 반복문


*/

#include <iostream>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int sum;
    cin >> sum;

    int tc;
    cin >> tc;
    while (tc--)
    {
        int price, cnt;
        cin >> price >> cnt;
        sum -= price * cnt;
    }

    if (sum == 0) cout << "Yes";
    else cout << "No";

    return 0;

}

