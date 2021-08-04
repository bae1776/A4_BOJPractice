//https://www.acmicpc.net/problem/20113

/*긴급 회의
*/

#include <iostream>
#include <vector>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int humans;
	cin >> humans;

	vector<int> voteResult(humans + 1, 0);

	for (int i = 0; i < humans; i++)
	{
		int vote;
		cin >> vote;
		voteResult[vote] += 1;
	}


	int maxVoted_index = 0;
	int maxVoted = 0;
	bool coleadered = false;

	for (int i = 1; i <= humans; i++)
	{
		if (voteResult[i] > maxVoted)
		{
			maxVoted_index = i;
			maxVoted = voteResult[i];
			coleadered = false;
		}
		else if (voteResult[i] == maxVoted) {
			coleadered = true;
		}
	}

	if (coleadered == true)
	{
		cout << "skipped";
	}
	else {
		cout << maxVoted_index;
	}

	return 0;
}