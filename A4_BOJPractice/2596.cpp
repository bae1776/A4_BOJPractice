//https://www.acmicpc.net/problem/2596

//�������
//0, 1�� �̷���� 6�ڸ� ���ĺ� �ϳ��� �ص��� �� �ִµ�,
//�׷��� ���� ��� ������ ���ڰ� �ְ�� ���� ���� ���̴�.
//�ٸ�, �ְ�� ���ڵ�, ���� ������ �ص� �ڵ带 ã�� �ؼ��� �� ���� ���̴�.
//�׷��� ���絵�� ����(��, ���̳��� ���� ������ �ּ�) ���ڴ� �ָ��� ���̴�.

//0, 1�� �̷������ �ڵ尡 �־��� ��,
//�̸� �ص��ϰ�, ��Ī�Ǵ� �ڵ尡 ���� ���� ���� ������ ������ �ص��ϰ�,
//������ ���ڰ� �������� �ָ��ϸ�, ���ڰ� �ƴ϶� �ָ��� ������ ��ġ�� ����Ͻÿ�.

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

char interpret_binCode(vector<char>::iterator start_pos);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int strCodeLen;
	cin >> strCodeLen;

	vector<char> binCode(strCodeLen * 6);

	for (char& vecRef : binCode)
		cin >> vecRef;  //char '0'

	auto this_itr = binCode.begin();
	vector<char> strCode;
	for (int i = 0; i < strCodeLen; i++)
	{
		char resultChar = interpret_binCode(this_itr);
		if (resultChar == NULL)
		{
			cout << i + 1;
			return 0;
		}
		strCode.push_back(resultChar);
		this_itr += 6;
	}

	for (char& ch : strCode)
		cout << ch;

	return 0;
}


const char* interpret_list[]
= { "000000", "001111", "010011", "011100", "100110",
	"101001", "110101", "111010" };

const int LISTLENGTH = 8;

char interpret_binCode(vector<char>::iterator start_pos)
{
	vector<char> binCode(start_pos, start_pos + 6);
	vector<pair<int, char>> codeDiff_list;

	for (int i = 0; i < LISTLENGTH; i++)
	{
		int diffCount = 0;
		for (int j = 0; j < 6; j++)
		{
			if (interpret_list[i][j] != binCode[j])
				diffCount++;
		}
		if (diffCount == 0)
			return 'A' + i;
		codeDiff_list.emplace_back(diffCount, 'A' + i);
	}

	sort(codeDiff_list.begin(), codeDiff_list.end());

	if (codeDiff_list[0].first == codeDiff_list[1].first)
		return NULL;
	else 
		return codeDiff_list[0].second;
}
