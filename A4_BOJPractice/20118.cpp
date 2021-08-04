//https://www.acmicpc.net/problem/20118 

/*호반우가 길을 건너간 이유.

각 칸에 숫자가 적혀 있는 격자판이 주어지고,
호반우는 왼쪽 위 -> 오른쪽 아래 칸으로 이동한다.
이때 (시작 끝 포함) 올라온 칸의 숫자로 모두 xor 연산했을 때 0이 되는 경로를 찾자.
단, 최단 거리일 필요는 없으나 이동 횟수가 ((격자 가로)+(격자 세로))*2 이하여야 한다.

격자의 최대 길이는 1000이다.
*/

#include <iostream>
#include <vector>
using namespace std;


inline void printPair(const int& a, const int& b)  {cout << a << ' ' << b << '\n';}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int row, col, dist;
    cin >> row >> col;

    int ret = row * col;
    for (int i = 0; i < ret; i++)
        cin >> dist;
    
    pair<int, int> nowPos = {0, 0};
    dist = max(row - nowPos.first, col - nowPos.second) - 1;
    cout << (dist / 2 + 1) * 4 << '\n';
    bool destReached = false;

    while (destReached == false)
    {
        dist = max(row - nowPos.first, col - nowPos.second) - 1;

        switch (dist)
        {
            case 1:
                printPair(nowPos.first, nowPos.second);
                printPair(row - 1, col - 1);
                printPair(nowPos.first, nowPos.second);
                printPair(row - 1, col - 1);
                destReached = true;
                break;
            
            case 2:
                printPair(nowPos.first, nowPos.second);
                printPair(row - 2, col - 2);
                printPair(nowPos.first, nowPos.second);
                printPair(row - 2, col - 2);
                nowPos = {row - 2, col - 1};
                break;

            default:
                if (nowPos.first >= row - 2)
                {
                    printPair(nowPos.first, nowPos.second);
                    printPair(nowPos.first, nowPos.second + 1);
                    printPair(nowPos.first, nowPos.second);
                    printPair(nowPos.first, nowPos.second + 1);
                    nowPos = {nowPos.first, nowPos.second + 2};

                } else if (nowPos.second >= col - 2) {
                    printPair(nowPos.first, nowPos.second);
                    printPair(nowPos.first + 1, nowPos.second);
                    printPair(nowPos.first, nowPos.second);
                    printPair(nowPos.first + 1, nowPos.second);
                    nowPos = {nowPos.first + 2, nowPos.second};

                } else {
                    printPair(nowPos.first, nowPos.second);
                    printPair(nowPos.first + 1, nowPos.second + 1);
                    printPair(nowPos.first, nowPos.second);
                    printPair(nowPos.first + 1, nowPos.second + 1);
                    nowPos = {nowPos.first + 2, nowPos.second + 2};
                }
        }
    }

    return 0;
}