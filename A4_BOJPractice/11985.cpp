//https://www.acmicpc.net/problem/11985

//오렌지 출하

#include <iostream>
#include <vector>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int orangeCount, boxSize, boxCost;
	cin >> orangeCount >> boxSize >> boxCost;

	vector<int> orangeWeight(orangeCount + 1);
	vector<long long> costDP(orangeCount + 1);

	for (int i = 1; i <= orangeCount; ++i)
	{
		cin >> orangeWeight[i];
	}

	costDP[0] = 0;
	costDP[1] = boxCost;

	for (int dpCursor = 2; dpCursor <= orangeCount; ++dpCursor)
	{
		long long dpValue = 0x7FFFFFFFFFFFFFFF;
		int lastBox_maxWeight = 0;
		int lastBox_minWeight = 0x7FFFFFFF;
		
		for (int lastBox_orangeCount = 1; lastBox_orangeCount <= boxSize; ++lastBox_orangeCount)
		{
			if (dpCursor - lastBox_orangeCount < 0)
				break;
			int& now_orangeWeight = orangeWeight[dpCursor - lastBox_orangeCount + 1];

			if (now_orangeWeight > lastBox_maxWeight)
				lastBox_maxWeight = now_orangeWeight;
			if (now_orangeWeight < lastBox_minWeight)
				lastBox_minWeight = now_orangeWeight;
			
			long long partResult = costDP[dpCursor - lastBox_orangeCount] +
			 boxCost + (long long)lastBox_orangeCount * (lastBox_maxWeight - lastBox_minWeight);


			if (partResult < dpValue)
				dpValue = partResult;
		}

		costDP[dpCursor] = dpValue;
	}

	cout << costDP[orangeCount];


	return 0;
}