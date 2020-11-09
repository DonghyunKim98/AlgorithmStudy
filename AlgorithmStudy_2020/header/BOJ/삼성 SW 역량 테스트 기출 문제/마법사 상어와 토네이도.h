#include <bits/stdc++.h>
// 20057¹ø ¹®Á¦
using namespace std;
typedef pair<int, int> pii;
const int MAX = 500;
int N;
int MAP[MAX][MAX];
pii dir[] = {
	{0,-1},
	{1,0},
	{0,1},
	{0,-1}
};

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> MAP[i][j];
	int cnt = 0, dirIdx=0, ypos = N / 2 + 1, xpos = N / 2 + 1;
	while (!(ypos == 0 && xpos == 0)) {
		cnt++;
		if (cnt == 2) {
			cnt = 0;
			dirIdx = (dirIdx + 1) % 4;
		}
		int ny = ypos + dir[dirIdx].first, nx = xpos + dir[dirIdx].second;
	}
}

/*
	1Ä­(2¹ø) -> 2Ä­(2¹ø) -> ... -> nÄ­(3¹ø)
*/