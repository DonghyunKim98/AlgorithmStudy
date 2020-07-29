#include <bits/stdc++.h>
//3190�� ����
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
		//������ ��� or ���� �Ӹ��� ���� �ε���
		if (visited[cur.first][cur.second] || !(0 < cur.first && cur.first <= N && 0 < cur.second && cur.second <= N)) break;
		//��ĭ ����
		visited[cur.first][cur.second] = true;
		snake.push_front(cur);
		//����� �ִ� ��ġ�� ���� �״��, ����� �����
		if (apple[cur.first][cur.second])	apple[cur.first][cur.second] = false;
		//����� ������ ������ �ڸ���
		else {
			pair<int, int> tail = snake.back();
			visited[tail.first][tail.second] = false;
			snake.pop_back();
		}

		//���� ��ȯ 
		//change_idx�� overflow ���� �ڵ�!! => �Ǽ����� �ʱ�
		if (change_idx <= L && change[change_idx].first == cnt) {
			if (change[change_idx].second == 'L') idx = (idx + 3) % 4;
			else idx = (idx + 1) % 4;
			change_idx++;
		}
	}
	std::cout << cnt;
}

/*
	�˰��� ����Ʈ
	1) �ᱹ �߿��Ѱ� �Ӹ�(����) �� ����(��)
	=> �ѹ��� ���� �� �� �ִ� ���� Deque
	2) moveDir �� �����ϴ� ���� �� ����.
	=> pair�� �����ϱ� ���ٴ� struct�� �����ؼ� �������� �� �������� �� �ְ� �� ��.
*/