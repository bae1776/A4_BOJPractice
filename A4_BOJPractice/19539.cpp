//https://www.acmicpc.net/problem/19539

//�������
//1��ŭ �����Ű�� ���Ѹ����� 2��ŭ �����Ű�� ���Ѹ����� �����ϰ� ����ϱ� (O(nlogn))


#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int treeCount, one = 0, two = 0;
	cin >> treeCount;

	for (int i = 0; i < treeCount; i++) 
	{
		int input;
		cin >> input;

		one += input % 2;
		two += input / 2;
	}

	if (two - one >= 0 && (two - one) % 3 == 0)
	{
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}


	return 0;
}