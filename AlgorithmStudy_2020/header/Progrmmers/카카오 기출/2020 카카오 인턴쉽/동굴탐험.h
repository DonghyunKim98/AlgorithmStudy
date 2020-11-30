#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000 + 1;
bool answer = true;
bool visited[MAX];
bool finished[MAX]; // 사이클 여부를 판단하기 위한 배열
vector <int> biDirAdj[MAX]; // 양방향 그래프
vector <int> oneDirAdj[MAX]; // 단방향 그래프
void DFS(int curNode) {
	if (answer == false) return;
	visited[curNode] = true;
	for (auto u : oneDirAdj[curNode]) {
		if (visited[u] == false) DFS(u);
		else if (finished[u]==false){
			answer = false;
			return;
		}
	}
	finished[curNode] = true;
	return;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	// 양방향 그래프
	for (auto p : path) {
		biDirAdj[p[0]].push_back(p[1]);
		biDirAdj[p[1]].push_back(p[0]);
	}
	// 단방향 그래프 -> 본인을 방문하기 위해서 필요한 노드를 기록
	memset(visited,false,sizeof(visited));
	queue<int> q;
	q.push(0); visited[0] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto u : biDirAdj[cur]) {
			if (visited[u]) continue;
			visited[u] = true;
			oneDirAdj[cur].push_back(u);
			q.push(u);
		}
	}
	for (auto o : order) {
		if (o[1] == 0) return false; // 만약 나중에 방문해야하는 node가 0번째 idx라면 절대 이뤄질 수 없으므로 false반환
		oneDirAdj[o[0]].push_back(o[1]);
	}
	memset(visited, false, sizeof(visited));
	memset(finished, false, sizeof(visited));
	DFS(0);
	return answer;
}