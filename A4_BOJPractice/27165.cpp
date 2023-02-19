//https://www.acmicpc.net/problem/999 (문제 번호)

/*모든 말을 안전하게
*/

#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> board(n + 1);
    vector<int> singleIndex;

    for (int i = 0; i <= n; i++)
    {
        cin >> board[i];
        if (singleIndex.size() < 3 && board[i] == 1)
            singleIndex.push_back(i);
    }

    int dice;
    cin >> dice;

    if (singleIndex.size() == 3)
        cout << "NO";
    else if (singleIndex.size() == 2)
    {
        if (singleIndex[0] + dice == singleIndex[1])
            cout << "YES\n" << singleIndex[0] << ' ' << singleIndex[1];
        else
            cout << "NO";
    } else if (singleIndex.size() == 1) {
        if (singleIndex[0] + dice <= n && board[singleIndex[0] + dice])
            cout << "YES\n" << singleIndex[0] << ' ' << singleIndex[0] + dice;
        else if (singleIndex[0] - dice >= 0 && board[singleIndex[0] - dice] >= 3)
            cout << "YES\n" << singleIndex[0] - dice << ' ' << singleIndex[0];
        else
            cout << "NO";
    } else {
        for (int i = 0; i <= n - dice; i++)
        {
            if (board[i] >= 3 && board[i + dice])
            {
                cout << "YES\n" << i << ' ' << i + dice;
                return 0;
            }
        }

        cout << "NO";
    }


	
	return 0;
}
