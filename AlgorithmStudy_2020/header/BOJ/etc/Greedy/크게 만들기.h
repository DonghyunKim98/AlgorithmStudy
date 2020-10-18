#include <bits/stdc++.h>
//2812번 문제
using namespace std;

void BigNumber() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	deque<char> dq;
	//부분 내림차순 만들기 -> K를 조건문에 넣음으로써 K개만 없애게 함.
	for (int i = 0; i < N; i++) {
		while (K && !dq.empty() && dq.back() < s[i]) {
			dq.pop_back();
			K--;
		}
		dq.push_back(s[i]);
	}
		

	for (int i = 0; i < dq.size()-K; i++) {
		cout << dq[i];
	}
}