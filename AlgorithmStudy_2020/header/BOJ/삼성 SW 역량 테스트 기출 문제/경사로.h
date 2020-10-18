#include <bits/stdc++.h>
//14890번 문제
using namespace std;
const int MAX = 100;
int N, L;
int arr[MAX][MAX];
bool slope[MAX][MAX];
int same_block_row(int y, int x) {
	int cnt = 1;
	for (int i = x + 1; i < N; i++) {
		if (arr[y][x] == arr[y][i]) cnt++;
		else break;
	}
	return cnt;
}

int same_block_col(int y, int x) {
	int cnt = 1;
	for (int i = y + 1; i < N; i++) {
		if (arr[y][x] == arr[i][x]) cnt++;
		else break;
	}
	return cnt;
}

bool slopeMount_row(int y, int x, int cnt) {
	for (int i = 0; i < cnt; i++) {
		if (slope[y][x + i]) return false;
		slope[y][x + i] = true;
	}
	return true;
}

bool slopeMount_col(int y, int x, int cnt) {
	for (int i = 0; i < cnt; i++) {
		if (slope[y + i][x]) return false;
		slope[y + i][x] = true;
	}
	return true;
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	int answer = 0;
	//가로 검사
	for (int i = 0; i < N; i++) {
		//초깃값
		int current = arr[i][0], cnt = 1;
		bool can_line = true; memset(slope, false, sizeof(slope));
		for (int j = 1; j < N; j++) {
			//높이가 같을때
			if (arr[i][j] == current) {
				current = arr[i][j], cnt++;
			}
			else {
				if (abs(arr[i][j] - current) != 1) {
					can_line = false; break;
				}
				else {
					if (arr[i][j] > current) {
						if (cnt < L) {
							can_line = false; break;
						}
						else {
							can_line = slopeMount_row(i, j - L, L);
							if (can_line == false) break;
						}
					}
					else {
						cnt = same_block_row(i, j);
						if (cnt < L) {
							can_line = false; break;
						}
						else {
							can_line = slopeMount_row(i, j, L);
							if (can_line == false) break;
						}
					}
					current = arr[i][j], cnt = 1;
				}
			}
		}
		if (can_line) answer++;
	}

	//세로 검사
	for (int j = 0; j < N; j++) {
		int current = arr[0][j], cnt = 1;
		bool can_line = true; memset(slope, false, sizeof(slope));
		for (int i = 1; i < N; i++) {
			//높이가 같을때
			if (arr[i][j] == current) {
				current = arr[i][j]; cnt++;
			}
			else {
				if (abs(arr[i][j] - current) != 1) {
					can_line = false; break;
				}
				else {
					if (arr[i][j] > current) {
						if (cnt < L) {
							can_line = false; break;
						}
						else {
							can_line = slopeMount_col(i - L, j, L);
							if (can_line == false) break;
						}
					}
					else {
						cnt = same_block_col(i, j);
						if (cnt < L) {
							can_line = false; break;
						}
						else {
							can_line = slopeMount_col(i, j, L);
							if (can_line == false) break;
						}
					}
					current = arr[i][j], cnt = 1;
				}
			}
		}
		if (can_line) answer++;
	}
	cout << answer;
}
