//https://www.acmicpc.net/problem/11967

/*불 켜기 (Gold 2)
Solution : BFS
인접해있으면서 불이 켜진 칸만 갈 수 있음에 유의한다.
BFS를 돌면서 위 두 조건을 모두 만족하는 곳만 큐에 추가한다.
*/

#include <iostream>
#include <queue>
#include <list>
using namespace std;

enum { NONE, BRIGHT, VISITABLE, LISTED };
int roomState[102][102];
list<pair<int, int>> switchList[102][102];
queue<pair<int, int>> visitBFS;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int roomSize, switchCount;
    cin >> roomSize >> switchCount;

    int answer = 1;
    //1번 방을 켜놓는다.
    roomState[1][1] = LISTED;
    visitBFS.emplace(1, 1);

    while (switchCount--)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        switchList[x][y].emplace_back(a, b);
    }

    while (visitBFS.empty() == false)
    {
        auto [x, y] = visitBFS.front();
        visitBFS.pop();

        //아래 두 조건을 모두 만족하면 큐에 추가됨
        //1. 불 켜기
        for (const auto& beBrighted : switchList[x][y])
        {
            int& state = roomState[beBrighted.first][beBrighted.second];
            switch (state)
            {
                case NONE:
                    state = BRIGHT; answer++; break;
                case VISITABLE:
                    state = LISTED; answer++;
                    visitBFS.emplace(beBrighted.first, beBrighted.second);
                    break;
                case BRIGHT: case LISTED:
                    break;
            }
        }

        //2. (불이 켜진다면) 방문 가능한 방 추가
        const int dx[] = { 0, 0, -1, 1 };
        const int dy[] = { -1, 1, 0, 0 };
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> adj = { x + dx[i], y + dy[i] };
            int& state = roomState[adj.first][adj.second];
            switch (state)
            {
                case NONE:
                    state = VISITABLE; break;
                case BRIGHT:
                    state = LISTED;
                    visitBFS.emplace(adj.first, adj.second);
                    break;
                case VISITABLE: case LISTED:
                    break;
            }
        }
    }

    cout << answer;

	return 0;
}
