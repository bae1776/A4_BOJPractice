//https://www.acmicpc.net/problem/15898

/* 피아의 아틀리에 ~신비한 대회의 연금술사~ (Gold 1)

Solution : 구현 (브루트포스)
최대 10개의 재료 중 순서 있게 3개를 고르는 경우의 수 720개 *
고른 3개의 재료를 가마에 어떻게 넣을 지 정하는 경우의 수 16개 ^ 3 *
품질 계산 25.
7200만으로 충분히 시간 내에 풀 수 있다. 
*/


#include <iostream>
#include <array>
using namespace std;
using Block = pair<int, char>;

Block plate[5][5];
Block mList[40][4][4];
int selected[3];
int getBestOf3Meterial(int depth);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int materialCount;
    cin >> materialCount;

    for (int num = 0; num < materialCount * 4; num += 4)
    {
        auto& now = mList[num];

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> now[i][j].first;

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> now[i][j].second;

        for (int rotate = 1; rotate < 4; rotate++)
        {
            for (int a = 0; a < 4; a++)
                for (int b = 0; b < 4; b++)
                    mList[num + rotate][a][b] = mList[num + rotate - 1][3-b][a];
        }
    }

    int answer = 0;
    for (selected[0] = 0; selected[0] < materialCount; selected[0]++)
    {
        for (selected[1] = 0; selected[1] < materialCount; selected[1]++)
        {
            if (selected[0] == selected[1])
                continue;
            for (selected[2] = 0; selected[2] < materialCount; selected[2]++)
            {
                if (selected[0] == selected[2] || selected[1] == selected[2])
                    continue;

                answer = max(answer, getBestOf3Meterial(0));
            }
        }
    }

    cout << answer;

	return 0;
}

bool order[3] = {true};
int getBestOf3Meterial(int depth)
{
    if (depth == 3)
    {
        int result = 0;


        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
            {
                switch (plate[i][j].second)
                {
                    case 'W': case '\0':
                        break;
                    case 'R':
                        result += 7 * plate[i][j].first; break;
                    case 'B':
                        result += 5 * plate[i][j].first; break;
                    case 'G':
                        result += 3 * plate[i][j].first; break;
                    case 'Y':
                        result += 2 * plate[i][j].first; break;
                }
            }

        
        return result;

    } else {
        int result = 0;
        Block before[5][5];
        for (int a = 0; a < 5; a++)
            for (int b = 0; b < 5; b++)
                before[a][b] = plate[a][b];
            
        for (int rotate = 0; rotate < 4; rotate++)
        {
            const Block (&select)[4][4] = mList[selected[depth] * 4 + rotate];
            for (int y = 0; y < 2; y++)
                for (int x = 0; x < 2; x++)
                {

                    for (int i = 0; i < 4; i++)
                        for (int j = 0; j < 4; j++)
                        {
                            plate[y + i][x + j].first += select[i][j].first;
                            if (plate[y + i][x + j].first > 9)
                                plate[y + i][x + j].first = 9;
                            else if (plate[y + i][x + j].first < 0)
                                plate[y + i][x + j].first = 0;
                        
                            if (select[i][j].second != 'W')
                                plate[y + i][x + j].second = select[i][j].second;
                        }

            
                    result = max(result, getBestOf3Meterial(depth + 1));

                    for (int a = 0; a < 5; a++)
                        for (int b = 0; b < 5; b++)
                            plate[a][b] = before[a][b];
                }
        }

        return result;
    }
}

