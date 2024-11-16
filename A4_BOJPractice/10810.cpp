//https://www.acmicpc.net/problem/10810

/*공 넣기 (Bronze 3)
Solution : 배열과 반복문

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

    while (ball--)
    {
        int start, end, num;
        cin >> start >> end >> num;

        for (int i = start; i <= end; i++)
            bucket[i] = num;
    }

    for (int i = 1; i <= bucketSize; i++)
        cout << bucket[i] << ' ';


    return 0;
}