#include <bits/stdc++.h>
//19237�� ����
using namespace std;
const int MAX = 25;
typedef struct {
	int ypos, xpos;
}point;
typedef struct {
	int smell_idx, smell_left;
}smell;
vector<pair<point, int>> shark((MAX* MAX));
int MAP[MAX][MAX], shark_cnt_MAP[MAX][MAX];
bool lived_shark[MAX];
smell smell_MAP[MAX][MAX];
vector<vector<int>> shark_priority[MAX * MAX];
int N, M, K;
//��,�Ʒ�,����,������
int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,-1,1 };
int cnt;

void make_smell() {
	for (int i = 1; i <= M; i++) {
		if (!lived_shark[i]) continue;
		smell_MAP[shark[i].first.ypos][shark[i].first.xpos] = { i,K };
	}
}
void move() {
	for (int idx = 1; idx <= M; idx++) {
		if (!lived_shark[idx]) continue;

		int py = shark[idx].first.ypos, px = shark[idx].first.xpos, p_dir = shark[idx].second;
		int ny = 0, nx = 0, n_dir = 0;
		//�켱������ �°� �ϴ� �ƹ� ������ ���� ���� ���Ѵ�.
		bool is_no_smell = false;
		for (int k = 0; k < 4; k++) {
			n_dir = shark_priority[idx][p_dir][k];
			ny = py + dy[n_dir], nx = px + dx[n_dir];
			if (ny <= 0 || N < ny || nx <= 0 || N < nx) continue;
			if (smell_MAP[ny][nx].smell_left == 0) {
				is_no_smell = true; break;
			}
		}
		if (is_no_smell) {
			shark_cnt_MAP[py][px] = 0, shark_cnt_MAP[ny][nx]++;
			shark[idx].first.ypos = ny, shark[idx].first.xpos = nx, shark[idx].second = n_dir;
			continue;
		}

		//�ڽ��� ������ �ִ� ĭ�� �������� ��´�.
		for (int k = 0; k < 4; k++) {
			n_dir = shark_priority[idx][p_dir][k];
			ny = py + dy[n_dir], nx = px + dx[n_dir];
			if (ny <= 0 || N < ny || nx <= 0 || N < nx) continue;
			if (smell_MAP[ny][nx].smell_idx == idx) {
				break;
			}
		}
		shark_cnt_MAP[py][px] = 0, shark_cnt_MAP[ny][nx]++;
		shark[idx].first.ypos = ny, shark[idx].first.xpos = nx, shark[idx].second = n_dir;
	}
}
void eliminate() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (shark_cnt_MAP[i][j] == 0 || shark_cnt_MAP[i][j] == 1) continue;
			int min_idx = M + 1;
			for (int k = 1; k <= M; k++) {
				if (!lived_shark[k]) continue;
				//�ش���ġ�� �ִ� ��� �϶�
				if (shark[k].first.ypos == i && shark[k].first.xpos == j) {
					//idx�� �ּڰ��� �ƴ϶��
					if (k > min_idx) {
						lived_shark[k] = false;
						cnt--;
					}
					//������ ����� idx�� 1���� �����ϱ⶧���� ������ �� ��Ȳ ���� X
					else {
						min_idx = k;
					}
				}
			}
		}
	}
}
void smell_down() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!smell_MAP[i][j].smell_left) continue;
			smell_MAP[i][j].smell_left--;
			//������ ������ ������ٸ� ����� idx���� �����ش�.
			if (smell_MAP[i][j].smell_left == 0) smell_MAP[i][j].smell_idx = 0;
		}
	}
}
void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j]) {
				shark[MAP[i][j]] = { {i,j},0 };
				shark_cnt_MAP[i][j] = 1;
				lived_shark[MAP[i][j]] = true;
			}
		}
	}
	int temp_dir;
	for (int i = 1; i <= M; i++) {
		cin >> temp_dir;
		shark[i].second = temp_dir;
	}

	for (int i = 1; i <= M; i++) {
		//0���� idxä���ֱ�
		shark_priority[i].push_back({ 0 });
		for (int j = 1; j <= 4; j++) {
			vector<int> temp_vc;
			for (int k = 1; k <= 4; k++) {
				int temp;
				cin >> temp;
				temp_vc.push_back(temp);
			}
			shark_priority[i].push_back(temp_vc);
		}
	}
}

//void debug(int turn) {
//	cout << turn << "��°\n";
//	for (int i = 1; i <= M; i++) {
//		if (!lived_shark[i]) continue;
//		cout << i << "��� :[" << shark[i].first.ypos << ',' << shark[i].first.xpos << "]\n";
//	}
//	cout << '\n';
//}


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	int ans = 0;
	cnt = M;
	while (ans <= 1000) {
		ans++;
		make_smell();
		move();
		eliminate();
		smell_down();
		//debug(ans);
		if (cnt == 1) break;
	}
	if (ans > 1000) cout << -1;
	else cout << ans;
}