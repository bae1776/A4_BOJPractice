//https://www.acmicpc.net/problem/2206

//벽 부수고 이동하기
//벽은 1, 길은 0으로 주어진 미로가 있고
//왼쪽 위 끝에서 오른쪽 아래 끝까지 가야하는데,
//벽을 한 번까지는 부수고 갈 수 있다.
//이때 최단 경로는?

#include <iostream>
#include <queue>
using namespace std;

typedef struct _coord
{
	int x;
	int y;
	int depth;
	bool skill;

	_coord(int x, int y, int depth, bool skill) :
	x(x), y(y), depth(depth), skill(skill) {};
	
} Coord;

int row, col;
bool** maze;
bool*** visited;  /*skill unavailable, available*/

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> row >> col;

	maze = new bool* [row];
	visited = new bool** [row];
	for (int i = 0; i < row; i++)
	{
		maze[i] = new bool[col];
		visited[i] = new bool*[col];
		for (int j = 0; j < col; j++)
		{
			char input;
			cin >> input;
			maze[i][j] = static_cast<bool>(input - '0');
			visited[i][j] = new bool[2];
			visited[i][j][0] = visited[i][j][1] = false;
		}
	}

	int result = -1;
	queue<Coord> mazeQueue;
	mazeQueue.emplace(0, 0, 1, true); //initial Coordinate

	while (!mazeQueue.empty())
	{
		Coord now_coord = mazeQueue.front();
		mazeQueue.pop();

		if (visited[now_coord.y][now_coord.x][now_coord.skill] == true)
			continue;
		
		if (now_coord.x == col - 1 && now_coord.y == row - 1)
		{
			result = now_coord.depth;
			break;
		}
		
		if (now_coord.skill == true)
			visited[now_coord.y][now_coord.x][true] = true;
		visited[now_coord.y][now_coord.x][false] = true;

		
		//Right
		if (now_coord.x < col - 1)
		{
			if (maze[now_coord.y][now_coord.x + 1] == 0 
				&& visited[now_coord.y][now_coord.x + 1][now_coord.skill] == false)
			{	
				mazeQueue.emplace(now_coord.x + 1, now_coord.y, now_coord.depth + 1, now_coord.skill);
			}
			else if (now_coord.skill == true) 
			{
				if (visited[now_coord.y][now_coord.x+1][false] == false)
					mazeQueue.emplace(now_coord.x + 1, now_coord.y, now_coord.depth + 1, false);
			}
		}

		//Left
		if (now_coord.x > 0)
		{
			if (maze[now_coord.y][now_coord.x - 1] == 0
				&& visited[now_coord.y][now_coord.x - 1][now_coord.skill] == false)
			{
				mazeQueue.emplace(now_coord.x - 1, now_coord.y, now_coord.depth + 1, now_coord.skill);
			}
			else if (now_coord.skill == true)
			{
				if (visited[now_coord.y][now_coord.x - 1][false] == false)
					mazeQueue.emplace(now_coord.x-1, now_coord.y, now_coord.depth + 1, false);
			}
		}

		//Down
		if (now_coord.y < row - 1)
		{
			if (maze[now_coord.y + 1][now_coord.x] == 0
				&& visited[now_coord.y + 1][now_coord.x][now_coord.skill] == false)
			{
				mazeQueue.emplace(now_coord.x, now_coord.y+1, now_coord.depth + 1, now_coord.skill);
			}
			else if (now_coord.skill == true)
			{
				if (visited[now_coord.y + 1][now_coord.x][false] == false)
					mazeQueue.emplace(now_coord.x, now_coord.y+1, now_coord.depth + 1, false);
			}
		}


		//Up
		if (now_coord.y > 0)
		{
			if (maze[now_coord.y - 1][now_coord.x] == 0
				&& visited[now_coord.y - 1][now_coord.x][now_coord.skill] == false)
			{
				mazeQueue.emplace(now_coord.x, now_coord.y-1, now_coord.depth + 1, now_coord.skill);
			}
			else if (now_coord.skill == true)
			{
				if (visited[now_coord.y-1][now_coord.x][false] == false)
					mazeQueue.emplace(now_coord.x, now_coord.y-1, now_coord.depth + 1, false);
			}
		}
	}

	cout << result;
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			delete[] visited[i][j];
		delete[] maze[i];
		delete[] visited[i];
	}
	delete[] maze;
	delete[] visited;
	

	return 0;
}
