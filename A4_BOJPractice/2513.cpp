//https://www.acmicpc.net/problem/2513

//���й���
//������ ���� ������ ����Ʈ ������ �װ��� ��� �л� ��, �б��� ��ġ�� �־�����.
//�б����� ž�� ������ �����Ǿ� �ִ� ���й��� 1��� �л����� ��� �б��� ���Ű���� �� ��, 
//���й����� �� �̵� �Ÿ��� �ּҸ� ���Ͻÿ�.

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


