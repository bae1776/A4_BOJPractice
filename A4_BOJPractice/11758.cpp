//https://www.acmicpc.net/problem/11758

/* CCW (Gold 5)

2차원 좌표 평면 위에 있는 점 3개 P1, P2, P3에 대해 P1-P2-P3 선분이 어떤 방향을 이루고 있는지 구하시오.
반시계방향이면 1, 시계방향이면 -1, 일직선이면 0을 출력하라.

Info :
CCW는 Counter Clock Wise의 줄임말로, 점 3개에 대해 점 3개를 이은 직선의 방향을 가르쳐준다.
이것의 원리는 '외적'으로 외적은 다음과 같은 성질을 가진다.
1. 두 벡터를 외적하면, 두 벡터의 수직벡터가 나온다. 그리고 그 크기는, 두 벡터가 만들어내는 평행 사변형의 넓이이다.
2. 벡터는 교환법칙이 성립하지 않는다. a x b != b x a
(임의의 두 벡터에 대한 수직 벡터는 일반적으로 2가지인데, 그중에서 오른손 법칙을 통해 둘 중 하나를 가려 낼 수 있다.)

오른손 법칙을 통해 A, B, C의 방향을 구해보면. AB x AC의 결과를 생각하면 된다.
3차원 공간 상 벡터는 행렬식(determinant) | |을 표현된다.
i, j, k는 각각 x, y, z축과 평행한 단위벡터라 하고, AB(vector) = (x, y, z), AC(vector) = (X, Y, Z)라 할 때,
AB x AC는
| i j k |      ==     i * | y z | - j * | x z | + k | x y |
| x y z | (행렬식 전개)     | Y Z |       | X Z |     | X Y |
| X Y Z |

A, B, C 점은 모두 2차원 평면 상의 점이므로 z = Z = 0이므로 결국,
AB x AC = k(0, 0, 1) * (xY - yX) =  (0, 0, (x2 - x1)(y3 - y1) - (y2 - y1)(x3 - x1)) 이다.  (2차 행렬식 공식 ad - bc)

이때, z 성분이 양수이면, AB AC가 반시계 방향으로 배치된 것이기 때문에 A, B, C는 좌회전이고,
             음수이면, AB AC가 시계 방향으로 배치된 것이기 때문에 A, B, C는 우회전이다.
(0이면, 일직선 상에 있다.)
*/

#include <iostream>
using namespace std;

int ccw(const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& c)
{
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    pair<int, int> a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;

    int result = ccw(a, b, c);

    if (result > 0)
        cout << 1;
    else if (result == 0)
        cout << 0;
    else
        cout << -1;
    
	return 0;
}
