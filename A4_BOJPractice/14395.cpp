//https://www.acmicpc.net/problem/14395

/* 4연산 (Gold 5)

정수 s를 t로 바꾸는 최소 연산 횟수 및 그 연산을 구하세요.
가능한 방법이 여러 가지인 경우, 사전 순으로 앞서는 것을 출력하세요. (*+-/ 순)
1. s = s + s, 2. s = s - s, 3. s = s * s, 4. s = s / s (s!=0)
s, t는 10억 이하의 자연수

Solution :
나눗셈 연산은 즉시 1로 만든다.
빼기 연산은 쓸 수 없다.

그러면 더하기, 곱하기 연산만 되는데,
더하기는 * 2 연산이고, 곱하기는 제곱 연산이다.
결론적으로, t = t의 배수 이거나, t = 2^n 일 때에만 (은 0 이상 정수)
연산이 가능할 수도 있다.
*/

#include <iostream>
#include <queue>
#include <map>
using namespace std;

string bfs(int start, int target);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int start, target;
    cin >> start >> target;

    string answer1, answer2 = "/";
    bool one = false, two = false;
    if (start == target)
    {
        cout << 0;
        return 0;
    }

    if (target % start == 0)
    {
        map<int, int> root;
        queue<int> bfsQueue;
        bfsQueue.push(start);
        root[start] = start;
        
        while (bfsQueue.empty() == false)
        {
            int now = bfsQueue.front();
            if (now == target)
            {
                one = true;

                while (now != start)
                {
                    if (root[now] == now / 2 && now != 4)
                        answer1 += '+';
                    else
                        answer1 += '*';
                    now = root[now];
                }

                for (int i = 0; i < answer1.size() / 2; i++)
                    swap(answer1[i], answer1[answer1.size() - 1 - i]);

                break;        
            }
            bfsQueue.pop();

            int value;
            if (now <= 40000 && 
                root.find(value = now * now) == root.end() && value <= target)
            {
                root[value] = now;
                bfsQueue.push(value);
            }

            if (root.find(value = 2 * now) == root.end() && value <= target)
            {
                root[value] = now;
                bfsQueue.push(value);
            }
        }
    }

    int pow = 0;
    for (int num = 1; num <= target; num *= 2, pow++)
    {
        if (num == target)
        {
            two = true;
            if (num == 1) break;
            
            while (pow != 0)
            {
                if (pow % 2) answer2 += '+';
                pow >>= 1;
                if (pow) answer2 += '*'; 
            }

            for (int i = 1; i <= answer2.size() / 2; i++)
                swap(answer2[i], answer2[answer2.size() - i]);

            break;
        }
    }

    if (one == true && two == true)
    {
        if (answer1.size() <= answer2.size())
            cout << answer1;
        else
            cout << answer2;
    } else if (one == true)
        cout << answer1;
    else if (two == true)
        cout << answer2;
    else
        cout << -1;

            
	return 0;
}

