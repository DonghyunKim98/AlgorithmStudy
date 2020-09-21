#include <bits/stdc++.h>
//2630번 문제
using namespace std;
const int MAX = 130;
int N;
int MAP[MAX][MAX];
int countW = 0, countB = 0;

void divConq(int start_x, int start_y, int end_x, int end_y) {
	int check = MAP[start_x][start_y];

	for (int i = start_x; i < end_x; i++) {
		for (int j = start_y; j < end_y; j++) {
			//현재 분할로 색종이 만들수 없으면 check을 2로 만들다.
			if (check == 0 && MAP[i][j] == 1) {
				check = 2;
			}
			else if (check == 1 && MAP[i][j] == 0) {
				check = 2;
			}
			if (check == 2) {
				divConq(start_x, start_y, (start_x + end_x) / 2, (start_y + end_y) / 2);
				divConq((start_x + end_x) / 2, start_y, end_x, (start_y + end_y) / 2);
				divConq(start_x, (start_y + end_y) / 2, (start_x + end_x) / 2, end_y);
				divConq((start_x + end_x) / 2, (start_y + end_y) / 2, end_x, end_y);
				return;
			}
		}
	}
	if (check == 0) countW++;
	else if (check == 1) countB++;

	return;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	divConq(0, 0, N, N);
	cout << countW << '\n';
	cout << countB << '\n';
}