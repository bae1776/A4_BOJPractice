//https://www.acmicpc.net/problem/26326

/*Circles Inside a Square (Silver 4)

���� ������ r�� �־��� ��,
�Ȱ��� �� 8���� ��� ���� �� �ִ� �簢���� �ּ� ���̴�?

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