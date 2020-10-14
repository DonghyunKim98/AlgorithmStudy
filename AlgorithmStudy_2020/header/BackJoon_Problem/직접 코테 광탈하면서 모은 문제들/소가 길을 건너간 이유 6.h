#include <bits/stdc++.h>
//14466¹ø ¹®Á¦
using namespace std;
typedef pair<int, int> pii;
const int MAX = 100 + 1;
int MAP[4][MAX][MAX];
int N, K, R;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pii> vc;
bool visited[MAX][MAX];

void DFS(int ypos,int xpos) {
	for (int k = 0; k < 4; k++) {
		int ny = ypos + dy[k], nx = xpos + dx[k];
		if (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
			if (visited[ny][nx]|| MAP[k][ny][nx]) continue;
			visited[ny][nx] = true;
			DFS(ny, nx);
		}
	}
}

int defineK(int row1, int col1, int row2, int col2) {
	if (row1 == row2) {
		if (col1 - col2 == 1) return 2;
		else return 3;
	}
	else {
		if (row1 - row2 == 1) return 0;
		else return 1;
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K >> R;
	for (int i = 0; i < R; i++) {
		int row1, col1, row2, col2;
		cin >> row1 >> col1 >> row2 >> col2;
		int k1 = defineK(row1, col1, row2, col2);
		int k2 = defineK(row2, col2, row1, col1);
		MAP[k1][row1][col1] = 1;
		MAP[k2][row2][col2] = 1;
	}

	vector<pii> cow;
	for (int i = 0; i < K; i++) {
		int row, col;
		cin >> row >> col;
		cow.push_back({ row,col });
	}
	int ans = 0;
	for (int i = 0; i < cow.size(); i++) {
		memset(visited, 0, sizeof(visited));
		DFS(cow[i].first,cow[i].second);
		for (int j = i + 1; j < cow.size(); j++) {
			if (!visited[cow[j].first][cow[j].second]) ans++;
		}
	}
	cout << ans;
}