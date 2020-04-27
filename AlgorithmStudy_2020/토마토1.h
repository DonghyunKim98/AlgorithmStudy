#include <bits/stdc++.h>

//7576�� ����
using namespace std;

int place[1001][1001] = { 0, }; //0: �� ���� �丶�� 1: ���� �丶�� -1: ���� �ڸ�
int visited[1001][1001] = { 0, }; // 0: �湮�� 1�̻�: ó�� ���� ���� ������� ���°�?
int ans[1000 * 1000] = { 0, };
int M, N;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

void DFS(int px, int py, int num) {
	visited[px][py] = num;
	++num;
	for (int k = 0; k < 4; k++) {
		int nx = px + dx[k];
		int ny = py + dy[k];
		if (nx >= 1 && nx <= M && ny >= 1 && ny <= N) {
			if (place[nx][ny] == 1 && (visited[nx][ny] == 0 || visited[nx][ny]>num)) {
				DFS(nx, ny, num);
			}
			else if (place[nx][ny] == -1) {
				return;
			}
		}
	}
}

void Tomato() {
	scanf_s("%d %d", &M, &N);
	//�丶�䰡 �;����� 1 �� �;����� 0 �����ڸ��� -1
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf_s("%d", &place[i][j]);
		}
	}

	int num = 0;
	//Ž��
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (place[i][j] == 1 && visited[i][j] == 0)
				DFS(i, j, ++num);
		}
	}

	//����
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = ans[(i - 1) * N + j];
		}
	}
	//����
	sort(ans+1, ans+1 + (M * N));
	if (ans[0] == 1) cout << 0;
	else if (ans[0] == 0) cout << -1;
	else cout << ans[0];
}
