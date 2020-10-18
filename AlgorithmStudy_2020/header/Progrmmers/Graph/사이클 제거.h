#include <bits/stdc++.h>
using namespace std;
const int MAX = 5000 + 1;
vector<int> adj[MAX];
//cnt는 이 node를 없앴을때 생기는 추가 컴포넌트의 개수
//dfsn-> 시작지점으로 부터 얼마나 depth가 들어갔는지 확인하는 변수
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
				//다음노드가 정상적으로 이번 노드 다음으로 방문하는 거라면
				if (temp > dfsn[current]) continue;
			}
			//다음 노드가 이전에 방문했고, 이 노드보다 더 깊게 만났더라면 => 사이클이라면
			//그 노드를 제거함으로서 cnt는 한개가 더 늘게된다.
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
		if (edges.size() - adj[i].size() + cnt[i] == n - 2) answer += i;
	}
	return answer;
}

/*
	(전체 간선의 수) - (i번 정점에 연결된 간선의 수) + (추가로 만들어지는 컴포넌트의 수) < (전체 정점의 수) - 1
	를 만족 시키는 노드가 우리가 원하는 노드.

	컴포넌트 1개 => node가 n`개 있다면 edge는 n`-1 개 있어야 함. -> 그 쪽도 사이클이 있으면 안되기 때문.
	ex) 원래 7개 였는데 1개를 제거 -> 2 / 2 / 2 이 됨
	-> edge의 개수 : 1 + 1 + 1 = 3 -> "3 + 2 (추가 컴포넌트) = n-2" 유지.
	-> 추가 컴포넌트의 개수 : 2

	DFS를 정말 끝까지 이해하고 있어야 풀 수 있는 문제.
	visited를 이용해서 이전에 방문했던 노드라면 사이클이다.
	라는 것을 이용해서 이전에 방문했던 노드이고, 깊이가 더 파여져있으면 그 노드를 없앴을때 추가 컴포넌트가 생긴다.
	라는 것은...
*/