#include <bits/stdc++.h>
//5827¹ø ¹®Á¦
using namespace std;
#define Top 0
#define Bottom 1
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
const int MAX = 500;
char MAP[MAX][MAX];
int N, M;
pii Captin;
int dx[2] = { -1,1 };
int dis[2][MAX][MAX];

struct cmp {
	bool operator()(pair<pii, pii>& a, pair<pii, pii>& b) { return a.second.first > b.second.first;  }
};

void init() { for (int k = 0; k < 2; k++) for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) dis[k][i][j] = INT_MAX; }

pair<pii, bool> falling(int ypos, int xpos, int gravity, int cnt) {
	if (gravity == Bottom) {
		while (1) {
			ypos++;
			if (ypos == N)	break;
			else if (MAP[ypos][xpos] == 'D') {
				cout << cnt;
				exit(0);
			}
			else if (MAP[ypos][xpos] == '#' && dis[gravity][ypos - 1][xpos] > cnt) {
				dis[gravity][ypos - 1][xpos] = cnt;
				return { {ypos - 1,xpos},true };
			}
		}
	}
	else {
		while (1) {
			ypos--;
			if (ypos == -1) break;
			else if (MAP[ypos][xpos] == 'D') {
				cout << cnt;
				exit(0);
			}
			else if (MAP[ypos][xpos] == '#' && dis[gravity][ypos + 1][xpos] > cnt) {
				dis[gravity][ypos + 1][xpos] = cnt;
				return { {ypos + 1,xpos},true };
			}
		}
	}
	return { {-1,-1},false };
}

int BFS() {
	init();
	priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, cmp> pq;
	pq.push({ {Captin},{0,Bottom} });
	dis[Bottom][Captin.first][Captin.second] = 0;
	while (!pq.empty()) {
		pii cur = pq.top().first;
		int cnt = pq.top().second.first, gravity = pq.top().second.second;
		pq.pop();
		int ypos = cur.first, xpos = cur.second;
		if (dis[gravity][ypos][xpos] < cnt) continue;
		dis[gravity][ypos][xpos] = cnt;
		for (int k = 0; k < 2; k++) {
			int ny = ypos, nx = xpos + dx[k];
			if (MAP[ny][nx] == '#') continue;
			pair<pii, bool> temp = falling(ny, nx, gravity, cnt);
			if (temp.second) pq.push({ {temp.first}, {cnt,gravity} });
		}
		gravity = gravity ? Top : Bottom;
		pair<pii, bool> temp = falling(ypos, xpos, gravity, cnt + 1);
		if (temp.second) pq.push({ {temp.first}, {cnt + 1,gravity} });
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