//https://www.acmicpc.net/problem/2527

/* 직사각형 (Silver 1)

2차원 격자 공간 상에 직사각형이 왼쪽 아래 점, 오른쪽 윗점 좌표가 주어진다. 
각 줄에 두 직사각형의 좌표 정보가 주어진다 (정수 8개)

이때, 두 직사각형이 직사각형으로 겹치면 a, 선분으로만 겹치면 b, 
점으로 겹치면 c, 안 겹치면 d를 출력하여라. 

Solution : 구현
어떤 한 직사각형을 기준으로, 한 직사각형 ABCD에 대하여
다른 직사각형 EFGH의 각 선분 EF, FG, GH, HE가
ABCD를 점 겹침, 변 겹침, 내부 통과, 외부 중 무엇에 해당하는지 구한다.

다음 조건문 순서로 처리한다.
1. 내부에 하나라도 있으면 무조건 a.
2. 네 선분 모두 외부에 있는 경우, EFGH가 ABCD를 감싸면 a, 아니면 d 이다.
3. 변 겹침이 오직 1개인 경우는 EFGH가 ABCD를 감싸면 a, 아니면 b.
   2개 이상인 경우에는 a이다.
4. 위 3개 모두에 해당하지 않는 경우 c 이다. 
*/

#include <iostream>
#include <deque>
using namespace std;

enum { OUTER, INNER, LINE, DOT}; //한 선분이 한 직사각형의 어디에 있는가?

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int aLeftx, aLefty, aRightx, aRighty, bLeftx, bLefty, bRightx, bRighty;
    for (int i = 0; i < 4; i++)
    {
        cin >> aLeftx >> aLefty >> aRightx >> aRighty >> 
               bLeftx >> bLefty >> bRightx >> bRighty;

        int record[4] = {0};

        int pivotDot = bLefty;
        //하변에 대한 판정
        if (aLefty < pivotDot && pivotDot < aRighty)
        {
            if ((aLeftx < bLeftx && bLeftx < aRightx) || (aLeftx < bRightx && bRightx < aRightx))
                // -------|-         |
                record[INNER]++;
            else if (bLeftx <= aLeftx && aRightx <= bRightx)
                // -------|----------|-------
                record[INNER]++;
            else if (bRightx == aLeftx || aRightx == bLeftx)
                // -------|          |
                record[DOT]++;
            else
                record[OUTER]++;
        } else if (aLefty == pivotDot || pivotDot == aRighty) {
            if ((aLeftx < bLeftx && bLeftx < aRightx) || (aLeftx < bRightx && bRightx < aRightx))
                record[LINE]++;
            else if (bLeftx <= aLeftx && aRightx <= bRightx)
                record[LINE]++;
            else if (bRightx == aLeftx || aRightx == bLeftx)
                record[DOT]++;
            else
                record[OUTER]++;
        } else {
            record[OUTER]++;
        }

        pivotDot = bRighty;
        //상변에 대한 판정
        if (aLefty < pivotDot && pivotDot < aRighty)
        {
            if ((aLeftx < bLeftx && bLeftx < aRightx) || (aLeftx < bRightx && bRightx < aRightx))
                // -------|-         |
                record[INNER]++;
            else if (bLeftx <= aLeftx && aRightx <= bRightx)
                // -------|----------|-------
                record[INNER]++;
            else if (bRightx == aLeftx || aRightx == bLeftx)
                // -------|          |
                record[DOT]++;
            else
                record[OUTER]++;
        } else if (aLefty == pivotDot || pivotDot == aRighty) {
            if ((aLeftx < bLeftx && bLeftx < aRightx) || (aLeftx < bRightx && bRightx < aRightx))
                record[LINE]++;
            else if (bLeftx <= aLeftx && aRightx <= bRightx)
                record[LINE]++;
            else if (bRightx == aLeftx || aRightx == bLeftx)
                record[DOT]++;
            else
                record[OUTER]++;
        } else {
            record[OUTER]++;
        }

        pivotDot = bLeftx;
        //좌변 판정
        if (aLeftx < pivotDot && pivotDot < aRightx)
        {
            if ((aLefty < bLefty && bLefty < aRighty) || (aLefty < bRighty && bRighty < aRighty))
                // -------|-         |
                record[INNER]++;
            else if (bLefty <= aLefty && aRighty <= bRighty)
                // -------|----------|-------
                record[INNER]++;
            else if (bRighty == aLefty || aRighty == bLefty)
                // -------|          |
                record[DOT]++;
            else
                record[OUTER]++;
        } else if (aLeftx == pivotDot || pivotDot == aRightx) {
            if ((aLefty < bLefty && bLefty < aRighty) || (aLefty < bRighty && bRighty < aRighty))
                record[LINE]++;
            else if (bLefty <= aLefty && aRighty <= bRighty)
                record[LINE]++;
            else if (bRighty == aLefty || aRighty == bLefty)
                record[DOT]++;
            else
                record[OUTER]++;
        } else {
            record[OUTER]++;
        }

        pivotDot = bRightx;
        //우변 판정
        if (aLeftx < pivotDot && pivotDot < aRightx)
        {
            if ((aLefty < bLefty && bLefty < aRighty) || (aLefty < bRighty && bRighty < aRighty))
                // -------|-         |
                record[INNER]++;
            else if (bLefty <= aLefty && aRighty <= bRighty)
                // -------|----------|-------
                record[INNER]++;
            else if (bRighty == aLefty || aRighty == bLefty)
                // -------|          |
                record[DOT]++;
            else
                record[OUTER]++;
        } else if (aLeftx == pivotDot || pivotDot == aRightx) {
            if ((aLefty < bLefty && bLefty < aRighty) || (aLefty < bRighty && bRighty < aRighty))
                record[LINE]++;
            else if (bLefty <= aLefty && aRighty <= bRighty)
                record[LINE]++;
            else if (bRighty == aLefty || aRighty == bLefty)
                record[DOT]++;
            else
                record[OUTER]++;
        } else {
            record[OUTER]++;
        }

        /*
        다음 조건문 순서로 처리한다.
        1. 내부에 하나라도 있으면 무조건 a.
        2. 네 선분 모두 외부에 있는 경우, EFGH가 ABCD를 감싸면 a, 아니면 d 이다.
        3. 변 겹침이 오직 1개인 경우는 EFGH가 ABCD를 감싸면 a, 아니면 b.
            2개 이상인 경우에는 a이다.
        4. 위 3개 모두에 해당하지 않는 경우 c 이다.
*/      
        if (record[INNER])
        {
            cout << "a\n";
        } else if (record[OUTER] == 4) {
            if (bLeftx < aLeftx && bLefty < aLefty && aRightx < bRightx && aRighty < bRighty)
                cout << "a\n";
            else
                cout << "d\n";
        } else if (record[LINE] == 1) {
            if (bLeftx <= aLeftx && bLefty <= aLefty && aRightx <= bRightx && aRighty <= bRighty)
                cout << "a\n";
            else
                cout << "b\n";
        } else if (record[LINE] >= 2) {
            cout << "a\n";
        } else {
            cout << "c\n";
        }
    }
            
	return 0;
}
