#include <bits/stdc++.h>
//3190번 문제
using namespace std;
const int MAX = 100 + 1;

bool apple[MAX][MAX];
bool visited[MAX][MAX];

typedef struct {
	int y;
	int x;
}Dir;
Dir moveDir[4] = { {0,1},{1,0},{0,-1},{-1,0} };//E S W N

vector <pair<int, char>> change(MAX);
deque<pair<int, int>> snake;
int N, K, L;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0);
	memset(apple, false, sizeof(apple));
	memset(visited, false, sizeof(visited));
	cin >> N;
	cin >> K;
	for (int i = 1; i <= K; i++) {
		int col, row;
		cin >> col >> row;
		apple[col][row] = true;
	}
	cin >> L;
	for (int i = 1; i <= L; i++) {
		int temp;
		char temp2;
		cin >> temp >> temp2;
		change[i] = make_pair(temp, temp2);
	}
	int cnt = 0, idx = 0, change_idx=1;
	snake.push_back({ 1,1 });
	visited[1][1] = true;
	while (1) {
		cnt++;
		pair<int, int> before = snake.front();
		pair<int, int> cur = { before.first + moveDir[idx].y,before.second + moveDir[idx].x };
		//범위를 벗어남 or 뱀이 머리가 몸에 부딪힘
		if (visited[cur.first][cur.second] || !(0 < cur.first && cur.first <= N && 0 < cur.second && cur.second <= N)) break;
		//한칸 전진
		visited[cur.first][cur.second] = true;
		snake.push_front(cur);
		//사과가 있는 위치면 꼬리 그대로, 사과만 지운다
		if (apple[cur.first][cur.second])	apple[cur.first][cur.second] = false;
		//사과가 없으면 꼬리를 자른다
		else {
			pair<int, int> tail = snake.back();
			visited[tail.first][tail.second] = false;
			snake.pop_back();
		}

		//방향 전환 
		//change_idx의 overflow 방지 코드!! => 실수하지 않기
		if (change_idx <= L && change[change_idx].first == cnt) {
			if (change[change_idx].second == 'L') idx = (idx + 3) % 4;
			else idx = (idx + 1) % 4;
			change_idx++;
		}
	}
	std::cout << cnt;
}

/*
	알고리즘 포인트
	1) 결국 중요한건 머리(시작) 과 꼬리(끝)
	=> 한번에 관리 할 수 있는 것은 Deque
	2) moveDir 로 관리하는 것이 더 좋음.
	=> pair로 선언하기 보다는 struct로 선언해서 변수명이 더 직관적일 수 있게 할 것.
*/