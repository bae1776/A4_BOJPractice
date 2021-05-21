//https://www.acmicpc.net/problem/14681

/*사분면 고르기
점의 좌표가 주어질 때, 평면 좌표계 상에 몇 사분면에 속하는 지 구하시오.
점이 x축 또는 y축 위에 있는 경우는 주어지지 않는다.
*/

#include <stdio.h>

int main(void)
{
    int x, y;
    
    scanf("%d %d", &x, &y);

    if (x > 0)
        if (y > 0)
            printf("1");
        else
            printf("4");
    else
        if (y > 0)
            printf("2");
        else
            printf("3");
            
	return 0;
}