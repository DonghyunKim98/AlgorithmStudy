#include <bits/stdc++.h>
//15649�� ����
using namespace std;
int n, r;
vector<int> pm;
bool* is_chosen = new bool[9]{ false, };

void Searching() {
	if (pm.size() == r) {
		for (auto u : pm)
			cout << u << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (is_chosen[i]) continue;
			//�����ϴϱ� Ž�� -> is_chosen�� ���ǹ��� �������!
			is_chosen[i] = true;
			pm.push_back(i);
			Searching();
			//Ž�� ���� �Ŀ� ���ư���
			is_chosen[i] = false;
			pm.pop_back();
		}
	}
}

void NM() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r;
	Searching();
}