//https://www.acmicpc.net/problem/1708

/*볼록 껍질 (Platinum 5)

2차원 평면에 N개의 점이 주어졌을 때, 이들 중 몇 개의 점을 골라 볼록 다각형을 만들면,
나머지 모든 점을 내부에 포함하도록 할 수 있다. 이를 볼록 껍질(CONVEX HULL)이라 한다.

점의 집합이 주어졌을 때, 볼록 껍질을 이루는 점의 개수를 구하는 프로그램을 작성하여라.
모든 점이 한 직선 위에 있는 Trivial 한 경우는 고려하지 않으며, 볼록 껍질의 변에 점이 여러 개 있는 경우 가장 양 끝 점만 개수에 포함한다.
점은 최대 10만개이다.

Solution : 전형적인 컨벡스 헐 알고리즘 문제로, 여러가지 알고리즘으로 풀 수 있다.
그라함 스캔(Graham's Scan) 이라는 알고리즘을 이용해보자. 점 개수 N에 대해 O(NlogN)에 풀 수 있다.

 - 그라함 스캔 알고리즘.
 1. 점 리스트들에서, 기준점을 하나 정해 맨 앞으로 옮깁니다. (보통 x 또는 y 좌표가 가장 작은 점)
 2. 반시계 방향으로 정렬합니다.
    ccw(p[0](기준점), a, b)가 양수(좌회전)일 때, a, b 순서로 정렬되도록 정렬 함수를 정의합니다.
    음수이면 b, a 순서로 정렬되고, 0(직선 상)이면 기준점과의 거리가 짧은 순으로 정렬됩니다.
 3. stack에 먼저 1, 2번 점을 넣고 다음과 같은 과정을 따릅니다.
  a. stack 최상단에 있는 두 점을, 넣은 순서대로 first, second라고 하자.
     이때 다음 i번째 점이 위 두 점을 이은 선분의 왼쪽, 즉, ccw(first, second, i) > 0 이면
     stack에 추가합니다. i를 1 더하고 3 과정을 반복합니다.
  b. 그렇지 않은 경우 stack을 한 번 pop하고 다시 i번째 점에 대해 3 과정을 반복합니다. (first, second가 바뀌어 있음)
 4. 3 과정을 모든 점에 대해 마치면, 
    stack에 있는 점들은 모두 볼록 껍질을 이루는 점이며, stack.size()는 볼록 껍질의 꼭짓점의 개수입니다.
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using Point = pair<long long, long long>;

vector<Point> grahamConvexHull(vector<Point> pointList); 

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int pointCount;
    cin >> pointCount;

    vector<Point> pointList(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> pointList[i].first >> pointList[i].second;

    cout << grahamConvexHull(pointList).size();

    return 0;
}


vector<Point> grahamConvexHull(vector<Point> pointList)
{
    auto ccw = [](const Point& a, const Point& b, const Point& c) -> long long {
        return a.first * b.second + b.first * c.second + c.first * a.second 
             - b.first * a.second - c.first * b.second - a.first * c.second;
    };

    //1. 기준점 설정 (x좌표 제일 작은 점) 
    sort(pointList.begin(), pointList.end());

    //2. 반시계 방향 정렬
    sort(pointList.begin() + 1, pointList.end(), 
    [&](const Point& a, const Point& b) -> bool {
        long long rotate = ccw(pointList[0], a, b);
        if (rotate == 0) //세 점이 모두 직선 상에 있는 경우, 거리 낮은 순
            if (abs(pointList[0].first - a.first) == abs(pointList[0].first - b.first))
                return abs(pointList[0].second - a.second) < abs(pointList[0].second - b.second);
            else
                return abs(pointList[0].first - a.first) < abs(pointList[0].first - b.first);

        return rotate > 0; 
    });

    vector<Point> result;
    result.push_back(pointList[0]);
    result.push_back(pointList[1]);
    
    //3. 스택
    for (int pointIndex = 2; pointIndex < pointList.size(); pointIndex++)
    {
        const auto& next = pointList[pointIndex];
        while (result.size() >= 2 && 
            ccw(result[result.size() - 2], result[result.size() - 1], next) <= 0)
        {              /* = first */             /* = second */
            result.pop_back();
        }
        result.push_back(next);
    }

    //4. 결과
    return result;
}