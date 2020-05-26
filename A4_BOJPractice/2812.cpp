//https://www.acmicpc.net/problem/2812

//ũ�� �����

//N�ڸ� ���ڰ� �־����� ��, ���⼭ ���� K���� ������ ���� �� �ִ� ���� ū ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//N�� K�� 50�� ������ �ڿ���.

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