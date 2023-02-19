//https://www.acmicpc.net/problem/27087

/*직육면체 (Gold 5)

*/

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testCase;
    cin >> testCase;
    
    while (testCase--)
    {
        int a, b, c, p;
        cin >> a >> b >> c >> p;

        int zeroCount = ((a % p) == 0) + ((b % p) == 0) + ((c % p) == 0);

        if (zeroCount >= 2)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

	return 0;
}