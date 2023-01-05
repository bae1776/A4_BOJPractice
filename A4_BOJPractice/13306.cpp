//https://www.acmicpc.net/problem/13306

/*트리 (Platinum 4)

트리의 성질 중 하나는 트리 내 임의의 두 정점을 연결하는 경로가 항상 존재한다는 것이다.
그런데 트리의 간선을 하나 제거하면, 임의의 두 정점을 연결하는 경로가 없어질 수 있다.
당신은 다음과 같은 질의 2가지를 처리해야 한다.
1. 어떤 정점 v와 이것의 부모 노드를 연결하는 간선을 제거한다.
2. 정점 v, w가 주어질 때 연결되었는지 답한다.

정점, 질의의 개수는 각각 최대 20만개이다. 트리의 루트 번호는 1이라고 가정한다.

Solution : 질의 순서를 거꾸로 돌려 생각해보면 
1.은 간선을 연결하는 것 (merge) 이고, 2.는 둘이 같은 집합인지 묻는 것이 된다. (find is same?)
즉, Union-Find를 이용하여, 질의 개수 Q, 정점 개수 N에 대해, O(Q * a(N)) 에 해결할 수 있다. 함수 a는 에크먼 함수로 상수 시간 복잡도에 수렴한다.

*/

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
using Query = tuple<int, int, int>;

int nodeCount, queryCount, answerCount;
int parent[200003], setPosition[200003], unionRank[200003];
vector<char> answerList;
vector<Query> queryList;

int union_find(const int& num);
void union_merge(const int& a, const int& b);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> nodeCount >> queryCount;

    parent[1] = setPosition[1] = unionRank[1] = 1;
    for (int nodeNumber = 2; nodeNumber <= nodeCount; nodeNumber++)
    {
        cin >> parent[nodeNumber];
        setPosition[nodeNumber] = nodeNumber;
        unionRank[nodeNumber] = 1;
    }

    queryCount += nodeCount - 1;
    queryList.reserve(queryCount);
    for (int queryNumber = 0; queryNumber < queryCount; queryNumber++)
    {
        Query newQuery;
        cin >> get<0>(newQuery);

        if (get<0>(newQuery)) //ask is connected query
        {
            cin >> get<1>(newQuery) >> get<2>(newQuery);
            answerCount++;
        }
        else
            cin >> get<1>(newQuery); //ask to cut node

        queryList.emplace_back(newQuery);
    }

    answerList.reserve(answerCount);
    for (auto revIt = queryList.rbegin(); revIt != queryList.rend(); ++revIt)
    {
        const auto& [querySort, num1, num2] = *revIt;

        if (querySort)
            //ask is connected query
            answerList.emplace_back(union_find(num1) == union_find(num2));
        else
            //ask to connect node
            union_merge(num1, parent[num1]);
    }

    for (auto revIt = answerList.rbegin(); revIt != answerList.rend(); ++revIt)
        if (*revIt)
            cout << "YES\n";
        else
            cout << "NO\n";

	
	return 0;
}




int union_find(const int& num)
{
    if (setPosition[num] == num)
        return num;
    else
        return setPosition[num] = union_find(setPosition[num]);
}




void union_merge(const int& a, const int& b)
{
    int parentA = union_find(a);
    int parentB = union_find(b);

    if (parentA == parentB)
        return;

    if (unionRank[parentA] < unionRank[parentB])
    {
        setPosition[parentA] = parentB;
    } else {
        setPosition[parentB] = parentA;
        if (unionRank[parentA] == unionRank[parentB])
            unionRank[parentA]++;
    }

    
}