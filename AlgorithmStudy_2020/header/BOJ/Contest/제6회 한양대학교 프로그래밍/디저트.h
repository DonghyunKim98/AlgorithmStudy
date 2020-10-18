#include <bits/stdc++.h>
//17953�� ����
using namespace std;
//[n��°��][m��°item] �� �Ծ������� �ִ� ȿ��
int dp[100000 + 1][10 + 1];
//[m��°item][n��°��] �������� ȿ��
vector<int> vc[10 + 1];
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		//0��° idx�� ���ϱ� ���� ��ġ
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
		//[i��°��][j��°����]�� �Ծ������� ȿ��
		for (int j = 1; j <= M; j++) {
			//���� k��° ���� ��츦 ���
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