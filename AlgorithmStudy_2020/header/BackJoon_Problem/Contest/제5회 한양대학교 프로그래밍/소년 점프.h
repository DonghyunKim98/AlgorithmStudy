#include <bits/stdc++.h>
//16469번 문제
using namespace std;
typedef pair<int, int> pii;
const int MAX = 100 + 1;
int R, C;
int MAP[MAX][MAX];
bool visited[3][MAX][MAX] = { false, };
int cnt_visited[3][MAX][MAX];
pii dir[4] = { {0,1},{0,-1},{1,0},{-1,0} };
pii pos[3];


void BFS() {
	memset(cnt_visited, -1, sizeof(cnt_visited));
	queue<pair<int, pii>> q;
	for (int i = 0; i < 3; i++) {
		cnt_visited[i][pos[i].first][pos[i].second] = 0;
		visited[i][pos[i].first][pos[i].second] = true;
		q.push(make_pair(i, pos[i]));
	}
	while (!q.empty()) {
		int current_idx = q.front().first;
		int dy = q.front().second.first, dx = q.front().second.second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = dy + dir[k].first;
			int nx = dx + dir[k].second;
			if (1 <= ny && ny <= R && 1 <= nx && nx <= C) {
				if (!visited[current_idx][ny][nx]&&MAP[ny][nx]==0) {
					visited[current_idx][ny][nx] = true;
					cnt_visited[current_idx][ny][nx] = cnt_visited[current_idx][dy][dx] + 1;
					q.push(make_pair(current_idx, make_pair(ny, nx)));
				}
			}
		}
	}
	//한 지점에서 모이는 최솟값 탐색
	pii ans = { INT_MAX,0 };
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (MAP[i][j] == 1) continue;
			int temp = 0;
			for (int k = 0; k < 3; k++) {
				if (cnt_visited[k][i][j] == -1) {
					temp = -1;
					break;
				}
				temp = max(temp, cnt_visited[k][i][j]);
			}
			//temp가 -1이 아니라면
			if (temp != -1) {
				//현재 값이 더 최소라면
				if (temp < ans.first) {
					ans.first = temp; ans.second = 1;
				}
				//최솟값과 같다면
				else if (temp == ans.first) ans.second++;
			}
		}
	}
	if (ans.first == INT_MAX) cout << -1;
	else cout << ans.first << '\n' << ans.second;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			MAP[i][j + 1] = (int)(temp[j] - '0');
		}
	}
	for (int i = 0; i < 3; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		pos[i] = make_pair(temp1, temp2);
	}
	BFS();
}