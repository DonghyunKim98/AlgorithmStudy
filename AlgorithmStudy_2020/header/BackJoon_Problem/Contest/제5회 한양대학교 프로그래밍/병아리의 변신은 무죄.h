#include<bits/stdc++.h>
//16467�� ����
using namespace std;
#define m 100000007;
typedef long long ll;
const int MAX = 100000000+1;
ll dp[MAX];
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int K, N;
		cin >> K >> N;
		memset(dp, N, sizeof(dp));
		//base case
		for (int i = 0; i <= K; i++) {
			dp[i] = 1;
		}
		for (int i = K + 1; i <= N; i++) {
			dp[i] = (dp[i - 1] + dp[i - (K + 1)]) % m;
		}
		cout << dp[N] << endl;
	}
	
}

/*
	1�� ����
	-> �⺻���� �Ǻ���ġ ������ dp?
	-> dp[n] = dp[n-1]+dp[n-(k+1)]
	-> O(n)�� ����ð��� �ɸ�
	���� TC �� 100���̰� N�� �ִ��� 1���̴� �� 100�ʰ� �ɸ��ٴ� ��
	�ּ��� O(log N)���� �ð����⵵�� ������� -> ���??
*/