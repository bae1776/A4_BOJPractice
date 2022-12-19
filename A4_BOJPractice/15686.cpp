//https://www.acmicpc.net/problem/15686

/*치킨 배달 (Gold 5)

크기가 최대 50x50인 정사각 도시가 있다. 도시의 각 칸은 빈 칸, 치킨집, 집 중 하나이다.
이 도시에 사는 사람들은 치킨을 매우 좋아해서 치킨 거리라는 말을 자주 사용한다.
치킨 거리는 집과 가장 가까운 치킨집 사이의 거리이다.
그리고 도시의 치킨 거리는, 도시의 모든 집의 치킨 거리의 합이다.

치킨 프렌차이즈 본사에서는 수익을 위해 도시의 일부 가맹점을 폐쇄시키기로 했다.
치킨 집을 최대 M개(최대 13)만 남길 때, 도시의 치킨 거리가 가장 작아질 때의 값을 구하시오.
집의 개수는 도시의 가로 길이의 2배를 넘지 않는다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool next_permutation(int max, vector<int>& list);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int citySize, remainChicken;
    cin >> citySize >> remainChicken;

    vector<pair<int, int>> houseLocationList;
    vector<pair<int, int>> chickenLocationList;

    int input;
    for (int y = 1; y <= citySize; y++)
        for (int x = 1; x <= citySize; x++)
        {
            cin >> input;
            if (input == 1)
                houseLocationList.emplace_back(y, x);
            else if (input == 2)
                chickenLocationList.emplace_back(y, x);
        }

    vector<vector<int>> distanceFromChickenList(houseLocationList.size(), vector<int>(chickenLocationList.size()));

    for (int houseIndex = 0; houseIndex < houseLocationList.size(); ++houseIndex)
    {
        for (int chickenIndex = 0; chickenIndex < chickenLocationList.size(); ++chickenIndex)
        {
            distanceFromChickenList[houseIndex][chickenIndex] = 
                abs(houseLocationList[houseIndex].first - chickenLocationList[chickenIndex].first)
                + abs(houseLocationList[houseIndex].second - chickenLocationList[chickenIndex].second);
        }

    }

    int i = 0;
    int result = 0x3FFFFFFF;
    vector<int> remainChickenPermutation(remainChicken);
    for (int& value : remainChickenPermutation)
        value = i++;

    do {
        int cityChickenDistance = 0;
        for (int houseIndex = 0; houseIndex < houseLocationList.size(); ++houseIndex)
        {
            int chickenDistance = 0x3FFFFFFF;
            for (const auto& remainChickenIndex : remainChickenPermutation)
            {
                chickenDistance = min(chickenDistance, distanceFromChickenList[houseIndex][remainChickenIndex]);
            }
            cityChickenDistance += chickenDistance;
        }
        result = min(result, cityChickenDistance);
    } while (next_permutation(chickenLocationList.size(), remainChickenPermutation));


    cout << result;


    return 0;
}


bool next_permutation(int max, vector<int>& list)
{
    int limitReachedIndex = list.size() - 1;
    while (list[limitReachedIndex] == max - 1)
    {
        limitReachedIndex--; max--;
        if (limitReachedIndex < 0) break;
    }
    
    if (limitReachedIndex == -1)
        return false;
    else
    {
        list[limitReachedIndex]++;
        for (int i = limitReachedIndex + 1; i < list.size(); i++)
            list[i] = list[i - 1] + 1;
        
        return true;
    }

}