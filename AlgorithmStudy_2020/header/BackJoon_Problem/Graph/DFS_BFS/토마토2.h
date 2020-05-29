#include <bits/stdc++.h>
//7569���� -> �丶��1�� 3�������� ->Ǯ����
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
	//ó������ ���� �� �ִ� �丶�� ��ü�� ���� ���
	if (q.empty()) return -1;

	while (!q.empty()) {
		int currentSize = q.size();
		for (int i = 0; i < currentSize; i++) {
			//1��°:y  2��°:x  3��°:z
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
					//�� �;��� ��쿡��
					if (place[ny][nx][nz] == 0) {
						place[ny][nx][nz] = 1;
						q.push(tuple<int, int, int>(ny, nx, nz));
					}
				}
			}
			//���� �� �ִ� �丶�並 ���� ������ ���� �;��� ���
			if (q.size() == 0 && allRipe())
				return day;
			//���� �� �ִ� �丶��� ���� �������� �� ���� �丶�� ����
			else if (q.size() == 0 && !allRipe())
				return -1;
		}
		day++;
	}
}

void Tomato() {
	cin >> M >> N >> H;
	//1��°:y  2��°:x  3��°:z
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
	//ó������ �丶�䰡 �� �;��ִ� ��Ȳ
	if (M * N * H - Wall == q.size()) cout << 0<<endl;
	else {
		cout<<bts()<<endl;
	}
	
}

/*
	1) ������ �迭 �� ������ǥ/ ��Ŀ� ���� ���� ���
	-> �츮�� �⺻������ (x,y) �� �ͼ��ϴ�. 
	������ �迭�� ����,
	[y��ǥ][x��ǥ] �� ����Ѵ�. �׸��� �̰� (x,y)�� �д� ���̰�
	������ǥ (x,y,z) �� ������
	[y��ǥ][x��ǥ][z��ǥ]�� ǥ���ϴ� ���� �� �Ϲ����̴�.
*/