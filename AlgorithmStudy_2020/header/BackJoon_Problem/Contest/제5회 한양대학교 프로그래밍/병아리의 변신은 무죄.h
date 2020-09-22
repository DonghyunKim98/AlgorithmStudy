#include<bits/stdc++.h>
//16467번 문제
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
	1차 생각
	-> 기본적인 피보나치 형식의 dp?
	-> dp[n] = dp[n-1]+dp[n-(k+1)]
	-> O(n)의 수행시간이 걸림
	따라서 TC 가 100개이고 N의 최댓값은 1억이니 총 100초가 걸린다는 뜻
	최소한 O(log N)으로 시간복잡도를 낮춰야함 -> 어떻게??
*/