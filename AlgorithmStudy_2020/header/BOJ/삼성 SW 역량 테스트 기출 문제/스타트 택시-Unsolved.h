#include <bits/stdc++.h>
//19238번 문제
using namespace std;
const int MAX = 20 + 1;
struct point {
	int ypos, xpos;
};
point driver;
int N, M, fuel;
int MAP[MAX][MAX], Visited[MAX][MAX];
//NWES 순으로 방문해야함
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };


void init() {
	memset(Visited, false, sizeof(Visited));
}

//손님을 찾았으면 목적지까지 이송해야함
int check(int customer_idx, int ypos, int xpos, int current_fuel) {
	init();	queue<pair<point, int>> q;
	q.push({ { ypos,xpos }, current_fuel + 1 }); Visited[ypos][xpos] = true;
	while (true) {
		point current = q.front().first; int temp_Fuel = q.front().second;
		q.pop(); temp_Fuel--;
		if (temp_Fuel < 0) break;
		if (MAP[current.ypos][current.xpos] - 400 == customer_idx) {
			fuel = temp_Fuel + (current_fuel - temp_Fuel) * 2;
			driver = { current.ypos,current.xpos };
			return 1;
		}
		for (int k = 0; k < 4; k++) {
			int ny = current.ypos + dy[k], nx = current.xpos + dx[k];
			if (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
				if (Visited[ny][nx] && MAP[ny][nx] == -1) continue;
				Visited[ny][nx] = true;
				q.push({ { ny,nx }, temp_Fuel });
			};
		}
	}
	return -1; //중간에 연료가 다 떨어진경우
}

int BFS() {
	init();
	queue<pair<point, int>> q;
	q.push({ driver,fuel + 1 }); Visited[driver.ypos][driver.xpos] = true;
	while (!q.empty() && fuel > 0) {
		point current = q.front().first; int current_fuel = q.front().second;
		q.pop(); current_fuel--;
		if (1<=MAP[current.ypos][current.xpos]&& MAP[current.ypos][current.xpos] <= 400) {
			int ret = check(MAP[current.ypos][current.xpos], current.ypos, current.xpos, current_fuel);
			MAP[current.ypos][current.xpos] = 0;
			return ret;
		}
		for (int k = 0; k < 4; k++) {
			int ny = current.ypos + dy[k], nx = current.xpos + dx[k];
			if (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
				if (Visited[ny][nx] || MAP[ny][nx] == -1) continue;
				Visited[ny][nx] = true;
				q.push({ { ny,nx },current_fuel });
			}
		}
	}
	return -1;
}

void Input() {
	cin >> N >> M >> fuel;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			//벽인 경우 -1로 바꿔줌
			if (MAP[i][j] == 1) MAP[i][j] = -1;
		}
	int row, col;
	cin >> row >> col;
	driver = { row,col };
	for (int i = 1; i <= M; i++) {
		int row_start, col_start, row_arrive, col_arrive;
		cin >> row_start >> col_start >> row_arrive >> col_arrive;
		MAP[row_start][col_start] = i, MAP[row_arrive][col_arrive] = i + 400;
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Input();
	for (int i = 1; i <= M; i++) {
		if (BFS() == 1) continue;
		else {
			cout << -1;
			return;
		}
	}
	cout << fuel;
}