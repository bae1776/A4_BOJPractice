//https://www.acmicpc.net/problem/1637

/*날카로운 눈 (Platinum 4)

Solution : 비트마스킹을 이용한 이분 탐색

모든 숫자를 일일히 해싱, 배열에 기록하는 것은 공간도 너무 클 뿐더러 수가 최고 20조개이기 때문에 불가능한 해결방법이다.

이 문제는 홀수 + 짝수 n개는 항상 홀수, 짝수 n개는 항상 짝수임을 이용한다.
각 정수 더미를 가장 낮은 비트부터 마스킹하며 0인 것과 1인 것으로 쪼개 저장한다. 
각 저장된 더미에서 개수를 세서 홀수개인 것만 선택한다.
이렇게 문제를 풀었을 때 시간복잡도는 O(N * logC) 이다. 
여기서 N은 최대 20000, C는 2^31이므로 충분히 풀 수 있다.

정수 더미를 쪼개는 방법은 다음 예시와 같다.
1 100 3 정수 더미가

step = 2
정수 더미의 step이 현재 step으로 나누어 떨어지지 않으면 정수 더미의 step에 2를 곱한다
(나누어 떨어지는 경우, 한쪽은 전부 가지고 한쪽은 모두 잃는다.)
홀수인 경우 : 1 100 6
짝수인 경우 : 4 100 6
첫 숫자가 마스킹 조건에 부합하지 않는 경우, 다음 숫자를 부여한다.

이를 다시 각각 쪼개면
step = 4
홀수 -> mod 4 = 3 : 7 100 12
홀수 -> mod 4 = 1 : 1 100 12
짝수 -> mod 4 = 2 : 10 100 12
짝수 -> mod 4 = 0 : 4 100 12
...
*/

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct Numbag {
    long long start, end, step;
};

struct Node {
    long long count;
    long long rest;
    vector<Numbag> numBags;

    Node() = delete;
    Node(long long bagCount)
    {
        this->count = 0;
        this->rest = 0;
        this->numBags.reserve(bagCount);
    }
};



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int bagCount;
    cin >> bagCount;

    //시작 정수 더미
    Node now(bagCount);
    for (int i = 0; i < bagCount; i++)
    {
        Numbag input;
        auto& [start, end, step] = input;
        cin >> start >> end >> step;

        now.count += (end - start) / step + 1;
        now.numBags.emplace_back(input);
    }
    
    if (now.count % 2 == 0)
    {
        cout << "NOTHING";
        return 0;
    }

    for (long long maxRest = 2; maxRest != 0; maxRest <<= 1)
    {
        Node fBag(now.numBags.size()), tBag(now.numBags.size());
        fBag.rest = now.rest;
        tBag.rest = now.rest + maxRest / 2;

        for (const auto& eachBag : now.numBags)
        {
            Numbag fNew = eachBag, tNew = eachBag;
            //fBag 첫번째 숫자가 다음 숫자 필터 조건을 만족하는가?
            if (eachBag.start % maxRest == fBag.rest)
            {
                //예 -> fBag만 시작 번호 그대로
                tNew.start += eachBag.step;
            } else {
                //아니오 -> tBag만 시작 번호 그대로
                fNew.start += eachBag.step;
            }

            if (eachBag.step % maxRest != 0)
            {
                fNew.step *= 2; tNew.step *= 2;
                if (fNew.start <= fNew.end)
                {
                    fBag.numBags.emplace_back(fNew);
                    fBag.count += (fNew.end - fNew.start) / fNew.step + 1;
                }

                if (tNew.start <= tNew.end)
                {
                    tBag.numBags.emplace_back(tNew);
                    tBag.count += (tNew.end - tNew.start) / tNew.step + 1;
                }
            } else {
                //한쪽만 모두 갖는다.
                if (tNew.start < fNew.start)
                {
                    tBag.numBags.emplace_back(tNew);
                    tBag.count += (tNew.end - tNew.start) / tNew.step + 1;
                } else {
                    fBag.numBags.emplace_back(fNew);
                    fBag.count += (fNew.end - fNew.start) / fNew.step + 1;
                }
            }

            
        }

        if (fBag.count % 2 == 0)
        {
            now = tBag;
        } else {
            now = fBag;
        }
    }

    cout << now.rest << ' ' << now.count;

	return 0;
}


