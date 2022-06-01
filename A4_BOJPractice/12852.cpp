//https://www.acmicpc.net/problem/12852

/*1로 만들기

정수 X에 사용할 수 있는 연산은 다음과 같다.
1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
2. X가 2로 나누어 떨어지면, 2로 나눈다.
3. 1을 뺀다.

정수 N이 주어졌을 때, 위 연산 3개를 적절히 활용하여 1을 만들려고 한다.
연산을 사용하는 횟수의 최솟값을 출력하시오.
*/

#include <iostream>
#include <queue>
using namespace std;
#define OperatorType first
#define visited second

enum class Op : char {
    nothing = 0,
    plus1 = 1,
    multiply2 = 2,
    multiply3 = 3
};

struct State {
    int number;
    int depth;
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int input;
    cin >> input;

    vector<pair<Op, bool>> DP(input + 1, {Op::nothing, false}); //operator type, visited
    queue<State> BFSQueue;
    BFSQueue.push({1, 0});

    while (BFSQueue.empty() == false)
    {
        const auto& element = BFSQueue.front();
        if (element.number == input)
            break;

        if (element.number + 1 <= input && DP[element.number + 1].visited == false)
        {
            DP[element.number + 1] = {Op::plus1, true};
            BFSQueue.push({element.number + 1, element.depth + 1});
        }

        if (element.number * 2 <= input && DP[element.number * 2].visited == false)
        {
            DP[element.number * 2] = {Op::multiply2, true};
            BFSQueue.push({element.number * 2, element.depth + 1});
        }

        if (element.number * 3 <= input && DP[element.number * 3].visited == false)
        {
            DP[element.number * 3] = {Op::multiply3, true};
            BFSQueue.push({element.number * 3, element.depth + 1});
        }

        BFSQueue.pop();
    }
    
    cout << BFSQueue.front().depth << '\n';
    while (input != 1)
    {  
        cout << input << ' ';
        switch (DP[input].OperatorType) {
            case Op::plus1:
                input = input - 1;
                break;

            case Op::multiply2:
                input /= 2;
                break;
            
            case Op::multiply3:
                input /= 3;
                break;
        }
    }

    cout << 1;


	
	return 0;
}