#include <bits/stdc++.h>
//15683번 문제
using namespace std;

struct str {
	int cctv; //cctv 종류
	int y; //cctv y좌표
	int x; //cctv x좌표
	str(int cctv, int y, int x) :cctv(cctv), y(y), x(x) {};
};

int N, M;
int ans = 100; //사각 지대 최소값
int cctv_cnt = 0; //cctv 개수
vector<vector<int>> arr(8, vector<int>(8, 0)); //사무실
vector<str> vec;

void move(int dir, int y, int x) {

	switch (dir) {

	//북
	case 0:
		for (int i = y - 1; i >= 0; i--) {
			if (arr[i][x] == 6) break;
			if (arr[i][x] == 0) arr[i][x] = -1; //cctv 감시 완료
		}
		break;

	//동
	case 1:
		for (int j = x + 1; j < M; j++) {
			if (arr[y][j] == 6) break;
			if (arr[y][j] == 0) arr[y][j] = -1;
		}
		break;

	//남
	case 2:
		for (int i = y + 1; i < N; i++) {
			if (arr[i][x] == 6) break;
			if (arr[i][x] == 0) arr[i][x] = -1;
		}
		break;

	//서
	case 3:
		for (int j = x - 1; j >= 0; j--) {
			if (arr[y][j] == 6) break;
			if (arr[y][j] == 0) arr[y][j] = -1;
		}

	}

}

void dfs(int step) {
	if (step == cctv_cnt) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0)
					cnt++;
			}
		}
		ans = min(ans, cnt);
		return;
	}
	int cctv = vec[step].cctv;
	int y = vec[step].y;
	int x = vec[step].x;
	//백업용 배열 arr2
	vector<vector<int>> arr2 = arr;
	switch (cctv) {
	case 1:
		//북,동,남,서
		for (int dir = 0; dir < 4; dir++) {
			move(dir, y, x);
			dfs(step + 1);
			//BackTracking
			arr = arr2;
		}
		break;

	case 2:
		//북남,동서
		for (int dir = 0; dir < 2; dir++) {
			move(dir, y, x);
			move(dir + 2, y, x);
			dfs(step + 1);
			//BackTracking
			arr = arr2;
		}
		break;

	case 3:
		//북동,동남,남서,서북
		for (int dir = 0; dir < 4; dir++) {
			move(dir, y, x);
			move((dir + 1) % 4, y, x);
			dfs(step + 1);
			//BackTracking
			arr = arr2;
		}
		break;

	case 4:
		//북동남,동남서,남서북,서북동
		for (int dir = 0; dir < 4; dir++) {
			move(dir, y, x);
			move((dir + 1) % 4, y, x);
			move((dir + 2) % 4, y, x);
			dfs(step + 1);
			//BackTracking
			arr = arr2;
		}
		break;

	case 5:
		for (int dir = 0; dir < 4; dir++)
			move(dir, y, x);
		dfs(step + 1);
	}

}


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				cctv_cnt++;
				vec.push_back(str(arr[i][j], i, j));
			}
		}
	}
	dfs(0);
	cout << ans << endl;
}

/*
	알고리즘 포인트
	1. cctv끼리 겹쳤을때 어떻게 통과할 것인가에 대한 구현
	-> move함수를 통해 6만 아니라면 그냥 쭉 통과하게 한다
	-> "1번 cctv로 감시했다 => 1로 표시" 라는 고정관념에서 탈출하면 된다.

	2. 지금까지 난 arr2를 실제 돌리는 배열로 했지만, 여기선 백업용 배열로 arr2를 썼다.
*/