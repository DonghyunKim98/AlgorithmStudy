#include<bits/stdc++.h>
//2636�� ����
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
				//case 0: -> q�� �ְ� ��� Ž�� ����
				if (MAP[ny][nx] == 0)	q.push({ ny,nx });
				//case 1: -> 2�� �ٲٰ� Ž�� �������� ����
				else if (MAP[ny][nx] == 1) MAP[ny][nx] = 2;
				//case 2: -> �ƹ����� ��������
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

	//��� 0���� �ٲ������ Ȯ��
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
	1. (0,0) ���� �����ϴ� BFS�� �ݺ� ����
	=> MAP�� ��� ���� 0���� �ٲ�� ������
	3. BFS�� �����ϸ鼭 0�� �´���ִ� 1�� 2�� �ٲ�.
	4. <1�� �´�� �ִ� 1�Ǵ� 2�� Ž���� �������� ���� >
	-> ������ ������ 1�̶�� 0�̶� �´���� ����
	3. �� ������ 2���� 0���� �ٲ� => �� �������� �󸶳� �������� ���
	4. ���� �� �����ٸ� ���
*/