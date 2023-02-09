//https://www.acmicpc.net/problem/2166

/* 다각형의 면적 (Gold 5)

2차원 평면 상에 N(3 ~ 10000)개의 점이 주어진다. 이 다각형의 면적을 소수 첫째자리까지 반올림하여 구하시오.

Solution :
1. ccw(11758번 참고)를 이용하여 구할 수 있다. ccw의 크기는 두 벡터를 평행이동하여 만든 평행사변형의 넓이와 같으므로,
여기에 2를 나누어 나오는 삼각형 넓이를 모두 합하면 된다. 즉, 점 a, b, c, d, e, f, g가 있을 때
다각형 abcdefg의 넓이는 | ccw(a, b, c) / 2 + ccw(a, c, d) / 2 + ... + ccw(a, f, g) / 2 | 이다.

2. 신발끈 공식 : 이것도 증명에는 외적이 이용되며, 사실 ccw의 연장선이다.
점 a(x1, y1), b(x2, y2) ... n(xn, yn) 에 대하여
넓이는 0.5 * | x1 x2 ... xn x1 | = 0.5 * | x1y2 + x2y3 ... + xny1 - x2y1 - x3y2 ... - x1yn |
            | y1 y2 ... yn y1 |


*/


#include <iostream>
using namespace std;
long long pointX[10001], pointY[10001];

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int pointCount;
    cin >> pointCount;

    //신발끈
    for (int i = 0; i < pointCount; i++)
        cin >> pointX[i] >> pointY[i];
    
    pointX[pointCount] = pointX[0];
    pointY[pointCount] = pointY[0];
    
    
    long long ans = 0;

    for (int i = 0; i < pointCount; i++)
    {
        ans += pointX[i] * pointY[i + 1];
        ans -= pointY[i] * pointX[i + 1];
    }

    cout << abs(ans / 2);

    if (ans % 2)
        cout << ".5";
    else
        cout << ".0";
    

    return 0;
}
