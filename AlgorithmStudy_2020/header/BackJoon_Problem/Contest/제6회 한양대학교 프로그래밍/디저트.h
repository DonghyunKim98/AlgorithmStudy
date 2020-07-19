#include <bits/stdc++.h>
//17953번 문제
using namespace std;
int dp[100000 + 1][10 + 1];
//vc의 item의 idx는 0부터
vector<int> vc[10 + 1];
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			int temp;
			cin >> temp;
			vc[i].push_back(temp);
		}
	}

	//base case
	for (int i = 1; i <= M; i++)
		dp[1][i] = vc[i - 1][0];

	//dynamic programming
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {

		}
	}
}