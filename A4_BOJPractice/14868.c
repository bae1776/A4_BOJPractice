#include <stdio.h>

typedef struct {
    int y, x;
} Element;

int mergeCount = 0;

int civilizationUnionFind[100010];
int civilizationRank[100010];
int worldmap[2000][2000];
Element civilizationBFS[4000010];
int front = 0, rear = 0;

void union_merge(int a, int b);
int union_find(const int a);

int main(void)
{
    int mapSize, civilizationCount;
    scanf("%d %d", &mapSize, &civilizationCount);

    for (int i = 1; i <= civilizationCount; i++)
        civilizationUnionFind[i] = i;
    
    
    for (int civilNumber = 1; civilNumber <= civilizationCount; ++civilNumber)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        worldmap[y - 1][x - 1] = civilNumber;
        civilizationBFS[rear].y = y - 1;
        civilizationBFS[rear++].x = x - 1;
    }

    int year = 0;

    while (1)
    {
        int loopCount = rear - front;

        //1. 문명 통합 확인
        for (int i = 0; i < loopCount; i++)
        {
            Element borderCoord = civilizationBFS[front + i];
            int borderCivil = worldmap[borderCoord.y][borderCoord.x];

            if (borderCoord.y != 0 && worldmap[borderCoord.y - 1][borderCoord.x] != 0)
                union_merge(borderCivil, worldmap[borderCoord.y - 1][borderCoord.x]);
            
            if (borderCoord.y != mapSize - 1 && worldmap[borderCoord.y + 1][borderCoord.x] != 0)
                union_merge(borderCivil, worldmap[borderCoord.y + 1][borderCoord.x]);
            
            if (borderCoord.x != 0 && worldmap[borderCoord.y][borderCoord.x - 1] != 0)
                union_merge(borderCivil, worldmap[borderCoord.y][borderCoord.x - 1]);
            
            if (borderCoord.x != mapSize - 1 && worldmap[borderCoord.y][borderCoord.x + 1] != 0)
                union_merge(borderCivil, worldmap[borderCoord.y][borderCoord.x + 1]);
        }

        if (mergeCount == civilizationCount - 1)
            break;

        year++;

        //2. 문명 확장
        while (loopCount--)
        {
            Element borderCoord = civilizationBFS[front++];
            int borderCivil = worldmap[borderCoord.y][borderCoord.x];
            
            if (borderCoord.y != 0 && worldmap[borderCoord.y - 1][borderCoord.x] == 0)
            {
                worldmap[borderCoord.y - 1][borderCoord.x] = borderCivil;
                civilizationBFS[rear].y = borderCoord.y - 1;
                civilizationBFS[rear++].x = borderCoord.x;
            }
            
            if (borderCoord.y != mapSize - 1 && worldmap[borderCoord.y + 1][borderCoord.x] == 0)
            {
                worldmap[borderCoord.y + 1][borderCoord.x] = borderCivil;
                civilizationBFS[rear].y = borderCoord.y + 1;
                civilizationBFS[rear++].x = borderCoord.x;
            }
            
            if (borderCoord.x != 0 && worldmap[borderCoord.y][borderCoord.x - 1] == 0)
            {
                worldmap[borderCoord.y][borderCoord.x - 1] = borderCivil;
                civilizationBFS[rear].y = borderCoord.y;
                civilizationBFS[rear++].x = borderCoord.x - 1;
            }
            
            if (borderCoord.x != mapSize - 1 && worldmap[borderCoord.y][borderCoord.x + 1] == 0)
            {
                worldmap[borderCoord.y][borderCoord.x + 1] = borderCivil;
                civilizationBFS[rear].y = borderCoord.y;
                civilizationBFS[rear++].x = borderCoord.x + 1;
            }

        }

    }
    printf("%d", year);
    
	
	return 0;
}



void union_merge(int a, int b)
{
    int parentA = union_find(a), parentB = union_find(b);
    if (parentA == parentB)
        return;

    mergeCount++;

    if (civilizationRank[parentA] < civilizationRank[parentB])
    {
        civilizationUnionFind[parentA] = parentB;
    } else {
        civilizationUnionFind[parentB] = parentA;
        if (civilizationRank[parentA] == civilizationRank[parentB]);
            civilizationRank[parentA]++;
    }

}

int union_find(const int a)
{
    if (civilizationUnionFind[a] == a)
        return a;
    else
        return civilizationUnionFind[a] = union_find(civilizationUnionFind[a]);
}