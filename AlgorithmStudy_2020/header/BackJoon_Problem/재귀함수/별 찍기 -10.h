#include <bits/stdc++.h>
//2447번 문제
//https://blog.naver.com/moonsoo5522/220706431458 참고
//Divide and Conqure (분할정복) 문제이기도 함
using namespace std;
char mat[2201][2201];
void Recursion(int y, int x, int number) {
	//쪼개고 쪼개기
	if (number == 1) {
		mat[y][x] = '*';
		return;
	}
	//계속 쪼개기
	int div = number / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1);
			else {
				Recursion(y + (i * div), x + (j * div), div);
			}
		}
	}
}

void Star() {
	int N;
	cin >> N;
	memset(mat, ' ', sizeof(mat));
	Recursion(0,0,N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << mat[i][j];
		cout << "\n";
	}
}
