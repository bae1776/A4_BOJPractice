//https://www.acmicpc.net/problem/1677

/*음악 (Gold 1)
Solution : 다이나믹 프로그래밍 with 비트마스킹

DP[지금까지 연주된 A 악보 길이][지금까지 연주된 B 악보 길이][지금까지 연주된 C 악보 길이][이번에 연주된 ABC(bitmask)]
로 놓으면 해결할 수 있다.
초기 조건 잡는 게 빡시다.
*/

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int DP[102][102][102][8];
string s1, s2, s3;

int& DPFunction(int a, int b, int c, int bit);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill((int*)DP, (int*)DP + sizeof(DP) / sizeof(int), -2);
    DP[0][0][0][0] = -1;
    DP[0][0][0][1] = 0;

    int ans = -1;

    cin >> s1 >> s2 >> s3;
    int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();


    for (int bit = 0b111; bit >= 0b001; bit--)
        ans = max(ans, DPFunction(len1, len2, len3, bit));

    cout << ans;

    return 0;
}


int& DPFunction(int a, int b, int c, int bit)
{
    if (a == 0 && b == 0 && c == 0)
        return DP[0][0][0][1]; // 0
    if (a - (bit & 0b100) / 4 < 0 || b - (bit & 0b10) / 2 < 0 || c - (bit & 0b1) < 0)
        return DP[0][0][0][0]; // -1
    if (DP[a][b][c][bit] != -2)
        return DP[a][b][c][bit];

    int score;
    switch (bit) {
    case 0b110:
        score = s1[a - 1] == s2[b - 1]; break;
    case 0b101:
        score = s1[a - 1] == s3[c - 1]; break;
    case 0b011:
        score = s2[b - 1] == s3[c - 1]; break;
    case 0b111:
        score = ((s1[a - 1] == s2[b - 1]) && (s2[b - 1] == s3[c - 1])) * 3; break;
    default:
        score = 0;
    }

    DP[a][b][c][bit] = -1;
    for (int prevBit = 0b111; prevBit >= 0b001; prevBit--)
    {
        if ((prevBit | bit) != 0b111) continue;
        int& prev = DPFunction(a - (bit & 0b100) / 4, b - (bit & 0b10) / 2, c - (bit & 0b1), prevBit);
        if (prev >= 0)
            DP[a][b][c][bit] = max(DP[a][b][c][bit], prev + score);
    }

    return DP[a][b][c][bit];
}