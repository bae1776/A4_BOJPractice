//https://www.acmicpc.net/problem/11690

/* LCM(1, 2, ..., n) (Gold 4)

자연수 n(최대 1억)이 주어졌을 때,
1, 2, 3, ... , n 의 최소 공배수를 구하시오. 
정답이 매우 커질 수 있으므로 2^32로 나눈 나머지를 출력한다.
*/


#include <iostream>
#include <chrono>
#include <bitset>
using namespace std;
bitset<100000001> isNotPrime;


int main(void)
{
    int val;
    cin >> val;

    //고속 에라토스테네스의 체   
    isNotPrime[0] = isNotPrime[1] = true;
    for (int i = 2; i <= 100000000; i += 2)
        isNotPrime[i] = true;


    for (long long i = 3; i <= 100000000; i += 2)
    {
        if (isNotPrime[i] == true) continue;

        for (long long idx = i * i; idx <= 100000000; idx += 2 * i)
            isNotPrime[idx] = true;
    }
    //소수 구하기 끝


    long long answer = 1;
    while (answer <= val)
        answer <<= 1;
    answer >>= 1;

    for (int i = 3; i <= val; i += 2)
    {
        if (isNotPrime[i]) continue;
        long long checker = 1, mul = i;

        while ((checker = mul * i) <= val)
            mul = checker;

        answer = answer * mul % 0x100000000ll;
    }

    cout << answer;
    
	
    return 0;
}