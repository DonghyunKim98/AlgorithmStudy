#include <bits/stdc++.h>
//17940번 문제
using namespace std;
const int MAX = 1000 + 1;
vector<pair<int, int>> adj[MAX];
int Distance[MAX];
bool visited[MAX];
bool isB[MAX];
int cnt[MAX];
int N, M;

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	//base case
	pq.push(make_pair(0, start));
	Distance[start] = 0, cnt[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		if (visited[currentNode]) continue;
		visited[currentNode] = true;

		for (auto u : adj[currentNode]) {
			int nextNode = u.first;
			int weight = u.second + cost;
			//다음역이 갈아타야 할때
			if (isB[currentNode] != isB[nextNode]) {
				//더 적게 환승할 수 있다면
				if (cnt[currentNode] + 1 < cnt[nextNode]) {
					Distance[nextNode] = weight;
					pq.push(make_pair(-weight, nextNode));
					cnt[nextNode] = cnt[currentNode] + 1;
				}
				//환승횟수가 같다면
				else if (cnt[currentNode]+1 == cnt[nextNode]) {
					//거리가 더 적은쪽을 따줘준다.
					if (Distance[nextNode] > weight) {
						Distance[nextNode] = weight;
						pq.push(make_pair(-weight, nextNode));
						cnt[nextNode] = cnt[currentNode] + 1;
					}
				}

			}
			//갈아타지 않아도 된다면
			else {
				//더 적게 환승할 수 있다면
				if (cnt[currentNode] < cnt[nextNode]) {
					Distance[nextNode] = weight;
					pq.push(make_pair(-weight, nextNode));
					cnt[nextNode] = cnt[currentNode];
				}
				//환승횟수가 같다면
				else if (cnt[currentNode] == cnt[nextNode]) {
					//거리가 더 적은쪽을 따줘준다.
					if (Distance[nextNode] > weight) {
						Distance[nextNode] = weight;
						pq.push(make_pair(-weight, nextNode));
						cnt[nextNode] = cnt[currentNode];
					}
				}
			}
		}
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> isB[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp == 0) continue;
			else adj[i].push_back(make_pair(j, temp));
		}
	}
	fill_n(Distance, MAX, INT_MAX);
	fill_n(cnt, MAX, INT_MAX);
	dijkstra(0);
	cout << cnt[M] << ' ' << Distance[M];
}