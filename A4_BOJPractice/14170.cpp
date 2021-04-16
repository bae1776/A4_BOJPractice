//https://www.acmicpc.net/problem/14170

//Counting Haybales (건초더미 세기)
//농부 존은 최대 100000개의 건초더미를 1차원상의 도로에 세웠습니다.
//건초들끼리 적절히 거리를 두어 놓기 위해, 특정 구간에 있는 건초 더미가 얼마나 되는 지 각 쿼리마다 알려주세요.
//쿼리는 최대 10만개 입니다.

//첫번째 줄에는 건초 더미의 수(N)과 쿼리의 개수(Q)가 주어집니다.
//다음 줄에는 N개의 서로 다른 정수가 ~10억 까지 주어지는데, 이는 건초 더미가 있는 위치를 의미합니다.
//그 다음 Q줄엔 두 정수 A, B (1<=A<=B<=10억)가 주어지는데, A 이상 B 사이 구간에 건초가 몇 개 있는 지 묻는 쿼리이고
//모든 쿼리를 1초 안에 해결할 수 있으면 정답입니다.

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int hayCount, query;
    cin >> hayCount >> query;

    int* hayLocation = new int[hayCount];
    for (int i = 0; i < hayCount; i++)
        cin >> hayLocation[i];

    sort(hayLocation, hayLocation + hayCount);
    
    while (query--)
    {
        int start, end;
        cin >> start >> end;

        //start : lower bound find
        int left = 0, right = hayCount - 1, pivot;
        
        while (left <= right)
        {
            pivot = (left + right) / 2;
            if (hayLocation[pivot] >= start)
                right = pivot - 1;
            else
                left = pivot + 1;
        }
        start = left;

        //end : upper bound find
        left = 0; 
        right = hayCount - 1;

        while (left <= right)
        {
            pivot = (left + right) / 2;
            if (hayLocation[pivot] > end)
                right = pivot - 1;
            else
                left = pivot + 1;
        }

        end = right;

        cout << end - start + 1 << '\n';
    }

    delete[] hayLocation;

	return 0;
}
