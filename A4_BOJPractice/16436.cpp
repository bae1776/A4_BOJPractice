//https://www.acmicpc.net/problem/16436

/*얼룩말 아트
대회 링크 : https://www.acmicpc.net/category/detail/1949

진수는 가로 W 픽셀, 세로 Y 픽셀 크기의 흰 이미지에 K개의 도형을 그릴 것이고, 2가지 종류가 있다.
1. 직사각형 - px, py, qx, qy이 주어지면 px ≤ x ≤ qx 와 py ≤ y ≤ qy 를 만족하는 모든 픽셀 (x, y)의 색상을 반전시킵니다.
2. 다이아몬드 - px, py, r이 주어지면 |x - px| + |y - py| ≤ r 을 만족하는 모든 픽셀 (x, y)의 색상을 반전시킵니다.

진수는 도형이 많아질 수록 그리는 것을 어려워하여, 위의 방식에 따라 그림을 그리는 "효율적인" 프로그램을 작성해달라고 부탁하였다.
10 <= W, H <= 2500, 1 <= K <= 150000 이므로 효율적인 알고리즘이 필요할 것이다.

진수가 그리는 도형이 이미지 밖으로 벗어나는 경우는 없다.

*/


#include <iostream>
#include <vector>
using namespace std;

int board[2502][2502] = { 0 };
int rotatedBoard[5002][5002] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int width, height, shapeCount, i;
    cin >> width >> height >> shapeCount;


    for (i = 0; i < shapeCount; i++)
    {
        int shapeType;
        cin >> shapeType;

        if (shapeType == 1)
            //SQUARE
        {
            int startX, startY, endX, endY;
            cin >> startX >> startY >> endX >> endY;

            startX += 1; startY += 1;
            endX += 2; endY += 2;

            board[startY][startX]++;
            board[endY][startX]--;
            board[startY][endX]--;
            board[endY][endX]++;
        }
        else {
            //Diamond
            int centerX, centerY, size;
            cin >> centerX >> centerY >> size;

            const int convertedStartX = (centerX - size) + centerY + 2,
                convertedStartY = (centerX - size) - centerY + 2501,
                convertedSize = size * 2 + 1;

            rotatedBoard[convertedStartY][convertedStartX]++;
            rotatedBoard[convertedStartY + convertedSize][convertedStartX]--;
            rotatedBoard[convertedStartY][convertedStartX + convertedSize]--;
            rotatedBoard[convertedStartY + convertedSize][convertedStartX + convertedSize]++;
        }
    }

    for (i = 1; i <= height; i++)
        for (int j = 1; j <= width; j++)
            board[i][j] = board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1] + board[i][j];

    for (i = 1; i <= 5001; i++)
        for (int j = 1; j <= 5001; j++)
            rotatedBoard[i][j] = rotatedBoard[i - 1][j] + rotatedBoard[i][j - 1] - rotatedBoard[i - 1][j - 1] + rotatedBoard[i][j];


    for (int j = 2; j <= 5001; j++)
    {   
        int startI = 2501 - (j - 2);
        if (startI < 1)
            startI = 2 - (startI % 2);

        int endI = 2501 + (j - 2);
        if (endI > 5001)
            endI = 5000 + (endI % 2);

        for (i = startI; i <= endI; i += 2)
        {
            const int rotatedX = (i + j - 2501) / 2;
            const int rotatedY = (2501 - i + j) / 2;

            if (rotatedX <= width && rotatedY <= height)
                board[rotatedY][rotatedX] += rotatedBoard[i][j];
        }
    }

    for (i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
            if (board[i][j] % 2 == 1)
                cout << '#';
            else
                cout << '.';
        cout << '\n';
    }
    
    return 0;
}