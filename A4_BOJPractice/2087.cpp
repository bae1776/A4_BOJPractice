//https://www.acmicpc.net/problem/2087

/*암호문 (Gold 1)

40개를 Yes/No 중 선택해서 답을 찾는 문제이다.
전부 다 계산하면 2^40 이기 때문에 절대로 풀 수 없다.

이 문제는 20개씩 반반 쪼개서, 각각에 대해 해답을 구한뒤,
한쪽은 선형(2^20) * 한쪽은 이분 탐색(log(2^20))하여 해를 찾아야 한다.
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

    int numCount;
    cin >> numCount;

    vector<int> arr(numCount);
    for (int i = 0; i < numCount; i++)
        cin >> arr[i];

    int target;
    cin >> target;


    int leftCount = numCount / 2;
    int rightCount = ((numCount % 2) == 1) ? numCount / 2 + 1 : numCount / 2;
    vector<int> arrLeft(1 << leftCount);
    vector<pair<int, int>> arrRight(1 << rightCount);

    for (int i = 1; i < arrLeft.size(); i++)
    {
        int bitMask = 0;
        while ((i & (1 << bitMask)) == 0)
            bitMask++;
        
        arrLeft[i] = arrLeft[i - (1 << bitMask)] + arr[bitMask];
    }

    for (int i = 1; i < arrRight.size(); i++)
    {
        int bitMask = 0;
        while ((i & (1 << bitMask)) == 0)
            bitMask++;
        
        arrRight[i].first = arrRight[i - (1 << bitMask)].first + arr[bitMask + leftCount];
        arrRight[i].second = i;
    }

    sort(arrRight.begin(), arrRight.end());

    int leftAnswerBit = 0;
    vector<pair<int, int>>::iterator rightAnswerIt;
    for (; leftAnswerBit < arrLeft.size(); leftAnswerBit++)
    {
        if (target - arrLeft[leftAnswerBit] < 0)
            continue;
        
        rightAnswerIt = lower_bound(arrRight.begin(), arrRight.end(), make_pair(target - arrLeft[leftAnswerBit], 0));

        if (rightAnswerIt != arrRight.end() && rightAnswerIt->first == target - arrLeft[leftAnswerBit])
            break;
    }

    const int& rightAnswerBit = rightAnswerIt->second;

    for (int i = 0; i < leftCount; i++)
        if ((leftAnswerBit & (1 << i)) != 0)
            cout << 1;
        else
            cout << 0;
    
    for (int i = 0; i < rightCount; i++)
        if ((rightAnswerBit & (1 << i)) != 0)
            cout << 1;
        else
            cout << 0;



	return 0;
}
