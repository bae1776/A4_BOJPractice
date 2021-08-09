//https://www.acmicpc.net/problem/7579

/*앱

스마트폰에서 앱을 실행하면, 메모리를 점유하는 데,
스마트폰을 끄거나 앱을 잠시 내려도 다음에 앱을 다시 빨리 불러올 수 있게 메모리에서 앱을 삭제하지 않는다.
그러나 스마트폰의 메모리는 한계가 있기 때문에, 메모리가 꽉 차면 어쩔 수 없이 앱을 삭제해야 한다.
비활성화된 앱들을 재 실행할 때 그만큼 시간이 더 걸리기 때문에 무작위로 앱을 삭제하는 것은 비효율적이다. 

새로운 앱 하나를 실행하기 위하여 메모리를 확보해야 하고,
현재 활성화된 앱의 메모리 점유량과 재실행 비용이 주어질때,
비활성화 된 앱을 재실행하는 비용의 최소를 구하시오.
*/

#include <iostream>
#include <vector>
using namespace std;
int DP[10001]; //Cost

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int appCount, neededMemory;
	cin >> appCount >> neededMemory;

	vector<int> appMemoryList(appCount);
	vector<int> appCostList(appCount);

	for (auto& val : appMemoryList)
		cin >> val;
	
	for (auto& val : appCostList)
		cin >> val;

	int maxTime = appCostList[0];
	DP[maxTime] = appMemoryList[0];

	for (int i = 1; i < appCount; i++)
	{
		maxTime += appCostList[i];

		for (int j = maxTime; j >= appCostList[i]; j--)
			DP[j] = max(DP[j], DP[j - appCostList[i]] + appMemoryList[i]);	
	}


	for (int i = 0; i <= 10000; i++)
		if (DP[i] >= neededMemory)
		{
			cout << i;
			break;
		}



	
    return 0;
}