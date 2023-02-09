//https://www.acmicpc.net/problem/26326

/*Circles Inside a Square (Silver 4)

원의 반지름 r이 주어질 때,
똑같은 원 8개를 모두 감쌀 수 있는 사각형의 최소 넓이는?

*/

#include <iostream>
#include <cmath>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    cout << fixed;
    cout.precision(5);

    double valConstant = (3.0 + sqrt(3.0) + sqrt(2.0) + sqrt(6.0)) * 4;

    while (testcase--)
    {
        double radius;
        cin >> radius;

        cout << valConstant * pow(radius, 2.0) << '\n';
    }
    return 0;
}