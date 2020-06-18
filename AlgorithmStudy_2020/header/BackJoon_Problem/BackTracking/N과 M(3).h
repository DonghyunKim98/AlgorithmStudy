#include <bits/stdc++.h>
//15651번 문제
using namespace std;
int n, r;
vector<int> pie;
bool* is_chosen = new bool[9]{ false, };

void Searching() {
	if (pie.size() == r) {
		for (auto u : pie)
			cout << u << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {
			is_chosen[i] = true;
			pie.push_back(i);
			Searching();
			is_chosen[i] = false;
			pie.pop_back();
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
	중복 순열을 구하는 문제
*/