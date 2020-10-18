#include <bits/stdc++.h>
//17142번 문제
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
		퍼트려야하는 cnt의 개수 => 빈공간만.
	*/
	while (!q.empty()) {
		point current = q.front(); q.pop();
		if (cnt == N * N - (wall_cnt + virus_cnt))
			break;
		//바이러스일때 해당턴 때 끝나지 않았다면 1을 추가.
		if (MAP[current.ypos][current.xpos] == 2)
			depth[current.ypos][current.xpos]++;
		for (int k = 0; k < 4; k++) {
			int ny = current.ypos + dy[k], nx = current.xpos + dx[k];
			if (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
				if (visited[ny][nx] == false) {
					if (MAP[ny][nx] == 0 || MAP[ny][nx] == 2) {
						visited[ny][nx] = true;
						q.push({ ny,nx });
						//빈 공간일 경우 현재 위치 +1 만큼 무조건 가야함
						if (MAP[ny][nx] == 0) {
							depth[ny][nx] = depth[current.ypos][current.xpos] + 1;
							cnt++;
						}
						//바이러스일 경우 다음 턴에 끝날경우, 지금 턴이 마지막턴으로 간주되야 하므로 그대로 복사만 해줌
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
	1. DFS (재귀함수) 의 기본! 탈출조건을 만들어야한다. if문쪽에 return이 있어야 한다!!!
	=> 예시들을 넣을때 시간이 유독 오래 걸리면 눈치를 챘어야 했는데..
	2. cnt를 파악하는 방법을 너무 어렵게 생각했다. 벽만 퍼지면 되는건데
	3. 바이러스라는 예외처리가 빡세긴 했지만, 그래도 풀만한 수준
	4. BFS 에서 최소를 구해야할때, 시작하는 곳이 여러곳이라면 (보통은 큐에 1개만 넣고 시작하는데, 이 문제처럼 M개를 집어넣는다면)
	visited배열과 depth배열은 따로 관리해야함
	<반례>
	5 3
	2 2 2 0 0
	1 1 1 1 1
	1 1 1 1 1
	1 1 1 1 1
	1 1 1 1 1
*/