#include <bits/stdc++.h>
//14866번 문제
//프로그래머스 "사이클제거" 와 동일 문제.
using namespace std;
const int MAX = 300000 + 1;
vector<int> adj[MAX];
int cnt[MAX], dfsn[MAX], dcnt;

int dfs(int current, int parent) {
	int temp;
	int ret = dfsn[current] = dcnt++;
	for (int next : adj[current]) {
		if (next != parent) {
			if (dfsn[next] == -1)
				temp = dfs(next, current);
			else {
				temp = dfsn[next];
				if (temp > dfsn[current]) continue;
			}
			if (temp >= dfsn[current]) ++cnt[current];
			ret = min(temp, ret);
		}
	}
	//첫항 예외 처리 -> 반드시 사이클은 존재하기 때문.
	if (parent == -1) cnt[current] = max(0, cnt[current] - 1);
	return ret;
}
void Solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, M;
	cin >>  N >> M;
	for (int i = 0; i < M; i++) {
		int current, next;
		cin >> current >> next;
		adj[current].push_back(next);
		adj[next].push_back(current);
	}

	fill_n(dfsn, MAX, -1);
	dfs(1, -1);

	long long int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (M - adj[i].size() + cnt[i] < N - 1) answer += i;
	}
	cout << answer;
}

/*
	단절점(Articulation Point)에 대한 이해가 필요한 문제
	=> 초록책이랑 종만북에서 개념 볼것.
*/