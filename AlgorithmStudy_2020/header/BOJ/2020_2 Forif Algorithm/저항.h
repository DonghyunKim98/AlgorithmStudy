#include <bits/stdc++.h>
// 1076¹ø ¹®Á¦
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
string arr[10] = {
	"black", "brown", "red", "orange",
	"yellow", "green", "blue", "violet", "grey", "white"
};

int Sqrt(int a, int b) {
	int ret = 1;
	for (int i = 0; i < b; i++) ret *= a;
	return ret;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	map<string, pii> mp;
	for (int i = 0; i < 10; i++) {
		mp[arr[i]] = { i,Sqrt(10,i) };
	}
	ll ans = 0;
	string temp;
	for (int i = 0; i < 3; i++) {
		cin >> temp;
		if (i == 0) ans += mp[temp].first * 10;
		else if (i == 1) ans += mp[temp].first;
		else ans *= mp[temp].second;
	}
	cout << ans;
}