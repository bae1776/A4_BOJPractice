//https://www.acmicpc.net/problem/12851

//숨바꼭질 2
//수빈이와 동생은 1~100000 중 하나의 점에 있다.
//수빈이는 이동 혹은 순간이동을 하여 동생에게 도달하는 최단 시간과 최단으로 찾는 방법의 수를 구하세요.
//수빈이가 점 X에서 이동하면 X-1 또는 X+1 로 1초만에 갈 수 있고
//수빈이가 점 X에서 순간이동하면 2*X로 1초만에 간다.


#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> BFSQueue;
int visitDepth[100002];
int visitCases[100002];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int subin, younger;
    cin >> subin >> younger;

    int result = 0x7FFFFFFF, cases = 0;
    visitDepth[100001] = 100000;
    BFSQueue.emplace(subin, 0);
    visitCases[subin] = 1;

    while (!BFSQueue.empty())
    {
        pair<int, int> nowQueue = BFSQueue.front();
        BFSQueue.pop();

        if (result < nowQueue.second)
            break;

        if (nowQueue.first < younger)
        {
            //X-1
            if (nowQueue.first != 0)
            {
                if (visitDepth[nowQueue.first - 1] == 0)
                {
                    visitDepth[nowQueue.first - 1] = nowQueue.second + 1;
                    visitCases[nowQueue.first - 1] = visitCases[nowQueue.first];
                    BFSQueue.emplace(nowQueue.first - 1, nowQueue.second + 1);
                } else if (visitDepth[nowQueue.first - 1] == nowQueue.second + 1)
                    visitCases[nowQueue.first - 1] += visitCases[nowQueue.first];
            }
            
            //X+1
            if (visitDepth[nowQueue.first + 1] == 0)
            {
                visitDepth[nowQueue.first + 1] = nowQueue.second + 1;
                visitCases[nowQueue.first + 1] = visitCases[nowQueue.first];
                BFSQueue.emplace(nowQueue.first + 1, nowQueue.second + 1);
            } else if (visitDepth[nowQueue.first + 1] == nowQueue.second + 1)
                visitCases[nowQueue.first + 1] += visitCases[nowQueue.first];

            //X * 2
            if (nowQueue.first != 0 && nowQueue.first * 2 <= younger + 1)
            {
                if (visitDepth[nowQueue.first * 2] == 0)
                {
                    visitDepth[nowQueue.first * 2] = nowQueue.second + 1;
                    visitCases[nowQueue.first * 2] = visitCases[nowQueue.first];
                    BFSQueue.emplace(nowQueue.first * 2, nowQueue.second + 1);
                } else if (visitDepth[nowQueue.first * 2] == nowQueue.second + 1)
                    visitCases[nowQueue.first * 2] += visitCases[nowQueue.first];
            }
        } 
        else if (nowQueue.first == younger) {
            result = nowQueue.second;
            cases += visitCases[nowQueue.first];
        } else {
            if (visitDepth[nowQueue.first - 1] == 0)
                {
                    visitDepth[nowQueue.first - 1] = nowQueue.second + 1;
                    visitCases[nowQueue.first - 1] = visitCases[nowQueue.first];
                    BFSQueue.emplace(nowQueue.first - 1, nowQueue.second + 1);
                } else if (visitDepth[nowQueue.first - 1] == nowQueue.second + 1)
                    visitCases[nowQueue.first - 1] += visitCases[nowQueue.first];
        }
    }

    cout << result << '\n' << cases;

	return 0;
}
