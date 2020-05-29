#include<bits/stdc++.h>

// 4963�� ����
//https://ldgeao99.tistory.com/400 ����
// �÷����� �˰���
using namespace std;

int place[51][51]; // 0: �ٴ� , 1: ��
int check[51][51]; //0: �湮����, 1�̻� : ���� ��ȣ
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int w, h; //w: �ʺ� h: ����

//������ ��� ���� Ž���ϰ�, ��ȣ�� �ο���
void dfs(int i, int j, int num) {
	check[i][j] = num;
	//8���� �����߿� �� �� �ִ� ���, �׸��� �湮���� ���� ��쿡�� Ž��
	for (int k = 0; k < 8; k++) {
		int x = i + dx[k];
		int y = j + dy[k];

		if (x >= 1 && x <= h && y >= 1 && y <= w) {
			if (place[x][y] == 1 && check[x][y] == 0) {
				dfs(x, y, num);
			}
		}
	}
}
void IslandNumber() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		
		//�迭 ����� �ʱ�ȭ
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				place[i][j] = 0;
				check[i][j] = 0;
			}
		}
		
		//�� ,�ٴ� ���� �Է¹ޱ�
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> place[i][j];
			}
		}

		//��� ���� ���������� �Ͽ� Ž�� ����, "����� ���� ��쿡 ���� ��ȣ �ο�"
		int num = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (place[i][j] == 1 && check[i][j] == 0)
					dfs(i, j, ++num);
			}
		}
		cout << num << "\n";
	}
}

/*
	�ʹ���ƴ� �ФФ� ���� �غ��� �־���ϴµ� ���� �����ؼ� �� �غ���!
	�����)
	1. ��������Ʈ�� ���� ��Ÿ���� �ʾƵ� �ȴ�!
	2. ���� �迭 dx �� dy�� Ȱ��!!
*/