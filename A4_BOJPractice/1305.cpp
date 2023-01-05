//https://www.acmicpc.net/problem/1305

/*광고 (Platinum 4)
전광판에는 같은 내용의 문구가 무한히 반복되어 나오며,
L개의 문자열이 한 번에 표시된다.

만약 광고 내용이 aaba이고 전광판의 크기가 6인 경우
맨 처음 전광판 내용은 aabaaa 이다. 그리고 1초가 지날 때마다 문자가 한 칸씩 옆으로 이동한다.
aabaaa -> abaaab -> baaaba ...

전광판이 주어질 때, 가능한 광고의 길이 중 가장 짧은 것의 길이를 출력하시오.
L은 최대 100만이다.

Solution : KMP 알고리즘에서 전광판 내용 전체에 대한 Pi(suffix == prefix) 배열을 구하면 된다.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPi(const string& str);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int strLen;
    cin >> strLen;

	string str;
    str.reserve(strLen);
    cin >> str;

    auto result = getPi(str);

    cout << strLen - result[strLen - 1];

	return 0;
}


vector<int> getPi(const string& str)
{
    int len = str.length();
    vector<int> result(len);

    int matchingPointer = 0;
    for (int p = 1; p < len;)
    {
        if (str[p] == str[matchingPointer])
        {
            result[p] = matchingPointer + 1;
            matchingPointer++;
            p++;
        }
        else {
            if (matchingPointer == 0)
            {
                result[p++] = 0;
                continue;
            }
            matchingPointer = result[matchingPointer - 1];
        }
    }

    return result;
}