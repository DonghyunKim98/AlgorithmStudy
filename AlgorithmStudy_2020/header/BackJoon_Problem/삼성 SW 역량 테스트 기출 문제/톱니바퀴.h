#include <bits/stdc++.h>
//14891번 문제
using namespace std;
vector<bool> sawtooth[5];
int K;

void rotate_clock(int idx) {
	int temp = sawtooth[idx][7];
	for (int i = 1; i < 8; i++)
		sawtooth[idx][i] = sawtooth[idx][i - 1];
	sawtooth[idx][0] = temp;
}
void rotate_counter_clock(int idx) {
	int temp = sawtooth[idx][0];
	for (int i = 0; i < 7; i++)
		sawtooth[idx][i] = sawtooth[idx][i + 1];
	sawtooth[idx][7] = temp;
}
//맞물린곳 index => [2,6] idx
//left를 기준으로 dir 회전한다고 생각.
bool is_rotate(int left, int right) {
	if (sawtooth[left][2] == sawtooth[right][6]) return false;
	else return true;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 4; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < 8; j++) {
			sawtooth[i].push_back(bool(temp[j] - '0'));
		}
	}

	cin >> K;
	while (K > 0) {
		int number, dir;
		cin >> number >> dir;

		if (number == 1) {
			if (is_rotate(1, 2)) {
				if (dir == 1) {
					rotate_clock(1); rotate_counter_clock(2);
				}
				else {
					rotate_counter_clock(1); rotate_clock(2);
				}
				if (is_rotate(2, 3)) {
					dir == 1 ? rotate_clock(3) : rotate_counter_clock(3);
					if (is_rotate(3, 4))
						dir == 1 ? rotate_counter_clock(4) : rotate_clock(3);
				}
			}
		}
		else if (number == 2) {
			if (is_rotate(2, 3)) {
				if (dir == 1) {
					rotate_clock(2); rotate_counter_clock(3);
				}
				else {
					rotate_counter_clock(2); rotate_clock(3);
				}
				if (is_rotate(3, 4))
					dir == 1 ? rotate_clock(4) : rotate_counter_clock(4);
			}
			if (is_rotate(1, 2)) {
				if (is_rotate(2, 3))
					dir == 1 ? rotate_counter_clock(1) : rotate_clock(2);
				else {
					if (dir == 1) {
						rotate_clock(2); rotate_counter_clock(1);
					}
					else {
						rotate_counter_clock(2); rotate_clock(1);
					}
				}
			}
		}
		else if (number == 3) {
			if (is_rotate(2, 3)) {
				if (dir == 1) {
					rotate_clock(3); rotate_counter_clock(2);
				}
				else {
					rotate_counter_clock(3); rotate_clock(2);
				}
				if (is_rotate(1, 2))
					dir == 1 ? rotate_clock(1) : rotate_counter_clock(1);
			}
			if (is_rotate(3, 4)) {
				if (is_rotate(2, 3))
					dir == 1 ? rotate_counter_clock(4) : rotate_clock(4);
				else {
					if (dir == 1) {
						rotate_clock(3); rotate_counter_clock(4);
					}
					else {
						rotate_counter_clock(3); rotate_clock(4);
					}
				}
			}
		}
		else {
			if (is_rotate(3, 4)) {
				if (dir == 1) {
					rotate_clock(3); rotate_counter_clock(4);
				}
				else {
					rotate_counter_clock(3); rotate_clock(4);
				}
				if (is_rotate(2, 3)) {
					dir == 1 ? rotate_counter_clock(2) : rotate_clock(2);
					if (is_rotate(1, 2))
						dir == 1 ? rotate_clock(1) : rotate_counter_clock(1);
				}

			}
		}
		K--;
	}

	int answer = 0;
	for (int i = 1; i <= 4; i++)
		answer += (sawtooth[i][0]) ? pow(2, i - 1) : 0;

	cout << answer;
}