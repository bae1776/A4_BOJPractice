//https://www.acmicpc.net/problem/1517

/*버블 소트
최대 50만 길이의 배열이 주어진다.
이 배열에 버블 소트를 실행했을 때, SWAP이 일어나는 횟수를 출력하여라.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

/*Solution : 
arr[N]이 움직이는 횟수는
arr[0]~arr[N-1] 에서 자기 자신보다 큰 수의 개수이다.

예를 들어
1 8 4 3 6 이라 하자.
arr[2]=4는 앞에 자기보다 큰 수 arr[1]=8을 가지고 있기 때문에 필히 밀리게 된다.
arr[3]=3은 앞에 자기보다 큰 수 2개를 가지고 있기 때문에 2번 밀리게 된다.

이 밀리는 행위는 모두 SWAP 횟수라고 할 수 있다.
즉 우리가 구해야 할 것은 각 원소별 자기 자신 앞에 있는 큰 수의 개수의 총합이다.

이 총합은 배열 구간의 합을 logN으로 구할 수 있는 세그먼트 트리를 이용하여 구해야 한다.
추가적으로 세그먼트 트리는 인덱스 기반이기 때문에 좌표압축이 추가로 필요하다.
*/
    int arrLength;
    cin >> arrLength;

    vector<pair<int, int>> arr;
    arr.reserve(arrLength);

    
    int value;
    for (int index = 0; index < arrLength; index++)
    {
        cin >> value;
        arr.emplace_back(value, index);
    }

    sort(arr.begin(), arr.end());

    int swapCount = 0;
    


	
	return 0;
}