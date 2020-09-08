#include <bits/stdc++.h>
//9466번 문제
using namespace std;
const int MAX = 100000 + 1;
bool cnt_visited[MAX];
bool visited[MAX];
int adj[MAX];

bool DFS(int idx) {
	memset(visited, false, sizeof(visited));
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		memset(cnt_visited, false, sizeof(cnt_visited));
		for (int i = 1; i <= N; i++) {
			cin >> adj[i];
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (cnt_visited[i]) continue;
			if (DFS(i)) {
				ans++;
			}
		}
		cout << N - ans << '\n';
	}
}

/*
	사이클을 이루는가?? 에 대한 것.
*/