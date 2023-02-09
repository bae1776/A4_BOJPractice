//https://www.acmicpc.net/problem/17425

/*약수의 합 (Gold 4)
자연수 A에 대하여,
f(A) = A의 약수의 합
g(A) = f(1) + f(2) + f(3) ... + f(A) 라 하자.

10만 개의 input에 대해
g(input)을 구하시오.
input은 최대 100만이다.

Solution : 
f는 다음 성질을 만족한다.
t = 자연수, P = 소수일때, f(t * P) = P * f(t) + f(t / P^k) 
(k는 t / P^k를 나누어떨어지게 하는 가장 큰 자연수.)
예를 들어, f(60) = 2 * f(30) + f(15) 이다.
*/

#include <stdio.h>
#include <stdbool.h>
long long f[1000001] = {0, 1}, g[1000001] = {0, 1};
int primeArr[1001] = {2, 3}, primeArrSq[1001] = {4, 9};

int main(void)
{
    //에라토스테네스의 체로 소수 리스트 생성
    int primeArrIndex = 2;
    int searchIndex = 0;
    for (int num = 5; num <= 2000; num++)
    {
        if (num >= primeArrSq[searchIndex])
            searchIndex++;
        
        bool isPrime = true;
        for (int i = 0; i < searchIndex; i++)
        {
            if (num % primeArr[i] == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            primeArr[primeArrIndex] = num;
            primeArrSq[primeArrIndex] = num * num;
            primeArrIndex++;
        }
    }

    //미리 g(1) ~ g(1000000)를 구해놓는다.
    for (int num = 2; num <= 1000000; num++)
    {
        /* f 성질 활용 */
        bool isPrime = true;
        int in1, in2;
        for (int idx = 0; primeArrSq[idx] <= num; ++idx)
        {
            if (num % primeArr[idx] == 0)
            {
                in1 = in2 = num / primeArr[idx];
                while (in2 % primeArr[idx] == 0)
                    in2 /= primeArr[idx];

                f[num] = primeArr[idx] * f[in1] + f[in2];
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            f[num] = num + 1;

        g[num] = g[num - 1] + f[num];
    }

    int query;
    scanf("%d", &query);

    while (query--)
    {
        int input;
        scanf("%d", &input);
        printf("%d \n", g[input]);
    }


	return 0;
}

