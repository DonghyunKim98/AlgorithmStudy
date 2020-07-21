#include <bits/stdc++.h>
//17940�� ����
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
			//�������� ����Ÿ�� �Ҷ�
			if (isB[currentNode] != isB[nextNode]) {
				//�� ���� ȯ���� �� �ִٸ�
				if (cnt[currentNode] + 1 < cnt[nextNode]) {
					Distance[nextNode] = weight;
					pq.push(make_pair(-weight, nextNode));
					cnt[nextNode] = cnt[currentNode] + 1;
				}
				//ȯ��Ƚ���� ���ٸ�
				else if (cnt[currentNode]+1 == cnt[nextNode]) {
					//�Ÿ��� �� �������� �����ش�.
					if (Distance[nextNode] > weight) {
						Distance[nextNode] = weight;
						pq.push(make_pair(-weight, nextNode));
						cnt[nextNode] = cnt[currentNode] + 1;
					}
				}

			}
			//����Ÿ�� �ʾƵ� �ȴٸ�
			else {
				//�� ���� ȯ���� �� �ִٸ�
				if (cnt[currentNode] < cnt[nextNode]) {
					Distance[nextNode] = weight;
					pq.push(make_pair(-weight, nextNode));
					cnt[nextNode] = cnt[currentNode];
				}
				//ȯ��Ƚ���� ���ٸ�
				else if (cnt[currentNode] == cnt[nextNode]) {
					//�Ÿ��� �� �������� �����ش�.
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