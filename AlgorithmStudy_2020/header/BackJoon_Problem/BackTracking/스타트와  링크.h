#include <bits/stdc++.h>
//14889�� ����
using namespace std;
int power_map[21][21];
int answer=0;
int N;

void Search(int index_x,int index_y,int temp_total) {
	if (1) {
		answer = min(answer,0);
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (index_x == index_y) continue;
			temp_total += power_map[index_y][index_x] + power_map[index_x][index_y];
		}
	}
}



void StartLink() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> power_map[i][j];
		}
	}

	Search(1,1,0);
	cout << answer;
}

/*
	N => ¦��
	�밢�� �������� ����� �ߺ����� ���� -> �� Ž��
	�ΰ��� ������ ���������� �ɷ�ġ ���� �ּ�ȭ
*/