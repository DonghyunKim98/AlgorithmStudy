#include <bits/stdc++.h>
//15685번 문제
using namespace std;
int N;
bool MAP[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int check() {
	int ret = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j <100; j++) {
			if (MAP[i][j] && MAP[i][j + 1] && MAP[i + 1][j] && MAP[i + 1][j + 1]) ret++;
		}
	}
	return ret;
}

int pow_2(int num) {
	int ret = 1;
	for (int i = 1; i <= num; i++) {
		ret *= 2;
	}
	return ret;
}
/*
	dir이 시계방향으로 회전 => (dir+1)%4
	오->위->왼->아->오
	dir이 시계반대방향으로 회전 =>(dir+3)%4
	오->아->왼->위->오
	
	1세대->시계
	2세대->시계/반시계
	3세대->시계/시계/반시계/반시계
	4세대->시계/시계/시계/반시계/반시계/시계/반시게/반시계
			   (반시계/반시계/시계/시계/반시계/시계/시계)
	0세대->아
	1세대->오
	2세대->위/오
	3세대->위/왼/위/오
	4세대->위/왼/아/왼/위/왼/위/오
	
	1. 무조건 처음은 시계방향
	2. 두번째부턴 직전세대들의 방향을 반대로함

	0세대 ->1개
	1세대 ->1개
	2세대 ->2개
	3세대 ->4개
	4세대 ->8개
	5세대 ->16개
	n세대 ->2^n개
*/
void process() {
	int ypos, xpos, dir, generation;
	cin >> xpos >> ypos >> dir >> generation;
	vector<bool> vc;
	for (int g = 0; g <= generation; g++) {
		bool is_over=false;
		//0세대 예외처리
		if (g == 0) {
			MAP[ypos][xpos] = true;
			ypos += dy[dir], xpos += dx[dir];
			MAP[ypos][xpos] = true;
			continue;
		}
		for (int i = 1; i <= pow_2(g-1); i++) {
			if (i == 1) {
				dir = (dir + 1) % 4;
				vc.push_back(true);
			}
			/*
				vc
				1세대 -> [시계]
				2세대 -> 시계 / [시계,반시계]
				3세대 -> 시계, 시계, 반시계 / [시계,시게,반시계,반시계]
				4세대 -> 시계,시계,반시계,시계,시계,반시계,반시계/[시계,
			*/
			else {
				bool is_clock_dir = !vc[vc.size() - 2 - (i - 2) * 2];
				is_clock_dir ? dir = (dir + 1) % 4 : dir = (dir + 3) % 4;
				vc.push_back(is_clock_dir);
			}
			ypos += dy[dir], xpos += dx[dir];
			//범위 초과시 하면 break
			if (ypos < 0 && 100 < ypos && xpos < 0 && 100 < xpos) {
				is_over = true; break;
			}
			MAP[ypos][xpos] = true;
		}
		if (is_over) break;
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--) {
		process();
	}
	cout << check();
}