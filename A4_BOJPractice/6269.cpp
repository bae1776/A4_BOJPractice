//https://www.acmicpc.net/problem/6269

/*Team Arrangement (Silver ??)

등번호 순으로 포메이션에 맞게 선발 선수를 고른뒤, 조건에 따라 주장 선수를 정한다.
문자열 파싱이 귀찮다.
귀찮은 게 많은 구현 문제.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

enum {GOALKEEPER, DEFENDER, MIDFIELDER, STRIKER};

struct Player {
    int number;
    string name;
    char position;
    int teamPlayed;
};

Player playerList[22];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    string playerInput;
    
    
    while (true)
    {
        bool endOfInput = false;
        for (int i = 0; i < 22; i++)
        {
            //선수 입력 받기
            Player& newPlayer = playerList[i];
            getline(cin, playerInput);
            stringstream ss(playerInput);

            ss >> newPlayer.number;
            if (newPlayer.number == 0)
            {
                endOfInput = true;
                break;
            }

            ss >> newPlayer.name;
            ss >> newPlayer.position;
            
            newPlayer.teamPlayed = 0;
            string year;
            while (!ss.eof())
            {
                ss >> year;
                int endYear = stoi(year.substr(5, 4));
                int startYear = stoi(year.substr(0, 4));
                newPlayer.teamPlayed += endYear - startYear + 1;
            }
        }

        if (endOfInput)
            break;

        
        //포메이션
        string formation;
        getline(cin, formation);
        int formCount[4] = {1, formation[0] - '0', formation[2] - '0', formation[4] - '0'}; 

        //등번호 순 정렬하고 선발 선수 선정
        Player starterList[11];
        int starterNumber = 0;

        sort(playerList, playerList + 22, [](const Player& a, const Player& b) -> bool {
                return a.number < b.number;
        });

        for (int i = 0; i < 22 && starterNumber != 11; i++)
        {
            int pos;
            switch (playerList[i].position) {
                case 'G':
                    pos = GOALKEEPER; break;
                case 'D':
                    pos = DEFENDER; break;
                case 'M':
                    pos = MIDFIELDER; break;
                case 'S':
                    pos = STRIKER; break;
            }

            if (formCount[pos] == 0)
                continue;
            formCount[pos]--;

            starterList[starterNumber++] = playerList[i];
        }

        if (starterNumber == 11)
        {
            //선발 선수 중에서 주장 정하기
            sort(starterList, starterList + 11, [](const Player& a, const Player& b) -> bool {
                if (a.teamPlayed == b.teamPlayed)
                    return a.number > b.number;
                else 
                    return a.teamPlayed > b.teamPlayed;
            });

            //주장 외에는 포지션 -> 등번호 정렬
            sort(starterList + 1, starterList + 11, [](const Player& a, const Player& b) {
                if (a.position == 'G')
                    return true;
                else if (b.position == 'G')
                    return false;
                else {
                    if (a.position == b.position)
                        return a.number < b.number;
                    else
                        return a.position < b.position;
                }
            }); 
            for (int i = 0; i < 11; i++)
            {
                Player& selected = starterList[i];
                cout << selected.number << ' ' << selected.name << ' ' << selected.position << '\n';
            }
        } else {
            cout << "IMPOSSIBLE TO ARRANGE\n";
        }
        cout << '\n';
    }
    


	return 0;
}
