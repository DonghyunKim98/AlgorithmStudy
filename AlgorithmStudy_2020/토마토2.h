#include <bits/stdc++.h>
//7569문제 -> 토마토1의 3차원버젼 ->풀었음
#define FIRST get<0>
#define SECOND get<1>
#define THIRD get<2>

using namespace std;
const int MAX = 100;
int place[MAX + 1][MAX + 1][MAX + 1];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int M, N, H;
queue <tuple<int, int,int>> q;
int Wall;
bool allRipe() {
	int possible = M * N *H - Wall;
	int cnt=0;
	for (int k = 1; k <= H; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (place[i][j][k] == 1) cnt++;
			}
		}
	}
	return possible == cnt;
}
int bts() {
	int day = 0;
	//처음부터 익힐 수 있는 토마토 자체가 없는 경우
	if (q.empty()) return -1;

	while (!q.empty()) {
		int currentSize = q.size();
		for (int i = 0; i < currentSize; i++) {
			//1번째:y  2번째:x  3번째:z
			int xpos = SECOND(q.front());
			int ypos = FIRST(q.front());
			int zpos = THIRD(q.front());
			q.pop();
			for (int k = 0; k < 6; k++) 
			{
				int nx = xpos + dx[k];
				int ny = ypos + dy[k];
				int nz = zpos + dz[k];

				if (nx >= 1 && nx <= M && ny >= 1 && ny <= N && nz >= 1 && nz <= H) {
					//안 익었을 경우에만
					if (place[ny][nx][nz] == 0) {
						place[ny][nx][nz] = 1;
						q.push(tuple<int, int, int>(ny, nx, nz));
					}
				}
			}
			//익힐 수 있는 토마토를 전부 익혁고 전부 익었을 경우
			if (q.size() == 0 && allRipe())
				return day;
			//익힐 수 있는 토마토는 전부 익혔지만 안 익을 토마토 존재
			else if (q.size() == 0 && !allRipe())
				return -1;
		}
		day++;
	}
}

void Tomato() {
	cin >> M >> N >> H;
	//1번째:y  2번째:x  3번째:z
	for (int k = 1; k <= H; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> place[i][j][k];
				if (place[i][j][k] == 1) {
					q.push(tuple<int, int, int>(i, j, k));
				}
				else if (place[i][j][k] == -1) Wall++;
			}
		}
	}
	//처음부터 토마토가 다 익어있는 상황
	if (M * N * H - Wall == q.size()) cout << 0<<endl;
	else {
		cout<<bts()<<endl;
	}
	
}

/*
	1) 삼차원 배열 및 공간좌표/ 행렬에 관한 개념 잡기
	-> 우리는 기본적으로 (x,y) 에 익숙하다. 
	하지만 배열을 쓸땐,
	[y좌표][x좌표] 로 써야한다. 그리고 이걸 (x,y)라 읽는 것이고
	공간좌표 (x,y,z) 라 쓰지만
	[y좌표][x좌표][z좌표]로 표현하는 것이 더 일반적이다.
*/