#include <bits/stdc++.h>
//1012번 문제 ->풀었음(O)
using namespace std;

int place[50][50] = { 0, }; // 0: 배추가 없음 1: 배추가 있음
int visited[50][50] = { 0, }; // 0: 방문함 1이상: 배추 번호
int M,N, K;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

void DFS(int i, int j, int num) {
	visited[i][j] = num;

	for (int k = 0; k < 4; k++) {
		int x = i + dx[k];
		int y = j + dy[k];
		if (x >= 0 && x <= M - 1 && y >= 0 && y <= N - 1) {
			if (place[x][y] == 1 && visited[x][y] == 0) {
				DFS(x, y, num);
			}
		}
	}
}
void OrganicCabbage() {
	int T;
	scanf_s("%d",&T);

	for (int i = 0; i < T; i++) {
		scanf_s("%d %d %d", &M, &N, &K);
		memset(place, 0, sizeof(place));
		memset(visited, 0, sizeof(visited));
		for (int j = 0; j < K; j++) {
			int temp1, temp2;
			scanf_s("%d %d", &temp1, &temp2);
			place[temp1][temp2] = 1;
		}
		int num = 0;
		//탐색
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if(place[i][j]==1 && visited[i][j]==0)
					DFS(i, j, ++num);
			}
		}

		cout << num << "\n";
	}
}
/*
	배워야 하는 지점
	1) 가로길이 M 세로 길이 N -> 2차원배열에서 place[temp2][temp1]으로 놔야함.
	2) 전체 for문이 한번만 도는 것이 아니라서, 초기화를 해줘야 함.
*/