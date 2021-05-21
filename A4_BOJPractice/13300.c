//https://www.acmicpc.net/problem/13300

//방 배정
//학생 수와 한 방에 배정할 수 있는 최대 인원 수가 주어지고
//각 학생의 학년과 성별 데이터가 주어진다.
//한 방에는 같은 학년의 같은 성별 학생만 배정할 수 있을때, 필요한 방의 최소 개수를 구하시오.

#include <stdio.h>

int DP[6][2];


int main(void)
{
	int studentCount, roomMax;
    scanf("%d %d", &studentCount, &roomMax);

    for (int i = 0; i < studentCount; i++)
    {
        int gender, grade;
        scanf("%d %d", &gender, &grade);

        DP[grade - 1][gender]++;
    }

    int result = 0;

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 2; j++)
        {
            result += DP[i][j] / roomMax;
            if (DP[i][j] % roomMax != 0)
                result++;
        }

    printf("%d", result);


	return 0;
}
