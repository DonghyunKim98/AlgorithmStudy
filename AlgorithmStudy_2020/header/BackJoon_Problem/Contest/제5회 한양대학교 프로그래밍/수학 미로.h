#include <bits/stdc++.h>
//16475¹ø ¹®Á¦
using namespace std;
typedef pair<int, int> pii;
const int MAX = 10000 + 1;
vector<pii> adj[MAX];
vector<pii> adj_trap[MAX];
vector<int> trap;
int Distance[MAX];
int N, M, K, L, P, S,E;

void dijkstra() {
	priority_queue<pii> pq;
	fill_n(Distance, MAX, INT_MAX);
	Distance[S] = 0;
	pq.push(make_pair(0, S));
	while (!pq.empty()) {
		int curCost = -pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();
		if (curCost > Distance[curVertex]) continue;
		for (auto u : adj[curVertex]) {
			int neighbor = u.first;
			int neighborDistance = u.second + curCost;
			if (neighborDistance < Distance[neighbor]) {
				Distance[neighbor] = neighborDistance;
				pq.push(make_pair(-neighborDistance, neighbor));
			}
		}

		for (auto u : adj_trap[curVertex]) {
			int neighbor = u.first;
			int neighborDistance = u.second + curCost;
			if (neighborDistance < Distance[neighbor]) {
				Distance[neighbor] = neighborDistance;
				pq.push(make_pair(-neighborDistance, neighbor));
			}
		}
	}
}

void Input() {
	cin >> N >> M >> K >> L >> P;
	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		trap.push_back(temp);
	}

	for (int i = 0; i < M - L; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		adj[start].push_back({ end,weight });
	}

	for (int i = 0; i < L; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		adj_trap[start].push_back({ end,weight });
	}
	cin >> S >> E;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Input();
}