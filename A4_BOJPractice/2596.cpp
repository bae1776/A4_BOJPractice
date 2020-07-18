//https://www.acmicpc.net/problem/2596

//비밀편지
//0, 1로 이루어진 6자를 알파벳 하나로 해독할 수 있는데,
//그런데 가끔 통신 오류로 숫자가 왜곡될 수도 있을 것이다.
//다만, 왜곡된 숫자도, 가장 유사한 해독 코드를 찾아 해석할 수 있을 것이다.
//그러나 유사도가 같은(즉, 차이나는 문자 갯수가 최소) 문자는 애매할 것이다.

//0, 1로 이루어지는 코드가 주어질 때,
//이를 해독하고, 매칭되는 코드가 없을 때는 가장 유사한 것으로 해독하고,
//유사한 문자가 여러개라 애매하면, 문자가 아니라 애매한 문자의 위치만 출력하시오.

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
