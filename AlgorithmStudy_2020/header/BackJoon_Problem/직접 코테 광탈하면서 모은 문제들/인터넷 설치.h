#include <bits/stdc++.h>
//1800번 문제
using namespace std;
typedef pair<int, int> pii;
const int MAX = 1000 + 1;
int N, P, K;
vector<pii> adj[MAX];
int Distance[MAX];

bool dijkstra(int mid) {
	priority_queue<pii> pq;
	for (int i = 1; i <= N; i++) Distance[i] = 987654321;
	Distance[1] = 0;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int curCost = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (curCost > Distance[curNode]) continue;
		for (auto u : adj[curNode]) {
			int neighbor = u.first;
			int neighborWeight = curCost + (u.second > mid);
			if (neighborWeight < Distance[neighbor]) {
				Distance[neighbor] = neighborWeight;
				pq.push({ -neighborWeight,neighbor });
			}
		}
	}
	return Distance[N] <= K;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> P >> K;
	int left = 0, right = 0, ans = -1;
	for (int i = 1; i <= P; i++) {
		int curNode, nextNode, weight;
		cin >> curNode >> nextNode >> weight;
		adj[curNode].push_back({ nextNode,weight });
		adj[nextNode].push_back({ curNode,weight });
		right = max(weight, right);
	}
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (dijkstra(mid)) {
			right = mid - 1;
			ans = mid;
		}
		else left = mid + 1;
	}
	cout << ans;
}

/*
	모든게 연결될 필요는 없고 1번과 N번만 연결시키면 된다.
	-> '최단거리'를 그래서 구해야하는 것
	-> 연결 자체가 안된다면 (컴포넌트가 안된다면) -1을 출력
	-> 특정 값 이하의 비용을 들이기 위해선 특정값보다 비싼 간선을 포함하지 않던가 포함하더라도 K개 이하로 포함
		=> 디익스트라
	-> 그런 특정 값 중에 제일 최소 값을 구해야함 
		=> 파라미틱 서치
	
	* 내가 처음봤을때 생각하지 못한 부분
		1) 비용들은 고정되어 있으므로, 파라미틱 서치가 불가능 할 것으로 생각
		2) 최소 값을 구해야하므로 MST 관련해서 풀어야하나?? 생각
*/