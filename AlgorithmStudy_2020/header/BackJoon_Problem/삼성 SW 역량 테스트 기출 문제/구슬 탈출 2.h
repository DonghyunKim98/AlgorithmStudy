#include <bits/stdc++.h>
//13460�� ����
using namespace std;
const int MAX = 10;
int N, M;
pair<int, int> red, blue, hole;
int board[10][10];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int MAX_CNT = 0, answer = INT_MAX;
void DFS(int Rx, int Ry, int Bx, int By, int cnt) {
	if (cnt > 10) answer = -1;

	for (int k = 0; k < 4; k++) {
		int nRx = Rx, nRy = Ry, nBx = Bx, nBy = By, Rcnt = 0, Bcnt = 0;
		bool is_R_hole = false, is_B_hole = false;
		cnt ++;
		//���� ���� ������
		while (board[Ry + dy[k]][Rx + dx[k]]) {
			if (Ry + dy[k] >= 0 && Ry + dy[k] < N && Rx + dx[k] >= 0 && Rx + dx[k] < M) {
				nRx += dx[k], nRy +=  dy[k];
				Rcnt++;
				if (hole == make_pair(nRy, nRx)) {
					is_R_hole = true;
					break;
				}
			}
			else break;
		}
		//�Ķ� ���� ������
		while (board[By + dy[k]][Bx + dx[k]]) {
			if (By + dy[k] >= 0 && By + dy[k] < N && Bx + dx[k] >= 0 && Bx + dx[k] < M) {
				nBx += dx[k], nRy += dy[k];
				Bcnt++;
				if (hole == make_pair(nBy, nBx)) {
					is_B_hole = true;
					break;
				}
			}
			else break;
		}

		//���� ������ �������� ��� ó��
		if (is_R_hole) {
			//�� �� �������� ���
			if (is_B_hole) {
				//���� ���� ���� �����ϸ� ��
				if (Rcnt < Bcnt) answer = cnt;
				else answer = -1;
			}
			else answer = cnt;
			break;
		}
		//���� ������ �Ķ� ������ ������ ��ġ�� ������ ó���ϱ�
		if (nRx == nBx && nRy == nBy) {
			//���� ���ϼ���
			if (Rx == Bx) {
				if (Ry > By) nRy -= dy[k];
				else nBy -= dy[k];
			}
			//���� ���ϼ���
			else {
				if (Rx > By) nRx -= dx[k];
				else nBx -= dx[k];
			}
		}
		//DFS
		DFS(nRx, nRy, nBx, nBy, cnt);
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//Input
	cin >> N >> M;
	// 0 : ��  // 1 : ���� , ����
	// �������� �Ķ���, ������ ��ġ ����
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

	//DFS
	DFS(red.second, red.first, blue.second, blue.first, 0);
	cout << answer;
}

/*
	�⺻ ���̵��
	1. ��Ʈ��ŷ : �������� ���� ���� �� ������ ���� �����ؼ� �ٽ� �������
	2. dfs
	3. ���� & �Ķ� ���� ���ÿ� �����̱� (?)
	�ϴ��� �̷��� �ϰ�, �ּڰ��� ���߿� �����غ���
*/