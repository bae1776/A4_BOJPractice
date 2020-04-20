//[4] C++ STL 기초

//STL은 구현을 직접 안하고도 편하게 쓸 수 있게하는 툴이다.
//STL의 사용은 기본 자료구조와 알고리즘를 구현해보는 기회를 빼앗긴 하지만
//Problem Solving에서는 이 자료구조들을 구현하는 것뿐만이 아닌 어떻게 응용할지 생각하는 것이 더 중요하다.

//또한 STL은 검증되어 있다.  (아마 우리가 밑바닥부터 만드는 거보다 훨 잘 만들었을 것임)



//알고리즘 풀이에 가장 흔히 쓰는 STL을 써보자

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <tuple>
#include <stack>
#include <queue>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//1. vector
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	cout << v.size() << '\n';
	v.push_back(30);
	cout << v.size() << '\n';
	cout << v[0] << '\n';
	cout << v.empty() << '\n';  //0, false
	v.clear();






	//2. sort (algorithm 헤더)
	sort(v.begin(), v.end());					//오름차순 정렬
	sort(v.begin(), v.end(), greater<int>());	//cmp 함수 포함 (내림차순 정렬)  --> greater는 functional 헤더 함수임






	//3. pair (utility 헤더)
	pair<int, int> p[5]; 

	p[0] = make_pair(100, 1); 
	p[1] = make_pair(10, 120); 
	p[2] = make_pair(5, 120); 
	p[3] = make_pair(5, 1); 
	p[4] = make_pair(50, -100);

	sort(p, p + 5); // 기본적으로 first->second 내림 차순으로 정렬함.

	for (int i = 0; i < 5; i++) 
	{ 
		cout << "(" << p[i].first << "," << p[i].second << ") "; 
	} 
	// 출력 : (5,1) (5,120) (10,120) (50,-100) (100,1)





	//4. tuple (2개 이상의 값 모임을 저장할 때 씀)
	tuple<int, string, double> tp; 
	tp = make_tuple(46, "Best gardener", 4.6);

	int first = get<0>(tp);			// first = 46 
	string second = get<1>(tp);		// second = "Best gardener" 
	double third = get<2>(tp);		// third = 4.6
	//tuple도 기본적인 sort cmp가 존재함





	//5. stack

	stack<int> st;
	st.push(1);				// 스택에 1 추가 
	st.push(2);				// 스택에 2 추가 
	int a = st.top();		// 스택의 제일 위에 있는 값 반환 (여기서는 2) 
	st.pop();				// 스택의 제일 위에 있는 값 삭제 (반환 없음)
	cout << st.size();		// 스택의 크기 (데이터 수) 반환

	if (st.empty()) 
	{ 
		cout << "스택이 비었다!\n"; 
	}
	else { 
		cout << "스택에 뭔가 있다!\n"; 
	}





	//6. queue

	queue<int> q;
	q.push(1);			// 큐에 1 추가 
	q.push(2);			// 큐에 2 추가 
	int a = q.front();	// 큐의 제일 앞에 있는 값 반환 (여기서는 1) 
	q.pop();			// 큐의 제일 앞에 있는 값 삭제 
	cout << q.size();	// 큐의 크기 (데이터 수) 반환

	if (q.empty()) {
		cout << "큐가 비었다!\n";
	}
	else { 
		cout << "큐에 뭔가 있다!\n"; 
	}



	//7. deque     (양쪽에서 push, pop 모두 가능한 큐)
	//• #include <deque> 
	//• push_front(), push_back() 
	//• pop_front(), pop_back() 
	//• front(), back()

	//메소드 stack, queue랑 거의 차이 없음






	return 0;
}
