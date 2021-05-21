//https://www.acmicpc.net/problem/13549

//숨바꼭질 3
//수빈이와 동생은 1~100000 중 하나의 점에 있다.
//수빈이는 이동 혹은 순간이동을 하여 동생에게 도달하는 최단 시간을 구하세요.
//수빈이가 점 X에서 이동하면 X-1 또는 X+1 로 1초만에 갈 수 있고
//수빈이가 점 X에서 순간이동하면 2*X로 0초만에 간다.


#include <iostream>
#include <queue>
using namespace std;

int countMove(int maxMultiply, int gap)
{
    if (gap < 0)
        return countMove(maxMultiply, -gap);
    else if (gap == 0)
        return 0;

    struct Data {
        int nowGap;
        int nowMultiply;
        int depth;
    };

    queue<Data> BFSQueue;
    Data initData = {0, maxMultiply, 0};
    BFSQueue.emplace(initData);

    while (true)
    {
        Data qFront = BFSQueue.front();
        BFSQueue.pop();

        if (qFront.nowGap == gap)
            return qFront.depth;
        else {
            for (int multiply = qFront.nowMultiply; multiply != 0; multiply /= 2)
            {
                Data addBranch = {qFront.nowGap + multiply, multiply / 2, qFront.depth + 1};
                Data subBranch = {qFront.nowGap - multiply, multiply / 2, qFront.depth + 1};

                if (abs(subBranch.nowGap - gap) < multiply)
                    BFSQueue.emplace(subBranch);

                if (abs(addBranch.nowGap - gap) < multiply)
                    BFSQueue.emplace(addBranch);
        
                
            }
        }
    }

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int subin, younger, result = 0;
    cin >> subin >> younger;
        
    if (subin >= younger)
    {
        cout << subin - younger;
        return 0;
    }

    if (subin == 0)
        subin = result = 1;
    if (subin == 1)
        subin = 2;
    if (younger <= 2)
    {
        cout << result;
        return 0;
    }
    
    int multiplier = 1;

    while (multiplier * 2 * subin < younger)
        multiplier *= 2;
    
    int leftGap = younger - subin * multiplier;
    int leftTopBitMove = leftGap / multiplier;
    int rightGap = subin * multiplier * 2 - younger;
    int rightTopBitMove = rightGap / (multiplier * 2);

    result += min(leftGap - leftTopBitMove * multiplier == 0 ? leftTopBitMove
                  : min(leftTopBitMove + countMove(multiplier / 2, leftGap - leftTopBitMove * multiplier), 
                  leftTopBitMove + 1 + countMove(multiplier / 2, leftGap - (leftTopBitMove + 1) * multiplier)),
                  rightGap - rightTopBitMove * multiplier * 2 == 0 ? rightTopBitMove
                  : min(rightTopBitMove + countMove(multiplier, rightGap - rightTopBitMove * multiplier * 2),
                  rightTopBitMove + 1 + countMove(multiplier, rightGap - (rightTopBitMove + 1) * multiplier * 2)));

    cout << result;

	return 0;
}
