#include <bits/stdc++.h>
//11052번 문제
using namespace std;
const int MAX = 1000 + 1;
int N;
int card[MAX], dp[MAX];
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> card[i];
	//base case
	dp[1] = card[1];
	//memoization
	for (int i = 2; i <= N; i++) {
		dp[i] = card[i];
		for (int j = 1; j <= i - 1; j++) {
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}
	cout << dp[N];
}

/*
	dp[i] = max(card[i],dp[i-k]+card[k])
	동전 문제와 거의 유사한 dynamic programming
*/