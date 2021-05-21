//https://www.acmicpc.net/problem/20112

/*사토르 마방진
* 대회 링크 : https://www.acmicpc.net/category/detail/2335
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int size;
	cin >> size;

	vector<string> Words(size);
	
	bool isSator = true;

	for (int i = 0; i < size; i++)
		cin >> Words[i];

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (Words[i][j] != Words[j][i])
			{
				isSator = false;
				break;
			}
		}
		if (isSator == false)
			break;
	}


	switch (isSator)
	{
	case true:
		cout << "YES" << '\n';
		break;
	case false:
		cout << "NO" << '\n';
	}



	return 0;
}