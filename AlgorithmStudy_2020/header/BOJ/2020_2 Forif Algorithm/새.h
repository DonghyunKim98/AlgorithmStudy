#include <bits/stdc++.h>
// 1568¹ø ¹®Á¦
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ans = 0, cnt=1;
	int N;
	cin >> N;
	while (N) {
		if (N < cnt) cnt = 1;
		N -= cnt;
		cnt++;
		ans++;
	}
	cout << ans;
}

/*
	14 => 1 + 2 + 3 + 4 : 10
	   => 1 + 2 : 3
	   => 1 : 1
	ÃÑ 7°³
*/