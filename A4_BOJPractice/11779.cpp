//https://www.acmicpc.net/problem/11779

/*최소비용 구하기 2

최대 1000개의 도시가 있고, 한 도시에서 다른 도시로 가는 버스 최대 10만개가 있다.
우리는 A에서 B 도시로 가는데 드는 비용을 최소화하려할 때,
그 비용과, 경유하는 정류장 개수와 리스트를 출력하시오.

*/


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    bool visited;
    int distance;
    int beforeNode;
    int viaCount;
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int cityCount, busCount;
    cin >> cityCount >> busCount;

    vector<vector<int>> busList(cityCount + 1, vector<int>(cityCount + 1, 0x3FFFFFFF));
    vector<Node> cityList(cityCount + 1, {false, 0x3FFFFFFF, -1, -1});

    for (int i = 0; i < busCount; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;

        if (weight < busList[start][end])
            busList[start][end] = weight;
    }

    int deperture, arrival;
    cin >> deperture >> arrival;
    
    int nowVisit = deperture;
    cityList[nowVisit].distance = 0;
    cityList[nowVisit].viaCount = 1;
    cityList[nowVisit].beforeNode = -1;

    while (true)
    {
        cityList[nowVisit].visited = true;

        for (int edgeEnd = 1; edgeEnd <= cityCount; edgeEnd++)
        {
            if (busList[nowVisit][edgeEnd] == 0x3FFFFFFF)
                continue;
            
            if (cityList[nowVisit].distance + busList[nowVisit][edgeEnd] < cityList[edgeEnd].distance)
            {
                cityList[edgeEnd].distance = cityList[nowVisit].distance + busList[nowVisit][edgeEnd];
                cityList[edgeEnd].viaCount = cityList[nowVisit].viaCount + 1;
                cityList[edgeEnd].beforeNode = nowVisit;
            }    
        }

        nowVisit = 0;
        for (int i = 1; i <= cityCount; i++)
            if (cityList[i].visited == false && cityList[i].distance < cityList[nowVisit].distance)
                nowVisit = i;
        
        if (nowVisit == 0)
            break;
    }


    cout << cityList[arrival].distance << '\n' << cityList[arrival].viaCount << '\n';

    
    stack<int> visitStack;
    int temp = arrival;
    
    while (temp != -1)
    {
        visitStack.emplace(temp);
        temp = cityList[temp].beforeNode;
    }

    while (visitStack.empty() == false)
    {
        cout << visitStack.top() << ' ';
        visitStack.pop();
    }

    return 0;
}