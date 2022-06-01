//https://www.acmicpc.net/problem/1075

/*나누기 (Bronze 2)
*/


#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int num, div;
    cin >> num >> div;

    num = num / 100 * 100;

    int rest = num % div;

    if (rest == 0)
        cout << "00";
    else
    {
        rest = div - rest;

        if (rest <= 9)
            cout << '0';
        cout << rest;
    
    }
    return 0;
}