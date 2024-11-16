//https://www.acmicpc.net/problem/27866

/*문자와 문자열 (Bronze 5)
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

    string s;
    int i;
    cin >> s >> i;
    cout << s[i - 1];
    

    return 0;
}
