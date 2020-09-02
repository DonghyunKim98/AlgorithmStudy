#include <bits/stdc++.h>
//12100¹ø ¹®Á¦
using namespace std;
const int MAX = 20;
int N, ans = 0;
int MAP[MAX][MAX];
int temp[MAX][MAX];

void DFS(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ans < MAP[i][j] ? ans = MAP[i][j] : ans = ans;
		return;
	}
	std::copy(&MAP[0][0], &MAP[0][0] + (MAX) * (MAX), &temp[0][0]);
	for (int k = 0; k < 4; k++) {
		DFS(cnt + 1);
		std::copy(&temp[0][0], &temp[0][0] + (MAX) * (MAX), &MAP[0][0]);
	}
}


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = -0; j < N; j++) cin >> MAP[i][j];
	DFS(0);
	cout << ans;
}