//https://www.acmicpc.net/problem/25305

/* 커트라인 (Bronze 2)
Solution : 정렬
*/

#include <algorithm>
#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int input[1000];
	int n, k;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> input[i];

	sort(input, input + n, greater<>()); //내림차순 정렬
	cout << input[k - 1];

	return 0;
}


