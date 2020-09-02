#include <bits/stdc++.h>
//13460번 문제
using namespace std;
const int MAX = 10;
int N, M;
pair<int, int> red, blue, hole;
int board[10][10];
int Rvisited[10][10], Bvisited[10][10];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int MAX_CNT = 0, answer = INT_MAX;

void BFS() {
	queue<pair<pair<int, int>,int>> Rq, Bq;
	Rq.push({ red,0 }), Bq.push({blue,0 });

	while (!Rq.empty() && !Bq.empty()) {
		int Ry = Rq.front().first.first, Rx = Rq.front().first.second;
		int By = Bq.front().first.first, Bx = Bq.front().first.second;
		int cnt = Rq.front().second;
		Rq.pop(), Bq.pop();
		if (cnt > 9) {
			std::cout << -1;
			exit(0);
		}
		for (int k = 0; k < 4; k++) {
			int nRy = Ry, nRx = Rx, nBy = By, nBx = Bx;
			bool is_R_hole = false, is_B_hole = false;
			//빨간 구슬 굴리기
			while (1) {
				if (nRy + dy[k] >= 0 && nRy + dy[k] < N && nRx + dx[k] >= 0 && nRx + dx[k] < M) {
					if (board[nRy + dy[k]][nRx + dx[k]]) {
						nRy += dy[k], nRx += dx[k];
						if (hole == make_pair(nRy, nRx)) {
							is_R_hole = true;
							break;
						}
					}
					else break;
				}
				else break;
			}
			//파란 구슬 굴리기
			while (1) {
				if (nBy + dy[k] >= 0 && nBy + dy[k] < N && nBx + dx[k] >= 0 && nBx + dx[k] < M) {
					if (board[nBy + dy[k]][nBx + dx[k]]) {
						nBy += dy[k], nBx += dx[k];
						if (hole == make_pair(nBy, nBx)) {
							is_B_hole = true;
							break;
						}
					}
					else break;
				}
				else break;
			}

			//공이 구슬에 도착했을 경우 처리
			if (is_R_hole) {
				//둘 다 도착했을 경우
				if (is_B_hole) continue;
				else {
					std::cout << cnt + 1;
					exit(0);
				}
				break;
			}
			else if (is_B_hole) continue;
			//빨간 구슬과 파란 구슬이 동일한 위치에 있을때 처리하기
			if (nRx == nBx && nRy == nBy) {
				//세로 동일선상
				if (Rx == Bx) {
					if (Ry > By) dy[k] == 1 ? nBy -= dy[k] : nRy -= dy[k];
					else dy[k] == 1 ? nRy -= dy[k] : nBy -= dy[k];
				}
				//가로 동일선상
				else {
					//빨간구슬이 원래 오른쪽에 있었음
					if (Rx > Bx) {
						dx[k]==1 ? nBx -= dx[k]: nRx -=dx[k];
					}
					//파란구슬이 원래 오른쪽에 있었음
					else dx[k] == 1 ? nRx -= dx[k] : nBx -= dx[k];
				}
			}
			//빨간 구슬과 파란 구슬 둘다 못 움직인 경우 ->배척
			if (nRy == Ry && nRx == Rx && nBy == By && nBx == Bx) continue;
			Rq.push({ make_pair(nRy, nRx),cnt + 1 });
			Bq.push({ make_pair(nBy, nBx),cnt + 1 });
		}
	}
	std::cout << -1;
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
	BFS();
}

/*
	기본 아이디어
	1. BFS -> 최솟값을 구해야하므로.
	2. 1칸씩 움직이는것이 아닌 한번에 기울이기 구현.
	3. 빨강 & 파랑 구슬 동시에 움직이기 
*/