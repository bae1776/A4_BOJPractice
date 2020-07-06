//https://www.acmicpc.net/problem/1759

//��ȣ �����
//���ĺ� �ҹ��ڷθ� �̷���� ��ȣ�� �����غ���.
//��ȣ�� ���̸� A, ��ȣ�� �� �� �ִ� ���ĺ� ������ ������ B�� �� ��
//3 <= A <= B <= 15�� ������Ű��,
//��ȣ�� �ּ� 1���� ������ �ּ� 2���� ������ �־�� �Ѵ�.
//�� ���ǵ��� ��� ������Ű�� ��ȣ�� ���� ������ ����غ���.

#include <iostream>
#include <algorithm>
using namespace std;

int passwordLength, totalChars;
char* candidates;
int* indexList;

void find_all_passwords(int depth, int startIndex);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> passwordLength >> totalChars;

	candidates = new char[totalChars];
	indexList = new int[passwordLength];
	for (int i = 0; i < totalChars; i++)
		cin >> candidates[i];

	sort(candidates, candidates + totalChars);

	//Find answer
	find_all_passwords(0, 0);

	delete[] candidates;
	delete[] indexList;
	return 0;
}



void find_all_passwords(int depth, int startIndex)
{
	if (depth == passwordLength)
	{
		int vowelCount = 0;
		for (int i = 0; i < passwordLength; i++)
			switch (candidates[indexList[i]])
			{
			case 'a': case 'e': case 'i': case 'o': case 'u':
				vowelCount++;
			}

		if (vowelCount >= 1 && passwordLength - vowelCount >= 2)
		{
			for (int i = 0; i < passwordLength; i++)
				cout << candidates[indexList[i]];
			cout << '\n';
		}

		return;
	}

	const int limitIndex = totalChars - passwordLength + depth;
	for (int i = startIndex; i <= limitIndex; i++)
	{
		indexList[depth] = i;
		find_all_passwords(depth + 1, i + 1);
	}
}
