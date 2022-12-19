//https://www.acmicpc.net/problem/2568

/*전깃줄 2 (Platinum 5)

두 전봇대 A, B를 높은 순으로 1~500000 구역으로 나눈다.
두 전봇대 사이에는 전깃줄이 최대 10만개 걸려있는 데,
줄 (1, 5), 줄 (4, 3) 과 같이 있는 경우, 두 줄은 서로 교차되었다고 한다.

최소한의 전깃줄을 없애서 서로 교차되는 전깃줄이 없게 하려고 할때,
없애야 하는 갯수와 없애는 전깃줄의 전봇대 A와 연결된 위치 리스트를 오름차순으로 출력하시오.

답은 여러 개일수 있고, 그 중 어느 무엇이든 답이 될 수 있다.
전봇대의 한 구역에는 하나의 전깃줄만 올 수 있다.

Solution : 증가하는 가장 긴 수열 O(nlogn)
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    int cableCount;
    cin >> cableCount;  

    vector<pair<int, int>> cableList;
    cableList.reserve(cableCount);

    pair<int, int> p;
    for (int i = 0; i < cableCount; i++)
    {
        cin >> p.first >> p.second;
        cableList.push_back(p);
    }

    sort(cableList.begin(), cableList.end(), [](auto const& a, auto const& b) -> bool {
        return a.second < b.second;
    });


    unordered_map<int, int> rootFinder;
    vector<int> cableLIS;
    cableLIS.reserve(cableCount);

    for (const auto& cable : cableList)
    {
        auto it = lower_bound(cableLIS.begin(), cableLIS.end(), cable.first);

        if (it == cableLIS.begin())
            rootFinder[cable.first] = 0;
        else
            rootFinder[cable.first] = *(it - 1);

        if (it == cableLIS.end())
            cableLIS.push_back(cable.first);
        else
            *it = cable.first;
    }
    
    vector<int> rootArray;
    rootArray.reserve(cableLIS.size());
    for (int nowRoot = *(cableLIS.rbegin()); nowRoot != 0; nowRoot = rootFinder[nowRoot])
        rootArray.push_back(nowRoot);
    
    cout << cableCount - cableLIS.size() << '\n'; 
    sort(cableList.begin(), cableList.end());
    
    auto leftIt = rootArray.rbegin();
    for (auto listIt = cableList.begin(); listIt != cableList.end(); ++listIt)
    {
        if (leftIt != rootArray.rend() && *leftIt == listIt->first)
            ++leftIt;
        else
            cout << listIt->first << '\n';
    }

    return 0;
}