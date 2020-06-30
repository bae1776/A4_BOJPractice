//https://www.acmicpc.net/problem/10451

//1~N까지 한번씩만 쓰인 수열이 주어질 때, 만들어지는 순열 사이클의 갯수를 구하시오.

//a(i) = k 를 그래프 i->k 간선으로 나타낼때, 한 바퀴 도는 그래프를 이룰 때 순열 사이클이라고 한다.
//자기가 자기 자신을 가리키는 경우도 1개로 간주한다.


#include <iostream>
#include <string.h>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	int testcase;
	cin >> testcase;

	for (int tc = 0; tc < testcase; tc++)
	{
		int arrLength;
		cin >> arrLength;

		int cycleCount = 0;

		int* arr = new int[arrLength + 1];
		bool* visited = new bool[arrLength + 1];
		memset(visited, false, sizeof(bool) *(arrLength + 1));


		for (int i = 1; i <= arrLength; i++)
			cin >> arr[i];


		for (int i = 1; i <= arrLength; i++)
		{
			if (!visited[i])
			{
				cycleCount++;
				visited[i] = true;
				int nextVisit = arr[i];
				while (!visited[nextVisit])
				{
					visited[nextVisit] = true;
					nextVisit = arr[nextVisit];
				}
			}
		}

		cout << cycleCount << '\n';


		delete[] arr;
		delete[] visited;
	}




	return 0;
}
