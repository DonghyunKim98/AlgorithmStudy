#include <bits/stdc++.h>
//17779번 문제
using namespace std;
const int MAX = 20;
int N, ans = INT_MAX, total = 0;
int MAP[MAX][MAX];
/*
	1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
	2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
	3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
	4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
*/
//d1->왼쪽 d2->오른쪽으로 얼마만큼 가는가?
int A1(int ypos, int xpos, int d1, int d2) {
	int ret = 0;
	for (int i = 0; i <= ypos - 1; i++) {
		for (int j = 0; j <= xpos; j++) {
			ret += MAP[i][j];
		}
	}
	for (int i = ypos; i < ypos + d1; i++) {
		//끝 값은 (xpos-1,xpos-2,...)으로 1씩 줄어듦
		for (int j = 0; j <= xpos - (i - ypos) - 1; j++) {
			ret += MAP[i][j];
		}
	}
	return ret;
}

int A2(int ypos, int xpos, int d1, int d2) {
	int ret = 0;
	for (int i = 0; i <= ypos; i++) {
		for (int j = xpos + 1; j < N; j++) {
			ret += MAP[i][j];
		}
	}

	for (int i = ypos + 1; i <= ypos + d2; i++) {
		//시작값은 (xpos+2,xpos+3...)
		for (int j = xpos + (i - ypos) + 1; j < N; j++) {
			ret += MAP[i][j];
		}
	}
	return ret;
}

int A3(int ypos, int xpos, int d1, int d2) {
	int ret = 0;
	for (int i = ypos + d1; i <= ypos + d1 + d2; i++) {
		//끝값은 (xpos-d1-1,xpos-d1-2,...)
		for (int j = 0; j <= xpos - d1 - 1 + (i - (ypos + d1)); j++) {
			ret += MAP[i][j];
		}
	}
	for (int i = ypos + d1 + d2 + 1; i < N; i++) {
		for (int j = 0; j < xpos - d1 + d2; j++) {
			ret += MAP[i][j];
		}
	}
	return ret;
}

int A4(int ypos, int xpos, int d1, int d2) {
	int ret = 0;
	for (int i = ypos + d2 + 1; i <= ypos + d2 + d1; i++) {
		//시작값은 (xpos+d2,xpos+d2+1,...)
		for (int j = xpos + d2 - i + (ypos + d2 + 1); j < N; j++) {
			ret += MAP[i][j];
		}
	}
	for (int i = ypos + d1 + d2 + 1; i < N; i++) {
		for (int j = xpos - d1 + d2; j < N; j++) {
			ret += MAP[i][j];
		}
	}
	return ret;
}



void process(int ypos, int xpos) {
	for (int d1 = 1; d1 < N; d1++) {
		//범위를 넘어서는 경우
		if (xpos - d1 < 0) break;
		for (int d2 = 1; d2 < N; d2++) {
			//범위를 넘어서는 경우
			if (ypos + d1 + d2 > N || xpos + d2 > N) break;
			int area1 = A1(ypos, xpos, d1, d2), area2 = A2(ypos, xpos, d1, d2), area3 = A3(ypos, xpos, d1, d2), area4 = A4(ypos, xpos, d1, d2);
			int area5 = total - (area1 + area2 + area3 + area4);
			int min_val = min(min(min(area1, area2), min(area3, area4)), area5), max_val = max(max(max(area1, area2), max(area3, area4)), area5);
			ans = min(ans, (max_val - min_val));
		}
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		cin >> MAP[i][j];
		total += MAP[i][j];
	}
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) process(i, j);
	cout << ans;
}

/*
	시물레이션 거지같은것...
*/