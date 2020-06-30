//https://www.acmicpc.net/problem/10451

//1~N���� �ѹ����� ���� ������ �־��� ��, ��������� ���� ����Ŭ�� ������ ���Ͻÿ�.

//a(i) = k �� �׷��� i->k �������� ��Ÿ����, �� ���� ���� �׷����� �̷� �� ���� ����Ŭ�̶�� �Ѵ�.
//�ڱⰡ �ڱ� �ڽ��� ����Ű�� ��쵵 1���� �����Ѵ�.


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
