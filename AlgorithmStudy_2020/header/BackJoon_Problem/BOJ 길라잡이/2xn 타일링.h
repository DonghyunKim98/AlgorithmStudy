#include <bits/stdc++.h>
//11726�� ����
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
	����������
	����������
	dp[i] = dp[i-1](���� �׿� ���� �۴�� �ϳ� ���̱�) + dp[i-2](�������׿� ���� �۴�� 2�� ���̱�)
*/