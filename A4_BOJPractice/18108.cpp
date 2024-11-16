//https://www.acmicpc.net/problem/18108

/*1998년생인 내가 태국에서는 2541년생?! (Bronze 5)
Solution : 사칙연산


*/

#include <iostream>
#include <string>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int y;
    cin >> y;
    cout << y - 2541 + 1998;
    return 0;
}

