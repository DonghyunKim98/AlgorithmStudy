#include <bits/stdc++.h>
//15650번 문제
using namespace std;
int n, r;
vector<int> cn;
bool* is_chosen = new bool[9]{ false, };

void Searching() {
	if (cn.size() == r) {
		for (auto u : cn)
			cout << u << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (is_chosen[i]) continue;
			if (!cn.empty() && cn.back() > i) continue;
			is_chosen[i] = true;
			cn.push_back(i);
			Searching();
			is_chosen[i] = false;
			cn.pop_back();
		}
	}
}

void NM() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> r;
	Searching();
}

/*
	조합을 구하는 문제 => 순열 + 순열에서의 오름차순 구현
*/