#include <bits/stdc++.h>
//2580�� ����
//https://jaimemin.tistory.com/664 ����
using namespace std;
int board[9][9];
bool row[9][10]; //��, 1~9�� �ִ��� Ȯ��
bool col[9][10]; // ��, 1~9�� �ִ��� Ȯ��
bool square[9][10]; //3*3 box index, 1~9�� �ִ��� Ȯ��

/*
	1 2 3 -> y=0~2
	4 5 6 -> y=3~5
	7 8 9 -> y=6~8
	=>3*3 box�� �Ȱ͵��� index.
*/
int ChangeBoxIdx(int y, int x) {
	return (y / 3) * 3 + x / 3;
}

void DFS(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << board[i][j] << ' ';
			cout << '\n';
		}
		//���� �Ѱ��� ���
		exit(0);
	}

	int y = cnt / 9;
	int x = cnt % 9;

	if (board[y][x])
		DFS(cnt + 1);
	else {
		//1���� 9���� �ִ� �� Ȯ��
		for (int i = 1; i <= 9; i++) {
			//�� �Ѱ��� ����! -> ä���ֱ�! => ���������� ���� �� �ְԲ� input�� �־����ٰ� �����Ƿ�!
			if (!col[x][i] && !row[y][i] && !square[ChangeBoxIdx(y, x)][i]) {
				board[y][x] = i;
				col[x][i] = row[y][i] = square[ChangeBoxIdx(y, x)][i] = true;
				DFS(cnt + 1);
				//BackTracking 
				board[y][x] = 0;
				col[x][i] = row[y][i] = square[ChangeBoxIdx(y, x)][i] = false;
			}
		}
	}
}


void SudoKu() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				//j��° ���� �ٿ� board[i][j]��� ���ڰ� �ִ�!
				col[j][board[i][j]] = true;
				row[i][board[i][j]] = true;
				square[ChangeBoxIdx(i, j)][board[i][j]] = true;
			}
		}
	}

	DFS(0);

}

/*
	�˰��� ����Ʈ)
	1. column & row & 3*3 box �� �� ������� 0�� 1���� �ִ� ���� ������ �̿�
		=> �� �� col / row / box �� index�� numbering���� ����ؼ� true /false�� ������!
		=> ��ġ counting sort
*/