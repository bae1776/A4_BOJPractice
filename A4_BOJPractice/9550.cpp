//https://www.acmicpc.net/problem/9550

//아이들은 사탕을 좋아해

#include <iostream>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;

	for (int rep = 0; rep < testcase; ++rep)
	{
		int candyType, minCandy;
		cin >> candyType >> minCandy;

		int result = 0;
		for (int i = 0; i < candyType; i++)
		{
			int candyCount;
			cin >> candyCount;
			result += candyCount / minCandy;
		}

		cout << result << '\n';
		
	}



	return 0;
}
