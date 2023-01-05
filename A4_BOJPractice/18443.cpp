//https://www.acmicpc.net/problem/18443

/*우체국 2 (Platinum 4)
원형으로 큰 길(순환로)이 뻗어 있고, 길 옆으로 V개(최대 100)의 마을이 자리 잡고 있다.
큰 길의 둘레 길이는 L(최대 1조)이다. 큰 길은 0 ~ L-1 의 정수가 늘어져 있는 원이고, 
각 마을의 위치는 길 상의 정수 좌표로 표현된다. (한 위치에 여러 마을 있을 수 있음)

우체국을 P개 지으려고 하는데, 모든 마을마다 다 지을 수는 없어서 전체 마을 중 몇 곳을 골라 짓게 된다.
이 때 각 마을과 그 마을과 가장 가까운 우체국 사이의 거리의 합이 최소가 되게 하도록 할 때
그 최솟값과 짓는 마을 위치 리스트를 구하시오.

Solution : 브루트포스로는 해결할 수 없다. 원형 도로상 마을 중간 지점을 자른다고 생각해
직선 도로로 만들고 O(n) * 직선 도로에 대한 DP O(n^3)로 푼다.  -> 총 O(n^4).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x7FFFFFFFFFFFFF
#define COUNT 100
using namespace std;

int town, postoffice;
long long circleSize;
vector<long long> townLoc;
//townLoc[i] = i번째 마을의 위치값 (0 ~ circleSize - 1)

pair<long long, int> minLoc[COUNT][COUNT]; 
pair<long long, int>& minLocFunction(int start, int end);
//minLoc[start][end] = start~end번째 마을만 생각했을 때, 그 중 1개의 마을에만 우체국을 지을 경우,
//                      {각 마을에서 그 우체국까지의 거리 총합, 우체국을 지을 마을 번째}

pair<long long, vector<int>> DP[COUNT + 1][COUNT + 1];
pair<long long, vector<int>>& DPFunction(int includedTown, int includedOffice); 
//DP[town][office] = 처음 마을부터 일렬로 town개의 마을 중 office개의 우체국을 지을 때,
//                   {각 마을에서 가까운 우체국까지의 거리 총합, 우체국을 지을 마을 번호 리스트}




int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> town >> postoffice >> circleSize;
    townLoc = vector<long long>(town);

    for (int i = 0; i < town; i++)
    {
        cin >> townLoc[i];
    }

    
    fill(minLoc[0], minLoc[0] + COUNT * COUNT, make_pair(INF, COUNT * 4));
    auto townLocOriginal = townLoc;
    pair<long long, vector<int>> result = {INF, vector<int>(postoffice)};

    //원형 마을촌 중에서 한 변씩 끊으면서, 일직선 상의 마을촌으로 생각한다. (O(n))
    for (int move = 0; move < town; move++)
    {
        //DP 초기화
        fill(DP[0], DP[0] + (COUNT + 1) * (COUNT + 1), make_pair(INF, vector<int>()));
        
        //minLoc 일부 재활용
        for (int a = 0; a < town - 1; a++)
            for (int b = a; b < town - 1; b++)
            {
                minLoc[a][b] = minLoc[a + 1][b + 1];
                minLoc[a][b].second--;
            }
        
        for (int a = 0; a < town; a++)
            minLoc[a][town - 1] = {INF, COUNT * 4};


        //DP 실행
        auto& answer = DPFunction(town, postoffice);


        //한 일직선 상의 경우에 대해 결과 처리
        if (answer.first < result.first)
        {
            result = answer;
            for (int i = 0; i < postoffice; i++)
                result.second[i] = (result.second[i] + move) % town;
        }

        townLoc.push_back(townLoc[0] + circleSize);
        townLoc.erase(townLoc.begin());
    }
    
    sort(result.second.begin(), result.second.end());
    cout << result.first;
    cout << '\n';
    for (const auto& ans : result.second)
        cout << townLocOriginal[ans] << ' ';

    return 0;
}

pair<long long, vector<int>>& DPFunction(int includedTown, int includedOffice)
{
    if (DP[includedTown][includedOffice].first != INF)
        return DP[includedTown][includedOffice];

    
    if (includedOffice == 1)
    {
        auto& result = minLocFunction(0, includedTown - 1);
        DP[includedTown][includedOffice].first = result.first;
        DP[includedTown][includedOffice].second.emplace_back(result.second);
        return DP[includedTown][includedOffice];
    }

    if (includedTown == includedOffice)
    {
        auto& preDP = DPFunction(includedTown - 1, includedOffice - 1);
        DP[includedTown][includedOffice] = preDP;
        DP[includedTown][includedOffice].second.emplace_back(includedTown - 1);
        return DP[includedTown][includedOffice];
    }

    long long minDist = INF;
    int index;
    for (int k = includedOffice - 1; k < includedTown; k++)
    {
        auto& preDP = DPFunction(k, includedOffice - 1);
        auto& adder = minLocFunction(k, includedTown - 1);
        long long dist = preDP.first + adder.first;
        
        if (dist < minDist)
        {
            minDist = dist;
            index = k;
        }
    }

    vector<int> locList;
    locList.reserve(includedOffice);
    locList = DP[index][includedOffice - 1].second;
    locList.emplace_back(minLoc[index][includedTown - 1].second);

    return DP[includedTown][includedOffice] = {minDist, move(locList)};
}


pair<long long, int>& minLocFunction(int start, int end)
{
    if (minLoc[start][end].first != INF)
        return minLoc[start][end];

    if (start == end)
        return minLoc[start][end] = {0, start};
    else {
        long long& minDistance = minLoc[start][end].first;
        
        for (int pivot = start; pivot <= end; pivot++)
        {
            long long distance = 0;
            for (int target = start; target <= end; target++)
                distance += abs(townLoc[pivot] - townLoc[target]);

            if (distance < minDistance)
            {
                minDistance = distance;
                minLoc[start][end].second = pivot;
            }
        }

        return minLoc[start][end];
    }

}
