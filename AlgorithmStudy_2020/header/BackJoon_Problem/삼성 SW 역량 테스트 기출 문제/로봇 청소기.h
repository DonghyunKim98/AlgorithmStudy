#include <bits/stdc++.h>
//14503�� ����
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
		//���� ��ġ û��
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
		// temp_dir�� �̿��ؼ� ������ �ϵ� dir�� ��� ����.
		int temp_dir = (dir + 2) % 4;
		robot.y += dy[temp_dir];
		robot.x += dx[temp_dir];
		if (arr[robot.y][robot.x] == 1) break;
	}

	cout << answer;
}

/*
	DFS ��� ���� �˾����� '�Լ�'�� �̿��ؼ� �����ϰ��� �ϴ� �������� ����� ���ߴ�.
	���ѷ����� �̿��ϸ� ���ѵ� ���̴�.
*/