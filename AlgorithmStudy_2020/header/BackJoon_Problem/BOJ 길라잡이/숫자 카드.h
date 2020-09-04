#include <bits/stdc++.h>
//10815¹ø ¹®Á¦
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	map<int,bool> mp;
	int N, M;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		mp[temp] = true;
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		int target;
		cin >> target;
		if (mp.count(target) == 1) cout << 1 << ' ';
		else cout << 0 << ' ';
	}
}