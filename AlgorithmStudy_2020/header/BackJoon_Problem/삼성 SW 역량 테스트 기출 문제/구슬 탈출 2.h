#include <bits/stdc++.h>
//13460번 문제
using namespace std;
const int MAX = 10;
int N, M;
pair<int, int> red, blue, hole;
int board[10][10];
int Rvisited[10][10], Bvisited[10][10];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int MAX_CNT = 0, answer = INT_MAX;

void BFS() {
	queue<pair<int, int>> Rq, Bq;
	Rq.push(red), Bq.push(blue);
	int cnt = 0;
	while (!Rq.empty() && !Bq.empty()) {
		int Ry = Rq.front().first, Rx = Rq.front().second;
		int By = Bq.front().first, Bx = Bq.front().second;
		Rq.pop(), Bq.pop();
		cnt++;
		if (cnt > 10) {
			std::cout << -1;
			exit(0);
		}
		for (int k = 0; k < 4; k++) {
			int nRx = Rx, nRy = Ry, nBx = Bx, nBy = By, Rcnt = 0, Bcnt = 0;
			bool is_R_hole = false, is_B_hole = false;
			//빨간 구슬 굴리기
			while (board[Ry + dy[k]][Rx + dx[k]]) {
				if (Ry + dy[k] >= 0 && Ry + dy[k] < N && Rx + dx[k] >= 0 && Rx + dx[k] < M && Rvisited[Ry + dy[k]][Rx + dx[k]] == 0) {
					nRx += dx[k], nRy += dy[k];
					Rcnt++;
					Rvisited[nRy][nRx] = cnt;
					if (hole == make_pair(nRy, nRx)) {
						is_R_hole = true;
						break;
					}
				}
				else break;
			}
			//파란 구슬 굴리기
			while (board[By + dy[k]][Bx + dx[k]]) {
				if (By + dy[k] >= 0 && By + dy[k] < N && Bx + dx[k] >= 0 && Bx + dx[k] < M && Bvisited[By + dy[k]][Bx + dx[k]] == 0) {
					nBx += dx[k], nRy += dy[k];
					Bcnt++;
					Bvisited[nBy][nRx] = cnt;
					if (hole == make_pair(nBy, nBx)) {
						is_B_hole = true;
						break;
					}
				}
				else break;
			}

			//공이 구슬에 도착했을 경우 처리
			if (is_R_hole) {
				//둘 다 도착했을 경우
				if (is_B_hole) {
					//빨간 공이 먼저 도착하면 됨
					if (Rcnt < Bcnt) {
						std::cout<<cnt;
						exit(0);
					}
					else {
						std::cout << -1;
						exit(0);
					}
				}
				else {
					std::cout << cnt;
					exit(0);
				}
				break;
			}
			//빨간 구슬과 파란 구슬이 동일한 위치에 있을때 처리하기
			if (nRx == nBx && nRy == nBy) {
				//세로 동일선상
				if (Rx == Bx) {
					if (Ry > By) nRy -= dy[k];
					else nBy -= dy[k];
				}
				//가로 동일선상
				else {
					if (Rx > By) nRx -= dx[k];
					else nBx -= dx[k];
				}
			}
			Rq.push(make_pair(Ry, Rx));
			Bq.push(make_pair(By, Bx));
		}
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0);
	memset(Rvisited, 0, sizeof(Rvisited));
	memset(Bvisited, 0, sizeof(Bvisited));
	//Input
	cin >> N >> M;
	// 0 : 벽  // 1 : 공간 , 구멍
	// 빨간공과 파란공, 구멍은 위치 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			cin >> temp;
			if (temp == '#') board[i][j] = 0;
			else {
				board[i][j] = 1;
				if (temp == 'R')
					red = make_pair(i, j);
				else if (temp == 'B')
					blue = make_pair(i, j);
				else if (temp == 'O')
					hole = make_pair(i, j);
			}
		}
	}

	//BFS
	BFS();
}

/*
	기본 아이디어
	1. 백트래킹 : 왼쪽으로 가본 길이 안 맞으면 원상 복귀해서 다시 원래대로
	2. dfs
	3. 빨강 & 파랑 구슬 동시에 움직이기 (?)
	일단은 이렇게 하고, 최솟값은 나중에 생각해보자
*/