//https://www.acmicpc.net/problem/2812

//���ǽ� ����

//������ ������ �� ������ ���� �ð��� ���� �ð��� �־�����.
//�� ��� ������ ��� �� �� �ְ��ϴ� �ּ� ���ǽ� ���� ���Ͻÿ�.

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int lectureCount;
	cin >> lectureCount;

	vector<pair<int, int>> lectureTime;
	lectureTime.reserve(lectureCount + 1);
	priority_queue<int, vector<int>, greater<>> classrooms;
	classrooms.push(0);

	for (int i = 0; i < lectureCount; i++)
	{
		int start, end;
		cin >> start >> end;
		lectureTime.emplace_back(start, end);
	}
	sort(lectureTime.begin(), lectureTime.end());


	for (auto& lecture : lectureTime)
	{
		if (classrooms.top() <= lecture.first)
			classrooms.pop();

		classrooms.push(lecture.second);
	}

	cout << classrooms.size();

	return 0;
}