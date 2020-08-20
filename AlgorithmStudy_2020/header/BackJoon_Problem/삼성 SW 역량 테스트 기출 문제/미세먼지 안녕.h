#include <bits/stdc++.h>
//17144�� ����
using namespace std;
int cleaner_ypos=-1;
deque <long long> c1, c2;
const int MAX = 50;
long long arr[MAX][MAX];
int R, C, T;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void spread() {
	//Ȯ��Ǵ� �̼������� �ӽ� �����ϴ� brr
	long long** brr = new long long* [MAX];
	for (int i = 0; i < MAX; i++) {
		brr[i] = new long long[MAX];
		memset(brr[i], 0, sizeof(long long) * MAX);
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] != 0 && arr[i][j] != -1) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k], nx = j + dx[k];
					if (0 <= ny && ny < C && 0 <= nx && nx < R)
						if (arr[ny][nx] != -1) {
							cnt++;
							brr[ny][nx] += arr[i][j] / 5;
						}
				}
				//Ȯ�� ���� ���� �̼����� �� ���
				arr[i][j] -= (arr[i][j] / 5) * cnt;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			arr[i][j] += brr[i][j];
		}
	}
}

void cleaning() {
	//cleaner1 ����
	//1. ����û���� ���������� (0,0)���� ��� �� �����ֱ�
	for (int i = cleaner_ypos - 1; i > 0; i--) arr[i][0] = arr[i - 1][0];
	//2. ���� ���� �����ֱ�
	for (int i = 0; i < C - 1; i++) arr[0][i] = arr[0][i + 1];
	//3. �ݴ� �� ���ζ���
	for (int i = 1; i <= cleaner_ypos; i++) arr[i - 1][C - 1] = arr[i][C - 1];
	//4. ���� û���� ���� �����ֱ�
	for (int i = C - 1; i > 1; i--) arr[cleaner_ypos][i] = arr[cleaner_ypos][i - 1];
	arr[cleaner_ypos][1] = 0;
	//cleaner2 ����
	int cleaner2_ypos = cleaner_ypos + 1;
	for (int i = cleaner2_ypos + 1; i < R - 1; i++) arr[i][0] = arr[i + 1][0];
	for (int i = 0; i < C - 1; i++) arr[R - 1][i] = arr[R - 1][i + 1];
	for (int i = R - 1; i >= cleaner2_ypos; i--) arr[i][C - 1] = arr[i - 1][C - 1];
	for (int i = C - 1; i > 1; i--) arr[cleaner2_ypos][i] = arr[cleaner2_ypos][i - 1];
	arr[cleaner2_ypos][1] = 0;
}


int check() {
	int ret = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] != 0 && arr[i][j] != -1) ret += arr[i][j];
		}
	}
	return ret;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				if (cleaner_ypos == -1) cleaner_ypos = i;
			}
		}
	}

	for (int k = 0; k < T; k++) {
		spread();
		cleaning();
	}

	cout << check();
}