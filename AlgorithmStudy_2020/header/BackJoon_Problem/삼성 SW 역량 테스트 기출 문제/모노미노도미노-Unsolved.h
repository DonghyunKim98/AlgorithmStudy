#include <bits/stdc++.h>
//19235번 문제
using namespace std;
const int MAX = 10000;
int N, ans = 0;
int red[4][4], blue[4][6], green[6][4];

void blue_copy(int idx) {
	for (int i = 0; i < 4; i++) {
		blue[i][idx] = blue[i][idx - 1];
	}
}
void blue_copy2(int idx) {
	for (int i = 0; i < 4; i++) {
		blue[i][idx] = blue[i][idx - 2];
	}
}
void check_two_block(int idx) {
	if (idx == 5 || idx == 3) return;
	if (idx == 4) {
		for (int k = 0; k < 4; k++) {
			if (blue[k][idx] == 2 && blue[k][idx - 1] == 2 && blue[k][idx + 1] == 0) {
				blue[k][idx - 1] = 0, blue[k + 1][idx + 1] = 2;
			}
		}
	}
	else//idx==3 
	{
		for (int k = 0; k < 4; k++) {
			if (blue[k][idx] == 2 && blue[k][idx - 1] == 2) {
				if (blue[k][idx + 1] == 0 && blue[k][idx + 2] == 0) {
					blue[k][idx] = blue[k][idx - 1] = 0;
					blue[k][idx + 1] = blue[k][idx + 2] = 2;
				}
				else if (blue[k][idx + 1] == 0) {
					blue[k][idx - 1] = 0, blue[k + 1][idx + 1] = 2;
				}
			}
		}
	}
}
void check_three_block(int idx) {
	if (idx == 5 || idx == 3) return;
	if (idx == 4) {
		for (int k = 0; k < 4; k++) {
			if (green[idx][k] == 3 && green[idx - 1][k] == 3 && green[idx + 1][k] == 0) {
				green[idx - 1][k] = 0, green[idx + 1][k] = 3;
			}
		}
	}
	else {
		for (int k = 0; k < 4; k++) {
			if (green[idx][k] == 3 && green[idx - 1][k] == 3) {
				if (green[idx + 1][k] == 0 && green[idx + 2][k]) {
					green[idx + 1][k] = green[idx + 2][k] = 3;
					green[idx][k] = green[idx - 1][k] = 0;
				}
				else if (green[idx + 1][k] == 0) {
					green[idx - 1][k] = 0, green[idx + 1][k] = 3;
				}
			}
		}
	}
}
void check_green() {
	//점수 계산
	int cnt = 0;
	while (cnt < 3) {
		for (int i = 2; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				if (!green[i][j]) break;
				if (j != 3) continue;
				ans++;
				for (int f = i; f > 0; f--) {
					copy(&green[f - 1][0], &green[f - 1][0] + 4, &green[f][0]);
				}
				check_three_block(i);
				memset(&green[0], false, sizeof(green[0]));
			}
		}
		cnt++;
	}

	int over_cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j]) {
				over_cnt = 2 - i; break;
			}
		}
	}
	if (over_cnt == 1) {
		for (int i = 5; i >= 2; i--) {
			copy(&green[i - 1][0], &green[i - 1][0] + 4, &green[i][0]);
		}
		memset(green[1], false, sizeof(green[1]));
	}
	else if (over_cnt == 2) {
		for (int i = 5; i >= 2; i--) {
			copy(&green[i - 2][0], &green[i - 2][0] + 4, &green[i + 2][0]);
		}
		memset(green[1], false, sizeof(green[1]));
		memset(green[0], false, sizeof(green[0]));
	}
}
void check_blue() {
	int cnt = 0;
	while (cnt < 3) {
		for (int i = 2; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				if (!blue[j][i]) break;
				if (j != 3) continue;
				ans++;
				for (int f = i; f > 0; f--) {
					blue_copy(f);
				}
				check_two_block(i);
				for (int k = 0; k < 4; k++) {
					blue[k][0] = false;
				}
			}
		}
		cnt++;
	}
	int over_cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (blue[j][i]) {
				over_cnt = 2 - i; break;
			}
		}
	}
	if (over_cnt == 1) {
		for (int i = 5; i >= 2; i--) {
			blue_copy(i);
		}
		for (int k = 0; k < 4; k++) {
			blue[k][1] = false;
		}
	}
	else if (over_cnt == 2) {
		for (int i = 5; i >= 2; i--) {
			blue_copy2(i);
		}
		for (int k = 0; k < 4; k++) {
			blue[k][0] = false;
			blue[k][1] = false;
		}
	}
}
void case_1(int ypos, int xpos) {
	for (int i = 0; i <= 5; i++) {
		if (i == 5) {
			blue[ypos][i] = 1;
			break;
		}
		if (!blue[ypos][i] && blue[ypos][i + 1]) {
			blue[ypos][i] = 1;
			break;
		}
	}

	for (int i = 0; i <= 5; i++) {
		if (i == 5) {
			green[i][xpos] = 1;
			break;
		}
		if (!green[i][xpos] && green[i + 1][xpos]) {
			green[i][xpos] = 1;
			break;
		}
	}
	check_blue(); check_green();
}
void case_2(int ypos, int xpos) {
	for (int i = 0; i <= 4; i++) {
		if (i == 4) {
			blue[ypos][i] = 2, blue[ypos][i + 1] = 2;
			break;
		}
		if (!blue[ypos][i] && !blue[ypos][i + 1] && blue[ypos][i + 2]) {
			blue[ypos][i] = 2, blue[ypos][i + 1] = 2;
			break;
		}
	}

	for (int i = 0; i <= 5; i++) {
		if (i == 5) {
			green[i][xpos] = 2, green[i][xpos + 1] = 2;
			break;
		}
		if (!green[i][xpos] && !green[i][xpos + 1] && (green[i + 1][xpos] || green[i + 1][xpos + 1])) {
			green[i][xpos] = 2, green[i][xpos + 1] = 2;
			break;
		}
	}
	check_blue(); check_green();
}
void case_3(int ypos, int xpos) {
	for (int i = 0; i <= 5; i++) {
		if (i == 5) {
			blue[ypos][i] = 3, blue[ypos + 1][i] = 3;
			break;
		}
		if (!blue[ypos][i] && !blue[ypos + 1][i] && (blue[ypos][i + 1] || blue[ypos + 1][i + 1])) {
			blue[ypos][i] = 3, blue[ypos + 1][i] = 3;
			break;
		}
	}
	for (int i = 0; i <= 4; i++) {
		if (i == 4) {
			green[i][xpos] = 3; green[i + 1][xpos] = 3;
			break;
		}
		if (!green[i][xpos] && !green[i + 1][xpos] && green[i + 2][xpos]) {
			green[i][xpos] = 3; green[i + 1][xpos] = 3;
			break;
		}
	}
	check_blue(); check_green();
}
void output() {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j < 6; j++) {
			if (blue[i][j]) cnt++;
		}
	}
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j]) cnt++;
		}
	}
	cout << ans << '\n';
	cout << cnt;
}
void debug() {
	cout << "Blue\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++)
			cout << int(blue[i][j]) << ' ';
		cout << '\n';
	}
	cout << "Green\n";
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++)
			cout << int(green[i][j]) << ' ';
		cout << '\n';
	}
	cout << "현재 정답: " << ans << '\n';
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(red, false, sizeof(red));
	memset(blue, false, sizeof(blue));
	memset(green, false, sizeof(green));

	cin >> N;
	while (N > 0) {
		int Case, ypos, xpos;
		cin >> Case >> ypos >> xpos;
		switch (Case)
		{
		case 1:
			case_1(ypos, xpos);
			break;
		case 2:
			case_2(ypos, xpos);
			break;
		case 3:
			case_3(ypos, xpos);
			break;
		}
		debug();
		N--;
	}
	output();
}