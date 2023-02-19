//https://www.acmicpc.net/problem/2309

/*일곱 난쟁이 (Bronze 1)

Solution : 구현

*/


#include <iostream>
#include <algorithm>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int heightList[9];
    int totalHeight = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> heightList[i];
        totalHeight += heightList[i];
    }

    for (int one = 0; one < 9; one++)
    {
        for (int two = one + 1; two < 9; two++)
        {
            if (totalHeight - heightList[one] - heightList[two] == 100)
            {
                heightList[one] = heightList[two] = 1000;
                break;
            }
        }
        if (heightList[one] == 1000)
            break;
    }

    sort(heightList, heightList + 9);

    for (int i = 0; i < 7; i++)
        cout << heightList[i] << '\n';



	return 0;
}

