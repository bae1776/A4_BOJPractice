//https://www.acmicpc.net/problem/2749

//피보나치 수 3
//N번째 피보나치 수 % 1000000 을 구하시오.
//그런데 N이 1,000,000,000,000,000,000 이하의 자연수이므로.
//O(logN) 알고리즘이 있어야 풀 수 있을 것이다.

#include <iostream>
#include <array>
#define RST 1000000
using namespace std;
using Matrix_2x2 = array<array<long long, 2>, 2>;


Matrix_2x2 matExpon(Matrix_2x2& matTwo, long long int exp) {
	if (exp <= 1) return matTwo;

	Matrix_2x2 half = matExpon(matTwo, exp / 2);

	Matrix_2x2 newMat = { {{0, 0}, {0, 0}} };
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++)
				newMat[i][j] += half[i][k] * half[k][j];
			newMat[i][j] %= RST;
		}
	
	if (exp % 2 == 1) {
		Matrix_2x2 copyMat = newMat;
		newMat = { {{0, 0}, {0, 0}} };

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++)
					newMat[i][j] += copyMat[i][k] * matTwo[k][j];
				newMat[i][j] %= RST;
			}
	}

	return newMat;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long input;
	cin >> input;

	//[1, 1; 1, 0]^n 으로 구할 수 있다.
	Matrix_2x2 matTwo = { { {1, 1}, {1, 0} } };
	auto result = matExpon(matTwo, input - 1);

	cout << result[0][0];
	return 0;
}