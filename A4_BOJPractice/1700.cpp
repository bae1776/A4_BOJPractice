//https://www.acmicpc.net/problem/1700

//멀티탭 스케줄링.

//멀티탭의 꽂을 수 있는 코드 갯수와, 전자 제품의 사용 순서가 주어질 때,
//코드 뽑는 횟수의 최소를 구하시오.


#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int multitapHole, useCount;
	cin >> multitapHole >> useCount;

	vector<int> multitap;
	vector<int> nextLoc;
	vector<int> useSchedule;
	multitap.reserve(multitapHole + 1);
	nextLoc.reserve(multitapHole + 1);
	useSchedule.reserve(useCount + 1);


	for (int i = 0; i < useCount; i++)
	{
		int input;
		cin >> input;
		useSchedule.emplace_back(input);
	}

	int unplugCount = 0;
	auto scheduleItr = useSchedule.begin();
	int multitap_capacity = multitapHole;

	while (scheduleItr != useSchedule.end())
	{
		int replaceIndex = 0;
		bool isalreadyExist = false;


		for (auto i = multitap.begin(); i != multitap.end(); ++i)
		{
			if (*i == *scheduleItr)
			{
				isalreadyExist = true;
				replaceIndex = i - multitap.begin();
			}
		}
		if (isalreadyExist == false)
		{
			if (multitap_capacity >= 1)
			{
				replaceIndex = multitap.size() - multitap_capacity;
				multitap_capacity--;
				multitap.emplace_back(*scheduleItr);
			}
			else {
				unplugCount++;
				int maxIndex = 0, max = 0;
				for (auto i = nextLoc.begin(); i != nextLoc.end(); ++i)
				{
					if (*i > max)
					{
						maxIndex = i - nextLoc.begin();
						max = *i;
					}
				}
				replaceIndex = maxIndex;
				multitap[replaceIndex] = *scheduleItr;
			}
		}



		auto nextFindIterator = scheduleItr + 1;
		while (nextFindIterator != useSchedule.end())
		{
			if (*nextFindIterator == *scheduleItr)
			{
				if (isalreadyExist == false && nextLoc.size() != multitapHole)
					nextLoc.emplace_back(nextFindIterator - useSchedule.begin());
				else nextLoc[replaceIndex] = nextFindIterator - useSchedule.begin();

				break;
			}
			nextFindIterator++;
		}

		if (nextFindIterator == useSchedule.end())
			if (isalreadyExist == false && nextLoc.size() != multitapHole)
				nextLoc.emplace_back(0x7FFFFFFF);
			else nextLoc[replaceIndex] = 0x7FFFFFFF;


		scheduleItr++;
	}

	cout << unplugCount;

	return 0;
}