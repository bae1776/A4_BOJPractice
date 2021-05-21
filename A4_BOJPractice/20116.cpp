//https://www.acmicpc.net/problem/20116

/*상자의 균형
* 대회 링크 : https://www.acmicpc.net/category/detail/2335
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int boxCount, boxSize;
	cin >> boxCount >> boxSize;

	vector<int> box_xList(boxCount);
	for (int i = 0; i < boxCount; i++)
		cin >> box_xList[i];

	bool isStable = true;
	int cum_boxCount = 0;
	long long coord_sum = 0;

	for (auto i = box_xList.rbegin(); i != box_xList.rend(); ++i)
	{

		if (i != box_xList.rbegin())
		{
			double weightCenter = coord_sum / (double)cum_boxCount;
			//cout << cum_boxCount + 1 << "번째 상자에서 허용범위 (" << (*i - boxSize) << ", " << (*i + boxSize) << ")  weightCenter is " << weightCenter << '\n';

			if (weightCenter < (*i + boxSize) && weightCenter > (*i - boxSize));
			else {
				isStable = false;
				break;
			}
			
		}

		cum_boxCount++;
		coord_sum += *i;
	}

	if (isStable)
		cout << "stable";
	else
		cout << "unstable";
	

	return 0;
}