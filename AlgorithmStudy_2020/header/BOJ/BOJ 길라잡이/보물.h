#include <bits/stdc++.h>
//1026번 문제
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<int> vc_a, vc_b;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		vc_a.push_back(temp);
	}
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		vc_b.push_back(temp);
	}
	sort(vc_a.begin(), vc_a.end());
	sort(vc_b.rbegin(), vc_b.rend());
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += vc_a[i] * vc_b[i];
	}
	cout << ans;
}
/*
	하나는 오름차순 하나는 내림차순으로 정렬하고 곱해주면 끝
*/