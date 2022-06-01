//https://www.acmicpc.net/problem/1450

/*냅색문제

세준이는 N개의 물건을 가지고 있고, 
최대 C만큼의 무게를 넣을 수 있는 가방을 하나 가지고 있다.
N개의 물건을 가방에 넣는 방법의 수를 구하는 프로그램을 작성하시오.

(N <= 30, C <= 10^9, 물건 무게 <= 10^9)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<long long, int> number_of_cases(vector<int>::iterator start, vector<int>::iterator end);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int goods;
    long long baglimit;
    cin >> goods >> baglimit;

    vector<int> goodList(goods);
    for (int& input : goodList)
        cin >> input;
    
    auto mid = goodList.begin() + (goodList.size() / 2);

    auto leftDP = number_of_cases(goodList.begin(), mid);
    auto rightDP = number_of_cases(mid, goodList.end());
    auto itrBefore = rightDP.begin();
    for (auto itr = ++rightDP.begin(); itr != rightDP.end(); ++itr, ++itrBefore)
         itr->second += itrBefore->second;

    auto leftPointer = leftDP.begin();
    auto rightPointer = rightDP.rbegin();

    long long result = 0;
    
    while (leftPointer != leftDP.end() && rightPointer != rightDP.rend())
    {
        if (leftPointer->first + rightPointer->first <= baglimit)
        {
            result += leftPointer->second * rightPointer->second;
            leftPointer++;
        } else 
            rightPointer++;

    }

    cout << result;
    //for (auto itr = leftDP.begin(); itr != leftDP.end(); ++itr)
    //    cout << "{ " << itr->first << " : " << itr->second << "개 }\n"; 
    


    return 0;
}


//[start, end) 물건들 구간에서 x kg 넣는 경우의 수를 나타내는 map<x, 경우의 수>를 반환합니다.
map<long long, int> number_of_cases(vector<int>::iterator start, vector<int>::iterator end)
{
    map<long long, int> DP;
    DP[0] = 1;

    for (;start != end; ++start)
    {
        int value = *start;
        
        queue<pair<long long, int>> addList;
        for (auto mapIter = DP.begin(); mapIter != DP.end(); ++mapIter)
            addList.emplace(mapIter->first + value, mapIter->second);

        while (addList.empty() == false)
        {
            auto deq = addList.front();
            if (DP.find(deq.first) == DP.end())
                DP[deq.first] = deq.second;
            else
                DP[deq.first] += deq.second;
            
            addList.pop();
        }

    }

    

    return DP;
}

