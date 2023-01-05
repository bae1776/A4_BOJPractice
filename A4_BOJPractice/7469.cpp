//https://www.acmicpc.net/problem/7469

/*K번째 수 (Platinum 2)
배열 a[1...n] 에 대해 다음과 같은 함수를 정의하자.
Q(i, j, k) = a[i...j]에서 k번째 수

각 원소는 절댓값이 10억을 넘지 않고 서로 다른 수를 가진다.
당신은 n이 최대 10만, Q 함수가 5천개일때 이를 1초안에 해결해야 한다.

Solution :
Merge Sort Tree, 좌표 압축, 이분 탐색을 이용하면 
O(NlogN + Q * (logN)^3) 에 해결 가능. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Element {
    vector<int> sortedArray;
    int left, right;
};

int arrayLen, queryCount;
int arr[100002];
pair<int, int> copyArr[100002];
int valueCompress[100002];
Element mergesortTree[262144]; // = 2^18, root = s[1]
Element& makeTree(int index, int left, int right);
int queryFunction(const int& left, const int& right, const int& k);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> arrayLen >> queryCount;

    //1. 좌표 압축
    for (int i = 1; i <= arrayLen; i++)
    {
        cin >> copyArr[i].first;
        copyArr[i].second = i;
    }
    sort(copyArr + 1, copyArr + arrayLen + 1);
    for (int i = 1; i <= arrayLen; i++)
    {
        valueCompress[i] = copyArr[i].first;
        arr[copyArr[i].second] = i;
    }
    //2. 머지소트 트리 구성하기
    makeTree(1, 1, arrayLen);


    //3. 쿼리 처리
    while (queryCount--)
    {
        int left, right, k;
        cin >> left >> right >> k;

        cout << valueCompress[queryFunction(left, right, k)] << '\n';
    }

	
	return 0;
}



Element& makeTree(int index, int left, int right)
{
    Element& ret = mergesortTree[index];
    ret.left = left;
    ret.right = right;
    ret.sortedArray.reserve(right - left + 1);

    if (left == right)
    {
        ret.sortedArray.emplace_back(arr[left]);
        return ret;
    }

    int mid = (left + right) / 2;
    //자식 노드들을 먼저 구성한다.
    vector<int>& leftArray = makeTree(index * 2, left, mid).sortedArray;
    vector<int>& rightArray = makeTree(index * 2 + 1, mid + 1, right).sortedArray;

    //자식 노드들의 배열들을 Merge한다.
    int leftIndex = 0, rightIndex = 0,
        leftSize = leftArray.size(), rightSize = rightArray.size();
    
    while (leftIndex != leftSize && rightIndex != rightSize)
    {
        if (leftArray[leftIndex] < rightArray[rightIndex])
            ret.sortedArray.emplace_back(leftArray[leftIndex++]);
        else
            ret.sortedArray.emplace_back(rightArray[rightIndex++]);
    }

    while (leftIndex != leftSize)
        ret.sortedArray.emplace_back(leftArray[leftIndex++]);
        
    while (rightIndex != rightSize)
        ret.sortedArray.emplace_back(rightArray[rightIndex++]);

    return ret;
}


int queryFunction(const int& left, const int& right, const int& k)
{
    vector<int> searchElementIndex;
    queue<int> bfsQueue;
    bfsQueue.emplace(1);

    //세그먼트 트리 처럼 구간 배열들을 모두 불러 searchElementIndex에 저장
    while (bfsQueue.empty() == false)
    {
        int index = bfsQueue.front();
        Element& nowElement = mergesortTree[index];
        bfsQueue.pop();

        if (left <= nowElement.left && nowElement.right <= right)
            searchElementIndex.emplace_back(index);
        else {
            int mid = (nowElement.left + nowElement.right) / 2;
            if (left <= mid)
                bfsQueue.emplace(index * 2);
            if (right >= mid + 1)
                bfsQueue.emplace(index * 2 + 1);
        }
    }

    int min = 1, max = arrayLen;
    
    //각 구간 배열에 대한 mid = min max 평균이 몇번째인지 구한다.
    //예를 들어 구해야할 구간이 10, 15로 6개이고 그 중 k = 3번째로 작은 수를 구한다.
    //그리고 구간이 3개이다
    //2 3 6 / 1 7 / 4
    //각 구간의 lower_bound = 2, upper_bound = 3 이면 종료 -> (둘 합이 2k - 1인경우)
    int boundSum, ans, target = 2 * k - 1;
    while (true)
    {
        boundSum = 0;
        ans = (min + max) / 2;

        for (const auto& index : searchElementIndex)
        {
            vector<int>& elementArr = mergesortTree[index].sortedArray;
            boundSum += lower_bound(elementArr.begin(), elementArr.end(), ans) - elementArr.begin();
            boundSum += upper_bound(elementArr.begin(), elementArr.end(), ans) - elementArr.begin();
        }

        if (boundSum < target)
            min = ans + 1;
        else if (boundSum > target)
            max = ans - 1;
        else
            return ans;
    }
}