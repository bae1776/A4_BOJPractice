//https://www.acmicpc.net/problem/1735

/*분수 합 (Silver 3)
Solution : 통분 후 GCD
*/

#include <iostream>
using namespace std;

int gcd(int a, int b);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int up1, down1, up2, down2;
    cin >> up1 >> down1 >> up2 >> down2;

    int up3 = up1 * down2 + up2 * down1;
    int down3 = down1 * down2;
    int div = gcd(up3, down3);

    cout << up3 / div << ' ' << down3 / div;
    
	return 0;
}

int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    return (b == 0) ? a : gcd(b, a % b); 
}