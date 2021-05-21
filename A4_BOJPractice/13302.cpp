//https://www.acmicpc.net/problem/13302

//리조트
//여름방학을 맞아 리조트를 예약하려고 한다.
//리조트에 예약할 수 있는 방법은 다음과 같다.
//1. 하루 이용권, 10000원
//2. 연속 3일권, 25000원, 쿠폰 1장
//3. 연속 5일권, 37000원, 쿠폰 2장
//쿠폰 3장을 모으면 무료 하루 이용권을 얻을 수 있다.
//여름방학의 기간과, 그중 리조트에 가지 않는 날이 주어질 때, 가장 싸게 예약할 때의 금액을 구하시오.
//여름방학은 최대 100일이다.


#include <iostream>
#include <vector>
#define INF 0x1FFFFFFF
using namespace std;

int main(void)
{
    int day, nonVisitCount;
    cin >> day >> nonVisitCount;

    vector<bool> visit(day + 1, true);
    for (int i = 0; i < nonVisitCount; i++)
    {
        int nonVisitDay;
        cin >> nonVisitDay;

        visit[nonVisitDay] = false;
    }

    vector<vector<int>> DP(day + 1, vector<int>(day + 1, INF));
    DP[0][0] = 0;

    for (int dayCount = 1; dayCount <= day; dayCount++)
    {
        int notVisits = 0;
        for (int nDay = dayCount; nDay >= 1; nDay--)
            if (visit[nDay] == false)
                notVisits++;
            else
                break;
        
        for (int coupon = 0; ; coupon++)
        {
            
            if (notVisits >= 5) //buy 5 series day (if needed)
                for (int i = 1; i <= 5; i++)
                    DP[dayCount][coupon] = min(DP[dayCount][coupon], DP[dayCount-i][coupon]);            else if (dayCount >= 5 && coupon >= 2)
                DP[dayCount][coupon] = min(DP[dayCount][coupon], DP[dayCount-5][coupon-2] + 37000);
            
            if (notVisits >= 3) //buy 3 series day (if needed)
                for (int i = 1; i <= 3; i++)
                    DP[dayCount][coupon] = min(DP[dayCount][coupon], DP[dayCount-i][coupon]);
            else if (dayCount >= 3 && coupon >= 1) 
                DP[dayCount][coupon] = min(DP[dayCount][coupon], DP[dayCount-3][coupon-1] + 25000);
            
            
            if (notVisits >= 1) 
                DP[dayCount][coupon] = min(DP[dayCount][coupon], DP[dayCount - 1][coupon]);
            else {
                //buy 1 day (if needed)
                DP[dayCount][coupon] = min(DP[dayCount][coupon], DP[dayCount - 1][coupon] + 10000);
                //get 1 day using coupon (if needed)
                if (dayCount >= 9)
                    DP[dayCount][coupon] = min(DP[dayCount][coupon], DP[dayCount - 1][coupon + 3]);
            }


            if (DP[dayCount][coupon] == INF)
                break;
        }
    }

    int result = INF;

    for (const int& lastDayDP : DP[day])
        result = min(result, lastDayDP);

    cout << result;

    

    return 0;
}
