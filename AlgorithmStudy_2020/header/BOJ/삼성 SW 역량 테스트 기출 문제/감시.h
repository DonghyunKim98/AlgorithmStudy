#include <bits/stdc++.h>
//15683�� ����
using namespace std;

struct str {
	int cctv; //cctv ����
	int y; //cctv y��ǥ
	int x; //cctv x��ǥ
	str(int cctv, int y, int x) :cctv(cctv), y(y), x(x) {};
};

int N, M;
int ans = 100; //�簢 ���� �ּҰ�
int cctv_cnt = 0; //cctv ����
vector<vector<int>> arr(8, vector<int>(8, 0)); //�繫��
vector<str> vec;

void move(int dir, int y, int x) {

	switch (dir) {

	//��
	case 0:
		for (int i = y - 1; i >= 0; i--) {
			if (arr[i][x] == 6) break;
			if (arr[i][x] == 0) arr[i][x] = -1; //cctv ���� �Ϸ�
		}
		break;

	//��
	case 1:
		for (int j = x + 1; j < M; j++) {
			if (arr[y][j] == 6) break;
			if (arr[y][j] == 0) arr[y][j] = -1;
		}
		break;

	//��
	case 2:
		for (int i = y + 1; i < N; i++) {
			if (arr[i][x] == 6) break;
			if (arr[i][x] == 0) arr[i][x] = -1;
		}
		break;

	//��
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
	//����� �迭 arr2
	vector<vector<int>> arr2 = arr;
	switch (cctv) {
	case 1:
		//��,��,��,��
		for (int dir = 0; dir < 4; dir++) {
			move(dir, y, x);
			dfs(step + 1);
			//BackTracking
			arr = arr2;
		}
		break;

	case 2:
		//�ϳ�,����
		for (int dir = 0; dir < 2; dir++) {
			move(dir, y, x);
			move(dir + 2, y, x);
			dfs(step + 1);
			//BackTracking
			arr = arr2;
		}
		break;

	case 3:
		//�ϵ�,����,����,����
		for (int dir = 0; dir < 4; dir++) {
			move(dir, y, x);
			move((dir + 1) % 4, y, x);
			dfs(step + 1);
			//BackTracking
			arr = arr2;
		}
		break;

	case 4:
		//�ϵ���,������,������,���ϵ�
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
	�˰��� ����Ʈ
	1. cctv���� �������� ��� ����� ���ΰ��� ���� ����
	-> move�Լ��� ���� 6�� �ƴ϶�� �׳� �� ����ϰ� �Ѵ�
	-> "1�� cctv�� �����ߴ� => 1�� ǥ��" ��� �������信�� Ż���ϸ� �ȴ�.

	2. ���ݱ��� �� arr2�� ���� ������ �迭�� ������, ���⼱ ����� �迭�� arr2�� ���.
*/