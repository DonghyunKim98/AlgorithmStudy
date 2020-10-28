#include <bits/stdc++.h>
// 16473�� ����
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
		// i+1��°�� �ݵ�� ����.
		for (int j = N; j >= i + 2; j--) {
			// ���ؼ� ���ٸ� 
			if (vc[i] == vc[j]) dp[i][j] = dp[i - 1][j + 1] + 1;
			// ���ؼ� �ٸ��ٸ�
			else dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
		}
	}
	while (T--) {
		cin >> idx;
		// dp�� �־��� idx�� ������ lcs�� �����̹Ƿ�, ������ �ּҰ��� ��ü���� dp�� ������
		cout << (N - dp[idx - 1][idx + 1] * 2 - 1) << '\n';
	}
}

/*
	2 3 1 4 3 4 2

	2��°�� �߽����� �ϴ� �縰���
	=> [2 "3" 2 ] => �����ʿ� 1 4 3 4 �� ����

	4��°�� �߽����� �ϴ� �縰���
	=> [2 3 "4" 3 2] => ���ʿ� 1 �� �������� 4�� ����


	�˰��� ����
	=> LCS (Longest Cummon Subsequence)
*/

