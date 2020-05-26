//https://www.acmicpc.net/problem/2437

//저울
//하나의 양팔 저울을 이용하여 물건의 무게를 측정하려고 한다.
//양팔 저울 한 쪽에는 물건이 올려져있고 다른 쪽에는 저울추를 놓을 수 있다.

//무게가 양의 정수인 N개의 저울추가 주어질 때, 이 추들을 사용하여 측정할 수 없는 양의 정수 무게 최솟값을 출력하시오.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int limit = 0;
	int weightCount;
	
	cin >> weightCount;

	vector<int> weights;
	weights.reserve(weightCount + 1);

	for (int i = 0; i < weightCount; i++)
	{
		int input;
		cin >> input;
		weights.emplace_back(input);
	}

	sort(weights.begin(), weights.end());


	auto arrIter = weights.begin();

	while (arrIter != weights.end() && limit + 1 >= *arrIter)
	{
		limit += *arrIter;
		++arrIter;
	}

	cout << limit + 1;

	

	return 0;
}