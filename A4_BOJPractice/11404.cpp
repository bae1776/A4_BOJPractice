//https://www.acmicpc.net/problem/11404 (문제 번호)

//플로이드
//플루이드 워셜 알고리즘 기본 문제

//20202 플루이드

#include <iostream>
#include <vector>
using namespace std;
#define INF 0x3FFFFFFF

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int vertex, edge;
    cin >> vertex >> edge;

    vector<vector<int>> board(vertex, vector<int>(vertex, INF));
    for (int i = 0; i < vertex; i++)
        board[i][i] = 0;
    
    for (int i = 0; i < edge; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;

        board[start - 1][end - 1] = min(board[start - 1][end - 1], weight);
    }


    //Floyd
    for (int via = 0; via < vertex; via++)
        for (int start = 0; start < vertex; start++)
            for (int end = 0; end < vertex; end++)
                board[start][end] = min(board[start][end], board[start][via] + board[via][end]);

    for (int start = 0; start < vertex; start++)
    {
        for (int end = 0; end < vertex; end++)
            cout << ((board[start][end] >= INF) ? 0 : board[start][end]) << ' ';
        cout << '\n';
    }   




	return 0;
}
