#include <bits/stdc++.h>
//6063¹ø ¹®Á¦
using namespace std;
vector<int> vc;
vector<int> chosen;
bool is_chosen[14];
void DFS(int idx,int size) {
	if (idx == 6) {
		for (auto u : vc) cout << u << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < size; i++) {
		if (is_chosen[i]) continue;
		if (!vc.empty() && vc.back() > chosen[i]) continue;
		is_chosen[i] = true;
		vc.push_back(chosen[i]);
		DFS(idx + 1,size);
		is_chosen[i] = false;
		vc.pop_back();
	}
}


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K;

	while (true) {
		cin >> K;
		if (!K) break;
		chosen.clear();
		memset(is_chosen, false, sizeof(is_chosen));
		for (int i = 0; i < K; i++) {
			int temp;
			cin >> temp;
			chosen.push_back(temp);
		}
		DFS(0,K);
		cout << '\n';
	}
}