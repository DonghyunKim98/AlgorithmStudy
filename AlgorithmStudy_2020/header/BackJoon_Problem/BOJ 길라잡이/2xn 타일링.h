#include <bits/stdc++.h>
//11726번 문제
#define m 10007
using namespace std;
int dp[1001];
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	//base case 
	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] % m + dp[i - 2] % m) % m;
	}
	cout << dp[N];
}

/*
	ㅁㅁㅁㅁㅁ
	ㅁㅁㅁㅁㅁ
	dp[i] = dp[i-1](이전 항에 세로 작대기 하나 붙이기) + dp[i-2](이전전항에 가로 작대기 2개 붙이기)
*/