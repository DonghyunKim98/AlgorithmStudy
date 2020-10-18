#include <bits/stdc++.h>
//17822번 문제
using namespace std;
const int MAX = 50 + 1;
int N, M, T;
int plate[MAX][MAX];
double ans = 0.0, avg = 0.0, cnt2=0.0;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
bool visited[MAX][MAX];
vector<pair<int, int>> vc;
bool DFS(int ypos,int xpos) {
	bool is_same = false;
	visited[ypos][xpos] = true;
	for (int k = 0; k < 4; k++) {
		int ny = ypos + dy[k], nx = xpos + dx[k];
		if (nx == M + 1) nx = 1;
		else if (nx == 0) nx = M;
		//x의 범위는 검사하지 않음. (원판이니깐)
		if (0 < ny && ny <= N) {
			if (!visited[ny][nx] && (plate[ypos][xpos] == plate[ny][nx])) {
				vc.push_back({ ny,nx }); is_same = true;
				DFS(ny, nx);
			}
		}
	}
	return is_same;
}

void check() {
	memset(visited, false, sizeof(visited));
	bool is_same = false; vc.clear();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j]&& plate[i][j]!=0) {
				is_same = DFS(i, j);
				//같은 것이 있다면 마지막에 본인까지 넣어줘야 함.
				if (is_same) 
					vc.push_back({ i,j });
			}
		}
	}
	if (vc.size()!=0) {
		for (int k = 0; k < vc.size(); k++) {
			ans -= plate[vc[k].first][vc[k].second];
			plate[vc[k].first][vc[k].second] = 0;
		}
		cnt2-= vc.size();
	}
	else {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (plate[i][j] < avg && plate[i][j] != 0) {
					plate[i][j]++;
					ans++;
				}
				else if (plate[i][j] > avg) {
					plate[i][j]--;
					ans--;
				}
			}
		}
	}
	avg = ans / cnt2;
}

void rotate(int idx, int cnt) {
	int* temp = new int[(M + 1)];
	for (int k = idx; k <= N; k += idx) {
		for (int i = 1; i <= M; i++) temp[i] = plate[k][i];
		for (int i = 1; i <= M; i++) {
			int temp_idx = ((i + cnt) % M == 0) ? M : (i + cnt) % M;
			plate[k][temp_idx] = temp[i];
		}
	}
	check();
}

void input() {
	cin >> N >> M >> T;
	cnt2 = double(N) * M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> plate[i][j]; ans += plate[i][j];
		}
	}
	avg = ans / cnt2;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	int x, dir, k;
	while (T--) {
		cin >> x >> dir >> k;
		//반시계 방향 k칸 이동 == 시계 방향 M-k 칸 이동
		if (dir == 1) k = M - k;
		rotate(x, k);
	}
	cout << (int)ans;
}