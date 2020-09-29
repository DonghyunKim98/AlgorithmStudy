#include <bits/stdc++.h>
//2740¹ø ¹®Á¦
using namespace std;
const int MAX = 100;
int arr[MAX][MAX], brr[MAX][MAX], crr[MAX][MAX];
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> brr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				crr[i][j] += (arr[i][k] * brr[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << crr[i][j] << ' ';
		}
		cout << '\n';
	}
}