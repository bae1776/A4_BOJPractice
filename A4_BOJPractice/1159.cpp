//https://www.acmicpc.net/problem/1159

/*농구 경기

농구 국가대표 감독이 된 상근이는 게을러서 선수의 이름과 능력을 잘 모른다.
그래서 그냥 성 첫 글자가 똑같은 5명을 선발하려고 한다.
성 첫 글자가 5명이 똑같은 경우의 알파벳을 모두 출력하시오.
만약에 하나도 없다면 항복(PREDAJA(크로아티아어))을 출력하시오.

*/

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nameCount;
    cin >> nameCount;

    string input;
    int result[26] = {0, };
    while (nameCount--)
    {
        cin >> input;
        result[input[0] - 'a']++;
    }

    int lineupCount = 0;

    for (int i = 0; i < 26; i++)
    {
        if (result[i] >= 5)
        {
            cout << char('a' + i);
            lineupCount++;
        }
    }
    
    if (lineupCount == 0)
        cout << "PREDAJA";


    return 0;
}
