//https://www.acmicpc.net/problem/11404 (문제 번호)

//역사
//역사 사건의 개수와, 서로 다른 두 역사 간의 선후 관계가 여러 개 주어진다.
//(선후 관계가 모순되는 경우는 없다)
//이후 두 사건의 관계를 묻는 질의를 할 때,
//선후 관계에 대하여 -1(앞 사건 우선), 0 (알 수 없음), 1(뒷 사건 우선)을 출력하여라.

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

    
    for (int i = 0; i < edge; i++)
    {
        int pre, post;
        cin >> pre >> post;
        
        board[pre - 1][post - 1] = 1;
    }

    //Floyd
    for (int via = 0; via < vertex; via++)
        for (int start = 0; start < vertex; start++)
            for (int end = 0; end < vertex; end++)
                board[start][end] = min(board[start][end], board[start][via] + board[via][end]);
        
    
    //question
    int inquiry;
    cin >> inquiry;

    for (int i = 0; i < inquiry; i++)
    {
        int start, end;
        cin >> start >> end;

        int toEnd = board[start - 1][end - 1];
        int toStart = board[end - 1][start - 1];

        if ((toEnd & toStart) == INF)
            cout << 0 << '\n';
        else if (toEnd == INF)
            cout << 1 << '\n';
        else   
            cout << -1 << '\n'; 
    }



    return 0;
}