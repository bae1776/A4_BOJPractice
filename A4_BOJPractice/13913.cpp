//https://www.acmicpc.net/problem/1697

//숨바꼭질 1
//수빈이와 동생은 1~100000 중 하나의 점에 있다.
//수빈이는 이동 혹은 순간이동을 하여 동생에게 도달하는 최단 시간을 구하세요.
//수빈이가 점 X에서 이동하면 X-1 또는 X+1 로 1초만에 갈 수 있고
//수빈이가 점 X에서 순간이동하면 2*X로 1초만에 간다.


#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<pair<int, int>> BFSQueue;
char visited[100002];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int subin, younger;
    cin >> subin >> younger;

    int result = 0;
    visited[100001] = true;
    BFSQueue.emplace(subin, 0);

    while (true)
    {
        pair<int, int> nowQueue = BFSQueue.front();
        BFSQueue.pop();

        if (nowQueue.first < younger)
        {
            if (nowQueue.first != 0 && visited[nowQueue.first - 1] == false)
            {
                BFSQueue.emplace(nowQueue.first - 1, nowQueue.second + 1);
                visited[nowQueue.first - 1] = '-';
            }

            if (visited[nowQueue.first + 1] == false)
            {
                BFSQueue.emplace(nowQueue.first + 1, nowQueue.second + 1);
                visited[nowQueue.first + 1] = '+';
            }

            if (nowQueue.first != 0 && nowQueue.first * 2 <= younger + 1 && visited[nowQueue.first * 2] == false)
            {
                BFSQueue.emplace(nowQueue.first * 2, nowQueue.second + 1);
                visited[nowQueue.first * 2] = '*';
            }

        } 
        else if (nowQueue.first == younger) {
            result = nowQueue.second;
            break;
        } else {
            if (visited[nowQueue.first - 1] == false)
            {
                BFSQueue.emplace(nowQueue.first - 1, nowQueue.second + 1);
                visited[nowQueue.first - 1] = '-';
            }
        }
    }

    cout << result << '\n';

    stack<int> routeRList;
    int nowRoute = younger;
    while (true)
    {
        routeRList.push(nowRoute);
        if (nowRoute == subin)
            break;
            
        switch (visited[nowRoute])
        {
            case '+':
                nowRoute--;
                break;
            case '-':
                nowRoute++;
                break;
            case '*':
                nowRoute /= 2;
        }
    }

    while (routeRList.empty() == false)
    {
        cout << routeRList.top() << ' ';
        routeRList.pop();
    }

	return 0;
}
