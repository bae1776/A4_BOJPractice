//https://www.acmicpc.net/problem/1062

/*가르침 (Gold 4)

Solution : 브루트포스 

26개의 글자 중 가르칠 것을 선택해야 하는데,
모든 단어는 a, c, n, i, t가 무조건 포함되야 하므로
21개만 따지면 된다. 그러면 시간복잡도는 최악의 경우 21C10으로 충분히 풀 수 있다.
*/

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

vector<bitset<26>> wordList;
int answer = 0;
int wordCount, alphaCount;
void func(bitset<26> alphaBit, const int& depth, const int& selected);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> wordCount >> alphaCount;
    wordList.reserve(wordCount);

    string input;
    for (int i = 0; i < wordCount; i++)
    {
        cin >> input;
        bitset<26> alphaBit(0);
        for (const char& ch : input)
            alphaBit[ch - 'a'] = true;
        
        wordList.emplace_back(alphaBit);
    }

    func(bitset<26>(0), 0, 0);
    cout << answer;

	return 0;
}


void func(bitset<26> alphaBit, const int& depth, const int& selected)
{
    if (selected == alphaCount)
    {
        int readable = 0;
        for (const auto& wordBit : wordList)
            if ((wordBit & alphaBit) == wordBit)
                readable++;
        answer = max(answer, readable);

        return;
    }

    if (depth == 26)
        return;

    const static char fix[5] = {'a', 'c', 'n', 'i', 't'};
    bool selectFix = false;
    for (int i = 0; i < 5; i++)
        if (depth == fix[i] - 'a')
            selectFix = true;
    
    if (!selectFix)
        func(alphaBit, depth + 1, selected);
    
    alphaBit[depth] = true;

    func(alphaBit, depth + 1, selected + 1);


}