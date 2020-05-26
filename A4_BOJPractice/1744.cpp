//https://www.acmicpc.net/problem/1744

//수 묶기

//원소 값 범위가 -10000~10000 인 배열이 있다.
//수열의 합을 구하려고 하는데, 단순히 더하는 것 뿐만 아니라, 특정 두 원소를 골라 묶어 곱한 값으로 합을 계산할 수 있다고 하자.
//(이미 묶인 원소는 또 묶일 수는 없다.)

//적절히 묶었을 때 합의 최댓값을 구하시오.


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int arrsize;
	cin >> arrsize;

	vector<int> arr;
	arr.reserve(arrsize + 1);

	for (int i = 0; i < arrsize; i++)
	{
		int input;
		cin >> input;
		arr.emplace_back(input);
	}

	sort(arr.begin(), arr.end());

	long long int sum = 0;

	
	if (arr.front() < 0)
	{
		for (auto i = arr.begin(); i != arr.end(); ++i)
		{
			if (*i < 0)
			{
				if (i == --arr.end() || *(i + 1) > 0)
					sum += *i;
				else {
					sum += (*i) * (*(i + 1));
					++i;
				}
			}
			else break;
		}
	}

	if (arr.back() > 0)
	{
		for (auto i = arr.rbegin(); i != arr.rend(); ++i)
		{
			if (*i > 0)
			{
				if (i == --arr.rend() || *(i + 1) <= 1)
					sum += *i;
				else {
					sum += (*i) * (*(i + 1));
					++i;
				}
			}
			else break;
		}
	}


	cout << sum;


	return 0;
}