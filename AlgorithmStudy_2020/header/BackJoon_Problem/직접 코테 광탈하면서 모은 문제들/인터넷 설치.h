#include <bits/stdc++.h>
//1800�� ����
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
	���� ����� �ʿ�� ���� 1���� N���� �����Ű�� �ȴ�.
	-> '�ִܰŸ�'�� �׷��� ���ؾ��ϴ� ��
	-> ���� ��ü�� �ȵȴٸ� (������Ʈ�� �ȵȴٸ�) -1�� ���
	-> Ư�� �� ������ ����� ���̱� ���ؼ� Ư�������� ��� ������ �������� �ʴ��� �����ϴ��� K�� ���Ϸ� ����
		=> ���ͽ�Ʈ��
	-> �׷� Ư�� �� �߿� ���� �ּ� ���� ���ؾ��� 
		=> �Ķ��ƽ ��ġ
	
	* ���� ó�������� �������� ���� �κ�
		1) ������ �����Ǿ� �����Ƿ�, �Ķ��ƽ ��ġ�� �Ұ��� �� ������ ����
		2) �ּ� ���� ���ؾ��ϹǷ� MST �����ؼ� Ǯ����ϳ�?? ����
*/