//https://www.acmicpc.net/problem/16985

/*Maaaaaaaaaze (Gold 2)
5x5 크기의 판이 5개 있다. 각 판은 갈 수 있는 위치와 갈 수 없는 위치가 색칠 되어 있다.
당신은 이 판을 자유롭게 90도씩 회전할 수 있고
회전한 판을 자유로운 순서로 쌓을 수 있다. 그러면 5x5x5 큐브가 참가자가 통과해야할 미로가 된다.
큐브의 입구는 참가자가 임의로 선택한 정육면체의 꼭짓점이며 출구는 그 반대쪽 꼭짓점이다.

주어진 판에서 자유롭게 회전, 쌓기하여, 가장 적은 이동 횟수로 출구로 도달 했을 때 그 횟수를 출력하세요.
어느한 경우에도 탈출이 불가능한 경우, -1을 출력하세요.

솔루션 : 브루트포스 + BFS
*/

#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
using Board = array<array<char, 5>, 5>;
using tuple4 = tuple<char, char, char, char>;
#define MAX 0x7FFFFFFF

Board boards[5][4];
vector<array<int, 5>> perms;

void makePerm(array<int, 5>& arr, int depth);
int escapeMaze(const array<Board, 5>& maze);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int boardIndex = 0; boardIndex < 5; boardIndex++)
    {
        for (int y = 0; y < 5; y++)
            for (int x = 0; x < 5; x++)
                cin >> boards[boardIndex][0][y][x];

        //회전체 만들기
        for (int y = 0; y < 5; y++)
            for (int x = 0; x < 5; x++)
            {
                //90도 우회전
                boards[boardIndex][1][y][x] = boards[boardIndex][0][4 - x][y];
                //180도 우회전
                boards[boardIndex][2][y][x] = boards[boardIndex][0][4 - y][4 - x];
                //270도 우회전
                boards[boardIndex][3][y][x] = boards[boardIndex][0][x][4 - y];
            }
    }

    array<int, 5> init = { 0, 1, 2, 3, 4 };
    //순열 만들기
    makePerm(init, 0);
    int result = MAX;


    for (int i = 0; i < 120; i++) //순열 (블럭 쌓는 순서) 선택
    {
        for (int j = 0; j < 1024; j++) //회전 선택
        {
            array<Board, 5> selectedMaze;
            for (int k = 0; k < 5; k++)
                selectedMaze[k] = boards[perms[i][k]][(j >> (k * 2)) % 4];

            result = min(escapeMaze(selectedMaze), result);
        }
    }

    if (result == MAX)
        cout << -1;
    else
        cout << result;

    return 0;
}


void makePerm(array<int, 5>& arr, int depth)
{
    if (depth == 4)
    {
        perms.push_back(arr);
        return;
    }

    for (int swapIndex = depth; swapIndex < 5; swapIndex++)
    {
        swap(arr[depth], arr[swapIndex]);
        makePerm(arr, depth + 1);
        swap(arr[depth], arr[swapIndex]);
    }
}


int escapeMaze(const array<Board, 5>& maze)
{
    bool visited[5][5][5] = { {{false, }} };

    if (maze[0][0][0] == '0')
        return MAX;

    queue<tuple4> bfsQueue;
    visited[0][0][0] = true;
    bfsQueue.emplace(0, 0, 0, 0);

    while (bfsQueue.empty() == false)
    {
        const auto& [x, y, z, depth] = bfsQueue.front();
        if (x == y && y == z && z == 4)
            return depth;

        if (x != 0 && maze[x - 1][y][z] == '1' && visited[x - 1][y][z] == false)
        {
            visited[x - 1][y][z] = true;
            bfsQueue.emplace(x - 1, y, z, depth + 1);
        }

        if (y != 0 && maze[x][y - 1][z] == '1' && visited[x][y - 1][z] == false)
        {
            visited[x][y - 1][z] = true;
            bfsQueue.emplace(x, y - 1, z, depth + 1);
        }

        if (z != 0 && maze[x][y][z - 1] == '1' && visited[x][y][z - 1] == false)
        {
            visited[x][y][z - 1] = true;
            bfsQueue.emplace(x, y, z - 1, depth + 1);
        }

        if (x != 4 && maze[x + 1][y][z] == '1' && visited[x + 1][y][z] == false)
        {
            visited[x + 1][y][z] = true;
            bfsQueue.emplace(x + 1, y, z, depth + 1);
        }

        if (y != 4 && maze[x][y + 1][z] == '1' && visited[x][y + 1][z] == false)
        {
            visited[x][y + 1][z] = true;
            bfsQueue.emplace(x, y + 1, z, depth + 1);
        }

        if (z != 4 && maze[x][y][z + 1] == '1' && visited[x][y][z + 1] == false)
        {
            visited[x][y][z + 1] = true;
            bfsQueue.emplace(x, y, z + 1, depth + 1);
        }

        bfsQueue.pop();
    }

    return MAX;

}