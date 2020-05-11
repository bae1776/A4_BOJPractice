//https://www.acmicpc.net/problem/1965

//상자 넣기.

//정육면체 상자들이 늘어서 있고, 각 상자마다 크기가 주어져 있는데, 앞에 있는 상자의 크기가 뒤에 있는 상자의 크기보다 작으면,
//앞에 있는 상자를 뒤에 있는 상자 안에 넣을 수 있다.
//상자의 크기들이 주어질 때, 한 번에 넣을 수 있는 최대의 상자 개수를 구하시오.

#include <vector>
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	int boxCount;
	cin >> boxCount;

	vector<int> boxSize;
	vector<int> DP;
	boxSize.reserve(boxCount);
	DP.reserve(boxCount);

	for (int i = 0; i < boxCount; i++)
	{
		int size;
		cin >> size;
		boxSize.emplace_back(size);
	}

	
	for (int i = 0; i < boxCount; i++)
	{
		int max = 1;
		for (int j = 0; j < i; j++)
		{
			if (boxSize[j] < boxSize[i] && DP[j] >= max)
			{
				max = DP[j] + 1;
			}
		}
		DP.emplace_back(max);
	}

	int DPmax = 0;

	for (auto i = DP.begin(); i < DP.end(); i++)
		if (*i > DPmax) DPmax = *i;
	
	cout << DPmax;


	return 0;
}