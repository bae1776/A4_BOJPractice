//https://www.acmicpc.net/problem/6269

/*Barbara Bennett's Wild Numbers (Silver ?)

각 자리마다 수를 비교해서 더하면 된다.
다만 자리자리마다 무식하게 하면 시간 초과가 날 수도 있다.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int answerFunc(const string& wild, const string& normal, int questionRemain, int depth);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    string wild, normal;
    while (true)
    {
        cin >> wild;
        if (wild[0] == '#')
            break;
        cin >> normal;

        int questionCount = 0;
        for (const char& ch : wild)
            if (ch == '?')
                ++questionCount;

        cout << answerFunc(wild, normal, questionCount, 0) << endl;
    }
    

	return 0;
}


int answerFunc(const string& wild, const string& normal, int questionRemain, int depth)
{
    if (depth == wild.size())
        return 0;
    
    if (wild[depth] != '?')
    {
        if (normal[depth] == wild[depth])
            return answerFunc(wild, normal, questionRemain, depth + 1);
        else if (normal[depth] < wild[depth])
            return pow(10, questionRemain);
        else
            return 0;
    } else {
        int ans = 0;
        ans += pow(10, questionRemain - 1) * ('9' - normal[depth]);
        ans += answerFunc(wild, normal, questionRemain - 1, depth + 1);

        return ans;
    }
}