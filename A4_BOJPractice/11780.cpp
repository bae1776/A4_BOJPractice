//https://www.acmicpc.net/problem/11780

/*플로이드 2

최대 100개의 도시가 있고, 한 도시에서 다른 도시로 가는 버스 최대 10만개가 있다.
모든 도시의 쌍 (A, B)에 대하여 도시 A에서 B로 가는데 필요한 비용의 최솟값과, 
그 경로의 경유 정류장 수와, 경유 정류장 리스트를 구하시오.

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int distance;
    vector<int> viaList;
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int cityCount, busCount;
    cin >> cityCount >> busCount;

    vector<vector<int>> busList(cityCount + 1, vector<int>(cityCount + 1, 0x3FFFFFFF));
    vector<vector<Node>> floydList(cityCount + 1, vector<Node>(cityCount + 1, {.distance = 0x3FFFFFFF}));
    
    for (int i = 0; i < busCount; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;

        if (weight < busList[start][end])
            busList[start][end] = weight;
    }

    for (int i = 1; i <= cityCount; i++)
    {   
        for (int j = 1; j <= cityCount; j++)
            floydList[i][j].distance = busList[i][j];
        
        floydList[i][i].distance = 0;
    }

    for (int via = 1; via <= cityCount ; via++)
        for (int start = 1; start <= cityCount; start++)
            for (int end = 1; end <= cityCount; end++)
                if (floydList[start][via].distance + floydList[via][end].distance < floydList[start][end].distance)
                {
                    floydList[start][end].distance = floydList[start][via].distance + floydList[via][end].distance;
                    floydList[start][end].viaList = floydList[start][via].viaList;
                    floydList[start][end].viaList.emplace_back(via);
                    for (const auto& e : floydList[via][end].viaList)
                        floydList[start][end].viaList.emplace_back(e);
                }

    for (int start = 1; start <= cityCount; start++)
    {
        for (int end = 1; end <= cityCount; end++)
            if (floydList[start][end].distance == 0x3FFFFFFF)
                cout << 0 << ' ';
            else
                cout << floydList[start][end].distance << ' ';

        cout << '\n';
    }

    for (int start = 1; start <= cityCount; start++)
    {
        for (int end = 1; end <= cityCount; end++)
        {
            if (start == end || floydList[start][end].distance == 0x3FFFFFFF)
            {
                cout << 0 << '\n';
            } else {
                cout << floydList[start][end].viaList.size() + 2 << ' ' << start << ' ';
                for (const int& via : floydList[start][end].viaList)
                    cout << via << ' ';
                cout << end << '\n';
            }
        }
    }

    
    return 0;
}
