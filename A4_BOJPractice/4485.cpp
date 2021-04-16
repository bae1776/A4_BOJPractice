//https://www.acmicpc.net/problem/4485

//녹색 옷 입은 애가 젤다지?
//젤다의 전설의 주인공인 '링크'는 매 칸마다 일정 루피(게임 내 재화)를 잃는 이상한 동굴에 있다.
//링크는 터널의 [0][0]에서 [N-1][N-1]로 가려고 한다.
//매 칸에 도달할 때마다 잃는 루피가 주어질 때, 끝까지 갔을 때 잃는 루피의 최소를 구하여라.
//테스트 케이스는 여러 개이다.


#include <iostream>
#include <vector>
using namespace std;
template <typename T>
using Board = vector<vector<T>>;
#define INF 987654321

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int testCase = 1;
	while (true)
    {
        int caveSize;
        cin >> caveSize;

        if (caveSize == 0) break;

        Board<int> caveRupee(caveSize, vector<int>(caveSize));
        for (int i = 0; i < caveSize; i++)
            for (int j = 0; j < caveSize; j++)
                cin >> caveRupee[i][j];

        Board<bool> visited(caveSize, vector<bool>(caveSize, false));
        Board<int> minCost(caveSize, vector<int>(caveSize, INF));

        int nowVisit_x = 0, nowVisit_y = 0;
        minCost[nowVisit_y][nowVisit_x] = caveRupee[nowVisit_y][nowVisit_x];

        do {
            visited[nowVisit_y][nowVisit_x] = true;
            
            if (nowVisit_y > 0)
                minCost[nowVisit_y - 1][nowVisit_x]
                    = min(minCost[nowVisit_y - 1][nowVisit_x], minCost[nowVisit_y][nowVisit_x] + caveRupee[nowVisit_y - 1][nowVisit_x]);
            
            if (nowVisit_y + 1 < caveSize)
                minCost[nowVisit_y + 1][nowVisit_x]
                    = min(minCost[nowVisit_y + 1][nowVisit_x], minCost[nowVisit_y][nowVisit_x] + caveRupee[nowVisit_y + 1][nowVisit_x]);

            if (nowVisit_x > 0)
                minCost[nowVisit_y][nowVisit_x - 1]
                    = min(minCost[nowVisit_y][nowVisit_x - 1], minCost[nowVisit_y][nowVisit_x] + caveRupee[nowVisit_y][nowVisit_x - 1]);

            if (nowVisit_x + 1 < caveSize)
                minCost[nowVisit_y][nowVisit_x + 1]
                    = min(minCost[nowVisit_y][nowVisit_x + 1], minCost[nowVisit_y][nowVisit_x] + caveRupee[nowVisit_y][nowVisit_x + 1]);

            int nowMin = INF;
            int nextMin_x = INF, nextMin_y = INF;
            for (int y = 0; y < caveSize; y++)
                for (int x = 0; x < caveSize; x++)
                    if (visited[y][x] == false && minCost[y][x] < nowMin)
                    {
                        nowMin = minCost[y][x];
                        nextMin_x = x; nextMin_y = y;
                    }

            nowVisit_x = nextMin_x;
            nowVisit_y = nextMin_y;

        } while (nowVisit_x != INF);
        

        cout << "Problem " << testCase << ": " << minCost[caveSize - 1][caveSize - 1] << '\n';
        testCase++;
        
    }

	return 0;
}
