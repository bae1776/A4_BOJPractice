//https://www.acmicpc.net/problem/14452

//Cow Dance Show
//소들은 매년 열리는 댄스 공연에서 올해 여러 달의 리허설을 거쳐 Cowpelia 발레를 선보인다.
//공연에서 마지막으로 정해야 할 부분이 공연장의 크기인데,
//K 사이즈의 공연장에서는 K마리의 소까지 동시에 춤출 수 있다.
//N (~10000) 마리의 소 무리는 무대에 들어오는 순서가 1~N까지 매겨져 있으며, 
//각 소마다 무대에서 춤추기로 한 시간이 주어진다. (최대 10만)
//우선, 1~K번 소가 무대에 나타나 춤을 추고, 소가 무대에서 빠져나오면, K+1번째 소가 춤을 추기 시작한다.
//즉, 쇼가 끝나기 즈음까지 무대에서는 계속 K마리에 소가 춤을 추고 있을 것이다. 쇼는 마지막 소까지 빠져나가면 끝난다.

//무대가 크면 공연 끝나는 시간이 빨라지는 건 자명하다. 공연을 너무 오래할 순 없기 때문에, 
//당신에겐 공연 최대 시간이 주어진다. (최대 100만)
//이 제한 시간 안에 공연을 끝내려면 적어도 무대의 크기가 얼마나 되어야 할 지 구하시오.
//K = N일때, 공연은 반드시 제 시간에 끝남이 보장된다. (공연 최대 시간이 어떤 소 한마리의 춤추는 시간보다 짧은 경우는 없다.)


#include <iostream>
#include <queue>
using namespace std;

int showTime(int*& cowDanceTimes, int cowCount, const int& stageSize);

int main(void)
{
    //Estimated Time Complexity : O(N(logN)^2) , N = cows
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int cowCount, timeLimit;
    cin >> cowCount >> timeLimit;
    
    int* cowDanceTimes = new int[cowCount];
    for (int i = 0; i < cowCount; i++)
        cin >> cowDanceTimes[i];

    int minStageSize = 1, maxStageSize = cowCount;
    
    while (minStageSize <= maxStageSize)
    {
        int pivotStageSize = (minStageSize + maxStageSize) / 2;
        int caculatedTime = showTime(cowDanceTimes, cowCount, pivotStageSize);

        if (caculatedTime <= timeLimit)
            maxStageSize = pivotStageSize - 1;
        else
            minStageSize = pivotStageSize + 1;
    }

    cout << minStageSize;
    
    delete[] cowDanceTimes;

	return 0;
}


int showTime(int*& cowDanceTimes, int cowCount, const int& stageSize)
{
    priority_queue<int, vector<int>, greater<int>> stageList;
    int cowIndex = 0;
    int timePassed = 0;

    while (cowCount != cowIndex)
    {
        if (stageList.size() == stageSize)
        {
            int nextEndCow = stageList.top();
            stageList.pop();
            timePassed = nextEndCow;
        }
        stageList.push(timePassed + cowDanceTimes[cowIndex++]);   
    }

    while (stageList.empty() == false)
    {
        int remainCow = stageList.top();
        stageList.pop();
        timePassed = remainCow;
    }

    return timePassed;
}
