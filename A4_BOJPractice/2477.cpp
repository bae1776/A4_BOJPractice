//https://www.acmicpc.net/problem/2477

/* 참외밭 (Silver 3)

ㄱ 자 모양(또는 회전한 모양, 큰 직사각형에서 모서리에 작은 직사각형이 없어진 모양) 참외밭과
단위 넓이 당 참외 수확 갯수가 주어진다.

참외 밭의 각 변의 길이는 한 꼭짓점에서 시작해서 반시계 방향으로 주어진다.
참외 밭에서 자라는 참외의 수를 구하세요.

Solution : 구현
*/

#include <iostream>
#include <deque>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    //3131(남동), 1414, 4242, 2323 패턴을 찾으면 된다.
     
    int perArea;
    cin >> perArea;

    deque<pair<int, int>> lineList(6); //direction, len
    for (int i = 0; i < 6; i++)
        cin >> lineList[i].first >> lineList[i].second;

    int area = 0;
    while (true)
    {
        if (lineList[0].first == lineList[2].first && lineList[1].first == lineList[3].first)
        {
            area = lineList[4].second * lineList[5].second - lineList[1].second * lineList[2].second;
            break;
        }

        auto temp = lineList.back();
        lineList.pop_back();
        lineList.push_front(temp);
    }

    cout << area * perArea;
            
	return 0;
}
