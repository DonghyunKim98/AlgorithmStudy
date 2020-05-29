#include <bits/stdc++.h>
//1012�� ���� ->Ǯ����(O)
using namespace std;

int place[50][50] = { 0, }; // 0: ���߰� ���� 1: ���߰� ����
int visited[50][50] = { 0, }; // 0: �湮�� 1�̻�: ���� ��ȣ
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
		//Ž��
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
	����� �ϴ� ����
	1) ���α��� M ���� ���� N -> 2�����迭���� place[temp2][temp1]���� ������.
	2) ��ü for���� �ѹ��� ���� ���� �ƴ϶�, �ʱ�ȭ�� ����� ��.
*/