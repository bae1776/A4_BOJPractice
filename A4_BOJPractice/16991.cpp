//https://www.acmicpc.net/problem/16991

/*외판원 순회 3 (Gold 1)

-> TSP 알고리즘 : 다이나믹 프로그래밍

*/

#include <iostream>
#include <cmath>
using namespace std;

double minDist[16][1 << 16]; //lastCity, visited
double adjList[16][16];
pair<int, int> cityCoord[16];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int cityCount;
    cin >> cityCount;

    const int maxBit = (1 << cityCount) - 1;
    for (int i = 0; i < cityCount; i++)
    {
        cin >> cityCoord[i].first >> cityCoord[i].second;

        for (int to = 0; to < i; to++)
        {
            adjList[i][to] = adjList[to][i] = sqrt((double)0.0 +
              (cityCoord[i].first - cityCoord[to].first) * (cityCoord[i].first - cityCoord[to].first)
              + (cityCoord[i].second - cityCoord[to].second) * (cityCoord[i].second - cityCoord[to].second)  
            );
        }

        for (int j = 0; j <= maxBit; j++)
            minDist[i][j] = 0xFFFFFF;
    }

    minDist[0][1] = 0;
    for (int bit = 3; bit <= maxBit; bit += 2)
    {
        for (int lastCity = 0; lastCity < cityCount; lastCity++)
        {
            int cityMask = 1 << lastCity; 
            if ((bit & cityMask) == 0)
                if (cityMask > bit)
                    break;
                else
                    continue;
            

            for (int prevLast = 0; prevLast < cityCount; prevLast++)
                minDist[lastCity][bit] = min(minDist[lastCity][bit],
                    minDist[prevLast][bit - cityMask] + adjList[prevLast][lastCity]);
        }
    }

    double result = 0xFFFFFF;
    for (int lastCity = 0; lastCity < cityCount; lastCity++)
        result = min(result, minDist[lastCity][maxBit] + adjList[lastCity][0]);
    
    cout << fixed;
    cout.precision(10);
    cout << result;

	return 0;
}
