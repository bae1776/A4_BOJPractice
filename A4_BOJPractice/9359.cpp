//https://www.acmicpc.net/problem/9359

/*서로소 (Gold 1)

Solution :
N과의 서로소 계산시,
A~B서로소 = 1~B까지 서로소 - 1~A-1까지 서로소 개수.
서로소 개수를 구하는 함수를 짤 때는 소수만 고려하면 된다.
예를 들어 1에서 1000까지의 60과의 서로소를 구하면, 60의 약수 중 소수인 것은 2, 3, 5 이므로
1000 - (2의 배수) - (3의 배수) - (5의 배수) + (6의 배수) + (10의 배수) + (15의 배수) - (30의 배수)
하면 된다.
*/

#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

int primeList[4000] = {2, };
int primeCount = 1;

long long coprimeCount(const long long& num, int target);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    for (int num = 3; primeList[primeCount - 1] <= 31622; num += 2)
    {
        bool isPrime = true;
        for (int i = 0; i < primeCount; i++)
            if (num % primeList[i] == 0)
            {
                isPrime = false;
                break;
            }
        
        if (isPrime)
        {
            primeList[primeCount] = num;
            primeCount++;
        }
    }

    for (int tc = 1; tc <= testcase; tc++)
    {
        long long a, b;
        int N;
        cin >> a >> b >> N;

        cout << "Case #" << tc << ": " << coprimeCount(b, N) - coprimeCount(a - 1, N) << '\n';
    }

    return 0;
}

long long coprimeCount(const long long& num, int target)
{
    if (num <= 1 || target == 1) return num;

    long long result = 0;
    int targetPrimeList[10] = {0};
    int targetPrimeCount = 0;

    for (int pIndex = 0; target != 1 && pIndex < primeCount; pIndex++)
    {
        if (target % primeList[pIndex] == 0)
        {
            targetPrimeList[targetPrimeCount++] = primeList[pIndex];
            target /= primeList[pIndex];
            while (target % primeList[pIndex] == 0)
                target /= primeList[pIndex];
        }
    }

    if (target != 1)
        targetPrimeList[targetPrimeCount++] = target;

    stack<tuple<long long, int, int>> dfsStack;
    //div, depth, mulCount
    dfsStack.emplace(1, 0, 0);
    
    while (dfsStack.empty() == false)
    {
        auto [div, depth, mulCount] = dfsStack.top();
        dfsStack.pop();

        if (depth == targetPrimeCount)
        {
            if (mulCount % 2)
                result -= num / div;
            else
                result += num / div;
        } else {
            long long next = div * targetPrimeList[depth];
            if (next > div /*overflow Check*/ && next <= num)
                dfsStack.emplace(div * targetPrimeList[depth], depth + 1, mulCount + 1);
            dfsStack.emplace(div, depth + 1, mulCount);
        }
    }


    return result;
}
