#include <bits/stdc++.h>
//17945�� ����
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int B, C;
	cin >> B >> C;
	//�߱��� ���
	if (B * B - C == 0) {
		cout << -B;
	}
	else {
		cout << -B - sqrt(B * B - C) << ' ' << -B + sqrt(B * B - C);
	}
}