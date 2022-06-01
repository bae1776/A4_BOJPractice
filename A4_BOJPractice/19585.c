#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#define NOTFOUND -1

typedef char mSize;

typedef struct Heap {
    char key; 
    struct Trie* children;
} Heap;

typedef struct Trie {
    bool self;
    mSize heapMaxSize;
    Heap* childrenHeap;
} Trie;


char input[2003], check[2003];

void Trie_insert(Trie* trie, char* string, bool reversed);
void Trie_search(Trie* trie, char* string, bool reversed);
void Heap_insert(Trie* heapOwner, char chKey, Trie* Trievalue);
mSize Heap_indexsearch(Trie* heapOwner, char chKey);


int main(void)
{
    int colorCount, nicknameCount;
    scanf("%d %d", &colorCount, &nicknameCount);
    
    Trie* colorTrie = (Trie*)calloc(1, sizeof(Trie));
    Trie* nicknameTrie = (Trie*)calloc(1, sizeof(Trie));
    
    for (int i = 0; i < colorCount; i++)
    {
        scanf("%s", input);
        Trie_insert(colorTrie, input, false);
    }

    for (int i = 0; i < nicknameCount; i++)
    {
        scanf("%s", input);
        Trie_insert(nicknameTrie, input, true);
    }

    int teamCount;
    scanf("%d", &teamCount);

    for (int i = 0; i < teamCount; i++)
    {
        scanf("%s", input);
        int len = strlen(input);
        for (int j = 0; j <= len; j++)
            check[j] = 0;

        Trie_search(colorTrie, input, false);
        Trie_search(nicknameTrie, input, true);

        bool isLegend = false;

        for (int j = 0; j <= len; j++)
        {
            if (check[j] == 2)
            {
                isLegend = true;
                break;
            }
        }

        if (isLegend)
            printf("Yes\n");
        else
            printf("No\n");


    }



    return 0;
}


void Trie_insert(Trie* trie, char* string, bool reversed)
{
    if (reversed)
    {
        int len = strlen(string);
        for (int index = len - 1; index >= 0; index--)
        {
            mSize heapIndex;
            if ((heapIndex = Heap_indexsearch(trie, string[index])) == NOTFOUND)
            {
                Heap_insert(trie, string[index], (Trie*)calloc(1, sizeof(Trie)));
                heapIndex = trie->childrenHeap[0].key;
            }

            trie = trie->childrenHeap[heapIndex].children;
        }
    } else {
        for (int index = 0; string[index] != NULL; index++)
        {
            mSize heapIndex;
            if ((heapIndex = Heap_indexsearch(trie, string[index])) == NOTFOUND)
            {
                Heap_insert(trie, string[index], (Trie*)calloc(1, sizeof(Trie)));
                heapIndex = trie->childrenHeap[0].key;
            }

            trie = trie->childrenHeap[heapIndex].children;
        }
    }
    trie->self = true;
    return;
}


void Trie_search(Trie* trie, char* string, bool reversed)
{

    if (reversed)
    {
        int len = strlen(string);
        for (int index = len - 1; index >= 0; index--)
        {
            mSize heapIndex;
            if ((heapIndex = Heap_indexsearch(trie, string[index])) == NOTFOUND)
                return;

            trie = trie->childrenHeap[heapIndex].children;

            if (trie->self == true)
                check[index]++;
            
        }
    } else {
        for (int index = 0; string[index] != NULL; index++)
        {
            mSize heapIndex;
            if ((heapIndex = Heap_indexsearch(trie, string[index])) == NOTFOUND)
                return;

            trie = trie->childrenHeap[heapIndex].children;

            if (trie->self == true)
                check[index + 1]++;
            
        }
    }

}


void Heap_insert(Trie* heapOwner, char chKey, Trie* Trievalue)
{
    if (heapOwner->heapMaxSize == 0)
    {
        heapOwner->childrenHeap = (Heap*)calloc(4, sizeof(Heap));
        heapOwner->heapMaxSize = 4;
    } 
    else if (heapOwner->childrenHeap[0].key == heapOwner->heapMaxSize - 1)
    {
        heapOwner->heapMaxSize *= 2;
        heapOwner->childrenHeap = (Heap*)realloc(heapOwner->childrenHeap, sizeof(Heap) * heapOwner->heapMaxSize);
    }

    Heap* heap = heapOwner->childrenHeap;
    mSize newElementIndex = ++(heap[0].key);

    heap[newElementIndex].key = chKey;
    heap[newElementIndex].children = Trievalue;
}

mSize Heap_indexsearch(Trie* heapOwner, char chKey)
{
    if (heapOwner->heapMaxSize == 0)
        return NOTFOUND;

    Heap* heap = heapOwner->childrenHeap;
    mSize left = 1, right = heap[0].key;

    for (; left <= right; left++)
    {
        if (heap[left].key == chKey)
            return left;
    }

    return NOTFOUND;
}