#include <bits/stdc++.h>
//1676번 문제
using namespace std;

void NumberOfZero() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int two_order = 0;
	int five_order = 0;
	for (int i = N; i > 0; i--) {
		int temp = i;
		while (true) {
			if (temp % 2 == 0) {
				two_order++;
				temp /= 2;
			}
			else break;
		}
		while (true) {
			if (temp % 5 == 0) {
				five_order++;
				temp /= 5;
			}
			else break;
		}
	}

	cout << min(two_order, five_order);
}

/*
	2^n + 5^m 에서 min(n,m) 값을 고르면 됨.
*/