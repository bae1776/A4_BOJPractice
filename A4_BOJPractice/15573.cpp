//https://www.acmicpc.net/problem/15573

//채굴

//채굴기를 이용하여 광물을 채굴하려하는데 
//공기에 맞닿은 광물만 채굴할 수 있고 채굴기 강도가 광물 강도보다 높아야 캘 수 있다.
//N개의 광물을 캐려할 때의 최소 채굴기 강도를 구하시오.


#include <iostream>
#include <queue>
using namespace std;

class Mineral {
public:
	int x;
	int y;
	int strength;
	bool observed;

	Mineral() {};
	Mineral(int x, int y, int strength, bool observed) :
		x(x), y(y), strength(strength), observed(observed) {};

	bool operator<(const Mineral& other) const {
		return this->strength > other.strength;
	}
};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int row, col, mineralWants;
	cin >> row >> col >> mineralWants;

	Mineral** mineralList = new Mineral * [row + 2];
	
	for (int y = 0; y <= row + 1; y++)
	{
		mineralList[y] = new Mineral[col + 2];

		for (int x = 0; x <= col + 1; x++)
		{
			Mineral& target = mineralList[y][x];
			target.x = x;
			target.y = y;
			if (y == row + 1)
			{
				target.observed = true;
				target.strength = 0x7FFFFFFF; //ground Block
			}
			else if (x == 0 || x == col + 1 || y == 0) {
				target.observed = true;
				target.strength = 0; //air Block
			}
			else {
				target.observed = false;
				int strength;
				cin >> strength;
				target.strength = strength;
			}
		}
	}

	priority_queue<Mineral> crawlingList; //minHeap
	
	for (int y = 1; y <= row; y++)
		for (int x = 1; x <= col; x++)
		{
			if (x == 1 || y == 1 || x == col)
			{
				crawlingList.push(mineralList[y][x]); //It's copy, not move.
				mineralList[y][x].observed = true;	  //surronded block
			}
		}
	

	int minStrength = 0;

	for (int nowMineral = 1; nowMineral <= mineralWants; nowMineral++)
	{
		Mineral nextMineral = crawlingList.top();
		crawlingList.pop();

		if (nextMineral.strength > minStrength)
			minStrength = nextMineral.strength;

		int this_x = nextMineral.x;
		int this_y = nextMineral.y;
		
		//left Find
		if (mineralList[this_y][this_x - 1].observed == false)
		{
			crawlingList.push(mineralList[this_y][this_x - 1]);
			mineralList[this_y][this_x - 1].observed = true;
		}
		
		//right Find
		if (mineralList[this_y][this_x + 1].observed == false)
		{
			crawlingList.push(mineralList[this_y][this_x + 1]);
			mineralList[this_y][this_x + 1].observed = true;
		}

		//up Find
		if (mineralList[this_y - 1][this_x].observed == false)
		{
			crawlingList.push(mineralList[this_y - 1][this_x]);
			mineralList[this_y - 1][this_x].observed = true;
		}

		//down Find
		if (mineralList[this_y + 1][this_x].observed == false)
		{
			crawlingList.push(mineralList[this_y + 1][this_x]);
			mineralList[this_y + 1][this_x].observed = true;
		}
	}

	cout << minStrength;

	for (int i = 0; i <= row + 1; i++)
		delete[] mineralList[i];
	delete[] mineralList;

	
	return 0;
}