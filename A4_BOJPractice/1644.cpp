//https://www.acmicpc.net/problem/1644

/*소수의 연속합

하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다.
3  : 3 (한 가지)
41 : 2 + 3 + 5 + 7 + 11 + 13 = 11 + 13 + 17 = 41 (세 가지)

자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하시오.

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int input;
    cin >> input;

    vector<int> primeList;
    primeList.emplace_back(2);

    for (int i = 3; i <= input; i++)
    {
        int isPrime = true;
        int max = (int)sqrt(i);

        for (int index = 0; primeList[index] <= max; ++index)
        {   
            if (i % primeList[index] == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            primeList.emplace_back(i);
    }
    
    int leftPtr = 0;
    int rightPtr = 0;
    int count = 0;
    int partSum = primeList[0];

    while (true)
    {
        if (partSum <= input)
        {
            if (partSum == input)
                count++;
            if (rightPtr == primeList.size() - 1)
                break;
            partSum += primeList[++rightPtr];
        } else
            partSum -= primeList[leftPtr++];
    }

    cout << count;

	
	return 0;
}