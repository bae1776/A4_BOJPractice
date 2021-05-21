//https://www.acmicpc.net/problem/13301

//타일 장식물

#include <stdio.h>
long long DP[81] = {1, 1,};

int main(void)
{
    int tile;
    scanf("%d", &tile);

    for (int i = 2; i < tile; i++)
        DP[i] = DP[i-2] + DP[i-1];

    if (tile == 1)
        printf("4");
    else
        printf("%lld", DP[tile - 1] * 4 + DP[tile - 2] * 2);
    
    
    return 0;
}
