#include <bits/stdc++.h>

//1260번 문제 ->풀었음!
//https://blog.naver.com/hwasub1115/221183031039 참고

using namespace std;
//인접리스트 형태의 그래프
vector<int> adj[1001];
//DFS를 위한 준비
bool visited[1001] = { false, };
//BFS를 위한 준비
queue <int> q;

int N, M, X;

void DFS(int s) {
	if (visited[s]) return;
	visited[s] = true;
	cout << s << ' ';
	for (int y : adj[s]) {
		DFS(y);
	}
}

void BFS(int x) {	
	visited[x] = true;
	q.push(x);
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		//노드 s 처리
		cout << s << ' ';
		for (int y: adj[s]) {
			if (visited[y]) continue;
			visited[y] = true;
			q.push(y);
		}	
	}
}

void Init() {
	for (int i = 1; i <= 1000; i++) visited[i] = false;
}

void DFS_BFS() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	//X는 시작노드
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		adj[temp1].push_back(temp2);
		adj[temp2].push_back(temp1);
	}

	//작은 번호부터 방문해야 하므로 정렬
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(),adj[i].end());
	}

	DFS(X);
	cout << "\n";
	Init();
	BFS(X);
}

/*
	공부할 점
	1) index 넘버링에 주의. 배열을 1001까지 선언해야한다.
	2) 문제 조건중 "방문할 수 있는 정점이 여러 개인 경우 정점 번호가 작은 것을 먼저 방문" 을 해결해야함
	-> sorting 으로 해결.
	3) distance 는 문제 해결 과정에서 쓸모 없고 visited는 굳이 2개를 선언할 이유X
	-> 메모리를 아껴야함.
*/