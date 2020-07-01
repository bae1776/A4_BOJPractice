//https://www.acmicpc.net/problem/2812

//강의실 배정

//수업의 개수와 각 수업의 시작 시간과 종료 시간이 주어진다.
//이 모든 수업을 모두 할 수 있게하는 최소 강의실 수를 구하시오.

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