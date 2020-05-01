//[Tips] memset은 0으로도, -1로도 초기화 할 수 있다.

#include <iostream>

int main(void)
{
	int ary[100];
	//--> memset으로 모든 값을 -1로 쉽게 초기화 할 수 있다.
	//memset은 1바이트 단위로 초기화하지만, 
	//-1로 초기화 값을 주면, 모든 비트가 -1이 되는데,
	//이 경우 어떤 자료형이든 모두 값은 -1이 된다.
	memset(ary, -1, sizeof(ary));


	//알고리즘을 풀려고 배열을 만들때, -1을 undetermined 상태로 쓰면 편리하다.
	//특히 DP에서 배열에 0도 포함될 수 있는 경우
	//(배열값) == -1을 unmemorized 로 간주 할 수 있을 것이다.


	return 0;
}