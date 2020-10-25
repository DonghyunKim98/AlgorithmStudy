#include <bits/stdc++.h>
// 20056¹ø ¹®Á¦
using namespace std;
#define MAX 51
typedef pair<int, int> pii;
typedef struct {
	int ypos, xpos, mass, d, speed;
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
		cur.ypos = ny, cur.xpos = nx;
		MAP[cur.ypos][cur.xpos]++;
	}
}

void check() {
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		if (MAP[i][j] <= 1) continue;
		fireBall temp = { i,j,0,0,0 };
		int size = vc.size();
		int prevDir = -1;
		bool isSameDir = true;
		for (int i = 0; i < size; i++) {
			if (!(vc[i].ypos == i && vc[i].xpos == j)) continue;
			if (prevDir == -1) prevDir = vc[i].d % 2;
			else prevDir == vc[i].d % 2 ? isSameDir = true : isSameDir = false;
			temp.mass += vc[i].mass, temp.speed += vc[i].mass;
			vc.erase(vc.begin() + i);
		}
		if (temp.mass < 5) continue;
		for (int k = 0; k < 4; k++) {
			// 0 2 4 6
			if (isSameDir) {
				vc.push_back(
					{ temp.ypos + dir[k * 2].first,
					  temp.xpos + dir[k * 2].second,
					  temp.mass/5,
					  k*2,
					  temp.speed/5});
			}
			// 1 3 5 7
			else {
				vc.push_back(
					{ temp.ypos + dir[k * 2 + 1].first,
					  temp.xpos + dir[k * 2 + 1].second,
					  temp.mass / 5,
					  k * 2 + 1,
					  temp.speed / 5 });
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
		int ypos, xpos, m, d, s;
		cin >> ypos >> xpos >> m >> d >> s;
		vc.push_back({ ypos,xpos,m,d,s });
		MAP[ypos][xpos]++;
	}
	while (K--) {
		move();
		check();
	}
	output();
}