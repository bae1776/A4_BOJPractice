//https://www.acmicpc.net/problem/2661

//좋은 수열

//숫자 1, 2, 3으로만 이루어지는 수열이 있다.
//임의의 길이의 인접한 두 개의 부분 수열이 동일한 것이 있으면, 
//그 수열을 나쁜 수열이라고 부른다. 그렇지 않은 수열은 좋은 수열이다.

//다음은 나쁜 수열의 예이다   -  33, 32121323, 123123213
//다음은 좋은 수열의 예이다.  -  2, 32, 32123, 1232123

//자리 수가 주어졌을 때, 해당 자리 수에서 가장 작은 좋은 수열 값을 출력하시오.

#include <iostream>
#include <cstring>
using namespace std;




int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int digit;
	cin >> digit;
	char goodSequence[100];
	memset(goodSequence, '0', sizeof(goodSequence));

	goodSequence[0] = '1';
	int depth = 1;
	while (depth < digit)
	{
		if (goodSequence[depth] == '3')
		{
			goodSequence[depth] = '0';
			depth--;
			continue;
		}
		goodSequence[depth] += 1;
		const int half = (depth + 1) / 2;
		char* lastSeq = goodSequence + depth;
		int i;
		for (i = 0; i <= half; i++)
		{
			if (strncmp(lastSeq - i * 2 - 1, lastSeq - i, i + 1) == 0)
				break;
			
		}
		if (i > half)
			depth++;
	}

	goodSequence[digit] = '\0';
	cout << goodSequence;



	return 0;
}
