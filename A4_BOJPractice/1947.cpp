//https://www.acmicpc.net/problem/1947

/* 선물 전달 (Gold 3)

모두들(최대 100만 명) 각자 선물을 1개씩 준비했다.
각자 선물을 전달하려고 할 때, 선물을 나누는 경우의 수를 구하시오.
모두 1개씩 받으며, 자기의 선물을 자기 자신이 받는 경우는 없다.

Solution : 완전 순열의 값을 구하는 것으로
사람 수 n명에 대해
정답 f(n) = (n - 1) * {f(n - 1) + f(n - 2)} 이다.
DP를 이용하면 O(N).
*/

#include <iostream>
using namespace std;

long long DP[4] = {0, 0, 1, 0};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int input;
    cin >> input;

    if (input <= 2)
        cout << DP[input];
    else
    {
        for (int index = 3; index <= input; ++index)
        {
            long long& subA = DP[(index - 2) & 0b11];
            long long& subB = DP[(index - 1) & 0b11];

            DP[index & 0b11] = (index - 1) * (subA + subB) % 1000000000;
        }

        cout << DP[input & 0b11];
    }
    
    
    return 0;
}
