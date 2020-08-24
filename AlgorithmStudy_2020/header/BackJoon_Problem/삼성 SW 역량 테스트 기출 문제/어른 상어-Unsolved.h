#include <bits/stdc++.h>
//19237번 문제
using namespace std;
const int MAX = 20 + 1;
typedef struct {
	int ypos, xpos;
}point;
vector<point> shark(MAX);
int arr[MAX][MAX];
int smell[MAX][MAX];
int shark_dir[MAX * MAX];
vector<vector<int>> shark_priority[MAX * MAX];
int N, M, K;
int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,-1,1 };
int cnt;

void make_smell() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 0) continue;
			smell[i][j] = K;
		}
	}
}

void move() {
	make_smell();
	for (int i = 1; i <= M; i++) {
		int py = shark[i].ypos, px = shark[i].xpos;
		for (int i = 1; i <= 4; i++) {

		}
		int ny = py + dy[shark_dir[i]], nx = px + dx[shark_dir[i]];
		
	}
}

void eliminate() {

}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	cnt = M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			shark[arr[i][j]] = { i,j };
		}
	}

	for (int i = 1; i <= M; i++) {
		cin >> shark_dir[i];
	}

	for (int i = 1; i <= M; i++) {
		//0번쨰 idx채워넣기
		shark_priority[i].push_back({ 0 });
		for (int j = 1; j <= 4; j++) {
			vector<int> temp;
			for (int k = 1; k <= 4; k++) {
				int temp2;
				cin >> temp2;
				temp.push_back(temp2);
			}
			shark_priority[i].push_back(temp);
		}
	}
	int ans = 0;
	while (ans <= 1000) {
		ans++;
		move();
		eliminate();
		if (cnt == 1) break;
	}
	cout << (ans > 1000) ? -1 : ans;
}