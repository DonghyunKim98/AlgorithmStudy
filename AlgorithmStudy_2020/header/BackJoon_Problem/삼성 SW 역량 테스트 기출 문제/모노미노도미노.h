#include <bits/stdc++.h>
//19235번 문제
using namespace std;
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

void case_1_green(int ypos, int xpos, int idx) {
	for (int i = idx; i <= 5; i++) {
		if (i == 5) {
			green[i][xpos] = 1;
			break;
		}
		if (!green[i][xpos] && green[i + 1][xpos]) {
			green[i][xpos] = 1;
			break;
		}
	}
}
void case_1_blue(int ypos, int xpos, int idx) {
	for (int i = idx; i <= 5; i++) {
		if (i == 5) {
			blue[ypos][i] = 1;
			break;
		}
		if (!blue[ypos][i] && blue[ypos][i + 1]) {
			blue[ypos][i] = 1;
			break;
		}
	}
}
void case_2_green(int ypos, int xpos, int idx) {
	for (int i = idx; i <= 5; i++) {
		if (i == 5) {
			green[i][xpos] = 2, green[i][xpos + 1] = 2;
			break;
		}
		if (!green[i][xpos] && !green[i][xpos + 1] && (green[i + 1][xpos] || green[i + 1][xpos + 1])) {
			green[i][xpos] = 2, green[i][xpos + 1] = 2;
			break;
		}
	}
}
void case_2_blue(int ypos, int xpos, int idx) {
	for (int i = idx; i <= 4; i++) {
		if (i == 4) {
			blue[ypos][i] = 1, blue[ypos][i + 1] = 1;
			break;
		}
		if (!blue[ypos][i] && !blue[ypos][i + 1] && blue[ypos][i + 2]) {
			blue[ypos][i] = 1, blue[ypos][i + 1] = 1;
			break;
		}
	}
}
void case_3_green(int ypos, int xpos, int idx) {
	for (int i = idx; i <= 4; i++) {
		if (i == 4) {
			green[i][xpos] = 1; green[i + 1][xpos] = 1;
			break;
		}
		if (!green[i][xpos] && !green[i + 1][xpos] && green[i + 2][xpos]) {
			green[i][xpos] = 1; green[i + 1][xpos] = 1;
			break;
		}
	}
}
void case_3_blue(int ypos, int xpos, int idx) {
	for (int i = idx; i <= 5; i++) {
		if (i == 5) {
			blue[ypos][i] = 3, blue[ypos + 1][i] = 3;
			break;
		}
		if (!blue[ypos][i] && !blue[ypos + 1][i] && (blue[ypos][i + 1] || blue[ypos + 1][i + 1])) {
			blue[ypos][i] = 3, blue[ypos + 1][i] = 3;
			break;
		}
	}
}

void drop_green(int idx) {
	for (int ypos = idx - 1; ypos >= 0; ypos--) {
		for (int xpos = 0; xpos < 4; xpos++) {
			if (green[ypos][xpos] == 1 || green[ypos][xpos]== 3) {
				green[ypos][xpos] = 0;
				case_1_green(ypos, xpos, ypos + 1);
			}
			else if (green[ypos][xpos] == 2) {
				if (green[ypos][xpos + 1] != 2) continue;
				green[ypos][xpos] = green[ypos][xpos + 1] = 0;
				case_2_green(ypos, xpos, ypos + 1);
			}
		}
	}
}
void drop_blue(int idx) {
	for (int xpos = idx - 1; xpos >= 0; xpos--) {
		for (int ypos = 0; ypos < 4; ypos++) {
			if (blue[ypos][xpos] == 1|| blue[ypos][xpos]==2) {
				blue[ypos][xpos] = 0;
				case_1_blue(ypos, xpos, xpos + 1);
			}
			else if (blue[ypos][xpos] == 3) {
				if (blue[ypos + 1][xpos] != 3) continue;
				blue[ypos][xpos] = blue[ypos + 1][xpos] = 0;
				case_3_blue(ypos, xpos, xpos + 1);
			}
		}
	}
}

void check_green() {
	//점수 계산
	int cnt = 0;
	while (cnt < 5) {
		for (int i = 2; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				if (!green[i][j]) break;
				if (j != 3) continue;
				ans++;
				for (int k = 0; k < 4; k++) green[i][k] = 0;
				drop_green(i);
			}
		}
		cnt++;
	}

	//튀어나온 부분 처리
	int over_cnt = 0;
	for (int i = 0; i < 2; i++) {
		bool is_over = false;
		for (int j = 0; j < 4; j++) {
			if (green[i][j]) {
				over_cnt = 2 - i, is_over = true; break;
			}
		}
		if (is_over) break;
	}
	if (over_cnt == 1) {
		for (int i = 5; i >= 2; i--) {
			copy(&green[i - 1][0], &green[i - 1][0] + 4, &green[i][0]);
		}
		memset(green[1], false, sizeof(green[1]));
	}
	else if (over_cnt == 2) {
		for (int i = 5; i >= 2; i--) {
			copy(&green[i - 2][0], &green[i - 2][0] + 4, &green[i][0]);
		}
		memset(green[1], 0, sizeof(green[1]));
		memset(green[0], 0, sizeof(green[0]));
	}
}
void check_blue() {
	int cnt = 0;
	while (cnt < 5) {
		for (int i = 2; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				if (!blue[j][i]) break;
				if (j != 3) continue;
				ans++;
				//i번째 열 전부 삭제.
				for (int k = 0; k < 4; k++) blue[k][i] = 0;
				drop_blue(i);
			}
		}
		cnt++;
	}
	int over_cnt = 0;
	for (int i = 0; i < 2; i++) {
		bool is_over = false;
		for (int j = 0; j < 4; j++) {
			if (blue[j][i]) {
				over_cnt = 2 - i, is_over = true; break;
			}
		}
		if (is_over) break;
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
	case_1_green(ypos, xpos, 0); case_1_blue(ypos, xpos, 0);
	check_blue(); check_green();
}
void case_2(int ypos, int xpos) {
	case_2_green(ypos, xpos, 0); case_2_blue(ypos, xpos, 0);
	check_blue(); check_green();
}
void case_3(int ypos, int xpos) {
	case_3_green(ypos, xpos, 0); case_3_blue(ypos, xpos, 0);
	check_green(); check_blue();
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
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(red, 0, sizeof(red));
	memset(blue, 0, sizeof(blue));
	memset(green, 0, sizeof(green));

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
		N--;
	}
	output();
}

/*
	해맸던 지점과 체크해야할 부분들
	1. over_cnt 구하는 부분 => for문이 2번 중첩되어 있다. 단순 break로는 안쪽 loop밖에 탈출을 못한다. 
	   over_cnt가 2일때 제대로 탈출을 못한다는 이야기
	2. 복사할때. "a->b->c->d" 로 복사한다고 예를 들어보자(a를 b로, b를 c로, c를 d로)
	   이때 a->b 처리하고 b->c 처리하면 당연히도, b자리 c자리 d자리 모두 a로 전부 가득찰것이다.
	   뒤에서부터 c를 d에다가 복사하고 b를 c에다가 복사하고 a를 b에다가 복사해야한다.
	3. 사라진 다음에 더 내려갈 수 있는가?? => 모든 Case에 대해서 생각을 해봐야 한다.

*/