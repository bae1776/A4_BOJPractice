//https://www.acmicpc.net/problem/2022

/* 사다리 (Gold 5)

Solution : 수학

1 = c * {(x^2 - l^2)^-0.5 + (y^2 - l^2)^-0.5}
여기서 x,y,z 가 주어질때, l을 구해야한다.
방정식의 해가 정리하기 어렵고 관계식만 알 수 있기 때문에 (음함수 꼴로만 나타내짐),
이분 탐색으로 찍어야한다.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    long double x, y, c;
    cin >> x >> y >> c;

    long double left = 0.0, right = min(x, y), mid;
 
    while (true) {
        mid = (left + right) / 2.0;
        if (right - left < 0.0001)
            break;

        long double answer = pow(x * x - mid * mid, -0.5) + pow(y * y - mid * mid, -0.5);
        answer *= c;

        if (answer >= 1)
            right = mid;
        else
            left = mid;
    }


    cout.precision(3);
    cout << fixed << mid;

    return 0;
}
