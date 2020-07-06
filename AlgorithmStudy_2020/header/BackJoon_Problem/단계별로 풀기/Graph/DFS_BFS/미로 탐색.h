#include <bits/stdc++.h>
//2178번 문제 ->풀었음(O)
using namespace std;
int maze[101][101] = { 0, };//1:갈수 있음 0:갈수 없음
int visited[101][101] = { 0, };//0:방문안함 1이상: (1,1)에서 얼마만에 갈수 있는가?
int ans[100*100];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;

void dfs(int px, int py, int num) {
	visited[px][py] = num;
	++num;
	for (int k = 0; k < 4; k++) {
		int nx = dx[k] + px;
		int ny = dy[k] + py;
		if (nx <= N && nx >= 1 && ny <= M && ny >= 1) {
			if ((visited[nx][ny] == 0 || visited[nx][ny]>num)&& (maze[nx][ny] == 1)) {
				dfs(nx, ny, num);
			}
		}
	}
}

void MazeSearch() {
	scanf_s("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s("%1d", &maze[i][j]);
		}
	}

	dfs(1, 1, 1);
	cout << visited[N][M];
		
}

/*
	최단경로를 구하자... 어떻게??
	와 처음으로 어떤것도 안보고 풀었어 행복
	visited[nx][ny] == 0 || visited[nx][ny]>num 
	요 코드가 유효했다
*/