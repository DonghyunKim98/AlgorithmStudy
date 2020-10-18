#include <bits/stdc++.h>
//17953번 문제
using namespace std;
//[n번째날][m번째item] 을 먹었을때의 최대 효율
int dp[100000 + 1][10 + 1];
//[m번째item][n번째날] 먹을때의 효율
vector<int> vc[10 + 1];
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		//0번째 idx를 피하기 위한 조치
		vc[i].push_back(0);
		for (int j = 1; j <= N; j++) {
			int temp;
			cin >> temp;
			vc[i].push_back(temp);
		}
	}

	//base case
	int answer = 0;
	for (int i = 1; i <= M; i++) {
		dp[1][i] = vc[i][1];
		answer = max(dp[1][i], answer);
	}

	//dynamic programming
	for (int i = 2; i <= N; i++) {
		//[i번째날][j번째음식]을 먹었을때의 효용
		for (int j = 1; j <= M; j++) {
			//전날 k번째 먹은 경우를 계산
			for (int k = 1; k <= M; k++) {
				int temp;
				if (j == k) temp = dp[i-1][k] + (vc[j][i] / 2);
				else temp = dp[i-1][k] + vc[j][i];
				dp[i][j] = max(dp[i][j], temp);
			}
			if (i == N) {
				answer = max(answer, dp[i][j]);
			}
		}
	}
	cout << answer;
}