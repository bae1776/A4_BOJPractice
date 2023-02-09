//https://www.acmicpc.net/problem/1269

/* 대칭 차집합 (Silver 3)

공집합이 아닌 두 자연수 집합 A, B에 대해
(A-B) U (B-A) 를 A, B의 대칭 차집합이라 한다.

A, B가 주어질 때 대칭 차집합의 원소 개수를 구하시오. (원소 각각 최대 20만, 값 1억 이하)
참고로 한 집합에 중복된 원소가 존재하지 않는다.

Solution : 
(A-B) U (B-A) = AUB - ANB 이다.
A 원소 개수 + B 원소 개수 - 2 * (ANB 원소 개수) 가 답이다.
공통 원소를 구하는 방법은 다양하다. 정렬을 하고 매칭하던가 set(balanced Tree)를 써도 된다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int setA[200000], setB[200000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int aSize, bSize;
    cin >> aSize >> bSize;

    for (int i = 0; i < aSize; i++)
        cin >> setA[i];
    
    for (int i = 0; i < bSize; i++)
        cin >> setB[i];

    sort(setA, setA + aSize);
    sort(setB, setB + bSize);

    int intersectCount = 0;
    int aIndex = 0, bIndex = 0;
    while (aIndex < aSize && bIndex < bSize)
    {
        if (setA[aIndex] == setB[bIndex])
        {
            intersectCount++;
            aIndex++;
            bIndex++;
        } else if (setA[aIndex] < setB[bIndex])
            aIndex++;
        else
            bIndex++;
    }

    cout << aSize + bSize - 2 * intersectCount;
    
    return 0;
}