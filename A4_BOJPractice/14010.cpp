//https://www.acmicpc.net/problem/14010
// 회식을 위한 문제
// Silver 4, 빡 구현


/*문제 제목
문제 설명
*/

#include <iostream>
#include <string>
using namespace std;

string base;
bool isMatchable(int startIndex, const string& s);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
    cin >> n;

    
    cin >> base;
    int baselen = base.length();
    constexpr char val = -'A' + 'a';
    for (int i = 0; i < baselen; i++)
        base[i] += val; 

    while (n--)
    {
        string s;
        cin >> s;
        int slen = s.length();

        bool isMatch = false;
        for (int i = 0; i <= baselen - slen; i++)
            if (isMatch = isMatchable(i, s))
            {
                cout << i << '\n';
                break;
            }

        if (!isMatch)
            cout << '-' << '\n';
    }
	
	return 0;
}


bool isMatchable(int startIndex, const string& s)
{
    char basematch[26] = {0, };
    char smatch[26] = {0, };

    for (int i = 0; i < s.length(); i++)
    {
        if (basematch[base[startIndex + i] - 'a'] == 0 
            && smatch[s[i] - 'a'] == 0)
        {
            basematch[base[startIndex + i] - 'a'] = s[i];
            smatch[s[i] - 'a'] = base[startIndex + i];
        }
        else if (basematch[base[startIndex + i] - 'a'] != s[i]
            || smatch[s[i] - 'a'] != base[startIndex + i])
            return false;
    }

    return true;   
}