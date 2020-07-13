//https://www.acmicpc.net/problem/2331

//반복 수열

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TABLESIZE 1000

typedef struct _elem {
	int num;
	int order;
} Element;

int startNumber, powScale;
Element hashTable[TABLESIZE];

int powFunction(int num);
void hashPut(int num, int order);
int hashFind(int num); //return order or 0


int main(void)
{
	scanf("%d %d", &startNumber, &powScale);

	int result;
	int order = 1;
	int now_num = startNumber;

	while ((result = hashFind(now_num)) == 0)
	{
		hashPut(now_num, order);
		now_num = powFunction(now_num);
		order++;
	}

	printf("%d", result - 1);

	return 0;
}


int powFunction(int num)
{
	int result = 0;
	while (num != 0)
	{
		int val = 1;
		int bottom = num % 10;
		num /= 10;
		for (int addCount = 1; addCount <= powScale; addCount++)
			val *= bottom;
		result += val;
	}

	return result;
}

void hashPut(int num, int order)
{
	int hashKey = num % TABLESIZE;
	if (hashTable[hashKey].num == 0)
	{
		hashTable[hashKey].num = num;
		hashTable[hashKey].order = order;
		return;
	}
	else {
		int moveBase = 1;
		while (1) {
			int move = moveBase * moveBase;
			Element* tablePtr = &hashTable[(hashKey + move) % TABLESIZE];

			if (tablePtr->num == 0)
			{
				tablePtr->num = num;
				tablePtr->order = order;
				return;
			}
			else {
				moveBase++;
			}
		}
	}
}


int hashFind(int num)
{
	int moveBase = 0;
	int hashKey = num % TABLESIZE;
	while (1)
	{
		int move = moveBase * moveBase;
		Element* tablePtr = &hashTable[(hashKey + move) % TABLESIZE];
		if (tablePtr->num == num)
			return tablePtr->order;
		else if (tablePtr->num == 0)
			return 0;
		else
			moveBase++;
	}
}