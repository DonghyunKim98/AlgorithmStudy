#include <bits/stdc++.h>
//16235¹ø ¹®Á¦
using namespace std;
const int MAX = 10 + 1;
int food[MAX][MAX];
int current[MAX][MAX];
vector<int> tree[MAX][MAX];
int N, M, K;
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
void Spring_Summer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].size() != 0) {
				sort(tree[i][j].begin(), tree[i][j].end());
				int idx = 0;
				while (idx < tree[i][j].size()) {
					if (current[i][j] - tree[i][j][idx] < 0) break;
					current[i][j] -= tree[i][j][idx], tree[i][j][idx]+=1;
					idx++;
				}
				for (int k = idx; k < tree[i][j].size();) {
					current[i][j] += (tree[i][j][k] / 2);
					tree[i][j].erase(tree[i][j].begin() + k);
				}
			}
		}
	}
}

void Fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].size() == 0) continue;
			for (auto u : tree[i][j]) {
				if (u % 5 != 0) continue;
				for (int k = 0; k < 8; k++) {
					int ny = i + dy[k], nx = j + dx[k];
					if (0 < ny && ny <= N && 0 < nx && nx <= N)	tree[ny][nx].push_back(1);
				}
			}
		}
	}
}

void Winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			current[i][j] += food[i][j];
		}
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> food[i][j];
			current[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int ypos, xpos, temp;
		cin >> ypos >> xpos >> temp;
		tree[ypos][xpos].push_back(temp);
	}
	while (K > 0) {
		Spring_Summer();
		Fall();
		Winter();
		K--;
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += tree[i][j].size();
		}
	}
	cout << answer;
}