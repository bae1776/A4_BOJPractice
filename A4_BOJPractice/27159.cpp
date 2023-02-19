//https://www.acmicpc.net/problem/999 (문제 번호)

/*노 떙스
*/

#include <iostream>
#include <algorithm>
using namespace std;


int arr[40];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int arrCount;
    cin >> arrCount;
    
    for (int i = 0; i < arrCount; i++)
    {
        cin >> arr[i];
    }

    int score = 0;
    for (int i = 0; i < arrCount; i++)
    {
        int start = arr[i];
        int j;
        for (j = i + 1; j < arrCount; j++)
            if (arr[j] == start + 1)
            {
                start = arr[j];
                continue;
            } else
                break;

        score += arr[i];
        i = j - 1;
    }

    cout << score;

	
	return 0;
}
