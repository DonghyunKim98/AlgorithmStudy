#include <bits/stdc++.h>
//9372�� ����
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
	�ּ� ���� Ʈ�� (Minimum Spanning Tree -> MST)
	=> Tree���� edge�� ������ node-1 �� �̹Ƿ� ������ N-1��.
*/