#include <bits/stdc++.h>
//5827번 문제
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
const int MAX = 500;
char MAP[MAX][MAX];
int N, M;
pii Captin;
int dx[2] = { -1,1 };
bool visited[2][MAX][MAX];

struct cmp {
	bool operator()(pair<pii, pib>& a, pair<pii, pib>& b) {
		return a.second.first > b.second.first;
	}
};

int BFS() {
	int ret = INT_MAX;
	memset(visited, false, sizeof(visited));
	priority_queue<pair<pii, pib>, vector<pair<pii, pib>>, cmp> pq;
	pq.push({ { Captin }, {0,true} });
	visited[0][Captin.first][Captin.second] = true;
	//가장 적은 gravity 뒤짚기를 구현해야하므로 pq로 구현
	while (!pq.empty()) {
		int ypos = pq.top().first.first, xpos = pq.top().first.second;
		int cnt = pq.top().second.first;
		bool fallBottom = pq.top().second.second;
		pq.pop();
		if (MAP[ypos][xpos] == 'D') return cnt;
		// 좌우로 움직이기
		for (int k = 0; k < 2; k++) {
			int ny = ypos, nx = xpos + dx[k];
			if (0 <= nx && nx < M) {
				if (MAP[ny][nx] == '#') continue;
				while (1) {
					if (fallBottom) {
						ny += 1;
						// 맵 밖으로 탈출 
						if (ny == N) break;
						if (MAP[ny][nx] == 'D') return cnt;
						// 벽을 만남
						else if (MAP[ny][nx] == '#') {
							if (visited[0][ny - 1][nx]) break;
							visited[0][ny - 1][nx] = true;
							pq.push({ { ny - 1,nx }, { cnt,fallBottom } });
							break;
						}
					}
					else {
						ny -= 1;
						if (ny == -1) break;
						if (MAP[ny][nx] == 'D') return cnt;
						else if (MAP[ny][nx] == '#') {
							if (visited[1][ny + 1][nx]) break;
							visited[1][ny + 1][nx] = true;
							pq.push({ { ny + 1,nx }, { cnt,fallBottom } });
							break;
						}
					}
				}
			}
		}
		//중력바꾸기
		fallBottom = fallBottom == true ? false : true;
		int ny = ypos, nx = xpos;
		if (fallBottom) {
			while (1) {
				ny += 1;
				if (ny == N) break;
				if (MAP[ny][nx] == 'D') return cnt;
				else if (MAP[ny][nx] == '#') {
					if (visited[0][ny - 1][nx]) break;
					visited[0][ny - 1][nx] = true;
					pq.push({ { ny - 1,nx }, { cnt + 1,fallBottom } });
					break;
				}
			}
		}
		else {
			while (1) {
				ny -= 1;
				if (ny == -1) break;
				if (MAP[ny][nx] == 'D') return cnt;
				else if (MAP[ny][nx] == '#') {
					if (visited[1][ny + 1][nx]) break;
					visited[1][ny + 1][nx] = true;
					pq.push({ { ny + 1,nx }, { cnt + 1,fallBottom } });
					break;
				}
			}
		}
	}
	return -1;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			MAP[i][j] = temp[j];
			if (MAP[i][j] == 'C')
				Captin = { i,j };
		}
	}
	cout << BFS();
}