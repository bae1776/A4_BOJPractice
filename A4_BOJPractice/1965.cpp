//https://www.acmicpc.net/problem/1965

//���� �ֱ�.

//������ü ���ڵ��� �þ �ְ�, �� ���ڸ��� ũ�Ⱑ �־��� �ִµ�, �տ� �ִ� ������ ũ�Ⱑ �ڿ� �ִ� ������ ũ�⺸�� ������,
//�տ� �ִ� ���ڸ� �ڿ� �ִ� ���� �ȿ� ���� �� �ִ�.
//������ ũ����� �־��� ��, �� ���� ���� �� �ִ� �ִ��� ���� ������ ���Ͻÿ�.

#include <vector>
#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	int boxCount;
	cin >> boxCount;

	vector<int> boxSize;
	vector<int> DP;
	boxSize.reserve(boxCount);
	DP.reserve(boxCount);

	for (int i = 0; i < boxCount; i++)
	{
		int size;
		cin >> size;
		boxSize.emplace_back(size);
	}

	
	for (int i = 0; i < boxCount; i++)
	{
		int max = 1;
		for (int j = 0; j < i; j++)
		{
			if (boxSize[j] < boxSize[i] && DP[j] >= max)
			{
				max = DP[j] + 1;
			}
		}
		DP.emplace_back(max);
	}

	int DPmax = 0;

	for (auto i = DP.begin(); i < DP.end(); i++)
		if (*i > DPmax) DPmax = *i;
	
	cout << DPmax;


	return 0;
}