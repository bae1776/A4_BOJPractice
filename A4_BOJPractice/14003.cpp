//https://www.acmicpc.net/problem/14003

/*가장 긴 증가하는 부분 수열 4

수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하시오.
(수열의 크기는 최대 1000000 이다.)

*/

#include <iostream>
#include <map>
#include <vector>
#include <stack>
using namespace std;

struct Data {
    int count;
    int index;

    Data(int c, int i) : count(c), index(i) {};
};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int arrlen;
    cin >> arrlen;

    vector<pair<int, int>> arr(arrlen);
    map<int, Data> DPTree;
    DPTree.emplace(-1000000001, Data(0, -1));

    for (int idx = 0; idx < arrlen; idx++)
    {
        cin >> arr[idx].first;

        auto iter = DPTree.lower_bound(arr[idx].first);

        if (iter == DPTree.end())
        {
            const auto& treeLast = DPTree.rbegin()->second;
            arr[idx].second = treeLast.index;
            DPTree.emplace(arr[idx].first, Data(treeLast.count + 1, idx));
        }
        else if (arr[idx].first < iter->first)
        {
            --iter;
            arr[idx].second = (iter++)->second.index;
            DPTree.emplace(arr[idx].first, Data(iter->second.count, idx));
            DPTree.erase(iter);
        } 
    }
    
    stack<int> resultStack;
    int arrIndex = DPTree.rbegin()->second.index;

    while (arrIndex != -1)
    {
        resultStack.emplace(arr[arrIndex].first);
        arrIndex = arr[arrIndex].second;
    }

    cout << DPTree.rbegin()->second.count << '\n';

    while (resultStack.empty() == false)
    {
        cout << resultStack.top() << ' ';
        resultStack.pop();
    }
    return 0;
}
