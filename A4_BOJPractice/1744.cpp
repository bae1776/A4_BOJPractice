//https://www.acmicpc.net/problem/1744

//�� ����

//���� �� ������ -10000~10000 �� �迭�� �ִ�.
//������ ���� ���Ϸ��� �ϴµ�, �ܼ��� ���ϴ� �� �Ӹ� �ƴ϶�, Ư�� �� ���Ҹ� ��� ���� ���� ������ ���� ����� �� �ִٰ� ����.
//(�̹� ���� ���Ҵ� �� ���� ���� ����.)

//������ ������ �� ���� �ִ��� ���Ͻÿ�.


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int arrsize;
	cin >> arrsize;

	vector<int> arr;
	arr.reserve(arrsize + 1);

	for (int i = 0; i < arrsize; i++)
	{
		int input;
		cin >> input;
		arr.emplace_back(input);
	}

	sort(arr.begin(), arr.end());

	long long int sum = 0;

	
	if (arr.front() < 0)
	{
		for (auto i = arr.begin(); i != arr.end(); ++i)
		{
			if (*i < 0)
			{
				if (i == --arr.end() || *(i + 1) > 0)
					sum += *i;
				else {
					sum += (*i) * (*(i + 1));
					++i;
				}
			}
			else break;
		}
	}

	if (arr.back() > 0)
	{
		for (auto i = arr.rbegin(); i != arr.rend(); ++i)
		{
			if (*i > 0)
			{
				if (i == --arr.rend() || *(i + 1) <= 1)
					sum += *i;
				else {
					sum += (*i) * (*(i + 1));
					++i;
				}
			}
			else break;
		}
	}


	cout << sum;


	return 0;
}