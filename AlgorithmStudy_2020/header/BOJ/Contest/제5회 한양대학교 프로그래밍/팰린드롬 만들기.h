#include <bits/stdc++.h>
// 16473번 문제
using namespace std;
const int MAX = 5000 + 5;
int N, T, idx;
int dp[MAX][MAX];
vector<int> vc(MAX);

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> vc[i];
	cin >> T;
	for (int i = 1; i <= N; i++) {
		// i+1번째는 반드시 포함.
		for (int j = N; j >= i + 2; j--) {
			// 비교해서 같다면 
			if (vc[i] == vc[j]) dp[i][j] = dp[i - 1][j + 1] + 1;
			// 비교해서 다르다면
			else dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
		}
	}
	while (T--) {
		cin >> idx;
		// dp는 주어진 idx를 제외한 lcs의 길이이므로, 제거할 최소값은 전체에서 dp를 빼야함
		cout << (N - dp[idx - 1][idx + 1] * 2 - 1) << '\n';
	}
}

/*
	2 3 1 4 3 4 2

	2번째를 중심으로 하는 펠린드롬
	=> [2 "3" 2 ] => 오른쪽에 1 4 3 4 를 버림

	4번째를 중심으로 하는 펠린드롬
	=> [2 3 "4" 3 2] => 왼쪽에 1 과 오른쪽의 4를 버림


	알고리즘 설명
	=> LCS (Longest Cummon Subsequence)
*/

