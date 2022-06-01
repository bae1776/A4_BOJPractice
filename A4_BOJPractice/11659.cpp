//https://www.acmicpc.net/problem/11659

/*구간 합 구하기 4
최대 10만 길이의 배열에서 특정 구간의 합을 구하시오.
합을 구해야 하는 질의는 최대 10만개 주어지므로 logN 안으로 해결 가능해야 한다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int numCount, queryCount;
    cin >> numCount >> queryCount;

    vector<int> numArray(numCount), sumArray(numCount + 1, 0);

    for (int index = 0; index < numCount; index++)
    {
        cin >> numArray[index];
        sumArray[index + 1] = sumArray[index] + numArray[index];
    }

    while (queryCount--)
    {
        int start, end;
        cin >> start >> end;
        cout << sumArray[end] - sumArray[start - 1] << '\n';
    }
    
	return 0;
}