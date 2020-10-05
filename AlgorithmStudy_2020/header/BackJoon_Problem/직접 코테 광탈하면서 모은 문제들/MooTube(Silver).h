#include <bits/stdc++.h>
//15591번 문제
using namespace std;
typedef pair<int, int> pii;
const int MAX = 5000 + 1;
vector<pii> adj[MAX];
int N, Q;
int cntVistited[MAX];

void init() {
	for (int i = 1; i <= N; i++) cntVistited[i] = INT_MAX;
}

void DFS(int parentNode, int curNode, int minWeight) {
	for (auto u : adj[curNode]) {
		int nextNode = u.first, weight = u.second;
		//부모로는 못 돌아가게 해야함
		if (nextNode == parentNode) continue;
		int curMinWeight = min(weight, minWeight);
		//현재 경로로 가는길이 최소가 아니라면 continue
		if (curMinWeight>cntVistited[nextNode]) continue;
		cntVistited[nextNode] = curMinWeight;
		DFS(curNode, nextNode, curMinWeight);
	}
}

int check(int startNode,int minWeight) {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		if (i == startNode) continue;
		if (cntVistited[i] >= minWeight) ret++;
	}
	return ret;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	for (int i = 1; i < N; i++) {
		int cur, next, weight;
		cin >> cur >> next >> weight;
		adj[cur].push_back({ next,weight });
		adj[next].push_back({ cur,weight });
	}

	while (Q--) {
		int startNode, minimum;
		cin >> minimum >> startNode;
		init();
		cntVistited[startNode] = -1;
		DFS(-1,startNode,INT_MAX);
		cout << check(startNode,minimum)<<'\n';
	}
	
}