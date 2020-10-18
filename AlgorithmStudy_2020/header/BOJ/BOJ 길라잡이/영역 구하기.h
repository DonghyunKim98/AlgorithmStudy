#include <bits/stdc++.h>
//2583¹ø ¹®Á¦

using namespace std;

int M,N,K;
int c;
int arrCount = 0;
int MAP[110][110];
int arr[10000];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void DFS(int a, int b)
{
	if (MAP[a][b] == 0) {
		MAP[a][b] = 1;
		++c;
		for (int l = 0; l < 4; ++l) {
			int x = dx[l] + a;
			int y = dy[l] + b;
			if (x >= 0 && y >= 0 && x < M && y < N) {
				DFS(x, y);
			}
		}
	}
}

void solution(){
	int x1, y1, x2, y2;
	memset(MAP, 0, sizeof(MAP));
	memset(arr, 0, sizeof(arr));
	cin >> M >> N >> K;

	while (K--) {
		cin >> x1 >> y1;
		cin >> x2 >> y2;

		for (int i = x1; i < x2; ++i) {
			for (int j = y1; j < y2; ++j) {
				MAP[j][i] = 1;
			}
		}
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (MAP[i][j] == 0) {
				c = 0;
				DFS(i, j);
				arr[arrCount++] = c;
			}
		}
	}
	sort(arr, arr + arrCount);
	cout << arrCount << endl;
	for (int i = 0; i < arrCount; ++i) {
		cout << arr[i] << " ";
	}
}