//https://www.acmicpc.net/problem/2655

//���� ������ ������Ű�鼭 ������ü ������ ���� ���� ���� ���� ���� ������ ���� ��ȣ�� 
//���� �ִ� �������� ����Ͻÿ�.

//1. ������ ȸ���� �� ����.
//2. ���� �ظ��� ���� ���� ���� �� ���� ������ �ø� �� ����.
//3. ���� ������ ���� ���� �� ���ſ� ������ �ø� �� ����.
//4. ���̰� ���� ���ų� ���԰� ���� ���� ������ ����.

//������ �ִ� 100���̴�. ����, ����, ���̴� 10000�� ���� �ʴ´�.

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