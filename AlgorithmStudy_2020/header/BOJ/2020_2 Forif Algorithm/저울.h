#include <bits/stdc++.h>
// 2437번 문제
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> vc;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vc.push_back(temp);
	}
	sort(vc.begin(), vc.end());
	int ans = 1;
	// 맨 처음이 1이 아니라면 당연히 1이 정답
	if (vc[0] == 1) {
		// 누적합을 구해줌
		int acc = vc[0];
		// 누적합 + 1 > vc[i] 까지 구해줘야 함
		for (int i = 1; i < vc.size() && acc + 1>vc[i] - 1; i++) {
			acc += vc[i];
		}
		ans = acc + 1;
	}

	cout << ans;
}