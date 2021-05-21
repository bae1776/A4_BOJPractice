//https://www.acmicpc.net/problem/14454

//Secret Cow Code
//소들은 프로그래밍에 쓸 무한한 길이의 문자열을 만들 수 있는 시크릿 코드를 고안하고 있다.
//문자열 S에 대하여, F(S)는 S에 뒤이어 오른쪽으로 "돌아간" S가 이어져 있는 문자열로 정의한다.
//오른쪽 회전은 s의 마지막 문자가 첫 번째 문자로 옮겨진다는 것을 의미한다.
//F(S)를 무한 적용하면 무한한 문자열이 만들어진다.
//예시 : S = COW 일때 F(S)=COWWCO, F(F(S))=COWWCOOCOWWC ...

//문자열 S(최대 30자, 영대문자로만 구성)와 정수 N(~10^18)이 주어질때
//무한한 문자열의 N번째 인덱스에 있는 문자를 구하세요. 첫 문자의 인덱스는 1이다.


#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    char initString[31];
    long long index;
    cin >> initString >> index;

    long long infStr_length, INIT_LENGTH = 0;
    while (initString[++INIT_LENGTH] != '\0');
    
    infStr_length = INIT_LENGTH;
    
    while (infStr_length < index)
        infStr_length *= 2;

    while (infStr_length > INIT_LENGTH)
    {
        if (index > infStr_length / 2) //if index in rotated(2nd) half
        {
            infStr_length /= 2;
            index -= infStr_length;
            //rollback rotating
            if (index == 1)
                index = infStr_length;
            else
                index--;
        } else {
            infStr_length /= 2;
        }
    }

    cout << initString[index - 1];


	return 0;
}
