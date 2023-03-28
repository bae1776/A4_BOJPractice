//https://www.acmicpc.net/problem/1509

/*팰린드롬 분할 (Gold 1)

Solution : 다이나믹 프로그래밍

DP[i] = 문자열 인덱스 0 ~ i-1 부분에 대해 펠린드롬 분할 개수
여기서 우리는 DP[strLen]을 구하면 되고
점화식은,
DP[i] = min(for a in 0...i-1 : 
            DP[a] + (isPellindrome(a, i - 1) ? 1 : i - a))

기저값은
DP[0] = 0, DP[1] = 1.

또 isPellindrome을 더 효율적으로 구하기 위해, 이 함수의 결과도 DP에 저장하는데,
b - a >= 2 이면 아래 등식이 성립함을 이용한다.
isPellindrome(a, b) = isPellindrome(a + 1, b - 1) && str[a] == str[b]
*/

#include <iostream>
#include <string>
using namespace std;

string str;
bool isPellindrome(int start, int end);
int DP[2501];
bool isPellin[2500][2500];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> str;
    int strLen = str.size();
    for (int i = 0; i <= strLen; i++)
        DP[i] = 999999;
    DP[0] = 0; DP[1] = 1;

    for (int i = 2; i <= strLen; i++)
    {  
        int& nowDP = DP[i];
        for (int a = 0; a < i; a++)
            if (isPellindrome(a, i - 1))
                nowDP = min(nowDP, DP[a] + 1);
            else
                nowDP = min(nowDP, DP[a] + i - a);
    }

    cout << DP[strLen];

	return 0;
}



bool isPellindrome(int start, int end)
{
    switch (end - start)
    {
        case 0:
            return isPellin[start][end] = true;
        
        case 1:
            return isPellin[start][end] = str[start] == str[end];
        
        default:
            if (isPellin[start + 1][end - 1] && str[start] == str[end])
                return isPellin[start][end] = true;
            else
                return isPellin[start][end] = false;
    }
}