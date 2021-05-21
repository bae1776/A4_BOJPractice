//https://www.acmicpc.net/problem/20114

/*미아 노트
* 대회 링크 : https://www.acmicpc.net/category/detail/2335
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int orglen, vertSpread, horiSpread;
	cin >> orglen >> vertSpread >> horiSpread;

	vector<string> spreadStr(vertSpread);
	vector<char> orgStr(orglen, '?');

	for (int i = 0; i < vertSpread; i++)
		cin >> spreadStr[i];


	for (int charOrder = 0; charOrder < orglen; charOrder++)
	{
		for (int vert = 0; vert < vertSpread; vert++)
		{
			int horizfirst = charOrder * horiSpread;
			int horizend = (charOrder + 1) * horiSpread;
			bool charFound = false;

			for (int i = horizfirst; i < horizend; i++)
			{
				if (spreadStr[vert][i] != '?')
				{
					orgStr[charOrder] = spreadStr[vert][i];
					charFound = true;
					break;
				}
			}
			if (charFound == true)
				break;
		}
	}

	for (char i : orgStr)
		cout << i;
	

	return 0;
}