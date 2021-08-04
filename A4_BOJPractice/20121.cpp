//https://www.acmicpc.net/problem/20121

/*카드 셔플

다음 두 가지 셔플로, 어떤 카드를 특정 위치로 보내려한다.
필요한 셔플 최소 순서를 구하세요.
(카드는 반드시 홀수 개이며 최대 10억 장이다. TC는 최대 100개 이다.)

X-셔플 : 첫 번째 카드는 놔두고, 뒤쪽 카드 절반을 사이사이에 끼워 넣는다.
예시 : 1234ABC -> 1A2B3C4

Y-셔플 : 끝 카드는 놔두고, 앞쪽 카드 절반을 사이사이에 끼워 넣는다.
예시 : 123ABCD -> A1B2C3D

*/

#include <iostream>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {

        int cardCount, startCard, endCard;
        cin >> cardCount >> startCard >> endCard;
        startCard--;
        endCard--;
        
        int suffleCount = 0;
        int suffleBit = -10;

        while (suffleBit == -10)
        {
            suffleCount++;
            startCard = startCard * 2 % cardCount;

            int rangeLength = 1 << suffleCount;
            int startRange = startCard % cardCount;
            int endRange = (startCard + rangeLength - 1) % cardCount;
            

            if (rangeLength > cardCount)
            {
                if (startRange <= endCard)
                    suffleBit = endCard - startRange;
                else
                    suffleBit = (endCard + cardCount) - startRange;
            } else if (startRange <= endCard && endCard <= endRange)
                suffleBit = endCard - startRange;
            else if (startRange > endRange)
                if (startRange <= endCard)
                    suffleBit = endCard - startRange;
                else if (endCard <= endRange)
                    suffleBit = (endCard + cardCount) - startRange;
        }
        
        for (int bits = (1 << (suffleCount - 1)); bits != 0; bits /= 2)
            if (suffleBit & bits)
                cout << 'Y';
            else
                cout << 'X';
        
        cout << '\n';

    }



    return 0;
}