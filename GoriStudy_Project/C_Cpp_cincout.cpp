//[3] C++ 입출력

//알고리즘에 프로그래밍 언어는 뭘 쓰든 상관이 없지만
//알고리즘 풀이에서 점유율이 높아 더 방대하고 또한 빠르므로 C++을 추천한다.
//주력 언어가 따로 있지 않으면 C++


//#include <bits/stdc++.h>   :  많이 사용하는 표준 라이브러리들이 거의 다 포함되있음. 컴파일 시간만 늘어나지 실행 시간엔 지장 X
//Visual Studio에선 사용 불가



//1. C++ 입출력


#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//이 두 줄은 C 방식의 입출력과의 Sync 기능을 없애 printf, scanf를 못 쓰게 하지만
	//cout, cin의 속도를 증가시켜준다.


	int a, b;

	cin >> a >> b;
	cout << a + b << '\n';	//endl을 쓰면 출력 버퍼를 항상 지우므로 엄청 느려진다.



	//추가 기능

	//1. 입력 버퍼 삭제
	cin.ignore();

	//2. 콤마를 포함한 순서쌍 등등을 입력받기
	int c, d;
	char comma;
	cin >> c >> comma >> d;		// 중간에 char 입력을 받아주면 된다. 3,5도 잘 받고, 3, 5도 잘 받는다.

	cout << c << " and " << d << '\n';
}