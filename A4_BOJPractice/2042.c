//https://www.acmicpc.net/problem/2042

/* 구간 합 구하기 (Gold 1)
어떤 N개의 수가 주어져 있는데, 중간에 번번히 수의 변경이 일어나는 경우에,
그 중간의 어느 구간의 합을 자주 구해야 하는 환경이다.
수의 개수 N(최대 100만개), 값 변경 횟수 M(최대 10000), 구간 합 구하는 횟수 K(최대 10000)이 주어진다.
그리고 다음 N줄에는 수가 주어지고
그 다음 M+K줄 만큼은 각 줄마다 a, b, c가 주어지는데,
a가 1인 경우 b번째 수를 c로 바꾸고
a가 2인 경우 b~c번째 수의 합을 구하면 된다.
숫자의 순서는 1부터 시작하고, 정답은 +-2^63 이내이다.

*/
#include <stdio.h>
#include <malloc.h>

typedef struct {
	int left;
	int right;
	long long value;
} Node;

int numCount, changeCount, summationCount, treeSize;
long long* numList;

void makeTree(Node tree[], int index);
inline int findLeafIndex(int numIndex);
void modifyValue(Node tree[], int numIndex, long long value);
long long getSummation(Node tree[], int left, int right);



int main(void)
{	
	//팁 : 기본적인 세그먼트 트리 문제이다.

	scanf("%d %d %d", &numCount, &changeCount, &summationCount);
	treeSize = numCount * 2 - 1;

	Node* segmentTree = (Node*)calloc(treeSize + 1, sizeof(Node)); //Root index = 1
	numList = (long long*)malloc(sizeof(long long) * (numCount + 1));
	
	for (int i = 1; i <= numCount; i++)
		scanf("%lld", &numList[i]);

	makeTree(segmentTree, 1);

	int loopCount = changeCount + summationCount;
	while (loopCount--)
	{
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);

		if (a == 1)
		{
			modifyValue(segmentTree, b, c);
		} else if (a == 2) {
			printf("%lld\n", getSummation(segmentTree, b, c));
		}
	}


	free(segmentTree);
	free(numList);

    return 0;
}



void makeTree(Node tree[], int index)
{
	static int NodeNumber = 1;

	if (index < numCount) //현재 index가 비단말 노드인경우,
	{
		//후위 순회하면서 트리 범위 번호를 매기고, 구간 합을 저장한다.
		makeTree(tree, index * 2);
		makeTree(tree, index * 2 + 1);

		tree[index].left = tree[index * 2].left;
		tree[index].right = tree[index * 2 + 1].right;
		tree[index].value = tree[index * 2].value + tree[index * 2 + 1].value;
	} else {
		//단말 노드인 경우, 값을 직접 대입한다.
		tree[index].left = tree[index].right = NodeNumber;
		tree[index].value = numList[NodeNumber];
		NodeNumber++;
	}
}

inline int findLeafIndex(int numIndex)
{
	static int leftestLeafIndex = 0;
	if (leftestLeafIndex == 0)
	{
		for (leftestLeafIndex = 1; leftestLeafIndex < numCount; leftestLeafIndex <<= 1);
	}

	int resultIndex = leftestLeafIndex + numIndex - 1;
	return (resultIndex > treeSize) ? resultIndex - numCount : resultIndex;
}


void modifyValue(Node tree[], int numIndex, long long value)
{
	//O(logN)
	int leafIndex = findLeafIndex(numIndex);
	tree[leafIndex].value = value;

	leafIndex /= 2;
	while (leafIndex != 0)
	{
		tree[leafIndex].value = tree[leafIndex * 2].value + tree[leafIndex * 2 + 1].value;
		leafIndex /= 2;
	}
}

int indexStack[1000];

long long getSummation(Node tree[], int left, int right)
{
	long long result = 0;
	int stackPointer = -1;
	indexStack[++stackPointer] = 1;

	while (stackPointer != -1)
	{
		int indexPop = indexStack[stackPointer--];

		if (left <= tree[indexPop].left && tree[indexPop].right <= right)
			result += tree[indexPop].value;
		else
		{
			if (left <= tree[indexPop * 2].right)
				indexStack[++stackPointer] = indexPop * 2;
			if (tree[indexPop * 2 + 1].left <= right)
				indexStack[++stackPointer] = indexPop * 2 + 1;
		}


	}


	return result;
}

/*
노드 - 단말노드
1 - 1
2 - 1
3 - 2 V
4 - 2
5 - 3 V
7 - 4 V
9 - 5 V
(이 경우 리프 인덱스 매칭)
1 - 8
2 - 9
3 - 5
4 - 6
5 - 7

fnd Tree    <-------------->
sub Tree    <------->                -> 1
		  <----->
           <--------------------|--------------------->

*/