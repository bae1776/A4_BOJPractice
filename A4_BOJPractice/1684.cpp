//https://www.acmicpc.net/problem/1684

/* 같은 나머지 (Gold 5)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int arrlen;
    cin >> arrlen;

    for (int i = 0; i < arrlen; i++)
        cin >> arr[i];

    sort(arr, arr + arrlen);

    for (int i = arrlen - 1; i >= 0; i--)
        arr[i] -= arr[0];

    int startIndex = upper_bound(arr, arr + arrlen, 0) - arr;

    for (int answer = arr[startIndex]; answer >= 1; answer--)
    {
        bool isAnswer = true;
        for (int i = startIndex; i < arrlen; i++)
        {
            if (arr[i] % answer)
            {
                isAnswer = false;
                break;
            }
        }

        if (isAnswer)
        {
            cout << answer;
            break;
        }
    }

    

    
    return 0; 
}
