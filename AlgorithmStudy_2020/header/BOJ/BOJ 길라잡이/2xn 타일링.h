#include <bits/stdc++.h>
//11726腰 庚薦
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
	けけけけけ
	けけけけけ
	dp[i] = dp[i-1](戚穿 牌拭 室稽 拙企奄 馬蟹 細戚奄) + dp[i-2](戚穿穿牌拭 亜稽 拙企奄 2鯵 細戚奄)
*/