//https://www.acmicpc.net/problem/9997

/*폰트 (Gold 3)

Solution :
문장이 25개이기 때문에 완전탐색으로 풀 수 있다.
(문장을 선택한다/안한다 두 경우이므로 2^25 = 3200만 정도 이다.)
*/

#include <iostream>
#include <bitset>
using namespace std;

void dfs(bitset<26> bitArray, int depth);
bitset<26> wordAlphabet[50];
int wordCount;
int result = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> wordCount;
    char input[102];

    for (int i = 0; i < wordCount; i++)
    {
        cin >> input;
        
        int index = 0;
        while (input[index] != '\0')
            wordAlphabet[i][input[index++] - 'a'] = true;
    }

    dfs(bitset<26>(0), 0);
    
    cout << result;
    
	return 0;
}


void dfs(bitset<26> bitArray, int depth)
{
    if (depth == wordCount)
    {
        const static bitset<26> fullBit("11111111111111111111111111");
        if (bitArray == fullBit)
            result++;

        return;
    } else {
        dfs(bitArray, depth + 1);
        bitArray |= wordAlphabet[depth];
        dfs(bitArray, depth + 1);
    }
}