//https://www.acmicpc.net/problem/2075

/*N번째 큰 수 (Silver 2)
Solution : 메모리 제한이 12MB이고, 수를 저장하는 데만 9MB가 필요하다.
이 때문에, 합병 정렬로 푸는 것은 불가능하다.

비교적 가장자리에 있는 수를 구하는 것이므로 maxHeap으로 구할 수 있다.
그러나 메모리제한이 매우 빡빡하므로 직접 구현해야 한다.
*/

#include <iostream>
using namespace std;

int maxHeap[2250001];
int heapSize = 0;
void heapPush(const int& value);
int heapPop();

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int size;
    cin >> size;

    int input;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            cin >> input;
            heapPush(input);
        }

    for (int order = 1; ; order++)
    {
        int result = heapPop();
        if (order == size)
        {
            cout << result;
            break;
        }

    }
    

	return 0;
}



void heapPush(const int& value)
{
    int nowLoc = ++heapSize;
    maxHeap[nowLoc] = value;

    while (nowLoc != 1 && maxHeap[nowLoc / 2] < maxHeap[nowLoc])
    {
        swap(maxHeap[nowLoc / 2], maxHeap[nowLoc]);
        nowLoc /= 2;
    }
}

int heapPop()
{
    int result = maxHeap[1];
    maxHeap[1] = maxHeap[heapSize--];

    int nowLoc = 1;
    while (true)
    {
        if (nowLoc * 2 + 1 <= heapSize)
        {
            if (maxHeap[nowLoc * 2] < maxHeap[nowLoc * 2 + 1])
            {
                if (maxHeap[nowLoc] < maxHeap[nowLoc * 2 + 1])
                {
                    swap(maxHeap[nowLoc], maxHeap[nowLoc * 2 + 1]);
                    nowLoc = nowLoc * 2 + 1;
                } else break;
            } else {
                if (maxHeap[nowLoc] < maxHeap[nowLoc * 2])
                {
                    swap(maxHeap[nowLoc], maxHeap[nowLoc * 2]);
                    nowLoc *= 2;
                } else break;
            }         
        }
        else if (nowLoc * 2 <= heapSize)
        {
            if (maxHeap[nowLoc] < maxHeap[nowLoc * 2])
            {
                swap(maxHeap[nowLoc], maxHeap[nowLoc * 2]);
                nowLoc *= 2;
            } else break;
        } else break;
    } 

    return result;
}