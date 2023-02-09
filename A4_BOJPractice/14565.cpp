//https://www.acmicpc.net/problem/14565

/* 역원(Inverse) 구하기  (Gold 2)

집합 Zn = {0, 1, 2, ... , n-1}이라 하자.
Zn의 원소 a, b, c에 대하여,
(a + b) mod n = 0 이면 b는 a의 덧셈역이고
(a * c) mod n = 1 이면 c는 a의 곱셈역이다.

n(최대 1조), a(n 미만의 자연수)에 대해 a의 덧셈역과 곱셈역을 구하시오. 곱셈역이 없는 경우 -1 출력.

Solution : 확장 유클리드 알고리즘
덧셈역은 매우 구하기 쉽다. n - b하면 된다.
곱셈역은
ac === 1 (mod n) 에 대하여
nd + ac = 1 이 성립한다. (모두 정수여야하는 부정방정식)
여기서 c, d은 변수이고 a, n는 고정된 수이다.
좌변은 임의의 정수 c, d에 대해 gcd(a, n)의 배수이므로 gcd(a, n) != 1 이면, 위 방정식의 정수해는 없다.
즉, 일단 a, n이 서로소인지를 확인한다. (서로소 아니면 곱셈역 없음)

이제 다음과 같은 과정을 거친다.
s0 = 1, t0 = 0, r0 = n
s1 = 0, t1 = 1, r1 = a

qi = ri-1 / ri (정수 나눗셈)
ri = ri-2 % ri-1 (유클리드 호제법 이용)
si = si-2 - si-1 * qi-1
ti = ti-2 - ti-1 * qi-1

종료 조건은 ri+1 = 0일 때이며 d = si, c = ti이다.
곱셈역은 양수여야 하므로
ti < 0 ? ti + n : ti를 출력하면 된다.

*/

#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

pair<long long, long long> eea(long long a, long long b)
{
    //https://www.crocus.co.kr/1232 참고

    vector<long long>
        left = { 1, 0 },
        right = { 0, 1 },
        rest = { a, b },
        quotient = { 0, a / b };
    /*
    s0 = 1, t0 = 0, r0 = a
    s1 = 0, t1 = 1, r1 = b

    ri = ri-2 % ri-1
    qi = ri-1 / ri (정수 나눗셈)
    si = si-2 - si-1 * qi-1
    ti = ti-2 - ti-1 * qi-1

    종료 조건 : ri+1 = 0일 때이며 x = si, y = ti이다.
    */
    int index = 2;
    long long nextRest;
    while (nextRest = rest[index - 2] % rest[index - 1])
    {
        rest.push_back(nextRest);
        quotient.push_back(rest[index - 1] / rest[index]);
        left.push_back(left[index - 2] - left[index - 1] * quotient[index - 1]);
        right.push_back(right[index - 2] - right[index - 1] * quotient[index - 1]);

        index++;
    }

    return make_pair(left[index - 1], right[index - 1]);


}



int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, a;
    cin >> n >> a;
    cout << n - a << ' ';
    
    if (gcd(n, a) == 1)
    {
        long long mulInverse = eea(n, a).second;
        cout << ((mulInverse < 0) ? mulInverse + n : mulInverse);
    }
    else
        cout << -1;

    return 0;
}