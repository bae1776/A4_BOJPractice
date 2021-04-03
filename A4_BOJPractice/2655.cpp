//https://www.acmicpc.net/problem/2655

//다음 조건을 만족시키면서 직육면체 벽돌을 가장 높게 쌓을 때의 쌓인 벽돌의 수와 번호를 
//위에 있는 벽돌부터 출력하시오.

//1. 벽돌은 회전할 수 없다.
//2. 보다 밑면이 좁은 벽돌 위에 더 넓은 벽돌을 올릴 수 없다.
//3. 보다 가벼운 벽돌 위에 더 무거운 벽돌을 올릴 수 없다.
//4. 높이가 서로 같거나 무게가 서로 같은 벽돌은 없다.

//벽돌은 최대 100개이다. 넓이, 무게, 높이는 10000을 넘지 않는다.

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

typedef struct _brick {
	int number;
	union {
		int bottomArea;
		int beforeIndex;
	};
	int height;
	int weight;
} Brick;

Brick maxHeight_forWeight[10001]; 




int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<Brick> bricks_inArea;

	int brickCount;
	cin >> brickCount;

	for (int brickNumber = 1; brickNumber <= brickCount; brickNumber++)
	{
		int area, height, weight;
		cin >> area >> height >> weight;

		bricks_inArea.push_back({ brickNumber, area, height, weight });
	}


	sort(bricks_inArea.begin(), bricks_inArea.end(), 
		[](const Brick& a, const Brick& b) -> bool {
		return a.bottomArea < b.bottomArea; 
	});


	for (auto itr = bricks_inArea.begin(); itr != bricks_inArea.end(); ++itr)
	{
		const Brick& next_narrowBrick = *itr;

		int bestBrick_index = 0;
		for (int index = 1; index < next_narrowBrick.weight; index++)
		{
			if (maxHeight_forWeight[index].height > maxHeight_forWeight[bestBrick_index].height)
			{
				bestBrick_index = index;
			}
		}

		Brick& bottomBrick = maxHeight_forWeight[next_narrowBrick.weight];
		bottomBrick.number = next_narrowBrick.number;
		bottomBrick.beforeIndex = bestBrick_index;
		bottomBrick.height = maxHeight_forWeight[bestBrick_index].height + next_narrowBrick.height;
	}


	int bottomBrick_index = 0;
	
	for (int idx = 1; idx <= 10000; idx++)
	{
		if (maxHeight_forWeight[idx].height > maxHeight_forWeight[bottomBrick_index].height)
			bottomBrick_index = idx;
	}

	Brick bottomBrick = maxHeight_forWeight[bottomBrick_index];
	stack<int> brickNumber;

	while (true)
	{
		brickNumber.push(bottomBrick.number);
		if (bottomBrick.beforeIndex != 0)
			bottomBrick = maxHeight_forWeight[bottomBrick.beforeIndex];
		else
			break;
	}


	cout << brickNumber.size() << '\n';
	while (brickNumber.empty() == false)
	{
		cout << brickNumber.top() << '\n';
		brickNumber.pop();
	}


	return 0;
}