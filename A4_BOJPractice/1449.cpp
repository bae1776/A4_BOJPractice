//https://www.acmicpc.net/problem/1449

//수리공

//지하철 수도 파이프에 물이 새서, 수리공이 출동했다.
//파이프에서 물이 새는 곳은 신기하게도 가장 왼쪽에서 정수만큼 떨어진 거리만 물이 샌다고 한다.

//수리공은 길이가 L인 테이프를 무한개 지니고 있고, 이 테이프로 물을 막으려한다.
//수리공은 구멍난 위치에서 좌우 0.5 간격은 줘야 다시는 새지 않을 것이라고 생각한다.

//물이 새는 곳 위치, L이 주어졌을 때 테이프의 최소 개수는?

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int holeCount, typeLength;
	cin >> holeCount >> typeLength;

	vector<int> holeLocation;
	holeLocation.reserve(holeCount);

	int input;
	for (int i = 0; i < holeCount; i++)
	{
		cin >> input;
		holeLocation.emplace_back(input);
	}

	sort(holeLocation.begin(), holeLocation.end());

	int typingIndex = 0;
	int typeCount = 0;

	do {
		int layered = typingIndex;

		while (layered < holeCount - 1 && holeLocation[layered + 1] - holeLocation[typingIndex] < typeLength)
			layered++;

		typeCount++;
		typingIndex = layered + 1;
	} while (typingIndex < holeCount);


	cout << typeCount;
	
	return 0;
}


