#include <bits/stdc++.h>
//3190번 문제
using namespace std;
const int MAX = 100 + 1;
bool arr[MAX][MAX];
bool snake[MAX][MAX];
vector <pair<int, char>> vc(MAX);
int N, K, L;
pair<int, int> direction[4] = { {0,1},{1,0},{0,-1},{-1,0} };

void solution() {
	ios::sync_with_stdio(0); cin.tie(0);
	memset(arr, false, sizeof(arr));
	memset(snake, false, sizeof(arr));
	//Input
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		int col, row;
		cin >> col >> row;
		arr[col][row] = true;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int temp;
		char temp2;
		cin >> temp >> temp2;
		vc[i] = make_pair(temp, temp2);
	}


	int cnt = 0, SnakeLength = 1;
	int startK = 0, startIdx = 0, endK = 0, endIdx = 0;
	int startX = 1, startY = 1, endX = 1, endY = 1;
	snake[1][1] = true;

	while (startX > 0 && startX <= N && startY > 0 && startY <= N) {
		cnt++;
		startY += direction[startK].first, startX += direction[startK].second;
		if (snake[startY][startX] == true) break;

		snake[startY][startX] = true;
		//사과가 없는경우 => end위치를 늘려줌
		if (arr[startY][startX] == false) {
			snake[endY][endX] = false;
			endY += direction[endK].first, endX += direction[endK].second;
		}
		//사과가 있는 경우 => end를 가만히 두어야함&&SnakeLength를 늘려야함&&사과를 없애야 함
		else {
			arr[startY][startX] = false;
			SnakeLength++;
		}
		//방향 바꾸는 경우
		if (vc[startIdx].first == cnt && (startIdx < L)) {
			vc[startIdx].second == 'D' ? startK++ : startK--;
			if (startK == -1) startK = 3;
			else if (startK == 4) startK = 0;
			startIdx++;
		}
		if (vc[endIdx].first == cnt - SnakeLength && (endIdx < L)) {
			vc[endIdx].second == 'D' ? endK++ : endK--;
			if (endK == -1) endK = 3;
			else if (endK == 4) endK = 0;
			endIdx++;
		}
	}
	std::cout << cnt;
}