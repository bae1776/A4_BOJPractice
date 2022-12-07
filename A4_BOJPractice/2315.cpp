//https://www.acmicpc.net/problem/2315

/* 가로등 끄기 (Platinum 3)
마을 중심에는 매우 긴 도로가 있고, 도로변에는 가로등이 세워져 있다. 마징가는 이 가로등은 매일 새벽 5시에 끄기 시작해야한다.
가로등은 일정 전력을 소비하는 전구가 달려있는데, 마징가는 쓸데없이 전력을 낭비하지 않고 싶다.

그래서, 소비전력을 최소화할 수 있도록 가로등을 끄는 순서를 알아내고 싶어 한다.
마징가는 초당 1m의 속도로 움직이고, 가로등을 끄는 데 걸리는 시간은 무시한다.

가로등의 위치와 그 가로등이 소비하는 전력의 양이 주어져 있을 때, 5시 정각 이후에 낭비될 수 있는 전력의 최솟값을 구하시오.

첫 줄에는 가로등의 개수 N(최대 1000), 마징가가 처음에 위치하는 가로등 번호가 주어진다. (가로등은 1번부터 시작한다)
다음 N개 줄에는 각 가로등의 위치와(최대 1000이고 오름차순으로 제시된다), 초당 소비전력이 주어진다. (최대 1억)
(결과로 구해지는 낭비되는 전력의 최솟값은 항상 10억보다 작다고 가정한다.)
*/
#include <iostream>
#include <vector>
using namespace std;


//DP[left][right][LEFT/RIGHT] = {consumed, consumptionpersec} left~right까지 소비전력 
pair<long long, int> DP[1001][1001][2];
vector<pair<int, int>> streetLightList; // <loc, consump>
int consumptionSum = 0;
int streetLightCount, robotLocation;

pair<long long, int>& DPfunction(const int& left, const int& right, const bool& isRight);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> streetLightCount >> robotLocation;

    
    streetLightList = vector<pair<int, int>>(streetLightCount + 1);
    

    for (int streetLightNumber = 1; streetLightNumber <= streetLightCount; ++streetLightNumber)
    {
        auto& [location, consumption] = streetLightList[streetLightNumber];
        cin >> location >> consumption;
        consumptionSum += consumption;
    }

    cout << min(DPfunction(1, streetLightCount, false), DPfunction(1, streetLightCount, true)).first;
    
    

    return 0;
}


pair<long long, int>& DPfunction(const int& left, const int& right, const bool& isRight)
{
    if (DP[left][right][isRight].second != 0)
        return DP[left][right][isRight];

    if (left == right)
    {   
        return DP[left][right][false] = DP[left][right][true] 
            = make_pair(0, consumptionSum - streetLightList[left].second);
    } 
    else if (left == robotLocation) 
    {
        if (isRight == false)
        {
            auto rightEnd = DPfunction(left, right, true);
            rightEnd.first += (long long)rightEnd.second * (streetLightList[right].first - streetLightList[left].first);

            return DP[left][right][false] = rightEnd;
        } else {
            auto rightEnd = DPfunction(left, right - 1, true);
            rightEnd.first += (long long)rightEnd.second * (streetLightList[right].first - streetLightList[right - 1].first);
            rightEnd.second -= streetLightList[right].second;

            return DP[left][right][true] = rightEnd;
        }
    }
    else if (right == robotLocation)
    {
        if (isRight == false)
        {
            auto leftEnd = DPfunction(left + 1, right, false);
            leftEnd.first += (long long)leftEnd.second * (streetLightList[left + 1].first - streetLightList[left].first);
            leftEnd.second -= streetLightList[left].second;

            return DP[left][right][false] = leftEnd;
        } else {
            auto leftEnd = DPfunction(left, right, false);
            leftEnd.first += (long long)leftEnd.second * (streetLightList[right].first - streetLightList[left].first);

            return DP[left][right][true] = leftEnd;
        }
    
    } else {
        if (isRight == false)
        {
            auto leftEnd = DPfunction(left + 1, right, false);
            leftEnd.first += (long long)leftEnd.second * (streetLightList[left + 1].first - streetLightList[left].first);
            leftEnd.second -= streetLightList[left].second;

            auto rightEnd = DPfunction(left + 1, right, true);
            rightEnd.first += (long long)rightEnd.second * (streetLightList[right].first - streetLightList[left].first);
            rightEnd.second -= streetLightList[left].second;

            return DP[left][right][false] = (rightEnd.first < leftEnd.first) ? rightEnd : leftEnd;
        } else {
            auto leftEnd = DPfunction(left, right - 1, false);
            leftEnd.first += (long long)leftEnd.second * (streetLightList[right].first - streetLightList[left].first);
            leftEnd.second -= streetLightList[right].second;

            auto rightEnd = DPfunction(left, right - 1, true);
            rightEnd.first += (long long)rightEnd.second * (streetLightList[right].first - streetLightList[right - 1].first);
            rightEnd.second -= streetLightList[right].second;

            return DP[left][right][true] = (rightEnd.first < leftEnd.first) ? rightEnd : leftEnd;
        }
    }
    
}
