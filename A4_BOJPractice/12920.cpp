//https://www.acmicpc.net/problem/12920

/* 평범한 배낭 2 (Platinum 4)
민호는 캠프 배낭을 싸고 있다. 가방에 어떤 물건들을 넣냐에 따라 민호의 만족도가 달라지는데, 무게 제한이 있어서 모든 물건을 다 싸갈 순 없다.
민호가 만족도를 최대로 느낄 수 있는 경우를 찾아보자.
참고로 같은 물건이 여러 개 있을 수도 있다.

첫 줄에 물건의 개수 N(최대 100개), 배낭 무게 제한 M(최대 10000)이 주어진다.
다음 N줄부터 각 줄마다 물건의 무게(M 이하), 물건을 가방에 넣었을 때 만족도(최대 10000), 그 물건의 개수(최대 10000) 가 주어진다.
여기서 물건의 무게와 개수의 곱 또한 10000을 넘지 않는다.

이때 민호의 최대 만족도를 구하시오.
*/


#include <iostream>
#include <vector>
using namespace std;


vector<int> knapsackDP; //index : weight, value : maximum satisfaction at weight
vector<pair<int, int>> itemList; //pair(weight, satisfaction)


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int itemCount, weightLimit;
    cin >> itemCount >> weightLimit;

    knapsackDP = vector<int>(weightLimit + 1, 0);

    while (itemCount--)
    {
        int weight, satisfaction, count;
        cin >> weight >> satisfaction >> count;

        //Idea : 아이템 개수를 1, 2, 4 ... , 나머지로 쪼개고 이들을 각각 단일 묶음 상품으로 취급한다.
        //예를 들어 물건이 12개라면 1, 2, 4, 8, 4 개로 각각 묶음 상품으로 만든다. (5개만으로 0~12개인 경우를 모두 고려할 수 있음)
        //이 아이디어를 적용할 수 있다면, 평범한 냅색문제가 된다.
        for (int splitCount = 1; count != 0; splitCount <<= 1)
        {
            if (count >= splitCount)
            {
                count -= splitCount;
                itemList.emplace_back(weight * splitCount, satisfaction * splitCount);
            } else {
                itemList.emplace_back(weight * count, satisfaction * count);
                break;
            }
        }
    }

    for (const auto& item : itemList)
    {
        for (int beforeWeight = weightLimit - item.first; beforeWeight >= 0; --beforeWeight)
            if (beforeWeight == 0 || knapsackDP[beforeWeight] != 0)
                knapsackDP[beforeWeight + item.first] =
                    max(knapsackDP[beforeWeight + item.first], knapsackDP[beforeWeight] + item.second); 
    }

    int result = 0;
    for (const auto& knapsackDPValue : knapsackDP)
        result = max(knapsackDPValue, result);

    cout << result;

    return 0;
}