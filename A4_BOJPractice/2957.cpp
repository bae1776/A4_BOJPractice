//https://www.acmicpc.net/problem/2957

/* 이진 탐색 트리 (Platinum 5)

이진 탐색 트리는 삽입할 때 재귀 함수를 사용할 수 있다. (단 첫 노드는 재귀하지 않음)
예를 들어, 현재 노드의 값보다 작으면 왼쪽 자식을 선택하는데, 
왼쪽에 이미 노드가 존재하는 경우 그 노드로 재귀한다. 

최대 30만개의 정수 [1, N]가 중복없이 무작위로 입력 될 때,
그 입력되는 순서로 이진 탐색 트리를 만들때, 위 (재귀를 이용한) 삽입 함수의 총 호출 횟수를
정수가 입력될 때마다 각 줄에 출력하세요.

Solution :
어떤 노드를 삽입(추가)할 때 삽입 함수의 호출 횟수는, 그 노드가 들어갈 자리의 깊이 - 1과 같다.
그런데 직접 트리를 구성하여 풀려고 하는 경우, 
이 문제의 노드의 수는 30만개이고, 사향 트리가 주어질 경우 호출 횟수는 1 + 2 + 3 ... + 30만으로 450억이나 되므로 시간 초과가 된다.
그래서 다음과 같은 성질을 이용해야 풀 수 있다.
어떤 이진 탐색 트리에 들어간 노드가 10, 20, 30, 40라 하자.
(탐색 트리의 모양은 삽입 순서에 따라 다를 수 있다.)

15가 삽입될 경우 노드 15의 깊이는 max(노드 10의 깊이, 노드 20의 깊이) + 1이다.
*/


#include <iostream>
#include <map>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int numCount;
    cin >> numCount;

    long long total = 0;
    int input;
    map<int, int> levelMap;

    while (numCount--)
    {
        cin >> input;
        auto pointer = levelMap.upper_bound(input);

        if (pointer == levelMap.end())
        {
            if (levelMap.empty())
                total += (levelMap[input] = 0);
            else
                total += (levelMap[input] = levelMap.rbegin()->second + 1);
        } else {
            if (pointer == levelMap.begin())
                total += (levelMap[input] = levelMap.begin()->second + 1);
            else {
                auto forwardPointer = pointer--;
                total += (levelMap[input] = max(pointer->second, forwardPointer->second) + 1);
            }
        }

        cout << total << '\n';
    }
    
	
    return 0;
}