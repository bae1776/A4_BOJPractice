//https://www.acmicpc.net/problem/1588

/* 부분수열의 합 (Gold 1)
* 1, 2, 3으로만 이루어진 수열은 처음에 수 하나만 가지고 있다.
* 매 초마다 1은 132, 2는 211, 3은 232로 바뀐다.
* N초 후 Left번째 수부터 Right번째 수 중에 1의 개수, 2의 개수, 3의 개수를 구하는 프로그램을 구하시오.
* 
* input : 처음 수, N, Left, Right
*/


#include <iostream>
#include <vector>
#include <array>
using namespace std;
using Result = array<int, 3>;


int valArray[4][3] = {
//valArray[A][B] : 수 A가 1초 후 변환된 숫자에서 B번째 자리에 있는 수 
		{},
		{1, 3, 2},
		{2, 1, 1},
		{2, 3, 2}
};
array<vector<Result>, 4> numCountDP;
vector<int> exp3;

Result func(int num, int start, int end, int time);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int num, left, right, time;
	cin >> num >> left >> right >> time;

	//3의 n승 값 미리 저장
	exp3 = vector<int>(time + 1);
	exp3[0] = 1;
	for (int exp = 1; exp < time; exp++)
		exp3[exp] = exp3[exp - 1] * 3;

	//DP 값 할당
	numCountDP[1] = vector<Result>(time + 1);
	numCountDP[2] = vector<Result>(time + 1);
	numCountDP[3] = vector<Result>(time + 1);
	numCountDP[1][0] = { 1, 0, 0 };
	numCountDP[2][0] = { 0, 1, 0 };
	numCountDP[3][0] = { 0, 0, 1 };
	for (int t = 1; t < time; t++)
		for (int n = 1; n <= 3; n++)
		{
			const Result& before = numCountDP[n][t-1];

			numCountDP[n][t] =
				{ before[0] + before[1] * 2, 
				  before[0] + before[1] + 2 * before[2], 
				  before[0] + before[2] };
		}
	
	auto [count1, count2, count3] = func(num, left, right, time);

	cout << count1 << ' ' << count2 << ' ' << count3;

	return 0;
}






Result func(int num, int start, int end, int time)
{
	if (time == 0)
		return numCountDP[num][0];
	else if (time == 1)
	{
		Result output = { 0, 0, 0 };
		for (int index = start; index <= end; index++)
			output[valArray[num][index] - 1]++;
		return output;	
	}
	
	const int& div = exp3[time - 1];
	int segStart = start / div;
	int segEnd = end / div;

	if (segStart == segEnd)
		return func(valArray[num][segStart], start - segStart * div, end - segEnd * div, time - 1);
	else if (segStart + 1 == segEnd)
	{
		int segStartIndex = start % div;
		int segEndIndex = end % div;
		
		Result leftSeg, rightSeg;

		if (segStartIndex == 0)
			leftSeg = numCountDP[valArray[num][segStart]][time - 1];
		else
			leftSeg = func(valArray[num][segStart], start - segStart * div, div - 1, time - 1);
		
		if (segEndIndex == div - 1)
			rightSeg = numCountDP[valArray[num][segEnd]][time - 1];
		else
			rightSeg = func(valArray[num][segEnd], 0, end - segEnd * div, time - 1);

		return { leftSeg[0] + rightSeg[0], leftSeg[1] + rightSeg[1], leftSeg[2] + rightSeg[2] };

	}
	else {
		int segStartIndex = start % div;
		int segEndIndex = end % div;
		
		Result leftSeg, middleSeg, rightSeg;

		if (segStartIndex == 0)
			leftSeg = numCountDP[valArray[num][0]][time - 1];
		else
			leftSeg = func(valArray[num][0], start, div - 1, time - 1);

		middleSeg = numCountDP[valArray[num][1]][time - 1];

		if (segEndIndex == div - 1)
			rightSeg = numCountDP[valArray[num][2]][time - 1];
		else
			rightSeg = func(valArray[num][2], 0, end - segEnd * div, time - 1);

		return { leftSeg[0] + middleSeg[0] + rightSeg[0], leftSeg[1] + middleSeg[1] + rightSeg[1], leftSeg[2] + middleSeg[2] + rightSeg[2]};
	}
}

