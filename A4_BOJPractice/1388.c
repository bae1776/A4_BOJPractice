//https://www.acmicpc.net/problem/1388

/*바닥 장식 (Silver 4)
형택이는 기훈이 방의 바닥 장식을 디자인했고, 이제 몇 개의 나무 판자가 필요한지 궁금해졌다. 
나무 판자는 크기 1의 너비를 가졌고, 양수의 길이를 가지고 있다. 
기훈이 방은 직사각형 모양이고, 방 안에는 벽과 평행한 모양의 정사각형으로 나누어져 있다.

이제 ‘-’와 ‘|’로 이루어진 바닥 장식 모양이 주어진다. 
만약 n개의 ‘-’가 인접해 있고, 같은 행에 있다면, n개는 같은 나무 판자이고, 
    n개의 ‘|’가 인접해 있고, 같은 열에 있다면, n개는 같은 나무 판자이다.

기훈이의 방 바닥을 장식하는데 필요한 나무 판자의 개수를 출력하는 프로그램을 작성하시오.
(방의 크기는 최대 50 * 50)
*/

#include <stdio.h>
#include <stdbool.h>

int row, col;
bool visited[50][50];
char room[51][51];

void roomScan(int i, int j)
{
    visited[i][j] = true;
    if (room[i][j] == '-')
    {
        if (j != col - 1 && room[i][j + 1] == '-')
            roomScan(i, j + 1);
    } 
    else if (room[i][j] == '|') 
    {
        if (i != row - 1 && room[i + 1][j] == '|')
            roomScan(i + 1, j);
    }
}

int main(void)
{
    scanf("%d %d", &row, &col);
    int woodCount = 0;

    for (int i = 0; i < row; i++)
        scanf("%s", room[i]);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (visited[i][j] == false)
            {
                woodCount++;
                roomScan(i, j);
            }
        }
    }

    printf("%d", woodCount);
	return 0;
	
}