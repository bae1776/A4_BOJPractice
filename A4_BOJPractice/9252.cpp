//https://www.acmicpc.net/problem/9252

/*LCS 2

Longest Common Subsequence (최장 공통 부분 수열) 문제는 두 수열이 주어졌을 때,
모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

 ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

두 문자열에 대하여 LCS를 구하시오 (각 문자열 최대 길이는 1000이다.)

*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    string A, B;
    cin >> A >> B;

    int Alen = A.length();
    int Blen = B.length();

    vector<vector<short>> DP(Alen + 1, vector<short>(Blen + 1, 0));

    for (int AIndex = 1; AIndex <= Alen; AIndex++)
        for (int BIndex = 1; BIndex <= Blen; BIndex++)
            if (A[AIndex - 1] == B[BIndex - 1])
                DP[AIndex][BIndex] = DP[AIndex-1][BIndex-1] + 1;
            else
                DP[AIndex][BIndex] = max(DP[AIndex-1][BIndex], DP[AIndex][BIndex-1]);
    
    cout << DP[Alen][Blen] << '\n';

    pair<short, short> nowIndex = {Alen, Blen};
    string LCS;

    while (DP[nowIndex.first][nowIndex.second] != 0)
    {
        if (DP[nowIndex.first][nowIndex.second] == DP[nowIndex.first][nowIndex.second - 1])
            nowIndex.second--;
        else if (DP[nowIndex.first][nowIndex.second] == DP[nowIndex.first - 1][nowIndex.second])
            nowIndex.first--;
        else
        {
            LCS += A[nowIndex.first - 1];
            nowIndex.first--;
            nowIndex.second--;
        }
    }

    for (auto itr = LCS.rbegin(); itr != LCS.rend(); ++itr)
        cout << *itr;
            
    return 0;
}