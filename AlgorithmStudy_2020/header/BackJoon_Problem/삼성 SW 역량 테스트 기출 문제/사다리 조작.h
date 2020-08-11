#include <bits/stdc++.h>
//15684번 문제
//https://blog.naver.com/jhc9639/221794904602 참고
using namespace std;
const int MAX = 987654321;
int ladder[34][34];
int N, M, H, ret=MAX;

bool check() {
	for (int i = 1; i <= N; i++) {
		int start = i;
		for (int j = 1; j <= H; j++) {
			if (ladder[j][start]) start++;
			else if (ladder[j][start - 1]) start--;
		}
		if (start != i) return false;
	}
	return true;
}

void go(int here, int cnt) {
	if (cnt > 3) return;
	if (check()) {
		ret = min(ret, cnt);
		return;
	}
	//사다리 설치
	for (int i = here; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			//이미 설치되어 있다면 pass
			if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1]) continue;
			ladder[i][j] = 1;
			go(i, cnt + 1);
			//BackTracking
			ladder[i][j] = 0;
		}
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> H;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = true;
	}
	go(1, 0);
	cout << ((ret == MAX) ? -1 : ret);
}