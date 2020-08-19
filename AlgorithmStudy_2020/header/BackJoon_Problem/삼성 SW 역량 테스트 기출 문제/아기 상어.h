#include <bits/stdc++.h>
//16236번 문제
using namespace std;
#define max_int 21
#define max_val 401
// a 배열은 지도의 정보를 저장합니다. check 배열은 이동거리를 저장합니다.
int N, arr[max_int][max_int], check[max_int][max_int], shark_x, shark_y, eat_cnt, shark_size = 2;
int min_dist, min_x, min_y, result;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

// 상어 또는 물고의 좌표(x, y)를 저장할 구초제 정의
// 가장 위, 가장 왼쪽 비교가 들어가기 때문에
// pair를 사용해도 좋습니다. (pair는 비교를 해주기 때문입니다.)
struct info {
	int x, y;
};

// BFS 수행을 위한 정보 초기화
void init_check() {
	min_dist = max_val;
	min_x = max_int;
	min_y = max_int;
	memset(check, -1, sizeof(check));
}

// 완전 탐색(BFS) 수행
void bfs(int x, int y) {
	// BFS에 사용할 큐를 선언합니다.
	queue<info> q;
	// 상어의 첫 위치의 시간은 0으로 초기화합니다.
	check[x][y] = 0;
	q.push({ x, y });

	while (!q.empty()) {
		// 큐에서 가장 앞에 있는 객체를 꺼냅니다.
		info cur = q.front();
		q.pop();
		int x = cur.x;
		int y = cur.y;

		// 4방향을 탐색합니다.
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 지도 밖으로 넘어갔을 경우 건너뜁니다.
			if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
			// 1) 이미 방문했거나, 2) 상어의 크기보다 큰 물고리인 경우 건너 뜁니다.
			if (check[nx][ny] != -1 || arr[nx][ny] > shark_size) continue;

			// (nx, ny)에 있는 물고기까지의 이동거리를 갱신해줍니다.
			check[nx][ny] = check[x][y] + 1;

			// 먹을 수 있는 물고기일 경우
			if (arr[nx][ny] != 0 && arr[nx][ny] < shark_size) {

				// 이 부분은 pair의 비교, 객체의 연산자 오버로딩을 통한 <= 비교로 더 간단하게 작성할 수 있습니다.
				// 만약 현재 물고기 까지의 이동시간이 더 짧은 경우
				if (min_dist > check[nx][ny]) {
					min_x = nx;
					min_y = ny;
					min_dist = check[nx][ny];
				}
				// 만약 현재 물고기 까지의 이동시간은 같으면 1) 가장 위쪽, 가장 왼쪽을 찾습니다.
				else if (min_dist == check[nx][ny]) {
					if (min_x == nx) {
						if (min_y > ny) {
							min_x = nx;
							min_y = ny;
						}
					}
					else if (min_x > nx) {
						min_x = nx;
						min_y = ny;
					}
				}
			}

			// 물고기의 위치를 큐에 넣어줍니다.
			q.push({ nx, ny });
		}
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	// 지도 정보를 입력받습니다.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];

			// 아기 상어일 경우
			if (arr[i][j] == 9) {
				// x, y 좌표를 따로 저장해주고
				shark_x = i;
				shark_y = j;
				// 지도상에서 0으로 비워줍니다.
				arr[i][j] = 0;
			}
		}
	}

	// 2. 반복문 수행
	// 총 n^2(물고기의 총 개수)번 수행됩니다.
	while (true) {
		// BFS 수행을 위한 정보 초기화
		init_check();

		// 완전 탐색으로 먹을 수 있는 물고기를 찾습니다.
		bfs(shark_x, shark_y);

		// 먹을 수 있는 물고기를 찾은 경우
		if (min_x != max_int && min_y != max_int) {
			// 이동시간을 더해줍니다.
			result += check[min_x][min_y];

			// 물고기 먹은 수를 1 증가시킵니다.
			eat_cnt++;

			// 만약 먹은 물고기 수가 상어의 크기와 같다면
			if (eat_cnt == shark_size) {
				// 상어의 크기를 1 증가시키고, 먹은 물고기 수를 0으로 초기화시켜줍니다.
				shark_size++;
				eat_cnt = 0;
			}

			// 먹은 물고기의 위치를 0으로 갱신해줍니다.
			arr[min_x][min_y] = 0;

			// 상어의 위치를 갱신해줍니다.
			shark_x = min_x;
			shark_y = min_y;
		}

		// 먹을 수 있는 물고기가 없는 경우 반복문을 끝냅니다.
		else {
			break;
		}
	}

	// 3. 출력
	// 이동에 걸린 시간을 출력합니다.
	cout << result;
}