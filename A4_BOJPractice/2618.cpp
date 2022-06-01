//https://www.acmicpc.net/problem/2618

/*경찰차

어떤 도시의 중심가는 N개의 동서방향 도로와 N개의 남북 방향 도로로 구성되어 있고
각 도로 사이의 거리는 모두 1이다.

이 도시에는 두 대의 경찰차가 있으며 두 차를 경찰차1과 경찰차2로 부른다. 
처음에는 항상 경찰차1은 (1, 1)의 위치에 있고 경찰차2는 (N, N)의 위치에 있다. 
경찰 본부에서는 처리할 사건이 있으면 그 사건이 발생된 위치를 두 대의 경찰차 중 하나에 알려 주고, 
연락 받은 경찰차는 그 위치로 가장 빠른 길을 통해 이동하여 사건을 처리한다. (하나의 사건은 한 대의 경찰차가 처리한다.) 
그리고 사건을 처리 한 경찰차는 경찰 본부로부터 다음 연락이 올 때까지 처리한 사건이 발생한 위치에서 기다린다. 
경찰 본부에서는 사건이 발생한 순서대로 두 대의 경찰차에 맡기려고 한다. 
처리해야 될 사건들은 항상 교차로에서 발생하며 경찰 본부에서는 이러한 사건들을 나누어 두 대의 경찰차에 맡기되, 
두 대의 경찰차들이 이동하는 거리의 합을 최소화 하도록 사건을 맡기려고 한다.

처리해야 할 사건들이 순서대로 주어질 때, 
두 대의 경찰차가 이동하는 거리의 합을 최소화 하도록 사건들을 맡기는 프로그램을 작성하시오.
*/


#include <iostream>
#include <vector>
#include <stack>
using namespace std;



struct Data {
    int total;
    pair<int, int> carPos[2];
    int movedCar;
    int beforeIndex;
};



inline int dist(const pair<int, int>& loc1, const pair<int, int>& loc2)
{
    return abs(loc1.first - loc2.first) + abs(loc1.second - loc2.second);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int boardSize, incidents;
    cin >> boardSize >> incidents;

    vector<vector<Data>> DP(incidents + 1);
    vector<pair<int, int>> incidentList(incidents + 1);
    for (int i = 1; i <= incidents; i++)
    {
        DP[i] = vector<Data>(i + 1, {.total = 0x3FFFFFFF});
        cin >> incidentList[i].first >> incidentList[i].second;
    }
    //DP[CaseNumber][notNowMovingCarPosition : {0 = Car1Start, 1, ... , CaseNumber = Car2Start}]
    

    
    DP[1][0] = {.total = dist({boardSize, boardSize}, incidentList[1]), 
                        .carPos = {{1, 1}, incidentList[1]}, 
                        .movedCar = 2,
                        .beforeIndex = -1};

    DP[1][1] = {.total = dist({1, 1}, incidentList[1]), 
                        .carPos = {incidentList[1], {boardSize, boardSize}}, 
                        .movedCar = 1,
                        .beforeIndex = -1};
    
    

    for (int incidNumber = 2; incidNumber <= incidents; incidNumber++)
    {
        const auto& prevState = DP[incidNumber-1];

        //DP[incidNumber][0] : Car1 Fixed Case
        DP[incidNumber][0] = {
            .total = prevState[0].total + dist(incidentList[incidNumber], incidentList[incidNumber - 1]),
            .carPos = {{1, 1}, incidentList[incidNumber]},
            .movedCar = 2,
            .beforeIndex = 0};
        
        //DP[incidNumber][1 ~ incidNumber - 2] : moves previous moved car
        for (int fixedCar_incidNum = 1; fixedCar_incidNum < incidNumber - 1; fixedCar_incidNum++)
        {

            DP[incidNumber][fixedCar_incidNum] = {
                    .total = prevState[fixedCar_incidNum].total + dist(incidentList[incidNumber], incidentList[incidNumber - 1]),
                    .carPos = {incidentList[incidNumber], incidentList[fixedCar_incidNum]},
                    .movedCar = prevState[fixedCar_incidNum].movedCar,
                    .beforeIndex = fixedCar_incidNum };
            

            if (DP[incidNumber][fixedCar_incidNum].movedCar == 2)
            { //SWAP(carPos[0], carPos[1])
                DP[incidNumber][fixedCar_incidNum].carPos[0] = incidentList[fixedCar_incidNum];
                DP[incidNumber][fixedCar_incidNum].carPos[1] = incidentList[incidNumber];
            }
        }

        //DP[incidNumber][incidNumber - 1] : check All prevState case
        // - lemma : 이전에 움직이지 않았던 차를 움직이는 케이스임. (그래야, 두 차가 현 사건 위치, 이전 사건 위치에 서 있을 수 있다)
        {
            vector<int> totalList(incidNumber);

            for (int i = 0; i < incidNumber; i++)
            {
                totalList[i] = prevState[i].total;

                if (prevState[i].movedCar == 1)
                    totalList[i] += dist(incidentList[incidNumber], prevState[i].carPos[1]);
                else
                    totalList[i] += dist(incidentList[incidNumber], prevState[i].carPos[0]);
            }

            int minIndex = 0;
            for (int i = 1; i < incidNumber; i++)
                if (totalList[i] < totalList[minIndex])
                    minIndex = i;

            DP[incidNumber][incidNumber - 1] = {
                .total = totalList[minIndex],
                .carPos = {incidentList[incidNumber], incidentList[incidNumber - 1]},
                .movedCar = 3 - prevState[minIndex].movedCar, //reverse
                .beforeIndex = minIndex};
            
            
            if (DP[incidNumber][incidNumber - 1].movedCar == 2)
            { //SWAP(carPos[0], carPos[1])
                DP[incidNumber][incidNumber - 1].carPos[0] = incidentList[incidNumber - 1];
                DP[incidNumber][incidNumber - 1].carPos[1] = incidentList[incidNumber];
            }
        }


        //DP[incidNumber][incidNumber] : Car2 Fixed Case
        DP[incidNumber][incidNumber] = {
            .total = prevState[incidNumber - 1].total + dist(incidentList[incidNumber], incidentList[incidNumber - 1]),
            .carPos = {incidentList[incidNumber], {boardSize, boardSize}},
            .movedCar = 1,
            .beforeIndex = incidNumber - 1};
    }


    int minIndex = 0;
    for (int i = 1; i <= incidents; i++)
        if (DP[incidents][i].total < DP[incidents][minIndex].total)
            minIndex = i;
    
    cout << DP[incidents][minIndex].total << '\n';

    stack<int> policeCars;
    while (minIndex != -1)
    {
        policeCars.emplace(DP[incidents][minIndex].movedCar);
        minIndex = DP[incidents--][minIndex].beforeIndex;
    }

    while (policeCars.empty() == false)
    {
        cout << policeCars.top() << '\n';
        policeCars.pop();
    }

    return 0;
}