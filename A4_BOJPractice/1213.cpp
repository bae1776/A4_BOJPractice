//https://www.acmicpc.net/problem/1213

//�Ӹ����(������ �о �ڷ� �о ���� ����) �����
//���ĺ� �빮�� ���ڿ�(�ִ� 50��)�� �־��� �� ���� ������ ���� �ռ� �縰����� ����ÿ�.
//�Ұ��� �ϸ� I'm Sorry Hansoo�� ����Ͻÿ�.

#include <iostream>
#include <string>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string name;
	cin >> name;
	
	int alphabet[26] = { 0 };
	for (auto i = name.begin(); i != name.end(); ++i)
		alphabet[*i - 'A']++;


	string pelind;
	pelind.reserve(name.length() + 1);
	bool odd_isPossible = true;
	char odd_char;
	bool validity = true;

	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] % 2 == 0)
		{
			for (int addCount = 0; addCount < alphabet[i] / 2; addCount++)
				pelind.push_back(i + 'A');
		}
		else {
			if (odd_isPossible == true)
			{
				odd_isPossible = false;
				for (int addCount = 0; addCount < alphabet[i] / 2; addCount++)
					pelind.push_back(i + 'A');
				odd_char = i + 'A';
			}
			else {
				validity = false;
				break;
			}
		}
	}

	if (validity == false)
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	for (auto i = pelind.begin(); i != pelind.end(); ++i)
		cout << *i;

	if (odd_isPossible == false)
		cout << odd_char;

	for (auto i = pelind.rbegin(); i != pelind.rend(); ++i)
		cout << *i;

	return 0;
}