//https://www.acmicpc.net/problem/2437

//����
//�ϳ��� ���� ������ �̿��Ͽ� ������ ���Ը� �����Ϸ��� �Ѵ�.
//���� ���� �� �ʿ��� ������ �÷����ְ� �ٸ� �ʿ��� �����߸� ���� �� �ִ�.

//���԰� ���� ������ N���� �����߰� �־��� ��, �� �ߵ��� ����Ͽ� ������ �� ���� ���� ���� ���� �ּڰ��� ����Ͻÿ�.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int limit = 0;
	int weightCount;
	
	cin >> weightCount;

	vector<int> weights;
	weights.reserve(weightCount + 1);

	for (int i = 0; i < weightCount; i++)
	{
		int input;
		cin >> input;
		weights.emplace_back(input);
	}

	sort(weights.begin(), weights.end());


	auto arrIter = weights.begin();

	while (arrIter != weights.end() && limit + 1 >= *arrIter)
	{
		limit += *arrIter;
		++arrIter;
	}

	cout << limit + 1;

	

	return 0;
}