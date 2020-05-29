#include <bits/stdc++.h>
//1753�� ����
//���ͽ�Ʈ�� �˰��� �̿�
//https://jaimemin.tistory.com/555 ����
using namespace std;
const int MAX = 20000 + 1;
const int INF = 2147483647;
int V, E, K;
vector<pair<int, int>> adj[MAX];

vector<int> dijkstra(int start, int vertex) {
	//start�� �������� ó��
	vector <int> distance(vertex, INF);
	//�ڱ� �ڽſ��� ���� ����� 0
	distance[start] = 0;

	priority_queue<pair<int, int>> pq; //-Cost, Vertex
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int curVertex = pq.top().second;
		pq.pop();
		
		for (auto u : adj[curVertex]) {
			int neighbor = u.first;
			int neighborDistance = u.second;
			if (distance[curVertex] + neighborDistance < distance[neighbor]) {
				distance[neighbor] = distance[curVertex] + neighborDistance;
				pq.push(make_pair(-distance[neighbor], neighbor));
			}
		}
	}
}
void ShortestPath() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E;

}