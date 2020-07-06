#include <bits/stdc++.h>
//2580번 문제
//https://jaimemin.tistory.com/664 참고
using namespace std;
int board[9][9];
bool row[9][10]; //열, 1~9가 있는지 확인
bool col[9][10]; // 행, 1~9가 있는지 확인
bool square[9][10]; //3*3 box index, 1~9가 있는지 확인

/*
	1 2 3 -> y=0~2
	4 5 6 -> y=3~5
	7 8 9 -> y=6~8
	=>3*3 box로 된것들의 index.
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
		//답을 한개만 출력
		exit(0);
	}

	int y = cnt / 9;
	int x = cnt % 9;

	if (board[y][x])
		DFS(cnt + 1);
	else {
		//1부터 9까지 있는 지 확인
		for (int i = 1; i <= 9; i++) {
			//단 한개라도 없다! -> 채워넣기! => 순차적으로 넣을 수 있게끔 input이 주어진다고 했으므로!
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
				//j번째 세로 줄에 board[i][j]라는 숫자가 있다!
				col[j][board[i][j]] = true;
				row[i][board[i][j]] = true;
				square[ChangeBoxIdx(i, j)][board[i][j]] = true;
			}
		}
	}

	DFS(0);

}

/*
	알고리즘 포인트)
	1. column & row & 3*3 box 를 다 살펴봐서 0이 1개만 있는 곳의 정보를 이용
		=> 이 때 col / row / box 의 index를 numbering으로 사용해서 true /false를 따지자!
		=> 마치 counting sort
*/