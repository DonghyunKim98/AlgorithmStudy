#include <bits/stdc++.h>
//14502번 문제
using namespace std;
const int MAX = 8;
int arr[MAX][MAX], brr[MAX][MAX];
int N, M;
int zero_cnt = 0;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };
int visited[MAX][MAX];
typedef struct {
	int y, x;
}point;
void BFS(int ypos, int xpos) {
	queue<point> q;
	q.push({ ypos,xpos });
	while (!q.empty()) {
		int py = q.front().y, px = q.front().x; q.pop();
		if (visited[py][px]) continue;
		visited[py][px] = true;
		for (int k = 0; k < 4; k++) {
			int ny = py + dy[k], nx = px + dx[k];
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (brr[ny][nx] == 1) continue;
				else if (brr[ny][nx] == 0) {
					brr[ny][nx] = 2; zero_cnt--;
					q.push({ ny,nx });
				}
				else q.push({ ny,nx });
			}
		}
	}
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) zero_cnt++;
		}
	zero_cnt -= 3;
	copy(&arr[0][0], &arr[0][0] + (MAX) * (MAX), &brr[0][0]);
	//Brute Force
	int wall_cnt = 0, answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			vector<point> temp;
			if (arr[i][j] != 0) continue;
			//첫번째 벽세우기
			brr[i][j] = 1;
			for (int p = i * M + j + 1; p < N * M; p++) {
				if (arr[p / M][p % M] != 0) continue;
				//두번째 벽세우기
				brr[p / M][p % M] = 1;
				for (int q = p + 1; q < N * M; q++) {
					if (arr[q / M][q % M] != 0) continue;
					//세번째 벽세우기
					brr[q / M][q % M] = 1;
					//BFS
					int tmp = zero_cnt;
					for (int f = 0; f < N; f++) {
						for (int g = 0; g < M; g++) {
							if (!visited[f][g] && brr[f][g] == 2) BFS(f, g);
						}
					}
					answer = max(answer, zero_cnt);
					//BackTracking -> 세번째벽만
					copy(&arr[0][0], &arr[0][0] + (MAX) * (MAX), &brr[0][0]);
					memset(visited, false, sizeof(visited));
					brr[i][j] = 1, brr[p / M][p % M] = 1;
					zero_cnt = tmp;
				}
				//BackTracking -> 두번째 벽
				copy(&arr[0][0], &arr[0][0] + (MAX) * (MAX), &brr[0][0]);
				memset(visited, false, sizeof(visited));
				brr[i][j] = 1;
			}
			//BackTriacking -> 세번째 벽
			copy(&arr[0][0], &arr[0][0] + (MAX) * (MAX), &brr[0][0]);
			memset(visited, false, sizeof(visited));
		}
	}
	std::cout << answer;
}

