#include <bits/stdc++.h>
//16475¹ø ¹®Á¦
using namespace std;
typedef pair<int, int> pii;
const int MAX = 10000 + 1;
const int MAX_CNT = 10 + 1;
int Di[MAX][MAX_CNT * 2];
vector<pii> adj[MAX], adj_trap1[MAX], adj_trap2[MAX];
map<int, bool> trap;
int N, M, K, L, P, S, E;


void dijkstra() {
	priority_queue<pair<pii, int>> pq;
	for (int i = 1; i <= N; i++) 
		for (int j = 0; j <= P * 2; j++) 
			Di[i][j] = 2023456789;
	Di[S][0] = 0;
	pq.push({ make_pair(0, S),0 });
	while (!pq.empty()) {
		int curCost = -pq.top().first.first;
		int curVertex = pq.top().first.second;
		int cnt = pq.top().second;
		if (cnt == 2 * P) cnt = 0;
		pq.pop();
		if (curCost >= Di[curVertex][cnt]) continue;
		Di[curVertex][cnt] = curCost;
		for (auto u : adj[curVertex]) {
			int neighbor = u.first;
			int neighborDistance = u.second + curCost;
			if (trap[neighbor]) cnt++;
			if (neighborDistance < Di[neighbor][cnt]) {
				pq.push({ make_pair(-neighborDistance, neighbor),cnt });
			}
			if (trap[neighbor]) cnt--;
		}
		if (cnt < P) {
			for (auto u : adj_trap1[curVertex]) {
				int neighbor = u.first;
				int neighborDistance = u.second + curCost;
				if (trap[neighbor]) cnt++;
				if (neighborDistance < Di[neighbor][cnt]) {
					pq.push({ make_pair(-neighborDistance, neighbor),cnt });
				}
				if (trap[neighbor]) cnt--;
			}
		}
		else {
			for (auto u : adj_trap2[curVertex]) {
				int neighbor = u.first;
				int neighborDistance = u.second + curCost;
				if (trap[neighbor]) cnt++;
				if (neighborDistance < Di[neighbor][cnt]) {
					pq.push({ make_pair(-neighborDistance, neighbor),cnt });
				}
				if (trap[neighbor]) cnt--;
			}
		}
	}
	sort(Di[E], Di[E] + (2 * P));
	if (Di[E][0] == 2023456789) cout << -1;
	else cout << Di[E][0];
}

void Input() {
	cin >> N >> M >> K >> L >> P;
	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		trap[temp] = true;
	}

	for (int i = 0; i < M - L; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		adj[start].push_back({ end,weight });
	}

	for (int i = 0; i < L; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		adj_trap1[start].push_back({ end,weight });
		adj_trap2[end].push_back({ start,weight });
	}
	cin >> S >> E;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Input();
	dijkstra();
}