#include <bits/stdc++.h>
// 2178¹ø ¹®Á¦
using namespace std;
typedef pair<int, int> pii;
const int MAX = 100;
int N, M;
int MAP[MAX][MAX];
int visited[MAX][MAX];
pii dir[4] = {
	{0,1},{1,0},{-1,0},{0,-1}
};

int BFS(int ypos, int xpos) {
	queue<pii> q;
	memset(visited, 0, sizeof(visited));
	q.push({ ypos,xpos });
	visited[ypos][xpos] = 1;
	while (!q.empty()) {
		pii curPos = q.front();
		q.pop();
		int cnt = visited[curPos.first][curPos.second];
		if (curPos.first == N-1 && curPos.second == M-1) {
			return cnt;
		}
		for (int k = 0; k < 4; k++) {
			int ny = curPos.first + dir[k].first;
			int nx = curPos.second + dir[k].second;
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (MAP[ny][nx] == 0) continue;
				if (visited[ny][nx] < cnt + 1) {
					visited[ny][nx] = cnt + 1;
					q.push({ ny,nx });
				}
			}
		}
	}
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			MAP[i][j] = int(temp[j] - '0');
		}
	}
	cout<< BFS(0, 0);
}
