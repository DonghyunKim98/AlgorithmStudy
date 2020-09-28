#include <bits/stdc++.h>
//1780¹ø ¹®Á¦
using namespace std;
const int MAX = 3 * 3 * 3 * 3 * 3 * 3 * 3 + 1;
typedef long long ll;
ll N;
int MAP[MAX][MAX];
int ans_minusOne = 0, ans_zero = 0, ans_one = 0;
void DivAndConqure(int start_y, int start_x, int end_y, int end_x) {
	int check = MAP[start_y][start_x];
	for (int ypos = start_y; ypos < end_y; ypos++) {
		for (int xpos = start_x; xpos < end_x; xpos++) {
			if (MAP[ypos][xpos] != check) check = 2;
			if (check == 2) {
				int gap = (end_y - start_y) / 3;
				DivAndConqure(start_y, start_x, start_y + gap, start_x + gap);
				DivAndConqure(start_y, start_x + gap, start_y + gap, start_x + gap * 2);
				DivAndConqure(start_y, start_x + gap * 2, start_y + gap, end_x);
				DivAndConqure(start_y + gap, start_x, start_y + gap * 2, start_x + gap);
				DivAndConqure(start_y + gap, start_x + gap, start_y + gap * 2, start_x + gap * 2);
				DivAndConqure(start_y + gap, start_x + gap * 2, start_y + gap * 2, end_x);
				DivAndConqure(start_y + gap * 2, start_x, end_y, start_x + gap);
				DivAndConqure(start_y + gap * 2, start_x + gap, end_y, start_x + gap * 2);
				DivAndConqure(start_y + gap * 2, start_x + gap * 2, end_y, end_x);
				return;
			}
		}
	}
	if (check == 1) ans_one++;
	else if (check == 0) ans_zero++;
	else if (check == -1) ans_minusOne++;
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
	DivAndConqure(0, 0, N, N);
	cout << ans_minusOne << '\n' << ans_zero << '\n' << ans_one;
}