//https://www.acmicpc.net/problem/2606

//바이러스

//컴퓨터를 노드로 하는 그래프가 주어진다.
//어떤 컴퓨터가 바이러스에 걸렸을 때, 그래프로 서로 연결되어 있는 컴퓨터만
//인터넷을 통해 같이 감염된다.

//1번 컴퓨터가 감염되었을 때, 감염되는 컴퓨터 수를 출력하시오.


#include <iostream>
#include <vector>
#include <functional>
using namespace std;




int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int infected = -1;

	int totalComputer;
	cin >> totalComputer;

	vector<int>* adjList = new vector<int>[totalComputer + 1];
	vector<bool> visited(totalComputer + 1, false);
	

	int connection;
	cin >> connection;

	for (int i = 0; i < connection; i++)
	{
		int start, end;
		cin >> start >> end;

		adjList[start].push_back(end);
		adjList[end].push_back(start);
	}

	
	//람다 함수를 저장하는 function STL 클래스
	function<void(int, vector<int>*, vector<bool>&)> dfs = 
		[&](int Node, vector<int>* adjList, vector<bool>& visited)->
	void {
		infected++;
		visited[Node] = true;

		for (int i : adjList[Node])
		{
			if (!visited[i])
				dfs(i, adjList, visited);
		}
	};

	dfs(1, adjList, visited);

	
	cout << infected;

	delete[] adjList;

	return 0;
}