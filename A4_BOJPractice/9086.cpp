//https://www.acmicpc.net/problem/9086

/*문자열 (Bronze 5)
Solution : 문자열 인덱스 추출

*/

#include <string>
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
        string s;
        cin >> s;
        cout << *(s.begin()) << *(s.rbegin()) << '\n';
    }
    


    return 0;
}
