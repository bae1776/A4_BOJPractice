//https://www.acmicpc.net/problem/7561

/* 크래머의 공식 (Gold 4)

미지수가 x1, x2, x3로 3개인 일차 방정식 3개

a11 * x1 + a12 * x2 + a13 * x3 = b1
a21 * '' + a22 * '' + a23 * '' = b2  ('' = 상동)
a31 ...             + a33 * '' = b3

3x3 행렬 A = (a11, a12, a13; ... a32, a33), 
벡터 b = (b1; b2; b3), x = (x1, x2, x3) 로 나타내면
A * x = b 로 나타낼 수 있고, 이때 크래머의 공식을 이용하면,

xi = det Ai / det A 를 계산함으로써 해를 구할 수 있다.
여기서 det는 행렬식이고, Ai는 A의 i번째 열을 벡터 b로 대체한 것이다.
det A != 0 이면 해가 없거나 무수히 많다.

A, b가 주어질 때, 
det A1, det A2, det A3, det A 그리고 해를 소수 세자리까지 출력하시오.

Solution : 수학
*/

#include <iostream>
#include <array>
using namespace std;
using Matrix3 = array<array<long long, 3>, 3>;
using Vector3 = array<long long, 3>;

long long determinant3(const Matrix3& m)
{
	return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
		 - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
		 + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		Matrix3 A;
		Vector3 b;

		for (int i = 0; i < 3; i++)
			cin >> A[i][0] >> A[i][1] >> A[i][2] >> b[i];

		long long det[3];

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				swap(A[j][i], b[j]);

			det[i] = determinant3(A);

			for (int j = 0; j < 3; j++)
				swap(A[j][i], b[j]);
		}

		long long detA = determinant3(A);

		cout << det[0] << ' ' << det[1] << ' ' << det[2] << ' ' << detA << '\n';

		if (detA == 0)
		{
			cout << "No unique solution\n\n";
		} else {
			cout << "Unique solution: ";

			for (int i = 0; i < 3; i++)
			{
				double answer = 1.0 * det[i] / detA; 
				if (-0.0005 < answer && answer < 0.0005)
					answer = 0.000;

				cout << fixed;
				cout.precision(3);
				cout << answer << ' ';
			}
			cout << "\n\n";

		}
	}


    

    return 0;
}

