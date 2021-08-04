//https://www.acmicpc.net/problem/17501

/*수식 트리

수식 트리는 2N-1개의 노드를 가지며, (N <= 10만)
N-1개의 연산자(자식을 항상 2개 가진 비단말 노드) + 또는 - 와 
N개의 숫자(단말 노드)로 구성되어 있습니다.

수식 트리의 계산은 루트 노드로부터 시작하여 다음과 같이 진행됩니다.

1. 해당 노드의 연산자가 '+' 인 경우, 그 노드를 (왼쪽 노드)+(오른쪽 노드)인 숫자로 바꿉니다.
2. 해당 노드의 연산자가 '-' 인 경우, 그 노드를 (왼쪽 노드)-(오른쪽 노드)인 숫자로 바꿉니다.
만약 자식 노드 역시 연산자이면, 위 과정을 재귀합니다.

이 트리에서, 연산자 노드는 옮기지 못하지만, 숫자 노드는 옮길 수 있습니다.
숫자 노드를 옮겨서 나올 수 있는 수식 트리 계산 결과의 최댓값을 구하세요.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#define NIL -1
using namespace std;
using OpNode = tuple<char, int, int>;

vector<int> numberList;
vector<OpNode> formulaTree;
int minIndex = 0, maxIndex;

int makeMax(int nodeNumber);
int makeMin(int nodeNumber);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int size;
    cin >> size;

    numberList = vector<int>(size);
    formulaTree = vector<OpNode>(size - 1);

    //1. 숫자 노드는 트리에 넣지 않고 배열에 담은 후 그냥 정렬한다.
    for (int i = 0; i < size; i++)
        cin >> numberList[i];
    sort(numberList.begin(), numberList.end());

    maxIndex = size - 1;
    

    
    //2. 연산자 노드만 트리에 넣고 숫자 노드(단말 노드)는 그냥 NIL(없음) 처리한다.
    //그리고 동시에 루트 노드를 찾습니다.
    vector<bool> hasParent(size - 1);
    for (int i = 0; i < size - 1; i++)
    {   
        int& leftLink = get<1>(formulaTree[i]);
        int& rightLink = get<2>(formulaTree[i]);
        cin >> get<0>(formulaTree[i]) >> leftLink >> rightLink;

        
        if (leftLink > size)
        {
            leftLink = leftLink - size - 1;
            hasParent[leftLink] = true;
        } else
            leftLink = NIL;

        if (rightLink > size)
        {
            rightLink = rightLink - size - 1;
            hasParent[rightLink] = true;
        } else
            rightLink = NIL; 
    }

    int rootNode;
    for (int i = 0; i < size - 1; i++)
        if (hasParent[i] == false)
        {
            rootNode = i;
            break;
        }

    int result;
    if (get<0>(formulaTree[rootNode]) == '+')
        result = makeMax(get<1>(formulaTree[rootNode])) + makeMax(get<2>(formulaTree[rootNode]));
    else
        result = makeMax(get<1>(formulaTree[rootNode])) - makeMin(get<2>(formulaTree[rootNode]));

    cout << result;

    
    return 0;
}



int makeMax(int nodeNumber)
{
    if (get<0>(formulaTree[nodeNumber]) == '+')
        return makeMax(get<1>(formulaTree[nodeNumber])) + makeMax(get<2>(formulaTree[nodeNumber]));
    else if (get<0>(formulaTree[nodeNumber]) == '-')
        return makeMax(get<1>(formulaTree[nodeNumber])) - makeMin(get<2>(formulaTree[nodeNumber]));
    else //NIL
        return numberList[maxIndex--];
}


int makeMin(int nodeNumber)
{
    if (get<0>(formulaTree[nodeNumber]) == '+')
        return makeMin(get<1>(formulaTree[nodeNumber])) + makeMin(get<2>(formulaTree[nodeNumber]));
    else if (get<0>(formulaTree[nodeNumber]) == '-')
        return makeMin(get<1>(formulaTree[nodeNumber])) - makeMax(get<2>(formulaTree[nodeNumber]));
    else //NIL
        return numberList[minIndex++];

}