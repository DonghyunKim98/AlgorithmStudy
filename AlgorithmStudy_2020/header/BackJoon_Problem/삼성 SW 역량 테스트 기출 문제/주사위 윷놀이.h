#include <bits/stdc++.h>
//17825번 문제
using namespace std;
int ans = 0;
int dice_result[10];
int position[4];
int MAP[] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,13,16,19,22,24,28,27,26,25,30,35,40,0 };

bool change_position(int idx, int cnt) {
	if (position[idx] == 32) return false;
	int temp = position[idx];
	if (temp == 5) {
		if (dice_result[cnt] <= 3) position[idx] = 19 + dice_result[cnt];
		else position[idx] = 24 + dice_result[cnt];
	}
	else if (temp == 10) {
		if (dice_result[cnt] <= 2) position[idx] = 22 + dice_result[cnt];
		else position[idx] = 25 + dice_result[cnt];
	}
	else if (temp == 15) {
		position[idx] = 24 + dice_result[cnt];
	}
	else if (16 <= temp && temp <= 19) {
		if (position[idx] + dice_result[cnt] == 20) position[idx] = 31;
		else if (position[idx] + dice_result[cnt] > 21) position[idx] = 32;
		else position[idx] += dice_result[cnt];
	}
	else if (20 <= temp && temp <= 22) {
		if (23 <= dice_result[cnt] + temp) position[idx] += 5 + dice_result[cnt];
		else position[idx] += dice_result[cnt];
	}
	else if (temp == 23 || temp == 24) {
		if (24 <= dice_result[cnt] + temp) position[idx] += 3 + dice_result[cnt];
		else position[idx] += dice_result[cnt];
	}
	else position[idx] += dice_result[cnt];

	//idx가 도착지점에 있는지 확인
	if (position[idx] > 32) position[idx] = 32;

	//겹치는지 확인
	for (int i = 0; i < 4; i++) {
		if (i == idx) continue;
		if (position[idx] == position[i]) {
			if (position[idx] == 32) continue;
			position[idx] = temp;
			return false;
		}
	}
	return true;
}

void DFS(int cnt, int temp_ret) {
	if (cnt == 10) {
		ans = max(temp_ret, ans);
		return;
	}
	for (int k = 0; k < 4; k++) {
		int temp = position[k];
		if (!change_position(k, cnt)) continue;
		DFS(cnt + 1, temp_ret + MAP[position[k]]);
		//backTracking
		position[k] = temp;
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 10; i++) {
		cin >> dice_result[i];
	}
	DFS(0, 0);
	cout << ans;
}