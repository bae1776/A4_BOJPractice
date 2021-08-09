//https://www.acmicpc.net/problem/11066

/*파일 합치기

소설가 김대전은 소설을 여러 장으로 나누어 각각의 파일로 저장한다.
이후 파일을 두 개씩 합치는 작업을 하는데, 파일을 합치는 데 드는 비용은
두 파일 크기의 합이다.
합치는 순서를 적절히 하면, 모든 소설 원고를 합치는 총 비용을 줄일 수 있다.
합치는 비용의 최솟값을 구해 주자. 

*/

#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {

        int fileCount;
        cin >> fileCount;

        vector<vector<unsigned int>> fileDP(fileCount, vector<unsigned int>(fileCount, 0x7FFFFFFFu));
        vector<vector<unsigned int>> fileSize(fileCount);
        for (int i = 0; i < fileCount; i++)
        {
            fileDP[i][i] = 0;
            fileSize[i] = vector<unsigned int>(i + 1);
            cin >> fileSize[i][i];
        }
        
        for (int fileSum = 2; fileSum <= fileCount; fileSum++)
        {
            for (int startFile = 0; startFile <= fileCount - fileSum; startFile++)
            {
                const int endFile = startFile + fileSum - 1;
                fileSize[endFile][startFile] = fileSize[endFile][endFile] + fileSize[endFile-1][startFile];

                for (int slice = startFile; slice < endFile; slice++)
                    fileDP[startFile][endFile] = 
                    min(fileDP[startFile][endFile], fileDP[startFile][slice] + fileDP[slice + 1][endFile]);

                fileDP[startFile][endFile] += fileSize[endFile][startFile];
            }
        }
        cout << fileDP[0][fileCount - 1] << '\n';

    }
	return 0;
}

