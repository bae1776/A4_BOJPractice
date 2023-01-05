//https://www.acmicpc.net/problem/2549

/*루빅의 사각형 (Platinum 3)
4x4 격자판에서 1부터 16까지 정수 번호가 매겨진 16개 타일이 임의로 놓여져 있다.
이를 행을 오른쪽으로 미는 연산, 열을 아래쪽으로 미는 연산만을 이용하여
임의로 놓은 배치되었던 타일을 1 2 3 4; 5 6 7 8; 9 10 11 12; 13 14 15 16; 로 정렬하는
최소 이동횟수 및 이동 방법을 출력하시오.

고민 과정 :
힌트에서 미는 횟수는 많아야 7번이라고 언급했으나
단순 브루트포스로는 해결할 수 없다. (미는 방법 24가지^7는 수십억 단위이다)

여기서 주어진 타일에서 BFS 4번 (24^4 = 24만쯤), 처음 타일에서 BFS 3번 수행 (약 1만) 한 뒤, 각 결과를 비교한다.
그러나 단순 비교를 하면 24만 * 1만이라는 말도 안되는 시간이 걸리기 때문에 결과에 대한 해싱이 필요할 것이다.
*/

#include <iostream>
#include <array>
#include <list>
#include <vector>
using namespace std;
using Board = array<array<short, 4>, 4>;
using QElement = pair<Board, array<char, 12>>;
using BQueue = list<QElement>;
char numCh[5] = { '0', '1', '2', '3', '4' };
vector<QElement> bfsFromStartHash[17][17];

vector<BQueue> bfs(const Board& start, int depth);
bool hashCompare(const Board& searchBoard, QElement& resultRef);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Board start, target;
	int num = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> start[i][j];
			target[i][j] = num++;
		}
	}

	//시작 보드로부터의 4 깊이 BFS
	vector<BQueue> bfs4FromStart = bfs(start, 4);

	//답이 4 이하일 경우 여기서 풀리고 바로 프로그램 종료
	for (int depth = 0; depth <= 4; depth++)
	{
		for (const auto& [answerBoard, answerLog] : bfs4FromStart[depth])
		{
			if (answerBoard == target)
			{
				cout << depth << '\n';
				for (int i = 0; i < 3 * depth; i += 3)
					cout << answerLog[i] << ' ' << answerLog[i + 1] << ' ' << answerLog[i + 2] << '\n';

				return 0;
			}
		}
	}

	//깊이가 4인 모든 경우의 수 해싱
	for (auto& [board, log] : bfs4FromStart[4])
	{
		pair<short, short> hashIndex = { board[0][0], board[3][3] };
		bfsFromStartHash[hashIndex.first][hashIndex.second].emplace_back(move(board), move(log));
	}

	//종료 보드로부터의 3 깊이 bfs
	vector<BQueue> bfs3FromTarget = bfs(target, 3);
	QElement resultFromStart;

	for (int depth = 1; depth <= 3; depth++)
	{
		for (const auto& [answerBoard, answerLog] : bfs3FromTarget[depth])
			if (hashCompare(answerBoard, resultFromStart))
			{
				cout << 4 + depth << '\n';

				for (int i = 0; i < 12; i += 3)
					cout << resultFromStart.second[i] << ' ' << resultFromStart.second[i + 1] << ' ' << resultFromStart.second[i + 2] << '\n';

				for (int i = 3 * depth - 3; i >= 0; i -= 3)
					cout << answerLog[i] << ' ' << answerLog[i + 1] << ' ' << (char)('0' + ('4' - answerLog[i + 2])) << '\n';

				return 0;
			}
	}



	return 0;
}




vector<BQueue> bfs(const Board& start, int depth)
{
	vector<BQueue> result(depth + 1);
	result[0].emplace_back(start, array<char, 12>{'\0', });

	for (int d = 0; d < depth; d++)
	{
		int logLength = d * 3;
		for (const auto& [nowBoard, moveLog] : result[d])
		{
			for (int index = 1; index <= 4; index++)
				for (int move = 1; move <= 3; move++)
				{
					//Right Move
					if (d == 0 || moveLog[logLength - 3] != numCh[1] || moveLog[logLength - 2] != numCh[index])
					{
						auto curBoard = nowBoard;
						auto curMoveLog = moveLog;

						for (int i = 0; i < 4; i++)
							curBoard[index - 1][(i + move) % 4] = nowBoard[index - 1][i];

						curMoveLog[logLength] = '1';
						curMoveLog[logLength + 1] = numCh[index];
						curMoveLog[logLength + 2] = numCh[move];

						result[d + 1].emplace_back(curBoard, curMoveLog);
					}

					//Down Move
					if (d == 0 || moveLog[logLength - 3] != numCh[2] || moveLog[logLength - 2] != numCh[index])
					{
						auto curBoard = nowBoard;
						auto curMoveLog = moveLog;

						for (int i = 0; i < 4; i++)
							curBoard[(i + move) % 4][index - 1] = nowBoard[i][index - 1];

						curMoveLog[logLength] = '2';
						curMoveLog[logLength + 1] = numCh[index];
						curMoveLog[logLength + 2] = numCh[move];

						result[d + 1].emplace_back(curBoard, curMoveLog);
					}
				}
		}
	}

	return result;
}


bool hashCompare(const Board& searchBoard, QElement& resultRef)
{
	const pair<short, short> hashIndex = { searchBoard[0][0], searchBoard[3][3] };

	for (const QElement& elem : bfsFromStartHash[hashIndex.first][hashIndex.second])
	{
		if (elem.first == searchBoard)
		{
			resultRef = elem;
			return true;
		}
	}

	return false;
}
