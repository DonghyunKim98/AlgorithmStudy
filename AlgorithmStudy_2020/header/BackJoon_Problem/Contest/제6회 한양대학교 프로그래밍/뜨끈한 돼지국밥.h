#include <bits/stdc++.h>
//17948¹ø ¹®Á¦
using namespace std;
#define N 5001
long long dist[N];
long long cost[N][N];
int n, C, M;
long long d[N];
int cnt[N];
long long go(int index) {
	if (d[index] != -1) return d[index];
	d[index] = (long long)(C * cost[index][n]) + M;
	cnt[index] = 1;
	for (int i = index + 1; i <= n; ++i) {
		long long temp = (long long)(C * cost[index][i - 1]) + go(i) + M;
		int store = cnt[i] + 1;
		if (temp < d[index]) {
			d[index] = temp;
			cnt[index] = store;
		}
		else if (temp == d[index]) {
			cnt[index] = min(cnt[index], store);
		}
	}
	return d[index];
}

void solution() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> dist[i];
	}
	cin >> C >> M;
	sort(dist + 1, dist + 1 + n);
	for (int i = 1; i <= n; ++i) {
		dist[i] += dist[i - 1];d
		d[i] = -1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			int m = i + j >> 1;
			if ((j - i) & 1) {
				cost[i][j] = dist[j] - dist[m] - dist[m] + dist[i - 1];
			}
			else {
				cost[i][j] = dist[j] - dist[m] - dist[m - 1] + dist[i - 1];
			}
		}
	}
	cout << go(1) << ' ';
	cout << cnt[1];
}