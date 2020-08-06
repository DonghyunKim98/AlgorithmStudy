#include <bits/stdc++.h>
//15863¹ø ¹®Á¦
using namespace std;
const int MAX = 8;
int visited[MAX][MAX];
int arr[MAX][MAX], brr[MAX][MAX];
int N, M;
typedef struct {
	int y, x;
}Dir;
//ESWN
Dir moveDir[4] = { {1,0},{0,1},{-1,0},{0,-1} };
Dir oneDir, twoDir[2], threeDir[3], fourDir[4] = { moveDir[0],moveDir[1],moveDir[3],moveDir[4] };

void DFS(int ypos, int xpos) {
	if (visited[ypos][xpos]) return;
	visited[ypos][xpos] = true;

	if (brr[ypos][xpos] == 1) {
		int ny = ypos + oneDir.y, nx = xpos + oneDir.x;
		if (0 <= ny && ny < N && 0 <= nx && nx < M) {
			if (brr[ny][nx] != 6 && !visited[ypos][xpos]) {
				brr[ny][nx] = brr[ypos][xpos];
				DFS(ny, nx);
			}
		}
	}
	else if (brr[ypos][xpos] == 2) {
		for (int k = 0; k < 2; k++) {
			int ny = ypos + twoDir[k].y, nx = xpos + twoDir[k].x;
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (brr[ny][nx] != 6 && !visited[ypos][xpos]) {
					brr[ny][nx] = brr[ypos][xpos];
					DFS(ny, nx);
				}
			}
		}
	}
	else if (brr[ypos][xpos] == 3) {
		for (int k = 0; k < 3; k++) {
			int ny = ypos + threeDir[k].y, nx = xpos + threeDir[k].x;
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (brr[ny][nx] != 6 && !visited[ypos][xpos]) {
					brr[ny][nx] = brr[ypos][xpos];
					DFS(ny, nx);
				}
			}
		}
	}
	else {
		for (int k = 0; k < 4; k++) {
			int ny = ypos + fourDir[k].y, nx = xpos + fourDir[k].x;
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (brr[ny][nx] != 6 && !visited[ypos][xpos]) {
					brr[ny][nx] = brr[ypos][xpos];
					DFS(ny, nx);
				}
			}
		}
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	copy(&arr[0][0], &arr[0][0] + (MAX) * (MAX), &brr[0][0]);
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		oneDir = moveDir[i];
		for (int j = 0; j < 2; j++) {
			twoDir[0] = moveDir[j]; twoDir[1] = moveDir[j + 2];
			for (int k = 0; k < 4; k++) {
				threeDir[0] = moveDir[k]; threeDir[1] = moveDir[k + 1 % 4]; threeDir[2] = moveDir[k + 2 % 4];
				int zero_cnt = 0; memset(visited, false, sizeof(visited));
				for (int f = 0; f < N; f++) {
					for (int g = 0; g < M; g++) {
						if (!visited[f][g] && 0 < brr[f][g] && brr[f][g] < 6)
							DFS(f, g);
					}
				}
				for (int f = 0; f < N; f++) {
					for (int g = 0; g < M; g++) {
						if (brr[f][g] == 0) zero_cnt++;
					}
				}
				answer = max(answer, zero_cnt);
				copy(&arr[0][0], &arr[0][0] + (MAX) * (MAX), &brr[0][0]);
			}
		}
	}
	cout << answer;
}
