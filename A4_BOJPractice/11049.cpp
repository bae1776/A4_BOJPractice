//https://www.acmicpc.net/problem/11049

/*행렬 곱셈 순서

(N, M) 행렬을 (M, K) 행렬과 곱하면 필요한 곱셈 연산의 수는 N*M*K 번이다.
행렬 A개를 곱하는데 필요한 연산의 수는 행렬 곱의 순서에 따라 다르다!
행렬 A개의 크기가 주어졌을 때, 곱셈 연산 수의 최소를 구하시오.

*/

#include <iostream>
#include <vector>
using namespace std;

struct Matrix {
    int row;
    int col;
    unsigned int calSum;

    Matrix() : row(0), col(0), calSum(0x7FFFFFFFu) {};
};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int matrixCount;
    cin >> matrixCount;

    vector<vector<Matrix>> matrixDP(matrixCount);

    for (int i = 0; i < matrixCount; i++)
    {
        matrixDP[i] = vector<Matrix>(i + 1, Matrix());
        cin >> matrixDP[i][i].row >> matrixDP[i][i].col;
        matrixDP[i][i].calSum = 0;
    }

    for (int mulSize = 2; mulSize <= matrixCount; mulSize++)
        for (int startMatrix = 0; startMatrix <= matrixCount - mulSize; startMatrix++)
        {
            const int endMatrix = startMatrix + mulSize - 1;
            Matrix& nowMatrix = matrixDP[endMatrix][startMatrix];
            nowMatrix.row = matrixDP[startMatrix][startMatrix].row;
            nowMatrix.col = matrixDP[endMatrix][endMatrix].col;

            for (int pivot = startMatrix; pivot < endMatrix; pivot++)
                nowMatrix.calSum = min(nowMatrix.calSum, 
                    matrixDP[endMatrix][pivot + 1].calSum + matrixDP[pivot][startMatrix].calSum 
                    + nowMatrix.row * nowMatrix.col * matrixDP[pivot][pivot].col);
        }

    cout << matrixDP[matrixCount-1][0].calSum;

    return 0;
}
