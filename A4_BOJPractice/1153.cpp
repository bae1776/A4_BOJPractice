//https://www.acmicpc.net/problem/1153

/*네 개의 소수 (Gold 3)

에라토스테네스의 체로 1000000 까지의 소수 리스트를 만든뒤, (DP[?][0] 에도 저장)
DP[a][b] = 자연수 a를 b개의 소수 합으로 나누었을때, 가능한 숫자값
(없는 경우 -1)

으로 정의하면 제한 시간 내에 풀 수 있다.
*/


#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000001][5];
int primeList[80000] = {2, 3};
int primeListSq[80000] = {4, 9};
int primeCount = 2;

int& DPFt(int num, int depth);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //ertos
    DP[2][1] = 2; DP[3][1] = 3;
    for (int num = 5; num <= 1000000; num += 2)
    {
        bool isPrime = true;
        for (int i = 1; num >= primeListSq[i]; i++)
            if (num % primeList[i] == 0)
            {
                isPrime = false;
                break;
            }

        if (isPrime) 
        {
            DP[num][1] = primeList[primeCount] = num;
            if (num <= 1600)
                primeListSq[primeCount] = num * num;
            primeCount++;
        }
    }

    int input;
    cin >> input;

    if (DPFt(input, 4) > 0)
    {
        for (int i = 4; i >= 1; i--)
        {
            cout << DP[input][i] << ' ';
            input -= DP[input][i];
        }
    } else {
        cout << -1;
    }

	return 0;
}


int& DPFt(int num, int depth)
{
    int& val = DP[num][depth];

    if (val != 0)
        return val;
    else {
        if (depth == 1)
            return val = -1;
        
        for (int* ptr = upper_bound(primeList, primeList + primeCount, num) - 1; ptr >= primeList; --ptr)
        {
            if (DPFt(num - *ptr, depth - 1) > 0)
                return val = *ptr;
        }

        return val = -1;
    }
}