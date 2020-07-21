//https://www.acmicpc.net/problem/2513

//통학버스
//수직선 상의 지도에 아파트 단지와 그곳에 사는 학생 수, 학교의 위치가 주어진다.
//학교에서 탑승 정원이 한정되어 있는 통학버스 1대로 학생들을 모두 학교로 등교시키려고 할 때, 
//통학버스의 총 이동 거리의 최소를 구하시오.

#include <iostream>
using namespace std;

int studentCount_list[100001] = { 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int minDistance = 0;
	int aptCount, busLimit, schoolLocation;
	cin >> aptCount >> busLimit >> schoolLocation;


	int leftest_apt = 1000000, rightest_apt = -1;

	for (int repeat = 0; repeat < aptCount; repeat++)
	{
		int aptLocation, studentCount;
		cin >> aptLocation >> studentCount;

		studentCount_list[aptLocation] = studentCount;

		if (leftest_apt > aptLocation)
			leftest_apt = aptLocation;
		if (rightest_apt < aptLocation)
			rightest_apt = aptLocation;
	}

	//take all leftChild to bus 
	while (leftest_apt < schoolLocation)
	{
		minDistance += (schoolLocation - leftest_apt) * 2;

		for (int leftLimit = busLimit; leftest_apt < schoolLocation; )
		{
			if (studentCount_list[leftest_apt] > leftLimit)
			{
				studentCount_list[leftest_apt] -= leftLimit;
				break;
			}
			else
			{
				leftLimit -= studentCount_list[leftest_apt];
				studentCount_list[leftest_apt] = 0;
				while (studentCount_list[++leftest_apt] == 0 && leftest_apt < schoolLocation);
			}
		}
	}

	//take all rightChild to bus
	while (schoolLocation < rightest_apt)
	{
		minDistance += (rightest_apt - schoolLocation) * 2;

		for (int leftLimit = busLimit; schoolLocation < rightest_apt ; )
		{
			if (studentCount_list[rightest_apt] > leftLimit)
			{
				studentCount_list[rightest_apt] -= leftLimit;
				break;
			}
			else
			{
				leftLimit -= studentCount_list[rightest_apt];
				studentCount_list[rightest_apt] = 0;
				while (studentCount_list[--rightest_apt] == 0 && schoolLocation < rightest_apt);
			}
		}
	}


	cout << minDistance;

	return 0;
}


