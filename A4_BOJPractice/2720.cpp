//https://www.acmicpc.net/problem/2720

/*ºº≈πº“ ªÁ¿Â µø«ı (Bronze 3)
Solution : ºˆ«–
*/

#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--)
    {
        int input;
        cin >> input;

        int quarter = input / 25;
        input %= 25;
        int dime = input / 10;
        input %= 10;
        int nickel = input / 5;
        input %= 5;
        
        cout << quarter << ' ' << dime << ' ' << nickel << ' ' << input << '\n';
    }

    return 0;
}