#include <bits/stdc++.h>
// 20056¹ø ¹®Á¦
using namespace std;
#define MAX 51
typedef pair<int, int> pii;
typedef struct {
	int ypos, xpos, mass, speed, d;
}fireBall;
vector<fireBall> vc;
int N, M, K;
int MAP[MAX][MAX];
pii dir[] = {
	{1,0},
	{1,1},
	{0,1},
	{-1,1},
	{-1,0},
	{-1,-1},
	{0,-1},
	{1,-1}
};

void move() {
	for (int i = 0; i < vc.size(); i++) {
		fireBall cur = vc[i];
		MAP[cur.ypos][cur.xpos]--;
		int curS = cur.speed, ny = cur.ypos, nx = cur.xpos;
		pii curD = dir[cur.d];
		while (curS--) {
			ny += curD.first, nx += curD.second;
			bool isBreak = false;
			if (!(1 <= ny && ny <= N)) {
				ny -= curD.first;
				isBreak = true;
			}
			if (!(1 <= nx && nx <= N)) {
				nx -= curD.second;
				isBreak = true;
			}
			if (isBreak) break;
		}
		vc[i].ypos = ny, vc[i].xpos = nx;
		MAP[ny][nx]++;
	}
}

void check() {
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		if (MAP[i][j] <= 1) continue;
		fireBall temp = { i,j,0,0,0 };
		int prevDir = -1, cnt = MAP[i][j];
		bool isSameDir = true;
		for (int k = 0; k < vc.size(); k++) {
			if (!(vc[k].ypos == i && vc[k].xpos == j)) continue;
			if (prevDir == -1) prevDir = vc[k].d % 2;
			else prevDir == vc[k].d % 2 ? isSameDir = true : isSameDir = false;
			temp.mass += vc[k].mass, temp.speed += vc[k].mass;
			vc.erase(vc.begin() + k);
			k--;
		}
		if (temp.mass < 5) {
			MAP[i][j] = 0;
			continue;
		}
		MAP[i][j] = 4;
		for (int k = 0; k < 4; k++) {
			// 0 2 4 6
			if (isSameDir) {
				vc.push_back(
					{ temp.ypos ,
					  temp.xpos ,
					  temp.mass / 5,
					  temp.speed / cnt,
					  k * 2 });
			}
			// 1 3 5 7
			else {
				vc.push_back(
					{ temp.ypos ,
					  temp.xpos ,
					  temp.mass / 5,
					  temp.speed / cnt,
					  k * 2 });
			}
		}
	}
}

void output() {
	int ans = 0;
	for (auto const u : vc) ans += u.mass;
	cout << ans << '\n';
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int ypos, xpos, m, s, d;
		cin >> ypos >> xpos >> m >> s >> d;
		vc.push_back({ ypos,xpos,m,s,d });
		MAP[ypos][xpos]++;
	}
	while (K--) {
		move();
		check();
	}
	output();
}