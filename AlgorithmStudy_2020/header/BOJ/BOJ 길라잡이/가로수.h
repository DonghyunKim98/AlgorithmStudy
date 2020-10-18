#include <bits/stdc++.h>
//2485번 문제
using namespace std;
int N;
vector<int> tree;
vector<int> Distance;

int uclid(int a, int b) {
	return b ? uclid(b, a % b) : a;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	//거리들간의 최대공약수.
	int gcd;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (i == 1) gcd = temp - tree.back();
		if (i >= 2) {
			gcd = uclid(gcd, temp - tree.back());
		}
		tree.push_back(temp);
	}
	int ans = 0;
	for (int idx = 1; idx < tree.size(); idx++) {
		ans += (tree[idx] - tree[idx - 1]) / gcd - 1;
	}
	cout << ans;
}


