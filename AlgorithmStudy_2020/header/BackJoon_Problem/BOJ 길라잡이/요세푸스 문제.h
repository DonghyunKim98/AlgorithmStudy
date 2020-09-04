#include <bits/stdc++.h>
//1158¹ø ¹®Á¦
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K;
	cin >> N >> K;
	deque<int> dq;
	for (int i = 1; i <= N; i++) dq.push_back(i);
	cout << '<';
	while (!dq.empty()) {
		for (int i = 1; i < K; i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		cout << dq.front();
		dq.pop_front();
		if (dq.size() != 0) cout << ", ";
	}
	cout << '>';
}