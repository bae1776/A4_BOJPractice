//https://www.acmicpc.net/problem/15656

/*N과 M (7) (Silver 3)
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
1. N개의 자연수 중에서 M개를 고른 수열
2. 같은 수를 여러 번 골라도 된다.

1 <= M <= N <= 7이며 각 자연수는 10000 이하의 서로 다른 수이다.
출력 시에는 사전 순 증가하는 순서로 출력한다.
*/

#include <stdio.h>

int arr[7], dictOrder[7];

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);

        //버블 소트 (오름 차순)
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } else {
                break;
            }
        }
    }

    while (dictOrder[0] != N)
    {
        for (int i = 0; i < M; i++)
            printf("%d ", arr[dictOrder[i]]);
        printf("\n");

        int index = M - 1;
        dictOrder[index]++;
        while (dictOrder[index] == N)
        {
            dictOrder[index--] = 0;
            if (index == -1) break;
            dictOrder[index]++;
        }
        if (index == -1) break;
    }
    

	return 0;
}