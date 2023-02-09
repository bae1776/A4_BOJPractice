//https://www.acmicpc.net/problem/1990

/*소수인팰린드롬 (Gold 5)

Solution : 에레토스테네스의 체 + 구현
최댓값이 1억이므로 모든 수에 대해 체를 하면 시간 초과 위험이 크다.
*/

#include <iostream>
using namespace std;

int primeList[3000] = {2, };
int primeListSq[3000] = {4, };
int primeCount = 1;

bool isPelindrome(int num);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int start, end;
    cin >> start >> end;

    //Erotos- + Pelindrome
    for (int num = 3; num <= end; num += 2)
    {
        bool isPrime = true, isPelin = isPelindrome(num);

        if (num >= 11000 && isPelin == false)
            continue;

        for (int i = 0; num >= primeListSq[i]; i++)
        {
            if (num % primeList[i] == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            if (num <= 11000) 
            {
                primeList[primeCount] = num;
                primeListSq[primeCount++] = num * num;
            }

            if (start <= num && isPelin)
                cout << num << '\n';
        }
    }

    cout << -1 << '\n';

	return 0;
}



bool isPelindrome(int num)
{
    if (num <= 9)
        return true;

    int digit[10];
    int digitCount = 0;

    while (num)
    {
        digit[digitCount++] = num % 10;
        num /= 10;
    }

    for (int i = 0; i < digitCount / 2; i++)
    {
        if (digit[i] != digit[digitCount - 1 - i])
            return false;    
    }

    return true;
}