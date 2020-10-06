#include <bits/stdc++.h>
//17780¹ø ¹®Á¦
using namespace std;
const int MAX = 12 + 1;
int N, K;
int MAP[MAX][MAX];
vector<pair<int, int>> piece[MAX][MAX];
int dy[] = { 0,0,0,-1,1 };
int dx[] = { 0,1,-1,0,0 };

void move_in(int py, int px, int ny, int nx) {
	for (int i = 0; i < piece[py][px].size();) {
		piece[ny][nx].push_back(piece[py][px][i]);
		piece[py][px].erase(piece[py][px].begin() + i);
	}
}

void move_reverse(int py, int px, int ny, int nx) {
	for (int i = piece[py][px].size() - 1; i >= 0; i--) {
		piece[ny][nx].push_back(piece[py][px].back());
		piece[py][px].pop_back();
	}
}

void dir_reverse(int py, int px, int target_idx) {
	switch (piece[py][px][target_idx].second) {
	case 1:
		piece[py][px][target_idx].second = 2;
		break;
	case 2:
		piece[py][px][target_idx].second = 1;
		break;
	case 3:
		piece[py][px][target_idx].second = 4;
		break;
	case 4:
		piece[py][px][target_idx].second = 3;
		break;
	}
}

int white(int py, int px, int ny, int nx) {
	move_in(py, px, ny, nx);
	return piece[ny][nx].size() >= 4 ? -1 : 1;
}

int red(int py, int px, int ny, int nx) {
	move_reverse(py, px, ny, nx);
	return piece[ny][nx].size() >= 4 ? -1 : 1;
}

int blue(int py, int px) {
	dir_reverse(py, px, 0);
	int ny = py + dy[piece[py][px][0].second], nx = px + dx[piece[py][px][0].second];
	if (MAP[ny][nx] == 2 || !(1 <= ny && ny <= N && 1 <= nx && nx <= N)) {
		return 1;
	}
	if (MAP[ny][nx] == 0) move_in(py, px, ny, nx);
	else if (MAP[ny][nx] == 1) move_reverse(py, px, ny, nx);
	return piece[ny][nx].size() >= 4 ? -1 : 1;
}


int DFS() {
	int ret = 0;
	for (int idx = 1; idx <= K; idx++) {
		int py, px;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < piece[i][j].size(); k++)
					if (piece[i][j][k].first == idx) {
						py = i, px = j;
						break;
					}
			}
		if (piece[py][px][0].first != idx) continue;
		int ny = py + dy[piece[py][px][0].second], nx = px + dx[piece[py][px][0].second];
		if (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
			if (MAP[ny][nx] == 0) ret = white(py, px, ny, nx);
			else if (MAP[ny][nx] == 1) ret = red(py, px, ny, nx);
			else ret = blue(py, px);
		}
		else {
			ret = blue(py, px);
		}
		if (ret == -1) return ret;
	}
	return ret;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> MAP[i][j];

	for (int i = 1; i <= K; i++) {
		int row, col, value;
		cin >> row >> col >> value;
		piece[row][col].push_back({ i, value });
	}

	int ans = 0;
	while (ans < 1000) {
		ans++;
		if (DFS() == -1) break;
	}

	if (ans == 1000) cout << -1;
	else cout << ans;
}