//https://www.acmicpc.net/problem/2812

//크게 만들기

//N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.
//N과 K는 50만 이하의 자연수.

#include <iostream>
#include <list>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int numlength, delCount;
	cin >> numlength >> delCount;

	list<char> numList;

	for (int i = 0; i < numlength; i++)
	{
		char input;
		cin >> input;
		numList.push_back(input);
	}


	auto listIter = numList.begin();
	for (int i = 0; i < delCount; i++)
	{
		if (listIter != numList.begin())
		{
			auto prevIter = listIter;
			--prevIter;
			if (*prevIter < *listIter)
				--listIter;
		}
		if (listIter == --numList.end())
		{
			numList.pop_back();
			listIter = --numList.end();
		}
		else {
			auto nextIter = listIter;
			++nextIter;
			
			if (*listIter >= *nextIter)
			{
				++listIter; i--;
				continue;
			}
			else {
				listIter = numList.erase(listIter);
			}
		}
	}

	for (char iter : numList)
		cout << iter;


	return 0;
}