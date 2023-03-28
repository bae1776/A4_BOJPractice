//https://www.acmicpc.net/problem/3033

/*가장 긴 문자열 (Platinum 3)
Solution : 파라메트릭 서치와 문자열 해싱(라빈-카프)

가장 긴 중복 부분문자열 길이를 구하는 문제인데, 문자열 길이가 20만이므로, 단순 구현 O(n^2)으로는 풀 수 없는 문제이다.

파라매트릭 서치 기법을 이용하여 최적화(찾기) 문제를 결정(Yes/No) 문제로 바꾸자.
길이가 l인 중복문자열을 찾으라는 질의는, 길이 l에 대해 결과가 이분적이다.
즉, 어떤 문자열의 가장 긴 중복 부분 문자열이 "abcde"일때, "abcd"도 중복 부분문자열, "abc"도 이에 해당한다.
그러나 길이가 6일 수는 없다. 즉, 카르노맵을 생각해보면 TT...TTFFFFFF 이다.
위 문제를 "길이"에 대하여 이분 탐색할 수 있다. 이분 탐색하여 위 질의가 참인 가장 큰 l을 구하면 된다.
위 파라메트릭 서치에 logN 시간이 소요된다.

길이가 l인 부분문자열 모음을 O(N)에 처리하려면 해싱을 사용해야 한다.
문자열 해싱에 가장 흔히 쓰이는 알고리즘은 라빈-카프(Rabin-Karp) 알고리즘이다.
https://blog.naver.com/ndb796/221240679247

요약하자면, 각 문자열 문자의 아스키 코드에 (자연수)^(자리)를 곱한 것의 합을 해시값으로 잡는 것이다. 해시 함수가 매우 간단하지만, 해시 충돌은 거의 일어나지 않는다.
또한 "롤링"을 통해 슬라이딩 윈도우 방식으로 다음 부분 문자열을 O(1)에 찾을 수 있다.
(참고로 롤링에 의해 해시값에 오버플로우가 발생하더라도 해시가 망가지지 않는다.)
*/

#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
using namespace std;
#define VAL 3

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int len;
	cin >> len;

	string str;
	cin >> str;

	//부분 문자열 길이에 대한 파라메트릭 서치
	int left = 1, right = len - 1;

	while (left <= right)
	{
		unordered_map<unsigned int, list<unsigned int>> RK_hashTable;
		int mid = (left + right) / 2;
		unsigned int hashValue = 0;
		bool hasTwice = false;
		unsigned int mul = 1; //VAL ^ (mid - 1)
		for (int i = 0; i < mid - 1; i++)
			mul *= VAL;

		for (int i = 0; i < mid; i++)
			hashValue = hashValue * VAL + str[i];
		
		for (int start = 0; start <= len - mid; start++)
		{
			if (RK_hashTable.find(hashValue) == RK_hashTable.end())
			{
				RK_hashTable[hashValue] = list<unsigned int>();
				RK_hashTable[hashValue].push_back(start);
			} else {
				for (const unsigned int& idx : RK_hashTable[hashValue])
				{
					int i = 0;
					for (; i < mid && str[start + i] == str[idx + i]; i++);
							
					if (i == mid)
					{
						hasTwice = true;
						break;
					}
				}

				if (hasTwice)
					break;
				else
					RK_hashTable[hashValue].push_back(start);
			}

			if (start == len - mid) break;
			hashValue = (hashValue - mul * str[start]) * VAL + str[start + mid];
		}

		if (hasTwice)
			left = mid + 1;
		else
			right = mid - 1;

	}

	cout << right;

	return 0;
}
