//https://www.acmicpc.net/problem/19539

//사과나무
//1만큼 성장시키는 물뿌리개와 2만큼 성장시키는 물뿌리개를 적절하게 사용하기 (O(nlogn))


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