#include <bits/stdc++.h>
//11066번 문제
//https://js1jj2sk3.tistory.com/search/11066 참고
using namespace std;
const int MAX = 500 + 1;
int dp[MAX][MAX];
int cost[MAX];
int sum[MAX];


void FileMerge() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T > 0) {
		int K;
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}

		for (int gap = 1; gap < K; gap++) {
			for (int tx = 1; tx + gap <= K; tx++) {
				int ty = tx + gap;
				dp[tx][ty] = INT_MAX;

				for (int mid = tx; mid < ty; mid++) {
					//tx~ty 까지의 부분합을 마지막에 더하는 이유는
					//[tx,mid] 까지의 비용과 [mid+1][ty] 까지의 비용을 합한 값이 곧 tx~ty의 부분합이기 때문.
					dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
				}
			}
		}

		cout << dp[1][K] << '\n';
		T--;
	}
}

/*
	알고리즘 포인트
	1. 일단 기본적으로 '시작' '끝' 을 기준으로 하는 2차원 dp 배열이 많다. 이 개념 챙겨두자.(팰린드롬도 같은 문제)
	2. gap을 기준으로 차차 늘려가는 dp 였다. 조금만 생각하면 사실 이것도 떠올리긴 쉬운듯 O(n^3)인게 문제이지만.
	3. O(n^2)도 있으니, 이해해보자.
*/