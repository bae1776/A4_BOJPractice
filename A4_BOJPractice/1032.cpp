//https://www.acmicpc.net/problem/1032

/*명령 프롬프트 (Bronze 1)
*/

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int strCount;
    cin >> strCount;

    string str;
    cin >> str;

    auto len = str.length();
    string newStr;
    for (int i = 2; i <= strCount; i++)
    {
        cin >> newStr;

        for (int j = 0; j < len; j++)
        {
            if (newStr[j] != str[j])
                str[j] = '?';
        }
    }

    cout << str;


    return 0;
}