#include <bits/stdc++.h>
//1520번 문제
using namespace std;
const int MAX = 500;
int grid[MAX][MAX];
bool visited[MAX][MAX];
int N, M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int answer = 0;
void dfs(int xpos, int ypos) {
	if (xpos == N-1 && ypos == M-1) {
		answer++;
		return;
	}
	//이전에 방문했다면 더이상 가치가 없음(이미 조사가 다 끝남)
	if (visited[ypos][xpos]) return;
	visited[ypos][xpos] = true;
	for (int k = 0; k < 4; k++) {
		int nx = xpos + dx[k];
		int ny = ypos + dy[k];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			if (grid[ny][nx] < grid[ypos][xpos]) 
				dfs(nx, ny);
	}
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++) 
		for (int j = 0; j < N; j++) 
			cin >> grid[i][j];
	memset(visited, false, sizeof(visited));
	dfs(0, 0);
	cout << answer;
}