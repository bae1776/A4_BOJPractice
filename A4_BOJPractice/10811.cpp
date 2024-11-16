//https://www.acmicpc.net/problem/10811

/*바구니 뒤집기 (Bronze 2)
Solution : 배열 범위 swap

*/

#include <iostream>
using namespace std;

int bucket[101];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int bucketSize, swapCnt;
    cin >> bucketSize >> swapCnt;

    for (int i = 1; i <= bucketSize; i++)
        bucket[i] = i;

    while (swapCnt--)
    {
        int a, b;
        cin >> a >> b;

        for (int i = 0; i <= (b - a) / 2; i++)
        {
            int temp = bucket[a + i];
            bucket[a + i] = bucket[b - i];
            bucket[b - i] = temp;
        }
    }

    for (int i = 1; i <= bucketSize; i++)
        cout << bucket[i] << ' ';

    return 0;
}
