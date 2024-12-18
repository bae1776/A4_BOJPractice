//[1] 그래프

//그래프에 간단한 내용들은 생략한다.  : Vertex(Node), Edge, Directed, Weighted



//1. 연결 그래프

//주어진 모든 정점이 모두 연결되어 있으면 연결 그래프(Connected graph)라고 한다.
//이런 정의가 있는 이유는, 모든 주어진 정점이 연결되지 않아도 그래프라고 할 수 있기 때문이다.

//그래프의 연결 요소(Connected component)라는 개념이 있는데, 서로 연결되어 있는 쌍의 갯수이다.
//연결 그래프의 경우 연결 요소가 1개이다.

/* Ex)

1 -- 2      4--5--6
 \         /
  \       7    8
   3            \
                 9

--> 연결 요소가 3개인 그래프 라고 할 수 있다.

*/




//2. 그래프 표현 방법

/*
A. 인접 행렬(Adjacency Matrix)

adj[A][B] : A->B로 가는 간선이 존재하는가? (+ 가중치 표현)
존재하면 1, 존재하지 않으면 0.

- 공간복잡도 : O(V^2)    V는 정점의 수
- 시간복잡도 : O(1)
- 특정 노드와 인접한 노드 확인 시간복잡도 : O(V)

정점이 많고 간선이 매우 적은 그래프는 인접 행렬이 공간을 많이 차지한다.



B. 인접 리스트(Adjacency List)
adj[A] : A와 연결되어 있는 정점 리스트.
C++ vector를 이용하면 편리하다.

pair와 같이 응용하면 (인접 노드 번호, 가중치)로 Weighted Graph까지도 표현할 수 있다.

- 공간복잡도 : O(V + E)
- 시간복잡도 : 최악일때 O(E)

DFS, BFS 탐색시에는 인접리스트가 시간복잡도 면에서 유리하다 : O(V+E)    [인접 행렬 : O(V^2)]


두 방식 모두 일장일단이 있으므로 문제에 따라 골라야한다.
*/