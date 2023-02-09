//https://www.acmicpc.net/problem/5504

/*Post Office (Gold 3)
전형적인 DP 문제. 18443(Platinum 4) 문제의 서브테스크.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x7FFFFFFFFFFFFF
#define COUNT 300
using namespace std;

int town, postoffice;
vector<long long> townLoc;
pair<long long, int> minLoc[COUNT][COUNT]; //totalDistance, Loc
pair<long long, vector<int>> DP[COUNT + 1][COUNT + 1];
pair<long long, vector<int>>& DPFunction(int includedTown, int includedOffice); //totalDistance, LocList
pair<long long, int>& minLocFunction(int start, int end);


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> town >> postoffice;
    townLoc = vector<long long>(town);

    for (int i = 0; i < town; i++)
    {
        cin >> townLoc[i];
    }

    fill(DP[0], DP[0] + (COUNT + 1) * (COUNT + 1), make_pair(INF, vector<int>()));
    fill(minLoc[0], minLoc[0] + COUNT * COUNT, make_pair(INF, COUNT));

    auto& result = DPFunction(town, postoffice);

    cout << result.first << '\n';
    for (const auto& ans : result.second)
        cout << townLoc[ans] << ' ';

    return 0;
}

pair<long long, vector<int>>& DPFunction(int includedTown, int includedOffice) //totalDistance, LocList  
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

    return DP[includedTown][includedOffice] = { minDist, move(locList) };
}

pair<long long, int>& minLocFunction(int start, int end)
{
    if (minLoc[start][end].first != INF)
        return minLoc[start][end];

    if (start == end)
        return minLoc[start][end] = { 0, start };
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