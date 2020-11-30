#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000 + 1;
bool answer = true;
bool visited[MAX];
bool finished[MAX]; // ����Ŭ ���θ� �Ǵ��ϱ� ���� �迭
vector <int> biDirAdj[MAX]; // ����� �׷���
vector <int> oneDirAdj[MAX]; // �ܹ��� �׷���
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
	// ����� �׷���
	for (auto p : path) {
		biDirAdj[p[0]].push_back(p[1]);
		biDirAdj[p[1]].push_back(p[0]);
	}
	// �ܹ��� �׷��� -> ������ �湮�ϱ� ���ؼ� �ʿ��� ��带 ���
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
		if (o[1] == 0) return false; // ���� ���߿� �湮�ؾ��ϴ� node�� 0��° idx��� ���� �̷��� �� �����Ƿ� false��ȯ
		oneDirAdj[o[0]].push_back(o[1]);
	}
	memset(visited, false, sizeof(visited));
	memset(finished, false, sizeof(visited));
	DFS(0);
	return answer;
}