//https://www.acmicpc.net/problem/10807

/*개수 세기 (Bronze 5)
Solution : 배열

*/

#include <iostream>
using namespace std;

int arr[100];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cnt;
    cin >> cnt;

    for (int i = 0; i < cnt; i++)
        cin >> arr[i];

    int v;
    cin >> v;
    
    int ans = 0;
    for (int i = 0; i < cnt; i++)
        ans += (arr[i] == v);

    cout << ans;


    return 0;
}
