//https://www.acmicpc.net/problem/10988

/*�縰������� Ȯ���ϱ� (Bronze 3)
Solution : �ݺ���

*/

#include <string>
#include <iostream>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    int len = s.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
        {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
    return 0;
}
