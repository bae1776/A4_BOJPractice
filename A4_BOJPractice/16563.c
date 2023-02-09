//https://www.acmicpc.net/problem/16563

/*어려운 소인수분해 (Gold 4)
100만 개의 자연수를 1초 안에 모두 소인수분해 하세요.
각 자연수는 최대 500만이다.

Solution : DP, 에라토스테네스의 체 혼합
*/

#include <stdio.h>
#include <stdbool.h>
int primeCount = 0;
int primeArr[2000] = {2, 3};
int primeArrSq[2000] = {4, 9};
int DP[5000001], div[5000001];

void DPFunction(int value);

int main(void)
{
    //에라토스테네스의 체로 소수 리스트 생성
    int primeArrIndex = 2;
    int searchIndex = 0, threshold = primeArr[searchIndex] * primeArr[searchIndex];
    for (int num = 5; num <= 8000; num++)
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

    //입력
    int numCount;
    scanf("%d", &numCount);

    while (numCount--) {
        int input;
        scanf("%d", &input);

        DPFunction(input);
        printf("\n");
    }

	return 0;
}


void DPFunction(int value)
{
    if (div[value] == 0)
    {
        for (int idx = 0; primeArrSq[idx] <= value; ++idx)
        {
            if (value % primeArr[idx] == 0)
            {
                int result = value / primeArr[idx];
                div[value] = primeArr[idx];
                DP[value] = result;

                printf("%d ", div[value]);
                DPFunction(DP[value]);
                return;
            }
        }

        div[value] = 1;
        printf("%d ", value);
    } 
    else if (div[value] == 1) 
    {
        printf("%d ", value);
    }
    else
    {
        printf("%d ", div[value]);
        DPFunction(DP[value]);
    }
}