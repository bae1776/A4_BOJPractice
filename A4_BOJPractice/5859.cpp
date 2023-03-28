//https://www.acmicpc.net/problem/5859

/*Liars and Truth Tellers (Gold 2)
문제 번역 :
최대 1000마리의 소가 대화를 하는데 누구는 항상 진실, 누구는 항상 거짓을 말한다.
농부 존은 소들로 부터 x y T 꼴로 최대 10000개의 진술을 듣는다.
예를 들어, 2 5 L은 2번 소가 5번 소는 항상 거짓말을 한다고 주장하는 진술이다. (T이면 진실)
농부 존이 듣는 진술을 순서대로 검토할 때 몇 번째 진술까지 
모두 참이 될 수 있는지 (모순이 없는지) 구하시오.

Solution : 논리학, Disjoint Set

a. A는 B를 진실하다고 한다. : A가 거짓말하는 소면, B도 거짓말하는 소. 반대로도 같다.
b. A는 B를 거짓하다고 한다. : A가 거짓말하는 소면, B는 진실한 소이다. 반대로도 같다.
그런데, A가 진실한지 거짓한지는 지금까지의 진술로는 알 수도 있고 모를 수도 있다.
그래서 a. 진술일 때는 A, B를 같은 집합. b. 진술일 때는 대치되는 집합으로 묶는다.

이어 나오는 진술이 모순되는 경우는,
A, B가 이미 같은 집합인데, b. 진술이 나오는 경우.
A, B가 이미 대치 집합인데, a. 진술이 나오는 경우. 이다.

위 아이디어를 구현하는 방법은 Disjoint Set 알고리즘이 가장 최적이며,
추가로 conflict 배열을 추가해 대립 관계를 표현한다.
*/

#include <iostream>
using namespace std;
#define NODE 1001
int root[NODE], uRank[NODE], conflict[NODE];

int& union_find(const int& num);
bool union_merge(int a, int b);
bool make_conflict(int a, int b);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int cow, statement;
    cin >> cow >> statement;

    for (int i = 1; i <= cow; i++)
    {
        root[i] = i;
        uRank[i] = 1;
    }

    int answer = 0;
    bool bound = true;
    while (statement--)
    {
        int teller, target; char what;
        cin >> teller >> target >> what;

        if (bound == true)
        {
            if (what == 'T')
                bound = union_merge(teller, target);
            else if (what == 'L')
                bound = make_conflict(teller, target);
        }

        if (bound == true)
            answer++;
    }

    cout << answer;
    return 0;
}


int& union_find(const int& num)
{
    if (root[num] == num)
        return root[num];
    else
        return root[num] = union_find(root[num]);
}

bool union_merge(int a, int b)
{
    a = union_find(a);
    b = union_find(b);
    conflict[a] = union_find(conflict[a]);
    conflict[b] = union_find(conflict[b]);

    if (a == b)
        return true;
    
   

    if (conflict[a] == b || conflict[b] == a)
        return false;
    
    if (uRank[a] < uRank[b])
    {
        root[a] = b;
    } else {
        root[b] = a;
        if (uRank[a] == uRank[b])
            uRank[a]++; 
    }

    if (conflict[a] != 0 && conflict[b] != 0)
        return union_merge(conflict[a], conflict[b]);
    else   
        return true;
}


bool make_conflict(int a, int b)
{
    a = union_find(a);
    b = union_find(b);
    conflict[a] = union_find(conflict[a]);
    conflict[b] = union_find(conflict[b]);
    
    if (a == b)
        return false;
    
    bool bound;
    if (conflict[a] != 0 && conflict[b] != 0)
        bound = union_merge(a, conflict[b]) && union_merge(b, conflict[a]);
    else if (conflict[a] != 0)
        bound = union_merge(b, conflict[a]);
    else if (conflict[b] != 0)
        bound = union_merge(a, conflict[b]);
    else
        bound = true;

    conflict[a] = b; conflict[b] = a;

    return bound;
}