#include <bits/stdc++.h>
//9372번 문제
using namespace std;

void solution() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T > 0) {
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
		}
		cout << N - 1<<'\n';
		T--;
	}
}

/*
	최소 신장 트리 (Minimum Spanning Tree -> MST)
	=> Tree에서 edge의 개수는 node-1 개 이므로 무조건 N-1개.
*/