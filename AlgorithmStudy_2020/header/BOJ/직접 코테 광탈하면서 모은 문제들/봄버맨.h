#include <bits/stdc++.h>
//16918번 문제
using namespace std;
typedef pair<int, int> pii;
vector<pii> bomb;
const int MAX = 200 + 1;
char MAP[MAX][MAX];
int R, C, N;
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

void output() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << MAP[i][j];
		}
		cout << '\n';
	}
}

void boom(int ypos, int xpos) {
	MAP[ypos][xpos] = '.';
	for (int k = 0; k < 4; k++) {
		int ny = ypos + dy[k], nx = xpos + dx[k];
		if(0<=ny&&ny<R&&0<=C&&nx<C)	MAP[ny][nx] = '.';
	}
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C >> N;

	for (int i = 0; i < R; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < C; j++) {
			MAP[i][j] = temp[j];
			if (MAP[i][j]=='O') bomb.push_back({ i,j });
		}
	}

	int cnt = 1;
	while (cnt <= N - 1) {
		//홀수 초가 지나갈때
		if (cnt & 1) {
			for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
				if (MAP[i][j]=='.') MAP[i][j] = 'O';
			}
		}
		//짝수 초가 지나갈때
		else {
			for (auto u : bomb) {
				boom(u.first, u.second);
			}
			bomb.clear();
			for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
				if (MAP[i][j]=='O') bomb.push_back({ i,j });
			}
		}
		cnt++;
	}
	output();
}