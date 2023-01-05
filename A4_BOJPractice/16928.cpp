//https://www.acmicpc.net/problem/16928

/* 뱀과 사다리 게임 (Gold 5)
정육면체 주사위를 굴려 1~6칸 씩 전진하여 1번 칸에서 100번 칸 까지 가야하는 게임이다.
각 칸에는 최대 1개의 뱀 또는 사다리를 가지는 데, 뱀인 경우 연결된 칸으로 내려가고, 사다리인 경우 연결된 칸으로 올라간다.

주사위를 던질 때마다 나오는 눈을 조작할 수 있다 가정할 때, 100번 칸에 도착하기 위해 굴려야 할 최소 횟수를 구하시오.
(100번 칸을 도착할 수 있는 입력만 주어진다.)

Solution : BFS.
뱀, 사다리를 타면 무조건 이동해야하므로 그것이 시작하는 칸은 BFS 상에서 고려할 필요 없다.
*/

#include <iostream>
#include <queue>
using namespace std;

int warp[101];
bool visited[101];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int ladder, snake;
    cin >> ladder >> snake;
    for (int i = 1; i <= 100; i++)
        warp[i] = i;

    for (int i = 0; i < ladder + snake; i++)
    {
        int start, end;
        cin >> start >> end;
        warp[start] = end;
    }

    queue<pair<int, int>> bfsQueue; //number, depth;
    bfsQueue.emplace(1, 0);
    visited[1] = true;

    while (true)
    {
        auto now = bfsQueue.front();
        if (now.first == 100)
        {
            cout << now.second;
            break;
        }

        for (int diceResult = 1; diceResult <= 6; diceResult++)
        {
            if (now.first + diceResult > 100)
                break;

            int next = warp[now.first + diceResult];
            if (visited[next] == false)
            {
                visited[next] = true;
                bfsQueue.emplace(next, now.second + 1);
            }
        }

        bfsQueue.pop();

    }

	return 0;
}
