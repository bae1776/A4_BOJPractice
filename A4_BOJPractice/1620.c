//https://www.acmicpc.net/problem/1620

/*나는야 포켓몬 마스터 이다솜 (Sliver 4)

포켓몬 도감을 조회하는 프로그램을 만들어보자.
포켓몬의 수(최대 10만)과 질의 개수가(최대 10만) 주어진다.
그리고 2~20글자의 영어로 된 각 포켓몬의 이름이 주어지는데, 주어진 순서대로 1번부터 번호를 매긴다.
이후, 번호로 질의하면, 포켓몬 이름. 포켓몬 이름으로 질의하면 번호를 출력하는 프로그램을 작성하시오.

Solution : 
포켓몬 번호에서 영문명을 구하는 것은 그냥 배열로,
포켓몬 영문명에서 포켓몬 번호를 구할 때는 동적 해싱(트라이)을 이용하였는데, 각 노드에 대해 최대 3개까지는 선형 저장되도록 하였다. (지나치게 많은 노드 할당으로 인한 메모리 낭비 방지)
같은 노드에 4번째 원소(포켓몬 번호)가 들어오면 알파벳 26개 해시 테이블이 이용되어 확장된다.

이론상 삽입, 탐색의 시간복잡도는 O(문자열최대길이 + 3)이다.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashNode {
	int value[3];
	int count;
	struct HashNode* pointerList[26];
} HashNode;
HashNode* root = NULL;
char pokemonNumberList[100001][21];
int pokemonNameLength[100001];


void insertHash(int number);
void reHash(HashNode** nodePointer, int depth);
int findHash(char* str, int len);
void clearHash(HashNode* nodePointer);

int main(void)
{
	int pokemonCount, queryCount;
	scanf("%d %d", &pokemonCount, &queryCount);

	for (int i = 1; i <= pokemonCount; i++)
	{
		scanf("%s", pokemonNumberList[i]);
		pokemonNumberList[i][0] = pokemonNumberList[i][0] - 'A' + 'a';
		pokemonNameLength[i] = strlen(pokemonNumberList[i]);
		insertHash(i);
	}

	char input[21];
	while (queryCount--)
	{
		scanf("%s", input);

		int num = atoi(input);

		if (num)
		{
			pokemonNumberList[num][0] = pokemonNumberList[num][0] - 'a' + 'A';
			printf("%s\n", pokemonNumberList[num]);
			pokemonNumberList[num][0] = pokemonNumberList[num][0] - 'A' + 'a';
		}
		else
		{
			input[0] = input[0] - 'A' + 'a';
			printf("%d\n", findHash(input, strlen(input)));
		}
	}

	if (root)
		clearHash(root);


	return 0;
}


void insertHash(int number)
{
	HashNode** hashPointer = &root;

	if (root == NULL)
	{
		root = (HashNode*)calloc(1, sizeof(HashNode));
		root->value[root->count++] = number;
		return;
	}

	int strIndex = 0;
	for (; strIndex < pokemonNameLength[number]; strIndex++)
	{
		char nowCh = pokemonNumberList[number][strIndex];
		if ((*hashPointer)->pointerList[nowCh - 'a'])
		{
			hashPointer = &((*hashPointer)->pointerList[nowCh - 'a']);
			continue;
		}
		else {
			break;
		}
	}

	if ((*hashPointer)->count == 3)
	{
		reHash(hashPointer, strIndex);
		insertHash(number);
	}
	else {
		(*hashPointer)->value[(*hashPointer)->count++] = number;
	}

}

void reHash(HashNode** nodePointer, int depth)
{
	int self = -1;
	for (int valIndex = 0; valIndex < 3; valIndex++)
	{
		int nowValue = (*nodePointer)->value[valIndex];
		char nowCh = pokemonNumberList[nowValue][depth];

		if (nowCh == '\0')
		{
			self = valIndex;
		}
		else {
			HashNode** deeperPointer = &((*nodePointer)->pointerList[nowCh - 'a']);
			if (*deeperPointer)
			{
				if ((*deeperPointer)->count == 3)
					reHash(deeperPointer, depth + 1);
				(*deeperPointer)->value[(*deeperPointer)->count++] = nowValue;
			}
			else {
				*deeperPointer = (HashNode*)calloc(1, sizeof(HashNode));
				(*deeperPointer)->value[(*deeperPointer)->count++] = nowValue;
			}
		}
	}

	if (self != -1)
	{
		(*nodePointer)->count = 1;
		(*nodePointer)->value[0] = (*nodePointer)->value[self];
	}
	else {
		(*nodePointer)->count = 0;
	}
}


int findHash(char* str, int len)
{
	HashNode* nowNode = root;

	for (int i = 0; i < len; i++)
	{
		if (nowNode->pointerList[str[i] - 'a'])
			nowNode = nowNode->pointerList[str[i] - 'a'];
		else
			break;
	}

	for (int i = 0; i < nowNode->count; i++)
	{
		if (!strcmp(str, pokemonNumberList[nowNode->value[i]]))
			return nowNode->value[i];
	}

	return -1;
}

void clearHash(HashNode* nodePointer)
{
	for (int i = 0; i < 26; i++)
	{
		if (nodePointer->pointerList[i] != NULL)
			clearHash(nodePointer->pointerList[i]);
	}
	free(nodePointer);
}