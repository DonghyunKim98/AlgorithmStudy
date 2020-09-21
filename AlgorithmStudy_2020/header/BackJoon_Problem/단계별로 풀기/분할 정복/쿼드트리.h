#include <bits/stdc++.h>
//1992¹ø ¹®Á¦
using namespace std;
const int MAX = 64;
int N;
int MAP[MAX][MAX];
string ans;

void divConq(int start_x, int start_y, int end_x, int end_y) {
	int check = MAP[start_x][start_y];

	for (int i = start_x; i < end_x; i++) {
		for (int j = start_y; j < end_y; j++) {
			if (check == 1 && MAP[i][j] == 0) {
				check = 2;
			}
			else if (check == 0 && MAP[i][j] == 1) {
				check = 2;
			}
			if (check == 2) {
				ans.push_back('(');
				divConq(start_x, start_y, (start_x + end_x) / 2, (start_y + end_y) / 2);
				divConq(start_x, (start_y + end_y) / 2, (start_x + end_x) / 2, end_y);
				divConq((start_x + end_x) / 2, start_y, end_x, (start_y + end_y) / 2);
				divConq((start_x + end_x) / 2, (start_y + end_y) / 2, end_x, end_y);
				ans.push_back(')');
				return;
			}
		}
	}
	if (check == 1) ans.push_back('1');
	else if (check == 0) ans.push_back('0');
	return;
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++)
			MAP[i][j] = (int)(temp[j] - '0');
	}
	divConq(0, 0, N, N);
	cout << ans;
}