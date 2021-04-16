//https://www.acmicpc.net/problem/17182

//우주 탐사선
//행성의 개수, 각 행성간의 거리(인접배열), 시작 행성이 주어질때,
//모든 행성을 방문하는 데 필요한 최소 이동 거리를 구하시오.
//다시 시작 행성으로 돌아올 필요는 없으며 이미 지나간 행성을 다시 가도 무방하다.

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
using Board = vector<vector<int>>;

bool next_permutation(vector<int>& permList);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int planet, start;
    cin >> planet >> start;

    Board adjList(planet, vector<int>(planet));

    for (auto& planetDist : adjList)
        for (auto& dist : planetDist)
            cin >> dist;
    
    //1. Floyd to get shortest path
    for (int via = 0; via < planet; via++)
        for (int start = 0; start < planet; start++)
            for (int end = 0; end < planet; end++)
                adjList[start][end] = min(adjList[start][end], adjList[start][via] + adjList[via][end]);
    

    //2. Brute force
    vector<int> visitOrder;
    for (int i = 0; i < planet; i++)
        if (i != start)
            visitOrder.push_back(i);

    int minDistance = 0x7FFFFFFF;
    do {
        int distance = 0;
        int prevIndex = start;
        for (int i = 0; i < (int)visitOrder.size(); i++)
        {
            distance += adjList[prevIndex][visitOrder[i]];
            prevIndex = visitOrder[i];
        }

        minDistance = min(distance, minDistance);
    } while (next_permutation(visitOrder));

    cout << minDistance;


	return 0;
}



bool next_permutation(vector<int>& permList)
{
    int arraySize = (int)permList.size();
    for (int pivot = arraySize - 1; pivot >= 1; pivot--)
    {
        if (permList[pivot - 1] < permList[pivot])
        {
            int minIndex = pivot;
            for (int i = pivot; i < arraySize; i++)
                if (permList[i] < permList[minIndex] && permList[i] > permList[pivot - 1])
                    minIndex = i;
            
            swap(permList[pivot - 1], permList[minIndex]);
            sort(permList.begin() + pivot, permList.end());
            
            return true;
        }
    }

    return false;
}