#include <bits/stdc++.h>
using namespace std;
const int MAX = 5000 + 1;
vector<int> adj[MAX];
//cnt는 이 node를 없앴을때 생기는 추가 컴포넌트의 개수
int cnt[MAX], dfsn[MAX], dcnt;

int dfs(int current, int parent) {
	int temp, ret = dfsn[current] = dcnt++;
	for (int next : adj[current]) {
		//다음 노드가 parent가 아닐때
		if (next != parent) {
			//다음 노드를 방문한적 없으면 방문
			if (dfsn[next] == -1)
				temp = dfs(next, current);
			//다음 노드를 방문했으면
			else {
				temp = dfsn[next];
				if (temp > dfsn[current]) continue;
			}
			if (temp >= dfsn[current]) ++cnt[current];
			ret = min(temp, ret);
		}
	}
	//첫항 예외 처리
	if (parent == -1) cnt[current] = max(0, cnt[current] - 1);
	return ret;
}

int solution(int n, vector<vector<int>> edges) {
	int answer = 0;
	//각 node별 간선의 개수 파악
	for (int i = 0; i < edges.size(); i++) {
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}

	fill_n(dfsn, MAX, -1);
	dfs(1, -1);


	//연결 그래프 상에서 사이클이 없을려면(tree) edge의 개수는 node-1
	//될수 있는 노드의 개수 파악.
	for (int i = 1; i <= n; i++) {
		if (edges.size() - adj[i].size() + cnt[i] < n - 1) answer += i;
	}
	return answer;
}

/*
	(전체 간선의 수) - (i번 정점에 연결된 간선의 수) + (추가로 만들어지는 컴포넌트의 수) < (전체 정점의 수) - 1
	를 만족 시키는 노드가 우리가 원하는 노드.
*/