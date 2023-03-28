//https://www.acmicpc.net/problem/1074

/*Z (Silver 1)

Solution : 분할 정복, 재귀

표를 가로 세로 절반으로 잘라 4칸으로 나누어 재귀하면 된다.
*/

#include <iostream>
using namespace std;

int ZFunction(int size, int row, int col);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int size, row, col;
    cin >> size >> row >> col;

    cout << ZFunction(size, row, col);

	return 0;
}

int ZFunction(int size, int row, int col)
{
    if (size == 0) return 0;
    int step = (1 << (size * 2 - 2));
    int boardLength = 1 << size;

    if (row < boardLength / 2 && col < boardLength / 2)
        return ZFunction(size - 1, row, col);
    if (row < boardLength / 2 && col >= boardLength / 2)
        return step + ZFunction(size - 1, row, col - boardLength / 2);
    if (row >= boardLength / 2 && col < boardLength / 2)
        return step * 2 + ZFunction(size - 1, row - boardLength / 2, col);
    if (row >= boardLength / 2 && col >= boardLength / 2)
        return step * 3 + ZFunction(size - 1, row - boardLength / 2, col - boardLength / 2);

    return step * 4;
}