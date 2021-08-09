//https://www.acmicpc.net/problem/7569

/*토마토
(3차원 버전)

토마토가 창고에 격자칸으로 나누어져 있는 상자에 담겨, 층층이 쌓여있다.
창고에 있는 토마토들 중에서 잘 익은 것도 있지만, 그렇지 않은 것들도 있다.

하루가 지나면, 익은 토마토들의 인접한 곳에 있는 덜 익은 토마토들이 다 익게 된다.
하나의 토마토에 인접한곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향의 토마토들을 의미한다.

철수는 창고에 있는 토마토들이 며칠이 지나야 다 익게 되는지 알고 싶다.
이를 찾는 프로그램을 작성하자.
이미 상자에 있는 토마토들이 모두 익은 상태라면 0,
아무리 시간이 지나도 익지 않는 토마토가 있다면, -1을 출력하자.

(상자의 크기는 최대 100 * 100이고 100층까지 쌓을 수 있다.)

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using vector3D = vector<vector<vector<char>>>;

struct Data {
    short x, y, z;

    Data(short x, short y, short z) : x(x), y(y), z(z) {};
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int width, depth, height;
    cin >> width >> depth >> height;
    
    vector3D tomatoes = vector3D(height, vector<vector<char>>(depth, vector<char>(width)));

    int num;
    int unripenCount = 0;
    queue<Data> bfsQueue;
    for (int z = 0; z < height; z++)
        for (int y = 0; y < depth; y++)
            for (int x = 0; x < width; x++)
            {
                cin >> num;
                switch (num)
                {
                    case -1:
                        tomatoes[z][y][x] = 'X';
                        break;
                    
                    case 0:
                        tomatoes[z][y][x] = 'N';
                        unripenCount++;
                        break;
                    
                    case 1:
                        tomatoes[z][y][x] = 'Y';
                        bfsQueue.emplace(x, y, z);
                        break;
                }
            }
    
    int result = -1;

    while (bfsQueue.empty() == false)
    {
        int repeat = bfsQueue.size();
        result++;

        for (int i = 0; i < repeat; i++)
        {
            Data nowBlock = bfsQueue.front();
            bfsQueue.pop();

            if (nowBlock.x != 0 && tomatoes[nowBlock.z][nowBlock.y][nowBlock.x - 1] == 'N')
            {
                tomatoes[nowBlock.z][nowBlock.y][nowBlock.x - 1] = 'Y';
                bfsQueue.emplace(nowBlock.x - 1, nowBlock.y, nowBlock.z);
                unripenCount--;
            }

            if (nowBlock.y != 0 && tomatoes[nowBlock.z][nowBlock.y - 1][nowBlock.x] == 'N')
            {
                tomatoes[nowBlock.z][nowBlock.y - 1][nowBlock.x] = 'Y';
                bfsQueue.emplace(nowBlock.x, nowBlock.y - 1, nowBlock.z);
                unripenCount--;
            }

            if (nowBlock.z != 0 && tomatoes[nowBlock.z - 1][nowBlock.y][nowBlock.x] == 'N')
            {
                tomatoes[nowBlock.z - 1][nowBlock.y][nowBlock.x] = 'Y';
                bfsQueue.emplace(nowBlock.x, nowBlock.y, nowBlock.z - 1);
                unripenCount--;
            }

            if (nowBlock.x < width-1 && tomatoes[nowBlock.z][nowBlock.y][nowBlock.x + 1] == 'N')
            {
                tomatoes[nowBlock.z][nowBlock.y][nowBlock.x + 1] = 'Y';
                bfsQueue.emplace(nowBlock.x + 1, nowBlock.y, nowBlock.z);
                unripenCount--;
            }

            if (nowBlock.y < depth-1 && tomatoes[nowBlock.z][nowBlock.y + 1][nowBlock.x] == 'N')
            {
                tomatoes[nowBlock.z][nowBlock.y + 1][nowBlock.x] = 'Y';
                bfsQueue.emplace(nowBlock.x, nowBlock.y + 1, nowBlock.z);
                unripenCount--;
            }

            if (nowBlock.z < height-1 && tomatoes[nowBlock.z + 1][nowBlock.y][nowBlock.x] == 'N')
            {
                tomatoes[nowBlock.z + 1][nowBlock.y][nowBlock.x] = 'Y';
                bfsQueue.emplace(nowBlock.x, nowBlock.y, nowBlock.z + 1);
                unripenCount--;
            }
        }
    }

    if (unripenCount != 0)
        cout << "-1";
    else
        cout << result;
    

	
	return 0;
}