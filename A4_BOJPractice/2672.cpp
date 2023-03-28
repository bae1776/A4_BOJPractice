//https://www.acmicpc.net/problem/2672

/*여러 직사각형의 전체 면적 구하기 (Gold 2)

Solution : 정렬하고 x 증가 순서로 합성된 사각형 넓이 구하기
포함-배제로 풀기는 너무 복잡한 문제이다.
각 직사각형의 시작 x, 끝 x를 구한뒤 이들을 x 증가하는 순서로 정렬하고
이 순서대로 넓이를 계산하는 방법이 더 쉽다.
*/

#include <iostream>
#include <iomanip>
#include <set>
using namespace std;


set<pair<int, int>> xList, yIncludeList; //coordinate, index
bool included[30], yIncluded[30];
pair<int, int> squareY[30];
int includedCount, yIncludedCount;
long long result;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int squareCount;
    cin >> squareCount;

    for (int i = 0; i < squareCount; i++)
    {
        double input[4]; //startX, startY, width, height;
        cin >> input[0] >> input[1] >> input[2] >> input[3];

        int conv[4];
        for (int i = 0; i < 4; i++)
            conv[i] = input[i] * 10;
        
        xList.emplace(conv[0], i);
        xList.emplace(conv[0] + conv[2], i);
        squareY[i] = {conv[1], conv[1] + conv[3]};
    }

    int leftX = xList.begin()->first;
    int height = 0;
    for (auto nextX = xList.begin(); nextX != xList.end(); ++nextX)
    {
        int rightX = nextX->first;

        //넓이 추가
        result += (rightX - leftX) * height;

        if (included[nextX->second] == true)
        {
            //현재 X에서 끝나는 사각형 제거
            yIncludeList.erase(make_pair(squareY[nextX->second].first, nextX->second));
            yIncludeList.erase(make_pair(squareY[nextX->second].second, nextX->second));
            includedCount--;
        } else {
            //현재 X에서 시작하는 사각형 추가
            yIncludeList.emplace(squareY[nextX->second].first, nextX->second);
            yIncludeList.emplace(squareY[nextX->second].second, nextX->second);
            includedCount++;
        }

        included[nextX->second] = !included[nextX->second];


        //부분 사각형의 높이 구하기 (포함된 사각형이 없는 경우 for문이 동작하지 않음)
        height = 0;
        int downY;
        for (auto nextY = yIncludeList.begin(); nextY != yIncludeList.end(); ++nextY)
        {
            if (yIncluded[nextY->second] == true)
            {
                yIncludedCount--;
                if (yIncludedCount == 0)
                    height += nextY->first - downY;

            } else {
                if (yIncludedCount == 0)
                    downY = nextY->first;
                yIncludedCount++;
            }
            yIncluded[nextY->second] = !yIncluded[nextY->second];
        }
        
        leftX = rightX;
    }

    cout << result / 100;
    if (result % 100)
        cout << '.' << setfill('0') << setw(2) << result % 100;

	return 0;
}