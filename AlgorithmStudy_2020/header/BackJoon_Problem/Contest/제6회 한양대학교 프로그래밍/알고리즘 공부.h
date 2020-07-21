#include <bits/stdc++.h>
//17942�� ����
using namespace std;
const int MAX = 100000 + 1;
int N, M;
int arr[MAX];
int brr[MAX];
bool visit[MAX];
vector<pair<int, int>> adj[MAX];

bool can(int x) {
	queue<int> q;
	int k = 0;
	for (int i = 1; i <= N; i++) {
		brr[i] = arr[i];
		visit[i] = 0;
		//�־��� ���η����� ������ �ϴ� ����
		if (arr[i] <= x) {
			q.push(i);
			k++;
			visit[i] = 1;
			//M�� �̻����� ���θ� �� �� ���� -> true ��ȯ
			if (k >= M) return true;
		}
	}

	while (!q.empty()) {
		int current = q.front(); q.pop();
		for (auto u : adj[current]) {
			int endNode = u.first, weight = u.second;
			if (visit[endNode]) continue;
			brr[endNode] -= weight;
			if (brr[endNode] <= x) {
				q.push(endNode);
				visit[endNode] = true;
				k++;
				if (k >= M) return true;
			}
		}
	}
	return false;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	int MAX = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		MAX = max(MAX, arr[i]);
	}

	int R;
	cin >> R;
	for (int i = 1; i <= R; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		adj[start].push_back(make_pair(end,weight));
	}

	//Parametric search
	int start = 0, end = MAX;
	while (start <= end) {
		int mid = (start + end)/2;
		//�־��� ���η��� �ʹ� ��ĥ�� (M�� �̻����� ���θ� �� �ڿ��� �� ���)
		if (can(mid)) {
			end = mid - 1;
		}
		else start = mid + 1;
	}
	cout << start;
}

/*
	�˰��� ����Ʈ
	=> �ִ밪 �ּڰ��� ������ �׻� Parametric�� ���ο� ����
*/