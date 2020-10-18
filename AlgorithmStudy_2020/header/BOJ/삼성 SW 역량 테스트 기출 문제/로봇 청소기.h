#include <bits/stdc++.h>
//14503번 문제
using namespace std;
const int MAX = 50 + 1;
int N, M, answer = 0;
int arr[MAX][MAX];
int dy[4] = { -1,0,1,0 }; //NESW
int dx[4] = { 0,1,0,-1 }; //NESW
typedef struct {
	int y, x;
}Point;
Point robot;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int temp1, temp2, dir;
	cin >> temp1 >> temp2 >> dir;
	robot.y = temp1, robot.x = temp2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	while (true) {
		//현재 위치 청소
		if (arr[robot.y][robot.x] == 0) {
			arr[robot.y][robot.x] = 2;
			answer++;
		}
		int check = 0;
		for (int i = 0; i < 4; i++) {
			dir = (dir + 3) % 4;
			int ny = robot.y + dy[dir];
			int nx = robot.x + dx[dir];
			if (arr[ny][nx] == 0) {
				robot.y = ny, robot.x = nx;
				check = 1;
				break;
			}
		}
		if (check) continue;
		// temp_dir을 이용해서 후진은 하되 dir은 계속 유지.
		int temp_dir = (dir + 2) % 4;
		robot.y += dy[temp_dir];
		robot.x += dx[temp_dir];
		if (arr[robot.y][robot.x] == 1) break;
	}

	cout << answer;
}

/*
	DFS 라는 것을 알았지만 '함수'를 이용해서 구현하고자 하는 생각에서 벗어나지 못했다.
	무한루프를 이용하면 편한데 말이다.
*/