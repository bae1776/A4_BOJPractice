//https://www.acmicpc.net/problem/10163

//색종이
//최대 101*101 크기의 격자판에 대하여,
//최대 100장의 색종이에 대한 정보(시작 위치, 너비, 높이)가 차례대로 주어진다.
//주어진 순서대로 색종이를 격자판에 붙인다.
//나중에 붙인 색종이는 이전에 붙였던 색종이를 일부, 혹은 전부 덮을 수도 있는 점을 참고하여
//붙인 순서대로 각 색종이가 보이는 부분의 면적을 한 줄에 하나씩 출력하세요.


#include <iostream>
using namespace std;

int board[101][101];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int paperCount;
    cin >> paperCount;

    for (int paperOrder = 1; paperOrder <= paperCount; paperOrder++)
	{
        int startX, startY, width, depth;
        cin >> startX >> startY >> width >> depth;

        for (int x = 0; x < width; x++)
            for (int y = 0; y < depth; y++)
                board[x + startX][y + startY] = paperOrder;
    }

    int* areaSumList = new int[paperCount + 1];
    for (int i = 1; i <= paperCount; i++)
        areaSumList[i] = 0;

    for (int x = 0; x <= 100; x++)
        for (int y = 0; y <= 100; y++)
            areaSumList[board[x][y]]++;

    for (int i = 1; i <= paperCount; i++)
        cout << areaSumList[i] << '\n';

    delete[] areaSumList;
    
    return 0;
}
