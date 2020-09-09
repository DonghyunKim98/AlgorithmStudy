#include<bits/stdc++.h>
//2636번 문제
using namespace std;
const int MAX = 100;
int MAP[MAX][MAX];
int N, M;
int visited[MAX][MAX];
typedef struct {
	int ypos, xpos;
}point;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int cnt;
bool BFS() {
	queue<point>q;
	memset(visited, false, sizeof(visited));
	q.push({ 0,0 });
	while (!q.empty()) {
		int c_ypos = q.front().ypos, c_xpos = q.front().xpos;
		q.pop();
		if (visited[c_ypos][c_xpos]) continue;
		visited[c_ypos][c_xpos] = true;
		for (int k = 0; k < 4; k++) {
			int ny = c_ypos + dy[k], nx = c_xpos + dx[k];
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				//case 0: -> q에 넣고 계속 탐색 진행
				if (MAP[ny][nx] == 0)	q.push({ ny,nx });
				//case 1: -> 2로 바꾸고 탐색 진행하지 않음
				else if (MAP[ny][nx] == 1) MAP[ny][nx] = 2;
				//case 2: -> 아무짓도 하지않음
			}
		}
	}
	cnt = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 2) {
				cnt++;
				MAP[i][j] = 0;
			}
		}

	//모두 0으로 바뀌었는지 확인
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (MAP[i][j] != 0) return false;

	return true;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> MAP[i][j];
	for (int i = 1;; i++) {
		if (BFS()) {
			cout << i << '\n' << cnt;
			break;
		}
	}
}


/*
	1. (0,0) 에서 시작하는 BFS를 반복 진행
	=> MAP의 모든 값이 0으로 바뀌기 전까지
	3. BFS를 진행하면서 0과 맞닿아있는 1을 2로 바꿈.
	4. <1과 맞닿아 있는 1또는 2는 탐색을 진행하지 않음 >
	-> 어차피 지워질 1이라면 0이랑 맞닿아져 있음
	3. 다 끝나고 2들을 0으로 바꿈 => 이 과정에서 얼마나 지운지를 기록
	4. 만약 다 지웠다면 출력
*/