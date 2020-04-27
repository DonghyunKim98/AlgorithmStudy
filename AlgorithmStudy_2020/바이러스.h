#include <bits/stdc++.h>
//2606번 문제 -> (맞았음)
using namespace std;

//컴포넌트에 있는 노드 개수를 구하는 문제

vector<int> adj[100];
bool visited[100] = { false ,};
int cnt=0;

void dfs(int s) {
	if (visited[s]) return;
	visited[s] = true;
	cnt++;
	for (auto u : adj[s]) {
		dfs(u);
	}
}

void Virus() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		adj[temp1].push_back(temp2);
		adj[temp2].push_back(temp1);
	}
	dfs(1);
	cout << cnt-1<<endl;
}

/*
	공부해야할 점
	1) count 변수는 std 라이브러리에도 있다 그래서 전역변수로 선언하면,
	모호하다고 한다. 다른 변수로 바꾸어주자.
	2) 내가 처음 짠 대로 하면 1번 컴퓨터까지 카운팅을 하는것이기 때문에 마지막에 하나를 빼준다.
*/