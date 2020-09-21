#include <bits/stdc++.h>
//16466¹ø ¹®Á¦
using namespace std;
const int MAX = INT_MAX;
map <int, bool> mp;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long N, temp;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> temp;
		mp[temp] = true;
	}
	int idx = 0;
	for (int i = 1; i < MAX; i++) {
		if (mp.count(i) == 1) continue;
		else {
			cout << i;
			break;
		}
	}
}