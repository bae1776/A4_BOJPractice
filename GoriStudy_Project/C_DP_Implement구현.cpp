//[3] DP를 구현하는 방법.


//1. Bottom-up : for-loop를 이용하여 작은 부분문제부터 풀어나간다. 일반적인 방식.

//예시 : Bottom-up 방식의 피보나치 수열

long long dp[91];

long long fibo1(int x)
{
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= x; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	return dp[x];
}




//2. top-down : 큰 문제를 마주쳤을 때 부분문제로 나누어 그것부터 푼 뒤 다시 돌아와 큰 문제를 푼다.
//--> 이 때 이미 계산한 부분은 중복 계산하지 않도록 저장을 잘 해야함.

//Bottom-up보다 함수 호출 오버헤드가 좀 걸리긴 하지만
//방법만 알면 직관적 재귀로 구현할 수 있다.


//예시 : Top-down 방식의 피보나치 수열


long long fibo2(int x)
{
	//메모되었으면 그냥 저장된 값을 반환한다!
	if (dp[x] != 0) return dp[x];

	if (x <= 1) return x;
	return dp[x] = fibo2(x - 2) + fibo2(x - 1);   //return 구문의 연산자 연산 순서를 보면 중복되어 계산될 일은 없다.

}
