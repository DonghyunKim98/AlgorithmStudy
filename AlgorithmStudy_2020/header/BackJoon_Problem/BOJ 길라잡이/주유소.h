#include <bits/stdc++.h>
//13305번 문제
using namespace std;
typedef long long ll;
const int MAX = 100000;
int N;
vector<ll> length(MAX);
vector<ll> price(MAX);
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) cin >> length[i];
	for (int i = 0; i < N; i++) cin >> price[i];
	ll ans = 0;
	ll min_price = INT_MAX;
	for (int i = 0; i < N - 1; i++) {
		min_price = min(min_price, price[i]);
		ans += length[i] * min_price;
	}
	cout << ans;
}

/*
	최솟값 최대값 => Greedy or BinaySearch 를 생각하자!
*/