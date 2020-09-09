#include <bits/stdc++.h>
//11727¹ø ¹®Á¦
using namespace std;
#define m 10007;
int N;
int dp[1001];
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	//base case
	dp[1] = 1; dp[2] = 3;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % m;
	}
	cout << dp[N];
}