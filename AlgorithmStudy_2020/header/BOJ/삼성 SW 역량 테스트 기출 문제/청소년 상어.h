#include <bits/stdc++.h>
//19236번 문제
using namespace std;
typedef struct {
	int y, x, dir, score;
}shark;
pair<int, int> arr[4][4];
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int answer = 0;

void Fish_Move(int ypos, int xpos, shark Shark) {
	for (int k = 0; k < 8; k++) {
		int dir = arr[ypos][xpos].second;
		int ny = ypos + dy[dir], nx = xpos + dx[dir];
		if (0 <= ny && ny < 4 && 0 <= nx && nx < 4) {
			if (!(ny == Shark.y && nx == Shark.x)) {
				//Swap
				pair<int, int> temp = arr[ny][nx];
				arr[ny][nx] = arr[ypos][xpos];
				arr[ypos][xpos] = temp;
				return;
			}
		}
		arr[ypos][xpos].second = (dir + 1) % 8;
	}
}

shark Shark_Move(shark Shark,int cnt) {
	int dir = Shark.dir;
	int ny = Shark.y + (dy[dir] * cnt), nx = Shark.x + (dx[dir] * cnt);
	if (!(0 <= ny && ny < 4 && 0 <= nx && nx < 4)) return { -1,-1,-1,-1 };
	else if (arr[ny][nx].first == 0) return { -2,-2,-2,-2 };
	else  {
		shark ret = { ny,nx,arr[ny][nx].second,Shark.score + arr[ny][nx].first };
		arr[ny][nx] = { 0,0 };
		answer = max(answer, ret.score);
		return ret;
	}
}

void move(shark Shark) {
	pair<int, int> brr[4][4];
	int idx = 1;
	//물고기 이동
	while (idx <= 16) {
		bool is_idx = false;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (arr[i][j].first == idx) {
					Fish_Move(i, j, Shark);
					is_idx = true;
					break;
				}
			}
			if (is_idx) break;
		}
		idx++;
	}
	int cnt = 1;
	while (true) {
		copy(&arr[0][0], &arr[0][0] + (4) * (4), &brr[0][0]);
		//상어 이동
		shark next = Shark_Move(Shark, cnt);
		if (next.y == -1) return;
		else if(next.y!= -2) move(next);

		//backTracking
		copy(&brr[0][0], &brr[0][0] + (4) * (4), &arr[0][0]);

		cnt++;
	}
}



void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			arr[i][j] = make_pair(num, dir - 1);
		}
	}
	//첫 상어 이동
	shark Shark = { 0,0,arr[0][0].second,arr[0][0].first }; answer += arr[0][0].first; arr[0][0] = { 0,0 };
	move(Shark);
	cout << answer;
}