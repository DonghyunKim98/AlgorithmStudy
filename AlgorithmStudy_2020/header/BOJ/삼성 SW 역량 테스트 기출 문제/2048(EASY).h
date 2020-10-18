#include <bits/stdc++.h>
//12100번 문제
using namespace std;
const int MAX = 20;
int N, ans = 0;
int MAP[MAX][MAX];

void DFS(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ans < MAP[i][j] ? ans = MAP[i][j] : ans = ans;
		return;
	}
	int temp[MAX][MAX];
	std::copy(&MAP[0][0], &MAP[0][0] + (MAX) * (MAX), &temp[0][0]);
	for (int k = 0; k < 4; k++) {
		int temp_val;
		//위로 밀기
		if (k == 0) {
			for (int xpos = 0; xpos < N; xpos++) {
				vector<int> vc;
				temp_val = MAP[0][xpos];
				for (int i = 1; i < N; i++) {
					//빈공간을 만났을때 -> 그냥 pass
					if (MAP[i][xpos] == 0) {}
					//temp_val는 0인데 블록을 만났을때
					else if (temp_val == 0 && MAP[i][xpos] != 0) {
						temp_val = MAP[i][xpos];
					}
					//temp_val와 같은 블록을 만났을때
					else if (MAP[i][xpos] == temp_val) {
						vc.push_back(temp_val * 2);
						temp_val = 0;
					}
					//temp_val와 같지 않은 블록을 만났을때
					else if (MAP[i][xpos] != temp_val) {
						vc.push_back(temp_val);
						temp_val = MAP[i][xpos];
					}
					//끝항 예외처리
					if (i == N - 1 && temp_val != 0) {
						vc.push_back(temp_val);
					}
				}
				if (N == 1) vc.push_back(temp_val);
				for (int i = 0; i < N; i++) {
					if (i < vc.size()) {
						MAP[i][xpos] = vc[i];
					}
					else MAP[i][xpos] = 0;
				}
			}
		}
		//아래로 밀기
		else if (k == 1) {
			for (int xpos = 0; xpos < N; xpos++) {
				vector<int> vc;
				temp_val = MAP[N - 1][xpos];
				for (int i = N - 2; i >= 0; i--) {
					//빈공간을 만났을때 -> 그냥 pass
					if (MAP[i][xpos] == 0) {}
					//temp_val는 0인데 블록을 만났을때
					else if (temp_val == 0 && MAP[i][xpos] != 0) {
						temp_val = MAP[i][xpos];
					}
					//temp_val와 같은 블록을 만났을때
					else if (MAP[i][xpos] == temp_val) {
						vc.push_back(temp_val * 2);
						temp_val = 0;
					}
					//temp_val와 같지 않은 블록을 만났을때
					else if (MAP[i][xpos] != temp_val) {
						vc.push_back(temp_val);
						temp_val = MAP[i][xpos];
					}
					//끝항 예외처리
					if (i == 0 && temp_val != 0) {
						vc.push_back(temp_val);
					}
				}
				if (N == 1) vc.push_back(temp_val);
				for (int i = N - 1; i >= 0; i--) {
					if (i < vc.size()) {
						MAP[i][xpos] = vc[i];
					}
					else MAP[i][xpos] = 0;
				}
			}
		}
		//왼쪽으로 밀기
		else if (k == 2) {
			for (int ypos = 0; ypos < N; ypos++) {
				vector<int> vc;
				temp_val = MAP[ypos][0];
				for (int i = 1; i < N; i++) {
					//빈공간을 만났을때 -> 그냥 pass
					if (MAP[ypos][i] == 0) {  }
					//temp_val는 0인데 블록을 만났을때
					else if (temp_val == 0 && MAP[ypos][i] != 0) {
						temp_val = MAP[ypos][i];
					}
					//temp_val와 같은 블록을 만났을때
					else if (MAP[ypos][i] == temp_val) {
						vc.push_back(temp_val * 2);
						temp_val = 0;
					}
					//temp_val와 같지 않은 블록을 만났을때
					else if (MAP[ypos][i] != temp_val) {
						vc.push_back(temp_val);
						temp_val = MAP[ypos][i];
					}
					//끝항 예외처리
					if (i == N - 1 && temp_val != 0) {
						vc.push_back(temp_val);
					}
				}
				if (N == 1) vc.push_back(temp_val);
				for (int i = 0; i < N; i++) {
					if (i < vc.size()) {
						MAP[ypos][i] = vc[i];
					}
					else MAP[ypos][i] = 0;
				}
			}
		}
		//오른쪽으로 밀기
		else {
			for (int ypos = 0; ypos < N; ypos++) {
				vector<int> vc;
				temp_val = MAP[ypos][N - 1];
				for (int i = N - 2; i >= 0; i--) {
					//빈공간을 만났을때 -> 그냥 pass
					if (MAP[ypos][i] == 0) {}
					//temp_val는 0인데 블록을 만났을때
					else if (temp_val == 0 && MAP[ypos][i] != 0) {
						temp_val = MAP[ypos][i];
					}
					//temp_val와 같은 블록을 만났을때
					else if (MAP[ypos][i] == temp_val) {
						vc.push_back(temp_val * 2);
						temp_val = 0;
					}
					//temp_val와 같지 않은 블록을 만났을때
					else if (MAP[ypos][i] != temp_val) {
						vc.push_back(temp_val);
						temp_val = MAP[ypos][i];
					}
					//끝항 예외처리
					if (i == 0 && temp_val != 0) {
						vc.push_back(temp_val);
					}
				}
				if (N == 1) vc.push_back(temp_val);
				for (int i = N - 1; i >= 0; i--) {
					if (i < vc.size()) {
						MAP[ypos][i] = vc[i];
					}
					else MAP[ypos][i] = 0;
				}
			}
		}
		DFS(cnt + 1);
		std::copy(&temp[0][0], &temp[0][0] + (MAX) * (MAX), &MAP[0][0]);
	}
}


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> MAP[i][j];
	DFS(0);
	cout << ans;
}