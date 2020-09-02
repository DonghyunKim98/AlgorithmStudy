#include <bits/stdc++.h>
//17142�� ����
using namespace std;
const int MAX = 50 + 1;
typedef struct {
	int ypos, xpos;
}point;
int MAP[MAX][MAX];
vector<point> virus, virus_selected;
int N, M, answer = INT_MAX;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[MAX][MAX], depth[MAX][MAX];
int virus_cnt = 0, wall_cnt = 0;

int max_ret() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) ret = max(ret, depth[i][j]);
	}
	return ret;
}

int BFS() {
	memset(visited, false, sizeof(visited));
	memset(depth, 0, sizeof(visited));
	int cnt = 0, ret;
	queue<point> q;
	for (int i = 0; i < virus_selected.size(); i++) {
		q.push(virus_selected[i]);
		visited[virus_selected[i].ypos][virus_selected[i].xpos] = true;
		depth[virus_selected[i].ypos][virus_selected[i].xpos] = -1;
	}
	/*
		��Ʈ�����ϴ� cnt�� ���� => �������.
	*/
	while (!q.empty()) {
		point current = q.front(); q.pop();
		if (cnt == N * N - (wall_cnt + virus_cnt))
			break;
		//���̷����϶� �ش��� �� ������ �ʾҴٸ� 1�� �߰�.
		if (MAP[current.ypos][current.xpos] == 2)
			depth[current.ypos][current.xpos]++;
		for (int k = 0; k < 4; k++) {
			int ny = current.ypos + dy[k], nx = current.xpos + dx[k];
			if (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
				if (visited[ny][nx] == false) {
					if (MAP[ny][nx] == 0 || MAP[ny][nx] == 2) {
						visited[ny][nx] = true;
						q.push({ ny,nx });
						//�� ������ ��� ���� ��ġ +1 ��ŭ ������ ������
						if (MAP[ny][nx] == 0) {
							depth[ny][nx] = depth[current.ypos][current.xpos] + 1;
							cnt++;
						}
						//���̷����� ��� ���� �Ͽ� �������, ���� ���� ������������ ���ֵǾ� �ϹǷ� �״�� ���縸 ����
						else depth[ny][nx] = depth[current.ypos][current.xpos];
					}
				}
			}
		}
	}
	if (q.empty() && cnt < N * N - (wall_cnt + virus_cnt)) ret = -1;
	else ret = max_ret();
	return ret;
}
void DFS(int idx, int cnt) {
	if (cnt == M) {
		int ret = BFS();
		if (ret == -1) {
			if (answer == -1 || answer == INT_MAX) answer = -1;
		}
		else {
			if (answer == -1)	answer = ret;
			else answer = min(answer, ret);
		}
		return;
	}
	for (int k = idx; k < virus.size(); k++) {
		virus_selected.push_back(virus[k]);
		DFS(k + 1, cnt + 1);
		virus_selected.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				virus_cnt++;
				virus.push_back({ i,j });
			}
			else if (MAP[i][j] == 1) {
				wall_cnt++;
				MAP[i][j] = -1;
			}
		}
	}
	DFS(0, 0);
	cout << answer;
}


/*
	1. DFS (����Լ�) �� �⺻! Ż�������� �������Ѵ�. if���ʿ� return�� �־�� �Ѵ�!!!
	=> ���õ��� ������ �ð��� ���� ���� �ɸ��� ��ġ�� ë��� �ߴµ�..
	2. cnt�� �ľ��ϴ� ����� �ʹ� ��ư� �����ߴ�. ���� ������ �Ǵ°ǵ�
	3. ���̷������ ����ó���� ������ ������, �׷��� Ǯ���� ����
	4. BFS ���� �ּҸ� ���ؾ��Ҷ�, �����ϴ� ���� �������̶�� (������ ť�� 1���� �ְ� �����ϴµ�, �� ����ó�� M���� ����ִ´ٸ�)
	visited�迭�� depth�迭�� ���� �����ؾ���
	<�ݷ�>
	5 3
	2 2 2 0 0
	1 1 1 1 1
	1 1 1 1 1
	1 1 1 1 1
	1 1 1 1 1
*/