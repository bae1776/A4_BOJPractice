//https://www.acmicpc.net/problem/22343

/*괄호의 값 비교 (Gold 2)

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s[2];
vector<int> sValue[2];

char compare();

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;


    while (testcase--)
    {
        cin >> s[0] >> s[1];

        sValue[0] = vector<int>(s[0].size() / 2);
        sValue[1] = vector<int>(s[1].size() / 2);

        cout << compare() << '\n';
    }

	
	return 0;
}


char compare()
{
    for (int a = 0; a <= 1; a++)
    {
        int index = -1;

        char before = '\0';
        for (const char& ch : s[a])
        {
            if (ch == '(')
            {
                index++;
            } else {
                if (before == '(')
                    sValue[a][index]++;
                index--;
            }

            before = ch;
        }

        for (int i = 0; i < sValue[a].size(); i++)
        {
            if (sValue[a][i] >= 2)
            {
                sValue[a][i + 1] += sValue[a][i] / 2;
                sValue[a][i] %= 2;
            }
        }
    }


    char result = '=';

    auto common = min(sValue[0].size(), sValue[1].size());
    for (int i = 0; i < common; i++)
    {
        if (sValue[0][i] < sValue[1][i])
            result = '<';
        else if (sValue[0][i] > sValue[1][i])
            result = '>';
    }

    if (sValue[0].size() > sValue[1].size())
    {
        for (int i = common; i < sValue[0].size(); i++)
        {
            if (sValue[0][i])
            {
                result = '>';
                break;
            }
        }
    }   

    if (sValue[0].size() < sValue[1].size())
    {
        for (int i = common; i < sValue[1].size(); i++)
        {
            if (sValue[1][i])
            {
                result = '<';
                break;
            }
        }
    }

    return result;
}