//https://www.acmicpc.net/problem/1799

/*비숍 (Gold 1)
체스의 비숍은 대각선 방향으로 거리 제한없이 움직일 수 있는 말이다.
체스판에서 비숍을 둘 수 있는 곳과 없는 곳이 주어질 때, 그 제한 하에서 최대한 많이 둘 수 있는 비숍의 갯수를 구하시오.

체스판의 크기는 최대 10x10인 정사각형이다.

Solution : 백트레킹
체스판을 흰 부분, 검은 부분으로 반반 나누어 백트레킹을 해야 시간초과가 나지 않는다.
*/

#include <iostream>
#include <tuple>
#include <stack>
#include <vector>
using namespace std;
using Element = tuple<int, int, bool, bool>; //depth, count, exist, visit

bool sevenAngle[20], fiveAngle[20]; //true -> Bishop exists


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int boardSize;
    cin >> boardSize;

    vector<pair<int, int>> bishopOddLoc, bishopEvenLoc;
    int input;
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++)
        {
            cin >> input;
            if (input == 1)
                if ((i + j) % 2)
                    bishopOddLoc.emplace_back(i, j);
                else
                    bishopEvenLoc.emplace_back(i, j);
        }

    int oddResult = 0, evenResult = 0;

    stack<Element> dfsStack;
    
    if (bishopOddLoc.size() != 0)
    {
        dfsStack.emplace(0, 0, false, false);
        dfsStack.emplace(0, 1, true, false);

        while (dfsStack.empty() == false)
        {
            auto& [depth, count, exist, visit] = dfsStack.top();
            int f = bishopOddLoc[depth].first - bishopOddLoc[depth].second + 10;
            int s = bishopOddLoc[depth].first + bishopOddLoc[depth].second;

            if (visit == false)
            { //아직 방문하지 않은 경우
                visit = true;
                //방문 시도 : 가지치기 조건이거나 비숍 추가가 불가능하면 방문 실패
                //가지치기 조건
                if (count + bishopOddLoc.size() - depth - 1 <= oddResult)
                {
                    dfsStack.pop();
                    continue;
                }

                //비숍 추가 작업 (추가 불가한 경우 가지치기)
                if (exist == true)
                {
                    if (fiveAngle[f] == true || sevenAngle[s] == true)
                    {
                        dfsStack.pop();
                        continue;
                    }
                    fiveAngle[f] = true;
                    sevenAngle[s] = true;
                }

                //방문 성공 상태
                oddResult = max(oddResult, count);

                //자식 노드를 스택에 추가 (끝이 아닌 경우)
                if (depth != bishopOddLoc.size())
                {
                    dfsStack.emplace(depth + 1, count, false, false);
                    dfsStack.emplace(depth + 1, count + 1, true, false);
                }
            } else {
                //이미 방문한 노드인경우 스택에서 삭제
                if (exist == true)
                {
                    fiveAngle[f] = false;
                    sevenAngle[s] = false;
                }
                dfsStack.pop();
            }
        }
    }
    
    if (bishopEvenLoc.size() != 0)
    {
        dfsStack.emplace(0, 0, false, false);
        dfsStack.emplace(0, 1, true, false);

        while (dfsStack.empty() == false)
        {
            auto& [depth, count, exist, visit] = dfsStack.top();
            int f = bishopEvenLoc[depth].first - bishopEvenLoc[depth].second + 10;
            int s = bishopEvenLoc[depth].first + bishopEvenLoc[depth].second;

            if (visit == false)
            { //아직 방문하지 않은 경우
                visit = true;
                //방문 시도 : 가지치기 조건이거나 비숍 추가가 불가능하면 방문 실패
                //가지치기 조건
                if (count + bishopEvenLoc.size() - depth - 1 <= evenResult)
                {
                    dfsStack.pop();
                    continue;
                }

                //비숍 추가 작업 (추가 불가한 경우 가지치기)
                if (exist == true)
                {
                    if (fiveAngle[f] == true || sevenAngle[s] == true)
                    {
                        dfsStack.pop();
                        continue;
                    }
                    fiveAngle[f] = true;
                    sevenAngle[s] = true;
                }

                //방문 성공 상태
                evenResult = max(evenResult, count);

                //자식 노드를 스택에 추가 (끝이 아닌 경우)
                if (depth != bishopEvenLoc.size())
                {
                    dfsStack.emplace(depth + 1, count, false, false);
                    dfsStack.emplace(depth + 1, count + 1, true, false);
                }
            } else {
                //이미 방문한 노드인경우 스택에서 삭제
                if (exist == true)
                {
                    fiveAngle[f] = false;
                    sevenAngle[s] = false;
                }
                dfsStack.pop();
            }
        }
    }

    cout << oddResult + evenResult;


    return 0;
}