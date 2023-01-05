//https://www.acmicpc.net/problem/5573

/*산책 (Platinum 3)
상근이는 바둑판 모양 도로에서 산책을 한다.
출발 지점은 항상 왼쪽 위 끝점(1, 1)이며, 교차로에서 오른쪽 혹은 아래쪽을 택해서,
가장 아래쪽 도로나 가장 오른쪽 도로에 도달하면 그 날 산책이 끝난다.
오른쪽 아래 끝 좌표는 (H + 1, W + 1)

상근이는 매일 질리지 않게 다른 코스로 산책을 하기 위해서, 다음과 같은 규칙으로 산책을 한다.
1. 모든 교차로에 '오', '아' 중 하나로 표기한다.
2. 교차로를 만났을 때 '오'라고 써있으면, 그 글자를 지우고 '아'를 쓴다. 그리고 오른쪽 길을 택한다.
3. 교차로를 만났을 때 '아'라고 써있으면, 그 글자를 지우가 '오'를 쓴다. 그리고 아랫쪽 길을 택한다.

이런 식으로 계속 산책했을 때, N번째 산책 경로가 끝나는 지점을 구하시오.
1 <= H, W <= 1000 이고, N은 최대 1000만이다.

Solution : N이 너무 크기 때문에 브루트 포스로는 풀 수 없고, DP를 이용하면, O(HW)로 풀린다.
DP[h][w] = N-1번 산책했을 때 (h, w)를 지나간 횟수라고 정의하면,
DP[h-1][w], DP[h][w-1]를 가지고 구할 수 있다. 
*/

#include <iostream>
using namespace std;
#define SIZE 1000

bool board[SIZE + 1][SIZE + 1];
int DP[SIZE + 1][SIZE + 1];
int height, width, count;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> height >> width >> count;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            cin >> board[i][j]; //false = Down, true = Right;

    //N-1번 산책의 기록
	DP[0][0] = count - 1;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            DP[i][j + 1] += DP[i][j] / 2;
            DP[i + 1][j] += DP[i][j] / 2;

            if (DP[i][j] % 2)
            {
                if (board[i][j])
                    DP[i][j + 1]++;
                else
                    DP[i + 1][j]++;

                board[i][j] = !board[i][j];
            }
        }

    //N번째 산책
    int y = 0, x = 0;
    while (y != height && x != width)
    {
        if (board[y][x])
            x++;
        else
            y++;
    }

    cout << y + 1 << ' ' << x + 1;
    

	return 0;
}
