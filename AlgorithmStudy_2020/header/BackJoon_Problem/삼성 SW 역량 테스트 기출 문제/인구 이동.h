#include <bits/stdc++.h>
//16234¹ø ¹®Á¦
using namespace std;
const int MAX = 50;
int N, L, R;
int arr[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool visited[MAX][MAX];
vector<pair<int, int>> vc;

void DFS(int ypos, int xpos) {
	if (visited[ypos][xpos]) return;
	visited[ypos][xpos] = true; vc.push_back({ ypos,xpos });
	for (int k = 0; k < 4; k++) {
		int ny = ypos + dy[k], nx = xpos + dx[k];
		if (0 <= ny && ny < N && 0 <= nx && nx < N && !visited[ny][nx]) {
			if (L <= abs(arr[ypos][xpos] - arr[ny][nx]) && abs(arr[ypos][xpos] - arr[ny][nx]) <= R)
				DFS(ny, nx);
		}
	}
}

bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k], nx = j + dx[k];
				if (0 <= ny && ny < N && 0 <= nx && nx < N) {
					if (L <= abs(arr[i][j] - arr[ny][nx]) && abs(arr[i][j] - arr[ny][nx]) <= R)
						return true;
				}
			}
		}
	}
	return false;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	int answer = 0;
	while (true) {
		if (!check()) break;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					vc.erase(vc.begin(), vc.end());
					DFS(i, j);
					int total = 0, avg = 0;
					for (auto u : vc) total += arr[u.first][u.second];
					avg = total / vc.size();
					for (auto u : vc) arr[u.first][u.second] = avg;
				}
			}
		}
		answer++;
	}
	cout << answer;
}