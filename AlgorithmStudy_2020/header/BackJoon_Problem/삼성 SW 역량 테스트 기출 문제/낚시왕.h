#include <bits/stdc++.h>
//17143¹ø ¹®Á¦
using namespace std;
const int MAX = 100;
typedef struct {
	int speed, dir, size;
}shark;
int R, C, M;
vector<shark> shark_vc[MAX][MAX];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int hunt(int col) {
	int idx = 0;
	while (idx < R) {
		if (shark_vc[idx][col].size()) {
			int ret = shark_vc[idx][col][0].size; shark_vc[idx][col].pop_back();
			return ret;
		}
		idx++;
	}
	return 0;
}

void move() {
	for (int ypos = 0; ypos < R; ypos++) {
		for (int xpos = 0; xpos < C; xpos++) {
			if (shark_vc[ypos][xpos].size() == 0) continue;
			shark cur = shark_vc[ypos][xpos].front();
			int ny = ypos + (dy[cur.dir] * cur.speed), nx = xpos + (dx[cur.dir] * cur.speed);
			while (!(0 <= ny && ny < R && 0 <= nx && nx < C)) {
				if (ny < 0) {
					ny *= -1;
					cur.dir = 1;
				}
				else if (R <= ny) {
					ny = 2 * (R - 1) - ny;
					cur.dir = 0;
				}
				else if (nx < 0) {
					nx *= -1;
					cur.dir = 3;
				}
				else if (C <= nx) {
					nx = 2 * (C - 1) - nx;
					cur.dir = 4;
				}
			}
			shark_vc[ny][nx].push_back(cur);
			shark_vc[ypos][xpos].erase(shark_vc[ypos][xpos].begin());
		}
	}
}

void is_duplicate() {
	for (int ypos = 0; ypos < R; ypos++) {
		for (int xpos = 0; xpos < C; xpos++) {
			if (shark_vc[ypos][xpos].size() == 0 || shark_vc[ypos][xpos].size() == 1) continue;
			while (shark_vc[ypos][xpos].size() != 1) {
				if (shark_vc[ypos][xpos][0].size > shark_vc[ypos][xpos][1].size)
					shark_vc[ypos][xpos].erase(shark_vc[ypos][xpos].begin() + 1);
				else shark_vc[ypos][xpos].erase(shark_vc[ypos][xpos].begin());
			}
		}
	}
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int ypos, xpos, speed, dir, size;
		cin >> ypos >> xpos >> speed >> dir >> size;
		if (dir == 1 || dir == 2) speed %= ((C * 2) - 1);
		else speed %= ((R * 2) - 1);
		shark_vc[ypos-1][xpos-1].push_back({ speed,dir-1,size });
	}
	int current_column = -1, answer = 0;
	while (current_column < C) {
		current_column++;
		answer += hunt(current_column);
		move();
		is_duplicate();
	}
	cout << answer;
}