//https://www.acmicpc.net/problem/1486

//등산
//(0, 0)에 위치하는 호텔에서 등산을 갔다가 오려고 한다.
//각 칸은 높이를 가지고 있고
//가는 칸이 현재 칸보다 높으면 (높이차)^2의 시간, 같거나 낮으면 1의 시간이 걸린다.
//격자의 크기 및 각 격자의 높이 정보와 한 번에 올라갈 수 있는 최대 높이와, 제한 시간이 주어질 때
//가장 높이 올라갈 수 있는 곳의 높이를 출력하시오.

#include <vector>
#include <queue>
#include <iostream>
#define INF 9999999
using namespace std;

vector<vector<int>> adjList;
vector<int> heightBoard;
int depth, width, maxJump, timeLimit, boardSize;

void makeEdge(int start, int end);
vector<int> dijkstra(int start);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    
    cin >> depth >> width >> maxJump >> timeLimit;
    boardSize = depth * width;
    adjList = vector<vector<int>>(boardSize, vector<int>(boardSize, INF));
    
    heightBoard.reserve(boardSize);
    //input height
    for (int i = 0; i < boardSize; i++)
    {
        char input;
        cin >> input;
        if (input >= 'A' && input <= 'Z')
            heightBoard.push_back(input - 'A');
        else if (input >= 'a' && input <= 'z')
            heightBoard.push_back(input - 'a' + 26);
    }

    //make Edge
    for (int i = 0; i < boardSize; i++)
    {
        //down, up, right, left Move
        if (i + width < boardSize) makeEdge(i, i + width);
        if (i - width >= 0) makeEdge(i, i - width);
        if (i + 1 < boardSize && (i + 1) % width != 0) makeEdge(i, i + 1);
        if (i - 1 >= 0 && i % width != 0) makeEdge(i, i - 1);
        adjList[i][i] = 0;
    }


    //Priority Queue DijkStra from Hotel
    vector<int> shortestFromHotel = dijkstra(0);

    //가장 유망한 경유지부터 답을 찾는 우선 순위 큐
    priority_queue<pair<int, int>> stopover_pQueue; //stopover height, stopover index
    for (int soIndex = 0; soIndex < boardSize; soIndex++)
    {
        if (shortestFromHotel[soIndex] < timeLimit)
            stopover_pQueue.emplace(heightBoard[soIndex], soIndex);
    }

    int maxHeight = heightBoard[0];

    while (stopover_pQueue.empty() == false)
    {
        auto stopover = stopover_pQueue.top();
        stopover_pQueue.pop();

        int distanceToHotel = dijkstra(stopover.second)[0];
        if (shortestFromHotel[stopover.second] + distanceToHotel <= timeLimit)
        {
            maxHeight = stopover.first;
            break;
        }
    }
    
    cout << maxHeight;

	return 0;
}



void makeEdge(int start, int end)
{
    if (heightBoard[start] < heightBoard[end])
    {
        if (heightBoard[end] - heightBoard[start] <= maxJump)
            adjList[start][end] = (heightBoard[start] - heightBoard[end]) * (heightBoard[start] - heightBoard[end]);            
    } 
    else 
        if (heightBoard[start] - heightBoard[end] <= maxJump)
            adjList[start][end] = 1;
}


vector<int> dijkstra(int start)
{
    //Priority Queue DijkStra
    vector<int> shortestPath(boardSize, INF);
    vector<bool> visited(boardSize, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> Dijkstra_pQueue; //<distance, number>

    Dijkstra_pQueue.emplace(0, start);
    shortestPath[start] = 0;

    do {
        auto nowQueue = Dijkstra_pQueue.top();
        Dijkstra_pQueue.pop();

        const int& nowVisit = nowQueue.second;
        if (visited[nowVisit] == false)
            visited[nowVisit] = true;
        else continue;

        
        //UP / DOWN / RIGHT / LEFT move Edge search
        if (nowVisit + width < boardSize && adjList[nowVisit][nowVisit + width] != INF)
        {
            shortestPath[nowVisit + width] 
                = min(shortestPath[nowVisit + width], shortestPath[nowVisit] + adjList[nowVisit][nowVisit + width]);
            Dijkstra_pQueue.emplace(shortestPath[nowVisit + width], nowVisit + width);
        }
        if (nowVisit - width >= 0 && adjList[nowVisit][nowVisit - width] != INF)
        {
            shortestPath[nowVisit - width] 
                = min(shortestPath[nowVisit - width], shortestPath[nowVisit] + adjList[nowVisit][nowVisit - width]);
            Dijkstra_pQueue.emplace(shortestPath[nowVisit - width], nowVisit - width);
        }
        if (nowVisit + 1 < boardSize && (nowVisit + 1) % width != 0 && adjList[nowVisit][nowVisit + 1] != INF)
        {
            shortestPath[nowVisit + 1] 
                = min(shortestPath[nowVisit + 1], shortestPath[nowVisit] + adjList[nowVisit][nowVisit + 1]);
            Dijkstra_pQueue.emplace(shortestPath[nowVisit + 1] , nowVisit + 1);
        }
        if (nowVisit - 1 >= 0 && nowVisit % width != 0 && adjList[nowVisit][nowVisit - 1] != INF)
        {
            shortestPath[nowVisit - 1] 
                = min(shortestPath[nowVisit - 1], shortestPath[nowVisit] + adjList[nowVisit][nowVisit - 1]);
            Dijkstra_pQueue.emplace(shortestPath[nowVisit - 1] , nowVisit - 1);
        }

    } while (Dijkstra_pQueue.empty() == false);
    
    return shortestPath;
}