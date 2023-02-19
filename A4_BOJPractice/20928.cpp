//https://www.acmicpc.net/problem/20928

/*걷는 건 귀찮아 (Gold 4)
그리디로 풀수 있다
*/

#include <iostream>
#include <queue>
using namespace std;

int manStart[100001], manEnd[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int man, destination;
    cin >> man >> destination;

    for (int i = 0; i < man; i++)
        cin >> manStart[i];

    for (int i = 0; i < man; i++)
    {
        cin >> manEnd[i];
        manEnd[i] += manStart[i];
    }

    
    priority_queue<int> pq;
    int startIndex = 1;
    int answer = 0;
    pq.push(manEnd[0]);

    while (true)
    {
        int maximumReach = pq.top();
        if (maximumReach >= destination)
            break;
        
        while (startIndex != man && manStart[startIndex] <= maximumReach)
        {
            pq.push(manEnd[startIndex]);
            startIndex++;
        }

        if (maximumReach == pq.top())
        {
            answer = -1;
            break;
        } else {
            answer++;
        }
    }

    cout << answer;



    

	
	return 0;
}
