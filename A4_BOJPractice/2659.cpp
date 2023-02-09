//https://www.acmicpc.net/problem/2659

/* 십자카드 문제 (Silver 3)

십자모양의 한 장의 카드에, 각 네 모서리에 1~9 중 하나의 수가 쓰여 있다.
모든 가능한 십자 카드가 주어질 때, 각 카드는 '시계수'라는 번호를 가지는 데,
시계수는 카드의 숫자들을 시계 방향으로 읽어 만들어지는 네 자리 수들 중에서 가장 작은 수이다.
예를 들어, 시계 방향으로 3, 2, 2, 7로 쓰인 십자 카드는 3227, 2273, 2732, 7322로 읽을 수 있는데
그 중 시계수는 2273이다.

카드가 쓰인 번호가 시계 방향으로 주어질 때, 
그것의 시계수가 모든 시계수들 중 몇 번째로 작은지 구하시오.

Solution : 브루트포스로 해결 가능
*/


#include <iostream>
using namespace std;
bool isClockNumber[10000];

int clockNumber(const int& a, const int& b, const int& c, const int& d)
{
    return min(min(a * 1000 + b * 100 + c * 10 + d,
                   b * 1000 + c * 100 + d * 10 + a),
               min(c * 1000 + d * 100 + a * 10 + b,
                   d * 1000 + a * 100 + b * 10 + c));
}

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for (int a = 1; a <= 9; a++)
        for (int b = 1; b <= 9; b++)
            for (int c = 1; c <= 9; c++)
                for (int d = 1; d <= 9; d++)
                {
                    isClockNumber[clockNumber(a, b, c, d)] = true;
                }

    int input[4];
    cin >> input[0] >> input[1] >> input[2] >> input[3];

    int inputCN = clockNumber(input[0], input[1], input[2], input[3]);
    int order = 0;

    for (int a = 1; a <= 9; a++)
        for (int b = 1; b <= 9; b++)
            for (int c = 1; c <= 9; c++)
                for (int d = 1; d <= 9; d++)
                {
                    int value = a * 1000 + b * 100 + c * 10 + d;
                    if (isClockNumber[value])
                        order++;
                    if (value == inputCN)
                    {
                        cout << order;
                        return 0;
                    }
                }
    return 0;
}