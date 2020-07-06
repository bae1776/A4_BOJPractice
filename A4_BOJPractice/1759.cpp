//https://www.acmicpc.net/problem/1759

//암호 만들기
//알파벳 소문자로만 이루어진 암호를 추측해보자.
//암호의 길이를 A, 암호에 들어갈 수 있는 알파벳 문자의 종류를 B라 할 때
//3 <= A <= B <= 15를 만족시키고,
//암호는 최소 1개의 모음과 최소 2개의 자음이 있어야 한다.
//이 조건들을 모두 만족시키는 암호를 사전 순으로 출력해보자.

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
