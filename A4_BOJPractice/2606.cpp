//https://www.acmicpc.net/problem/2606

//���̷���

//��ǻ�͸� ���� �ϴ� �׷����� �־�����.
//� ��ǻ�Ͱ� ���̷����� �ɷ��� ��, �׷����� ���� ����Ǿ� �ִ� ��ǻ�͸�
//���ͳ��� ���� ���� �����ȴ�.

//1�� ��ǻ�Ͱ� �����Ǿ��� ��, �����Ǵ� ��ǻ�� ���� ����Ͻÿ�.


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

	
	//���� �Լ��� �����ϴ� function STL Ŭ����
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