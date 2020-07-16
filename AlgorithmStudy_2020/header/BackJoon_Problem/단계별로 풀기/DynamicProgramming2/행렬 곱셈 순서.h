#include <bits/stdc++.h>
//11049¹ø ¹®Á¦
using namespace std;
const int MAX = 500;
int dp[MAX][MAX];
pair<int, int> matrix[MAX];
void solution() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		matrix[i] = make_pair(temp1, temp2);
	}

	for (int gap = 1; gap <= N; gap++) {
		for (int start = 0; start + gap < N; start++) {
			int end = start + gap;
			dp[start][end] = INT_MAX;
			for (int mid = start; mid < end; mid++) {
				dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + matrix[start].first * matrix[mid].second * matrix[end].second);
			}
		}
	}

	cout << dp[0][N-1];
}