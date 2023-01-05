//https://www.acmicpc.net/problem/15976

/*XCorr (Gold 3)
길이가 동일하고 각 원소가 음이 아닌 정수로 이루어진 두 개의 수열 
X = (x0, x1, ..., xn-1), Y = (y0, y1, ..., yn-1)이 주어진다.
이때 XCorr(t) = Sum(i = 0; i < n; i++) xi * y(i+t)로 정의한다. 이때 i가 0~(n-1) 범위를 벗어나는 경우 모두 0으로 간주한다.
또한 S(a, b) = Sum(t = a; t <= b; t++) XCorr(t)로 정의한다.
S(a, b)를 구하시오.

수열의 길이는 최대 10억이나, 0이 아닌 원소의 개수는 30만개 이하이다. 
a, b는 -10억 ~ 10억이다. 원소의 값은 0~3000이다.

Solution : 슬라이딩 윈도우
최대한 값이 커질 때, 3000 * 3000이 30만 * 30만번 더해진다. 900억 * 900만 = 27경 (long long 으로 표현 가능)
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long result = 0;
    int countA, countB;

    cin >> countA;
    vector<pair<int, int>> arrayA(countA);
    for (int i = 0; i < countA; i++)
        cin >> arrayA[i].first >> arrayA[i].second; //index, value;
    
    cin >> countB;
    vector<pair<int, int>> arrayB(countB);
    for (int i = 0; i < countB; i++)
        cin >> arrayB[i].first >> arrayB[i].second; //index, value;

    int rangeLeft, rangeRight;
    cin >> rangeLeft >> rangeRight;

    long long rangeBSum = 0;
    auto arrayBRightIterator = arrayB.begin();
    auto arrayBLeftIterator = arrayB.begin();
    for (const auto& arrayAElement : arrayA)
    {
        //Right Slide
        while (arrayBRightIterator != arrayB.end() && arrayBRightIterator->first <= arrayAElement.first + rangeRight)
        {
            rangeBSum += arrayBRightIterator->second;
            ++arrayBRightIterator;
        }

        //Left Slide 
        while (arrayBLeftIterator != arrayB.end() && arrayBLeftIterator->first < arrayAElement.first + rangeLeft)
        {
            rangeBSum -= arrayBLeftIterator->second;
            ++arrayBLeftIterator;
        }

        result += arrayAElement.second * rangeBSum;
    }

    cout << result;
    
	return 0;
}
