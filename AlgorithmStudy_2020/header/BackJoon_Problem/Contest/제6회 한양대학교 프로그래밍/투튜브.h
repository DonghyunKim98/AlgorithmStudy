#include <bits/stdc++.h>
//17954�� ����
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	int** arr = new int* [2];
	for (int i = 0; i < 2; i++)
		arr[i] = new int[N];
	/*
	ex) n=5
	[10 1 2 3 9]
	[8  4 5 6 7]
	=> 7 6 5 4 8 9 3 2 1 10
	*/
	//ù��° �� �Է�
	arr[0][0] = 2 * N;
	arr[0][N - 1] = 2 * N - 1;
	for (int i = 1; i < N - 1; i++)
		arr[0][i] = i;
	//�ι�° �� �Է�
	arr[1][0] = 2 * N - 2;
	arr[1][N - 1] = 2 * N - 3;
	for (int i = 1; i < N - 1; i++)
		arr[1][i] = (N - 2) + i;

	long long answer = 0, total = (2 * N) * (2 * N + 1) / 2, day = -1;
	//���
	//0��° ��~N-1��° ��
	for (int i = 1; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			day++;
			answer += total * day;
			total -= arr[i][j];
		}
	}
	//N�� 1�϶� ����ó��
	if (N == 1) {
		cout << 2 << '\n';
		cout << 1 << '\n';
		cout << 2 << '\n';
	}
	else {
		cout << answer << '\n';
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}


