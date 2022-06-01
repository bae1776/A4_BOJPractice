//https://www.acmicpc.net/problem/17472

/*다리 만들기 2

섬으로 이루어진 나라가 있고, 모든 섬을 다리로 연결하려고 한다. 이 나라의 지도는 N*M 크기의 이차원 격자이다.
격자의 각 칸은 땅이거나 바다이다.

섬은 연결된 땅이 상하좌우로 붙어있는 덩어리를 일컫는다.
다리는 바다에만 건설할 수 있고, 다리의 길이는 격차에서 차지하는 칸의 수인데,
다리를 연결해서 모든 섬을 연결하려고 한다. 다리는 다음과 같은 조건을 만족해야 한다.

1. 길이가 2 이상이어야 한다.
2. 다리의 양 끝은 섬과 인접한 바다에 있어야 한다.
3. 다리를 건널 때 중간에 방향이 틀어져서는 안된다.

나라의 정보가 주어졌을 때, 모든 섬을 연결하는 다리 길이의 최솟값을 구하시오. (N*M은 3 이하이다.)

*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

template <typename T>
using MinEdgeHeap = priority_queue<tuple<T, int, int>, vector<tuple<T, int, int>>, greater<tuple<T, int, int>>>;


struct Node {
    int parent;
    int level;
};

int row, col;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<vector<int>> bridgeList;
vector<Node> nodeList;


void bind_island(const int& row, const int& col, const int& islandNumber);
void make_horizontalBridge(int rowNumber);
void make_verticalBridge(int colNumber);
bool merge(int node1, int node2);
int find(int node);


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> row >> col;


    board = vector<vector<int>>(row, vector<int>(col));
    visited = vector<vector<bool>>(row, vector<bool>(col, false));

    int island = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> board[i][j];


    //write island number
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] != 0 && visited[i][j] == false)
                bind_island(i, j, ++island);
        }


    //make proper Bridge
    bridgeList = vector<vector<int>>(island + 1, vector<int>(island + 1, 0x1FFFFFFF));
    
    for (int i = 0; i < row; i++)
        make_horizontalBridge(i);
    
    for (int i = 0; i < col; i++)
        make_verticalBridge(i);

    

    //input available Bridge(Edge) to Priority Queue.
    nodeList = vector<Node>(island + 1); //(Union Find Array)
    MinEdgeHeap<int> bridgePQ;

    for (int y = 1; y <= island; y++)
    {
        nodeList[y].parent = y;
        nodeList[y].level = 1;

        for (int x = 1; x <= island; x++)
            if (bridgeList[y][x] != 0x1FFFFFFF)
                bridgePQ.emplace(bridgeList[y][x], y, x);
    }


    int bridge = 0;
    int minDistance = 0;

    //Kruskal algorithm + union find
    while (bridgePQ.empty() == false)
    {
        if (bridge == island - 1) break;
        
        auto [bridgeLen, start, end] = bridgePQ.top();
        bridgePQ.pop();

        if (!merge(start, end)) continue;
        
        minDistance += bridgeLen;
        bridge++;
    }


    //print result
    if (bridge == island - 1)
        cout << minDistance;
    else
        cout << -1;


    return 0;
}



void bind_island(const int& row, const int& col, const int& islandNumber)
{
    board[row][col] = islandNumber;
    visited[row][col] = true;

    const static int dx[4] = {-1, 0, 1, 0};
    const static int dy[4] = {0, -1, 0, 1};

    for (int dir = 0; dir < 4; dir++)
    {
        const int nextY = row + dy[dir], nextX = col + dx[dir];
        if (0 <= nextY && nextY < board.size() && 0 <= nextX && nextX < board[0].size())
        {
            if (visited[nextY][nextX] == false && board[nextY][nextX] != 0)
                bind_island(nextY, nextX, islandNumber);
        }
    }
}


void make_horizontalBridge(int rowNumber)
{
    int prevIsland = -1;
    int bridgeLen = 0;

    for (int i = 0; i < board[0].size(); i++)
    {
        if (board[rowNumber][i] == 0)
            bridgeLen++;
        else
        {
            if (prevIsland != -1 && bridgeLen >= 2)
                bridgeList[prevIsland][board[rowNumber][i]] = 
                    min(bridgeList[prevIsland][board[rowNumber][i]], bridgeLen);
                 
            bridgeLen = 0;
            prevIsland = board[rowNumber][i];
        }
    }
}


void make_verticalBridge(int colNumber)
{
    int prevIsland = -1;
    int bridgeLen = 0;

    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][colNumber] == 0)
            bridgeLen++;
        else
        {
            if (prevIsland != -1 && bridgeLen >= 2)
                bridgeList[prevIsland][board[i][colNumber]] = 
                    min(bridgeList[prevIsland][board[i][colNumber]], bridgeLen);
                 
            bridgeLen = 0;
            prevIsland = board[i][colNumber];
        }
    }
}


bool merge(int node1, int node2)
{
    node1 = find(node1);
    node2 = find(node2);

    if (node1 == node2)
        return false;

    if (nodeList[node1].level < nodeList[node2].level)
    {
        int temp = node1;
        node1 = node2;
        node2 = temp;
    }

    nodeList[node2].parent = node1;

    if (nodeList[node1].level == nodeList[node2].level)
        ++nodeList[node1].level;

    return true;
}


int find(int node)
{
    if (node == nodeList[node].parent)
        return node;
    else
        return nodeList[node].parent = find(nodeList[node].parent);
}
