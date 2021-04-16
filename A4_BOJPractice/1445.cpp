//https://www.acmicpc.net/problem/1445

//일요일 아침의 데이트
//F, S, ., g로 이루어진 테이블 상에서 한 칸씩 움직여 S->F로 가려고 한다.
//g는 쓰레기를 나타내는 것이어서 g는 지나기 싫고, 쓰레기 옆도 되도록이면 지나지 않으려 한다. (회피 우선 순위 : 쓰레기 > 쓰레기 옆)
//쓰레기 그리고 쓰레기 옆을 가능한 피해가는 경로를 지날 때, 쓰레기 옆을 지나야 하는 횟수 및 쓰레기를 지나야 하는 횟수를 구하시오.
//테이블의 최대 크기는 50 x 50이다. 

#include <vector>
#include <iostream>
#include <queue>
#define UNKNOWN 99999
using namespace std;

template <typename T>
using Board = vector<vector<T>>;
using Coordinate = pair<int, int>;
using MOVE = enum {UP, LEFT, RIGHT, DOWN, NONE};


Coordinate finalLocation, startLocation;

struct State 
{
    Coordinate nowLocation;
    int garagePassed;
    int garageSidePassed;

    //deep copy
    State(Coordinate nowLoc = {0, 0}, int garage = 0, int garageSide = 0)
    : garagePassed(garage), garageSidePassed(garageSide) {
        this->nowLocation = nowLoc; 
    }

    bool operator<(const State& state) const
    {
        if (this->garagePassed != state.garagePassed)
            return this->garagePassed > state.garagePassed;
        else if (this->garageSidePassed != state.garageSidePassed)
            return this->garageSidePassed > state.garageSidePassed;
        else
        {
            int thisDistance = abs(this->nowLocation.first - finalLocation.first) + abs(this->nowLocation.second - finalLocation.second);
            int stateDistance = abs(state.nowLocation.first - finalLocation.first) + abs(state.nowLocation.second - finalLocation.second);

            return thisDistance > stateDistance;
        }
    }

    bool isPromising(const int& garagePassedCount, const int& garageSidePassedCount)
    {
        if (this->garagePassed == garagePassedCount)
            return this->garageSidePassed < garageSidePassedCount;
        else
            return this->garagePassed < garagePassedCount;
    }
};

int depth, width;
Board<char> board;       //각 위치의 유형을 담음 (길, 쓰레기, 쓰레기 옆, 시작지, 목적지 중 1)
Board<State> boardState; //각 위치의 최적해를 담는 배열
int optimal_garagePass = 10000, optimal_garageSidePass = 10000;

MOVE addMovedState(priority_queue<State>& pQueue, const State& nowState);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> depth >> width;

    board = Board<char>(depth, vector<char>(width));
    boardState = Board<State>(depth, vector<State>(width));

    for (int y = 0; y < depth; y++)
        for (int x = 0; x < width; x++)
        {
            cin >> board[y][x];

            switch (board[y][x])
            {
                case 'S':
                    startLocation.first = y;
                    startLocation.second = x;
                    break;
                
                case 'F':
                    finalLocation.first = y;
                    finalLocation.second = x;
                    break;
            }

            boardState[y][x].nowLocation.first = y;
            boardState[y][x].nowLocation.second = x;
            boardState[y][x].garagePassed = boardState[y][x].garageSidePassed = UNKNOWN;
            
        }

    //쓰래기 옆을 s로 표현
    for (int y = 0; y < depth; y++)
        for (int x = 0; x < width; x++)
            if (board[y][x] == '.')
                if ((y != 0 && board[y-1][x] == 'g') || (x != 0 && board[y][x-1] == 'g') ||
                    (y + 1 < depth && board[y+1][x] == 'g') || (x + 1 != width && board[y][x + 1] == 'g')) 
                        board[y][x] = 's';
    

    priority_queue<State> state_pQueue; 
    //탐색 시작 위치 : 현 위치 ('S')
    state_pQueue.emplace(startLocation, 0, 0);

    //우선 순위 큐에 따라, 유망한 (쓰레기, 쓰레기 근처를 덜 밟는) 경로부터 탐색
    while (!state_pQueue.empty())
    {
        State nowState = state_pQueue.top();
        state_pQueue.pop();
        //현재 탐색 해가 지금까지 구한 최적해보다 덜 유망하면, 남은 큐도 다 덜 유망하므로 탐색 종료
        if (nowState.isPromising(optimal_garagePass, optimal_garageSidePass) == false)
            break;

        //현재 위치에서 상하좌우로 한 칸씩 이동했을 때의 상태를 유망한(더 좋은 해가 나올 수 있는) 경우에만
        //큐에 추가
        MOVE reachedMove = addMovedState(state_pQueue, nowState);

        if (reachedMove != NONE)
        {
            optimal_garagePass = nowState.garagePassed;
            optimal_garageSidePass = nowState.garageSidePassed;
        }

    }

    cout << optimal_garagePass << ' ' << optimal_garageSidePass;



	return 0;
}



MOVE addMovedState(priority_queue<State>& pQueue, const State& nowState)
{
    const auto& nowLoc = nowState.nowLocation;
    const static int add_y[4] = {-1, 0, 0, 1};
    const static int add_x[4] = {0, -1, 1, 0};
    const static MOVE movDir[4] = {UP, LEFT, RIGHT, DOWN};

    MOVE finalReachedMove = NONE;

    //4방향 반복문
    for (const MOVE& moveIdx : movDir)
    {
        Coordinate moveLoc(nowLoc.first + add_y[moveIdx], nowLoc.second + add_x[moveIdx]);
        switch (moveIdx)
        {
            case UP:
                if (moveLoc.first < 0) continue;
                break;
            case DOWN:
                if (moveLoc.first >= depth) continue;
                break;
            case LEFT:
                if (moveLoc.second < 0) continue;
                break;
            case RIGHT:
                if (moveLoc.second >= width) continue;
                break;
        } //board 가장자리에서 4방향 예외 처리

        State movedState(moveLoc, nowState.garagePassed, nowState.garageSidePassed); //움직인 상태를 담는 State 구조체
        const char& steped = board[moveLoc.first][moveLoc.second];
        State& stepedState = boardState[moveLoc.first][moveLoc.second];

        //밟을 곳의 유형에 따라 처리
        switch (steped)
        {
            case 'S':
                continue;
            case 'F':
                //밟는 곳이 목적지인 경우, 목적지가 있음을 나타내기 
                finalReachedMove = moveIdx;
                continue;
            case 's':
                movedState.garageSidePassed++;
                break;
            case 'g':
                movedState.garagePassed++;
                break;
            case '.': 
                break;
        }

        //밟은 상태가 그 지점에 대한 현재까지 구한 최적해보다 최적인 경우에만 큐에 추가
        //(그 지점에 대하여 최적해를 구한 바가 없는 경우에는 UNKNOWN이므로 무조건 큐에 추가됨)
        if (movedState.isPromising(stepedState.garagePassed, stepedState.garageSidePassed))
        {
            stepedState.garagePassed = movedState.garagePassed;
            stepedState.garageSidePassed = movedState.garageSidePassed;
            pQueue.emplace(movedState);
        }
    }
    
    return finalReachedMove;

}