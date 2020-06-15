#include <bits/stdc++.h>
//1018�� ����
//https://jaimemin.tistory.com/667 ����
using namespace std;
const int MAX = 50;
const int INF = 987654321;
string board[MAX];
// white�� ���� ������
string white_board[8] = {
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"}
};
string black_board[8] = {
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"}
};

int whiteFirst(int ypos, int xpos) {
	int cnt = 0;
	for (int i = ypos; i < ypos + 8; i++) {
		for (int j = xpos; j < xpos + 8; j++) {
			if (board[i][j] != white_board[i-ypos][j-xpos])
					cnt++;
		}
	}
	return cnt;
}

int blackFirst(int ypos, int xpos) {
	int cnt = 0;
	for (int i = ypos; i < ypos + 8; i++) {
		for (int j = xpos; j < xpos + 8; j++) {
			if (board[i][j] != black_board[i-ypos][j-xpos])
					cnt++;
		}
	}
	return cnt;
}

void Chess() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i <N; i++) {
		cin >> board[i];
	}

	int result = INF;

	//Brutal Force
	for (int i = 0; i + 7 < N; i++) {
		for (int j = 0; j + 7 < M; j++) {
			result = min(result, whiteFirst(i,j));
			result = min(result, blackFirst(i,j));
		}
	}

	cout << result << "\n";
}

/*
	�ٽ� �˰���) Brutal Force
	=> �̸� 8 * 8 ü������ �����س��� ���� ���� ���ϱ�

	���� ������ ���� ���� �ԷµǹǷ� string���� �Է¹��� �� �񱳸� �ؾ��Ѵ�!

*/