//https://www.acmicpc.net/problem/2629

/*양팔 저울

양팔 저울과 최대 30개의 추가 있다. (각 추는 500g을 넘지 않는다.)
주어진 추들만으로
(최대 7개의) 구슬의 무게를 정확하게 잴 수 있는 지 구하여라.
추를 적절히 배치하고 한쪽 팔에 구슬을 올려서 수평이 될 수 있다면
구슬의 무게를 젤 수 있다.

*/

#include <iostream>
#include <vector>
using namespace std;
bool DP[30][15001]; //추 번호, 총 무게


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int weightCount;
    cin >> weightCount;
    
    vector<int> weightList(weightCount);
    for (auto& weight : weightList)
        cin >> weight;

    int maxWeight = weightList[0];
    DP[0][0] = true;
    DP[0][weightList[0]] = true;
    
    for (int weightNum = 1; weightNum < weightCount; weightNum++)
    {
        maxWeight += weightList[weightNum];

        for (int nowWeight = 0; nowWeight <= maxWeight; nowWeight++)
        {
            DP[weightNum][nowWeight]
            = DP[weightNum - 1][nowWeight] || 
              DP[weightNum - 1][nowWeight + weightList[weightNum]] || 
              DP[weightNum - 1][abs(nowWeight - weightList[weightNum])];
        }   
    }

    int query;
    cin >> query;
    
    while (query--)
    {
        int marble;
        cin >> marble;
        if (marble > maxWeight)
            cout << "N ";
        else
            cout << (DP[weightCount - 1][marble] ? 'Y' : 'N') << ' ';
    }

    return 0;
}