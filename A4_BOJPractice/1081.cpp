//https://www.acmicpc.net/problem/1081

/*합 (Gold 1)

Solution : 수학
(단순 계산은 당연히 시간 초과가 뜬다)
각 자릿수의 분포를 이용한다.

ft 함수 내부 주석을 참고하라.
*/ 

#include <iostream>
using namespace std;

long long digitSum(long long value)
{
    long long result = 0;
    while (value)
    {
        result += value % 10;
        value /= 10;
    }

    return result;
}


long long ft(long long value)
{
    //예를 들어 value = 1024라 하자.
    const static long long base[10] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45};
    if (value <= 9) 
        return base[max(0ll, value)];

    long long result = 0;

    //quotient = 102, rest = 4 이다.
    long long quotient = value / 10;
    long long rest = value % 10;

    //1. 십의 자리 이후만 생각 했을 때, 
    //0 ~ 101(quotient - 1)까지 10번씩 등장한다 + 102는 5(rest + 1)번 등장한다.
    result += ft(quotient - 1) * 10 + digitSum(quotient) * (rest + 1);

    //2. 일의 자리만 생각했을 때,
    //0 1 2 ... 9가 102(quotient)번 반복된다 + 1 ... 4(rest)까지 한번 등장한다.
    result += base[9] * quotient + base[rest];

    return result;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int start, end;
    cin >> start >> end;

    cout << ft(end) - ft(start - 1);

	return 0;
}

