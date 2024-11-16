//https://www.acmicpc.net/problem/25206

/*너의 평점은 (Silver 5)
Solution : 딕셔너리 활용(C++ map) 그리고 가중평균

*/

#include <map>
#include <iostream>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<string, double> grade;

    grade["A+"] = 4.5;
    grade["A0"] = 4.0;
    grade["B+"] = 3.5;
    grade["B0"] = 3.0;
    grade["C+"] = 2.5;
    grade["C0"] = 2.0;
    grade["D+"] = 1.5;
    grade["D0"] = 1.0;
    grade["F"] = 0.0;

    string lec, gd;
    double credit;

    double up = 0, down = 0;

    for (int i = 0; i < 20; i++)
    {
        cin >> lec >> credit >> gd;

        if (grade.find(gd) != grade.end())
        {
            up += credit * grade[gd];
            down += credit;
        }
    }

    cout << up / down;



    return 0;
}
