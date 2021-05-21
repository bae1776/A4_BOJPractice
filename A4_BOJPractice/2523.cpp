//https://www.acmicpc.net/problem/2523

//별 찍기 - 13
//브론즈 3 레벨의 쉬운 별 찍기 문제
//라인 수가 주어질 때, 다음과 같이 별을 찍으세요 (예시 : line = 3)
//*
//**
//***
//**
//*

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int lineCount;
    cin >> lineCount;

    for (int star = 1; star < lineCount; star++)
    {
        for (int i = 0; i < star; i++)
            cout << '*';
        cout << '\n';
    }
    for (int i = 0; i < lineCount; i++)
        cout << '*';
    cout << '\n';
    for (int star = lineCount - 1; star > 0; star--)
    {
        for (int i = 0; i < star; i++)
            cout << '*';
        cout << '\n';
    }
    
    return 0;
}
