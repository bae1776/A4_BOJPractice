//https://www.acmicpc.net/problem/10813

/*�� �ٲٱ� (Bronze 2)
Solution : �迭 swap

*/

#include <iostream>
using namespace std;

int bucket[101];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int bucketSize, ball;
    cin >> bucketSize >> ball;

    for (int i = 1; i <= bucketSize; i++)
        bucket[i] = i;

    while (ball--)
    {
        int a, b;
        cin >> a >> b;
        int temp = bucket[a];
        bucket[a] = bucket[b];
        bucket[b] = temp;
    }

    for (int i = 1; i <= bucketSize; i++)
        cout << bucket[i] << ' ';


    return 0;
}
