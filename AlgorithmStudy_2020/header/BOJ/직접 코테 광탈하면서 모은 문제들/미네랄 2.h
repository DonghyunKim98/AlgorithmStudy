#include <bits/stdc++.h>
//18500�� ����
using namespace std;
const int MAX = 100+1;
typedef pair<int, int> pii;
vector<pii> vc;
vector<int> minElementVC(MAX);
char MAP[MAX][MAX];
int visited[MAX][MAX];
int R, C, N;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int minInterval;

bool cmp(const pii & a, const pii & b) {
	return a.first < b.first;
}

void DFS(int ypos, int xpos) {
	vc.push_back({ ypos,xpos });
	for (int k = 0; k < 4; k++) {
		int ny = ypos + dy[k], nx = xpos + dx[k];
		if (1 <= ny && ny <= R && 1 <= nx && nx <= C) {
			if (visited[ny][nx] == true) continue;
			//�ܼ� �湮�̶�� 2
			visited[ny][nx] = 2;
			if (MAP[ny][nx] == 'x') {
				//x�� �湮�ϴ°Ÿ� 1
				visited[ny][nx] = 1;
				DFS(ny, nx);
			}
		}
	}
	return;
}

void check(int py, int px) {
	vc.clear(), minInterval=INT_MAX;
	for (int i = 1; i <= C; i++) minElementVC[i] = INT_MAX;
	memset(visited, 0, sizeof(visited));
	visited[py][px] = 1;
	DFS(py, px);
	sort(vc.rbegin(), vc.rend(),cmp);
	//���� �̾����ִٸ� �� ������ ��
	if (vc.front().first == R) return;
	//minElement ���
	for (int i = 0; i < vc.size(); i++) {
		int temp;
		for (int j = vc[i].first + 1; j <= R + 1; j++) {
			if (j == R + 1) temp = R - vc[i].first;
			//dfs�� ���� ����� �ƴѰ�쿡�� temp ����
			if (MAP[j][vc[i].second] == 'x' && visited[j][vc[i].second]!=1) {
				temp = j - vc[i].first - 1;
				break;
			}
		}
		minElementVC[vc[i].second] = min(temp, minElementVC[vc[i].second]);
	}
	//minInterval ���
	for (int i = 1; i <= C; i++) {
		minInterval = min(minInterval, minElementVC[i]);
	}
	//������ -> R�� ���� ���� ���������Ǿ������Ƿ� ��ġ�� ����
	for (int i = 0; i < vc.size(); i++) {
		MAP[vc[i].first+minInterval][vc[i].second] = 'x';
		MAP[vc[i].first][vc[i].second] = '.';
	}
}

void output() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C ; j++) {
			cout << MAP[i][j];
		}
		cout << '\n';
	}
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= C; j++)
			MAP[i][j] = temp[j-1];
	}
	cin >> N;
	bool left = false;
	while (N--) {
		left = left == false ? true : false;
		int height;
		cin >> height;
		height = R - height + 1;
		if (left) {
			for (int i = 1; i <= C; i++) {
				if (MAP[height][i] == 'x') {
					MAP[height][i] = '.';
					for (int k = 0; k < 4; k++) {
						int ny = height + dy[k], nx = i + dx[k];
						if (1 <= ny && ny <= R && 1 <= nx && nx < C) {
							if(MAP[ny][nx]=='x') check(ny,nx);
						}
					}
					break;
				}
			}
		}
		else {
			for (int i = C; i >= 1; i--) {
				if (MAP[height][i] == 'x') {
					MAP[height][i] = '.';
					for (int k = 0; k < 4; k++) {
						int ny = height + dy[k], nx = i + dx[k];
						if (1 <= ny && ny <= R && 1 <= nx && nx <= C) {
							if (MAP[ny][nx] == 'x') check(ny, nx);
						}
					}
					break;
				}
			}
		}
	}
	output();
}