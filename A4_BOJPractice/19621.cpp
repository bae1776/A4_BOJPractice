//https://www.acmicpc.net/problem/19621

/* 회의실 배정 2 (Silver 4)
최대 25개의 회의에 대해 시작 시간, 종료 시간, 회의 인원 수가 주어진다.
회의실은 단 1개의 회의만 진행할 수 있으며, 회의가 끝나자마자 바로 다른 회의를 시작할 수 있다.
회의를 진행할 수 있는 최대 인원은?

Solution : 브루트포스로 충분히 가능. 하지만 bfs로 풀어보자. 조금 더 시간을 아낄 수 있을 것 같다.
*/

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int inDegree[25];
bool edgeList[25][25];
tuple<int, int, int> meetingList[25];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int meetingCount;
    cin >> meetingCount;

    for (int i = 0; i < meetingCount; i++)
    {
        auto& [start, end, people] = meetingList[i];
        cin >> start >> end >> people;
    }
	
    for (int prev = 0; prev < meetingCount; prev++)
    {
        for (int next = 0; next < meetingCount; next++)
        {
            if (prev == next) continue;
            if (get<1>(meetingList[prev]) <= get<0>(meetingList[next]))
            {
                edgeList[prev][next] = true;
                inDegree[next]++;
            }
        }
    }

    int answer = 0;
    for (int start = 0; start < meetingCount; start++)
    {
        if (inDegree[start] != 0) continue;

        queue<pair<int, int>> bfsQueue; //index, person
        bfsQueue.emplace(start, get<2>(meetingList[start]));

        while (bfsQueue.empty() == false)
        {
            auto nowElement = bfsQueue.front();
            bfsQueue.pop();

            answer = max(answer, nowElement.second);

            for (int next = 0; next < meetingCount; next++)
                if (edgeList[nowElement.first][next] == true)
                    bfsQueue.emplace(next, nowElement.second + get<2>(meetingList[next]));
        }
    }

    cout << answer;
    
	return 0;
}
