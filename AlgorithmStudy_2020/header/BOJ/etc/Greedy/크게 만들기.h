#include <bits/stdc++.h>
//2812�� ����
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
	//�κ� �������� ����� -> K�� ���ǹ��� �������ν� K���� ���ְ� ��.
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