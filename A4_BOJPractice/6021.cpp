//https://www.acmicpc.net/problem/6021 (문제 번호)

/*DNA Sequencing

*/

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

vector<string> bullsDNA;
vector<string> cowsDNA;

bool DNA_match(const string& father, const string& mother, const string& candiChild);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int bullCount, cowCount;
    cin >> bullCount >> cowCount;

    bullsDNA = vector<string>(bullCount);
    cowsDNA = vector<string>(cowCount);

    for (int i = 0; i < bullCount; i++)
        cin >> bullsDNA[i];
    
    for (int i = 0; i < cowCount; i++)
        cin >> cowsDNA[i];

    vector<vector<int>> result(bullCount, vector<int>(cowCount, 0));

    for (int bullNumber = 0; bullNumber < bullCount; bullNumber++)
        for (int cowNumber = 0; cowNumber < cowCount; cowNumber++)
        {
            const string& father = bullsDNA[bullNumber];
            const string& mother = cowsDNA[cowNumber];

            for (const auto& child : bullsDNA)
                result[bullNumber][cowNumber] += DNA_match(father, mother, child);
                
            for (const auto& child : cowsDNA)
                result[bullNumber][cowNumber] += DNA_match(father, mother, child);
            
        }



    for (int i = 0; i < bullCount; i++)
    {
        for (int j = 0; j < cowCount; j++)
            cout << result[i][j] - 2 << ' ';
        cout << '\n';
    }

	return 0;
}


bool DNA_match(const string& father, const string& mother, const string& candiChild)
{
    const static bitset<25> fullBit("1111111111111111111111111");

    bitset<25> fatherBit;
    bitset<25> motherBit;

    for (int index = 0; index < 25; index++)
    {
        fatherBit[index] = (father[index] == candiChild[index]);
        motherBit[index] = (mother[index] == candiChild[index]);
    }

    return (fatherBit | motherBit) == fullBit; 
}