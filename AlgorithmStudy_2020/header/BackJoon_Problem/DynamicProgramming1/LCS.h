#include <bits/stdc++.h>
//9251번 문제
using namespace std;

void LCS() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	int dp[1001][1001], i, j;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			//비교해서 같다면 행렬상의 왼쪽 위 (현재 index에 해당하는 2개의 문자가 추가되지 않았던) +1
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			//비교해서 다르다면, 행렬상의 왼쪽이나 위쪽의 값중 MAX값.
			else dp[i][j] = max(dp[i][j - 1], dp[i][j - 1]);

		}
	}
	cout << dp[s1.size()][s2.size()];
}


/*
	알고리즘 설명
	1. String1[n], String2[k]가 같다면 : [n, k] == [n-1, k-1] + 1
	=> 즉 비교해서 같다면 String1[n] 과 String2[k]를 둘 다 포함하지 않은 상태에서 +1
	=> 아예 2개를 모두 고려하면 안 됨 (2개가 모두 상관있기 때문)
	=> 근데 사실 생각해보면 [n-1,k] +1  or [n,k-1]+1 해도 됨
	2. String1[n], String2[k]가 다르면 : [n, k] == [n-1, k]와 [n, k-1] 중 큰 값
	=> 즉 비교해서 같지 않다면 String1[n]이 없었거나, String2[k]가 없던 상태에서 큰 값.
	=> String1[n]과 String[k]를 이용해서 같은 값이 나왔을 수도 있으므로!! 둘 다 사용하지 않은 값에 +1을 하면 안됨.
*/