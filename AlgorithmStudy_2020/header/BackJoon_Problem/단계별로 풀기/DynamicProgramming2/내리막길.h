#include <bits/stdc++.h>
//1520번 문제
//https://wootool.tistory.com/83 참고
using namespace std;
const int MAX = 500;
int grid[MAX][MAX];
int visited[MAX][MAX];
int N, M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dfs(int xpos, int ypos) {
	if (xpos == N-1 && ypos == M-1) 
		return 1;

	//이전에 방문했다면 조사한 값을 반환.
	if (visited[ypos][xpos]!=-1) return visited[ypos][xpos];
	visited[ypos][xpos] = 0;
	for (int k = 0; k < 4; k++) {
		int nx = xpos + dx[k];
		int ny = ypos + dy[k];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			if (grid[ny][nx] < grid[ypos][xpos]) 
				//더해준다 -> 이것으로 한번 방문한 곳을 재방문하지 않고 효과적으로 모든 경우의 수를 구할 수 있음
				visited[ypos][xpos]+=dfs(nx, ny);
	}
	return visited[ypos][xpos];
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++) 
		for (int j = 0; j < N; j++) 
			cin >> grid[i][j];
	memset(visited, -1, sizeof(visited));
	cout<<dfs(0, 0);
}

/*
	알고리즘 포인트
	1. 파고드는 것은 위에서부터 채워지는 것은 아래서부터.
	2. 벽 부수고 이동하기 처럼, 이미 방문한 곳을 또 방문함 
	=> 벽 부수고 이동하기는 이전에 부쉈는가 안 부쉈는가만 확인하면 됐기에 3차원 배열로 진행
	=> 이건 경우의 수가 더 많지만, 특정 격자점에 도착하고 '그 다음 경로는 무조건 같기에' 단순히 더해주면 됨.
	=> 벽 부수고 이동하기는 특정 격자점에 도착한다고 해도 그 다음 경로가 같을지 안 같을지 (이전에 벽을 부쉈는지 안 부쉈는지 여부) 모르기에 3차원 배열로 진행하야 했음.

	3. 단순한 DFS는 시간초과가 떴다.
*/