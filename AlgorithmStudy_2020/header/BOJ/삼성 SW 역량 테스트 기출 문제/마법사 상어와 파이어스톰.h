#include <bits/stdc++.h>
//20058¹ø ¹®Á¦
using namespace std;
#define MAX 64
#define pii pair<int,int>
int MAP[MAX][MAX], temp[MAX][MAX];
int N = 1, Q, grid = 1, cnt = 0;
bool visited[MAX][MAX];
pii dir[] = {
	{0,1},
	{0,-1},
	{-1,0},
	{1,0}
};
void DFS(int ypos, int xpos) {
	if (visited[ypos][xpos]) return;
	cnt++;
	visited[ypos][xpos] = true;
	for (int k = 0; k < 4; k++) {
		int ny = ypos + dir[k].first, nx = xpos + dir[k].second;
		if (0 <= ny && ny < N && 0 <= nx && nx < N) {
			if(MAP[ny][nx]) DFS(ny, nx);
		}
	}
}

void output() {
	int total = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) total += MAP[i][j];
	cout << total << '\n';
	memset(visited, false, sizeof(visited));
	int ans = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		if (visited[i][j] || MAP[i][j] == 0) continue;
		cnt = 0;
		DFS(i, j);
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
}

void rotate(int yStart, int yEnd, int xStart, int xEnd) {
	int dif = yEnd - yStart;
	if (dif != grid) {
		rotate(yStart, yStart + (dif / 2), xStart, xStart + (dif / 2));
		rotate(yStart, yStart + (dif / 2), xStart + (dif / 2), xEnd);
		rotate(yStart + (dif / 2), yEnd, xStart, xStart + (dif / 2));
		rotate(yStart + (dif / 2), yEnd, xStart + (dif / 2), xEnd);
		return;
	}
	for (int i = yEnd - 1; i >= yStart; i--) for (int j = xStart; j < xEnd; j++) temp[j - xStart][(yEnd - 1) - i] = MAP[i][j];
	for (int i = 0; i < grid; i++) for (int j = 0; j < grid; j++) MAP[yStart + i][xStart + j] = temp[i][j];
	return;
}


void melt() {
	vector<pii> vc;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!MAP[i][j]) continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dir[k].first, nx = j + dir[k].second;
				if (!(0 <= ny && ny < N && 0 <= nx && nx < N)) cnt++;
				else if (!MAP[ny][nx]) cnt++;
			}
			if (cnt > 1)
				vc.push_back({ i,j });
		}
	}
	for (auto u : vc) MAP[u.first][u.second]--;
}

//void debug() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) cout << MAP[i][j] << ' ';
//		cout << '\n';
//	}
//}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int temp;
	cin >> temp >> Q;
	for (int i = 1; i <= temp; i++) N *= 2;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> MAP[i][j];
	while (Q--) {
		grid = 1;
		cin >> temp;
		for (int i = 1; i <= temp; i++) grid *= 2;
		rotate(0, N, 0, N);
		//debug();
		melt();
	}
	output();
}