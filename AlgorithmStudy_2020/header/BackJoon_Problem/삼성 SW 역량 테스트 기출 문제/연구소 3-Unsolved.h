#include <bits/stdc++.h>
//17142¹ø ¹®Á¦
using namespace std;
const int MAX = 50 + 1;
typedef struct {
	int ypos, xpos;
}point;
int MAP[MAX][MAX], temp_MAP[MAX][MAX];
vector<point> virus, virus_selected;
int N, M, answer = INT_MAX;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[MAX][MAX];

int check() {

}
void BFS(point current) {
	queue<int> q;

}
void DFS(int cnt, int idx) {
	if (cnt == M) {
		copy(&MAP[0][0], &MAP[0][0] + (MAX) * (MAX), &temp_MAP[0][0]);
		memset(visited, false, sizeof(visited));
		for (auto u : virus_selected) BFS(u);
		answer = min(check(), answer);
	}

	for (int k = idx; k < virus.size(); k++) {
		virus_selected.push_back(virus[k]);
		DFS(cnt + 1, idx + 1);
		virus_selected.pop_back();
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) virus.push_back({ i,j });
			else if (MAP[i][j] == 1) MAP[i][j] = -1;
		}
	}

	DFS(0, 0);
}