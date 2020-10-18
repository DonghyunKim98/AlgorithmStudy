#include <bits/stdc++.h>
//17945번 문제
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int B, C;
	cin >> B >> C;
	//중근일 경우
	if (B * B - C == 0) {
		cout << -B;
	}
	else {
		cout << -B - sqrt(B * B - C) << ' ' << -B + sqrt(B * B - C);
	}
}