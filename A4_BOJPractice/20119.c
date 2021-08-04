//https://www.acmicpc.net/problem/20119

/*클레어와 물약

세상에는 N종류의 물약이 있고, 클레어는 M개의 물약을 가지고 있다.
물약 레시피가 주어질 때, 클레어가 만들 수 있는 물약을 모두 구하시오.

클레어가 가지고 있는 물약은 무한하다고 가정합니다.
(M, N은 최대 20만, 레시피에 포함되는 물약의 수는 40만을 넘지 않음)
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct {
    int* recipeList;
    int size;
    int maxSize;
    bool used;
} Potion;

int main(void)
{
    int worldPotions, recipeCount;
    scanf("%d %d", &worldPotions, &recipeCount);

    int index;
    Potion* potionToRecipeList = (Potion*)malloc(sizeof(Potion) * (worldPotions + 1));
    for (int i = 1; i <= worldPotions; i++)
    {
        potionToRecipeList[i].maxSize = 4;
        potionToRecipeList[i].size = 0;
        potionToRecipeList[i].recipeList = (int*)malloc(sizeof(int) * 4);
        potionToRecipeList[i].used = false;
    }

    int* recipe_potionNeeded = (int*)malloc(sizeof(int) * (recipeCount + 1));
    int* recipeResult = (int*)malloc(sizeof(int) * (recipeCount + 1));


    for (int recipeNumber = 1; recipeNumber <= recipeCount; recipeNumber++)
    {
        scanf("%d", &recipe_potionNeeded[recipeNumber]);

        for (int j = 0; j < recipe_potionNeeded[recipeNumber]; j++)
        {
            scanf("%d", &index);
            Potion* nowPotion = &potionToRecipeList[index];

            if (nowPotion->size == nowPotion->maxSize)
            {
                nowPotion->maxSize *= 2;
                nowPotion->recipeList = (int*)realloc(nowPotion->recipeList, sizeof(int) * nowPotion->maxSize);
            }
            nowPotion->recipeList[(nowPotion->size)++] = recipeNumber;   
        }

        scanf("%d", &recipeResult[recipeNumber]);
    }

    
    int clarePotionCount;
    scanf("%d", &clarePotionCount);

    int bfsQueue[200000];
    int front = 0, rear = 0;

    for (int i = 0; i < clarePotionCount; i++)
    {
        scanf("%d", &index);
        bfsQueue[rear++] = index;
        potionToRecipeList[index].used = true;
    }

    while (front != rear)
    {
        const Potion* nowPotion = &potionToRecipeList[bfsQueue[front++]]; //queue pop

        for (int i = 0; i < nowPotion->size; i++)
        {
            if (--recipe_potionNeeded[nowPotion->recipeList[i]] == 0 &&
                potionToRecipeList[recipeResult[nowPotion->recipeList[i]]].used == false)
            {
                bfsQueue[rear++] = recipeResult[nowPotion->recipeList[i]];
                potionToRecipeList[recipeResult[nowPotion->recipeList[i]]].used = true;
            }
        }
    }

    int cnt = 0;
    for (int potionNum = 1; potionNum <= worldPotions; potionNum++)
        if (potionToRecipeList[potionNum].used == true)
            cnt++;

    printf("%d\n", cnt);
    
    for (int potionNum = 1; potionNum <= worldPotions; potionNum++)
        if (potionToRecipeList[potionNum].used == true)
            printf("%d ", potionNum);

    for (int i = 1; i <= recipeCount; i++)
        free(potionToRecipeList[i].recipeList);
    free(potionToRecipeList);
    free(recipe_potionNeeded);
    free(recipeResult);

    return 0;
}